cl.exe /c /EHsc Window.c
rc Window.rc -> this gives Window.res file
link.exe Window.obj Window.res User32.lib GDI32.lib /SUBSYSTEM:WINDOWS

EHsc - exception handler synchronous catch
