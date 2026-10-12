@echo off
REM ---- Build the shell lexer + parser on Windows (WinFlexBison + MinGW gcc) ----
win_bison -d -o parser.tab.c parser.y
if errorlevel 1 goto :fail
win_flex --wincompat -o lex.yy.c lexer.l
if errorlevel 1 goto :fail
gcc -o shellparser.exe parser.tab.c lex.yy.c
if errorlevel 1 goto :fail
echo.
echo Build OK - shellparser.exe created
goto :eof
:fail
echo.
echo BUILD FAILED
exit /b 1
