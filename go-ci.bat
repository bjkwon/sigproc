@path %path%;c:\dev\GnuWin32\bin\
bison -d -v cipsycon.y
flex -ocipsycon.yy.c cipsycon.l
@copy /y psycon.yacc.h ..\common\include
@copy /y sigproc.h ..\common\include
@pause
