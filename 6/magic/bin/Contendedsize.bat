setlocal
set "file=compiled_CONTENDED.bin"
set maxbytesize=8487
call :setsize %file%
if %size% gtr %maxbytesize% (
    echo Contended Memory Size TOO Large
    pause
) else (
    echo Contended Memory Size OK
)

SET /A a = %size%
SET /A b = %maxbytesize%
SET /A c = %b%-%a%
echo %c% bytes free in CONTENDED

goto :eof

:setsize
set size=%~z1
goto :eof

