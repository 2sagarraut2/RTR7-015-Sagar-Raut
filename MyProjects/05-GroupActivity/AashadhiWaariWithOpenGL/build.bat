del *.exe
del *.obj
del *.obj

cl.exe /FC /c /EHsc AashadhiWaari.c

rc.exe OGL.rc

link.exe AashadhiWaari.obj OGL.res USER32.lib GDI32.lib /SUBSYSTEM:WINDOWS
