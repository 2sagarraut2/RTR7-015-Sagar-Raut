// header files
// standard headers
#include <stdio.h>
#include <stdlib.h> // for exit

// OpenCL headers
#include <CL/opencl.h>

// global variables
const int iNumberOfArrayElements = 5;

// opencl specific variables
cl_platform_id oclPlatformID;
cl_device_id oclDeviceID;

cl_context oclContext = NULL;
cl_command_queue oclCommandQueue = NULL;

cl_program oclProgram = NULL;
cl_kernel oclKernel = NULL;

float *hostInput1 = NULL;
float *hostInput2 = NULL;
float *hostOutput = NULL;

cl_mem deviceInput1 = NULL;
cl_mem deviceInput2 = NULL;
cl_mem deviceOutput = NULL;

// OpenCL kernel
const char *oclSourceCode =
    "__kernel void vecAddGPU(__global float *in1, __global float *in2, __global float *out, int len)"
    "{"
    "int i = get_global_id(0);"
    "if(i < len)"
    "{"
    "out[i] = in1[i] + in2[i];"
    "}"
    "}";

// entry-point function
int main(void)
{
    // function declarations
    void cleanup(void);

    // variable declarations
    int size = iNumberOfArrayElements * sizeof(float);
    cl_int result;

    // code
    // host memory allocation
    hostInput1 = (float *)malloc(size);
    if (hostInput1 == NULL)
    {
        printf("Host Memory allocation is failed for hostInput1 array.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    hostInput2 = (float *)malloc(size);
    if (hostInput2 == NULL)
    {
        printf("Host Memory allocation is failed for hostInput2 array.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    hostOutput = (float *)malloc(size);
    if (hostOutput == NULL)
    {
        printf("Host Memory allocation is failed for hostOutput array.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // filling values into host arrays
    hostInput1[0] = 101.0;
    hostInput1[1] = 102.0;
    hostInput1[2] = 103.0;
    hostInput1[3] = 104.0;
    hostInput1[4] = 105.0;

    hostInput2[0] = 201.0;
    hostInput2[1] = 202.0;
    hostInput2[2] = 203.0;
    hostInput2[3] = 204.0;
    hostInput2[4] = 205.0;

    // get OpenCL supporting platform's ID
    result = clGetPlatformIDs(1, &oclPlatformID, NULL);
    if (result != CL_SUCCESS)
    {
        printf("clGetPlatformIDs() Failed: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // get OpenCL supporting GPU device's ID
    result = clGetDeviceIDs(oclPlatformID, CL_DEVICE_TYPE_GPU, 1, &oclDeviceID, NULL);
    if (result != CL_SUCCESS)
    {
        printf("clGetDeviceIDs() Failed: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // create OpenCL compute context
    oclContext = clCreateContext(NULL, 1, &oclDeviceID, NULL, NULL, &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateContext() Failed: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // create command queue
    oclCommandQueue = clCreateCommandQueue(oclContext, oclDeviceID, 0, &result);
    // clCreateCommandQueueWithProperties - use if given warning to clCreateCommandQueue
    if (result != CL_SUCCESS)
    {
        printf("clCreateCommandQueue() Failed: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // create OpenCL program from .cl
    // program object which will compile and link (build) the kernel code
    // this program contains kernel compilar and linker of GPU program
    oclProgram = clCreateProgramWithSource(oclContext, 1, (const char **)&oclSourceCode, NULL, &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateProgramWithSource() Failed: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // build OpenCL program
    result = clBuildProgram(oclProgram, // program object
                            0,          // number of devices
                            NULL,       // array of multiple devices list
                            NULL,       // buid option string - FAST_MATH
                            NULL,       // if callback function then provide address of callback function
                            NULL);      // parameter to callback function
    if (result != CL_SUCCESS)
    {
        size_t len;
        char buffer[2048];                          // to store error in kernel
        clGetProgramBuildInfo(oclProgram,           // build program
                              oclDeviceID,          // device id
                              CL_PROGRAM_BUILD_LOG, // build log
                              sizeof(buffer),       // size of the buffer in which we will get this info
                              buffer,               // address of buffer
                              &len);                // length of information given
        printf("Program Build Log: %s\n", buffer);
        printf("clBuildProgram() Failed: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // create OpenCL kernel by passing kernel function name that we used in .cl file
    oclKernel = clCreateKernel(oclProgram,  // name of program
                               "vecAddGPU", // function from which we want to create kernel
                               &result);    // error
    if (result != CL_SUCCESS)
    {
        printf("clCreateKernel() Failed: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // device memory allocation
    deviceInput1 = clCreateBuffer(oclContext,       // context
                                  CL_MEM_READ_ONLY, // we want read data from input1
                                  size,             // size of input1
                                  NULL,             // address of existing buffer if we have so that it can be copied
                                  &result);         // error
    if (result != CL_SUCCESS)
    {
        printf("clCreateBuffer() Failed For deviceInput1 Array: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    deviceInput2 = clCreateBuffer(oclContext,       // context
                                  CL_MEM_READ_ONLY, // we want read data from input1
                                  size,             // size of input1
                                  NULL,             // address of existing buffer if we have so that it can be copied
                                  &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateBuffer() Failed For deviceInput2 Array: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    deviceOutput = clCreateBuffer(oclContext, CL_MEM_WRITE_ONLY, // we want for writing
                                  size, NULL, &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateBuffer() Failed For deviceOutput Array: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based argument i.e. deviceInput1
    // setting opencl kernel arguments
    result = clSetKernelArg(oclKernel,              // kernel name
                            0,                      // index of the parameter to the kernel
                            sizeof(cl_mem),         // size of sending parameter
                            (void *)&deviceInput1); // parameter name
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed For 1st Argument: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based 1st argument i.e. deviceInput2
    result = clSetKernelArg(oclKernel, 1, sizeof(cl_mem), (void *)&deviceInput2);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed For 2nd Argument: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based 2nd argument i.e. deviceOutput
    result = clSetKernelArg(oclKernel, 2, sizeof(cl_mem), (void *)&deviceOutput);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed For 3rd Argument: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based 3rd argument i.e. len
    result = clSetKernelArg(oclKernel, 3, sizeof(cl_int), (void *)&iNumberOfArrayElements);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed For 4th Argument: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // write above 'input' device buffer to device memory
    result = clEnqueueWriteBuffer(oclCommandQueue, // which queue
                                  deviceInput1,    // which buffer | target
                                  CL_FALSE,        // asynchronous || non-blocking
                                  0,               // where to start from 0th byte of state
                                  size,            // size of data
                                  hostInput1,      // source name
                                  0,               // number of event array
                                  NULL,            // how many events
                                  NULL);           // which one will be returned
    if (result != CL_SUCCESS)
    {
        printf("clEnqueueWriteBuffer() Failed For 1st Input Device Buffer: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    result = clEnqueueWriteBuffer(oclCommandQueue, deviceInput2, CL_FALSE, 0, size, hostInput2, 0, NULL, NULL);
    if (result != CL_SUCCESS)
    {
        printf("clEnqueueWriteBuffer() Failed For 2nd Input Device Buffer: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // kernel configuration
    size_t global_size = 5; // 1-D 5 element array operation
    // tell opencl to execute kernel
    result = clEnqueueNDRangeKernel(oclCommandQueue, //
                                    oclKernel,       // which kernel
                                    1,               // dimention
                                    NULL,            // reserved
                                    &global_size,    // global size
                                    NULL,            // local size
                                    0,               // number of event array
                                    NULL,            // how many events
                                    NULL);           // which one will be returned
    if (result != CL_SUCCESS)
    {
        printf("clEnqueueNDRangeKernel() Failed: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // finish OpenCL command queue
    clFinish(oclCommandQueue); // enqueue finished start executing

    // read back result from the device (i.e from deviceOutput) into cpu variable (i.e hostOutput)
    result = clEnqueueReadBuffer(oclCommandQueue,
                                 deviceOutput, // from where to read
                                 CL_TRUE,      // blocking reading | synchronous
                                 0,            // from 0th byte of set
                                 size,         // how much to read
                                 hostOutput,   // where to copy after reading
                                 0,            // number of event array
                                 NULL,         // how many events
                                 NULL);        // which one will be returned
    if (result != CL_SUCCESS)
    {
        printf("clEnqueueReadBuffer() Failed: %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // display results
    int i;
    for (i = 0; i < iNumberOfArrayElements; i++)
    {
        printf("%f + %f = %f\n", hostInput1[i], hostInput2[i], hostOutput[i]);
    }

    // cleanup
    cleanup();
    return (0);
}

void cleanup(void)
{
    // code
    if (deviceOutput)
    {
        clReleaseMemObject(deviceOutput);
        deviceOutput = NULL;
    }

    if (deviceInput2)
    {
        clReleaseMemObject(deviceInput2);
        deviceInput2 = NULL;
    }

    if (deviceInput1)
    {
        clReleaseMemObject(deviceInput1);
        deviceInput1 = NULL;
    }

    if (oclKernel)
    {
        clReleaseKernel(oclKernel);
        oclKernel = NULL;
    }

    if (oclProgram)
    {
        clReleaseProgram(oclProgram);
        oclProgram = NULL;
    }

    if (oclCommandQueue)
    {
        clReleaseCommandQueue(oclCommandQueue);
        oclCommandQueue = NULL;
    }

    if (oclContext)
    {
        clReleaseContext(oclContext);
        oclContext = NULL;
    }

    if (hostOutput)
    {
        free(hostOutput);
        hostOutput = NULL;
    }

    if (hostInput2)
    {
        free(hostInput2);
        hostInput2 = NULL;
    }

    if (hostInput1)
    {
        free(hostInput1);
        hostInput1 = NULL;
    }
}
