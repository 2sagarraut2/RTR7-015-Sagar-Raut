del *.exe
del *.obj
del *.obj

cl.exe /FC /c /EHsc OGL.c font.c

rc.exe OGL.rc

link.exe OGL.obj font.obj OGL.res USER32.lib GDI32.lib /SUBSYSTEM:WINDOWS
