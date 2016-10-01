@path %path%;c:\dev\GnuWin32\bin\
bison -d -v psycon.y
flex -opsycon.yy.c psycon.l
@copy /y psycon.yacc.h ..\common\include
@copy /y sigproc.h ..\common\include
pause
