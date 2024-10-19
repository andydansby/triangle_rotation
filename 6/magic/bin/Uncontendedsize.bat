rem uncontended consist of the compiled code + IM2 + stack
rem stack is
rem uncontended code starts at 32768 to 48572
rem IM2 runs from 48573  (336 bytes)
rem stack is 243 bytes
rem as it is programmed right now $BF02 to $BFFF
rem FD (253) Bytes is stack size
rem $BF02 - $BFFF is STACK
rem 48898 - 49151 = stack

setlocal
set "file=compiled_CODE.bin"
set maxbytesize=15804
call :setsize %file%
if %size% gtr %maxbytesize% (
    echo Uncontended Memory Size TOO Large
    pause
) else (
    echo Uncontended Memory Size OK
)

SET /A a = %size%
SET /A b = %maxbytesize%
SET /A c = %b%-%a%
echo %c% bytes free in UNCONTENDED

goto :eof

:setsize
set size=%~z1
goto :eof


