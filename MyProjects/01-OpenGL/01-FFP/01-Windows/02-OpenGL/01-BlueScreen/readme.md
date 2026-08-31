## How to go to opengl from our stub code

# step 1:

Ask OS to give its pixel format to match the rendering requirements. This will require device device context too

# step 2:

choose and select that OS given pixel format

# step 3:

use bridging API to create rendering context according to the chosen pixel format and device context

# step 4:

make that rednering conext as current context for further rendering

# step 5:

start rendering API
