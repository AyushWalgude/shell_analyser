@echo off
echo ===== VALID scripts (expect: syntax is VALID) =====
for %%f in (tests\valid1.sh tests\crlf.sh) do shellparser.exe %%f
echo.
echo ===== INVALID scripts (expect: syntax errors) =====
for %%f in (tests\bad_*.sh) do (
    echo ---- %%f
    shellparser.exe %%f
)
