@rem SET PATH=c:\z88dk199c;c:\z88dk199c\bin;c:\z88dk199c\lib\;c:\z88dk199c\lib\clibs;c:\z88dk199c\lib\config;C:\Program Files\SDCC\bin



SET PATH=c:\z88dk203;c:\z88dk203\bin;c:\z88dk203\lib\;c:\z88dk203\lib\clibs;c:\z88dk203\lib\config;C:\Program Files\SDCC\bin;C:\Program Files\GnuWin32\bin

move "1output.tap" "archive"

cls

rem using sdcc_iy 2.03

cd utils
    copy "bas2tap.exe" "..\magic"
    copy "loader.bas" "..\magic"
cd ..

rem pause

cd CONTENDED
	call ramlow.bat
	move "contended.txt" "..\"
cd ..

rem pause

cd RAM0
	call ram0.bat
	move "ram0.txt" "..\"
cd ..

rem pause

cd UNCONTENDED
	call uncontended.bat
	move "uncontended.txt" "..\"
cd ..

rem pause

echo on

move "contended.o" "OBJECTS\"
move "ram0.o" "OBJECTS\"
move "uncontended.o" "OBJECTS\"


rem pause


cd OBJECTS
	call magic.bat
cd ..

rem pause

cd UNCONTENDED
    call rammain.bat
cd ..

rem pause

@cd magic
@   call voodoo.bat
@   cd bin
@       call sizeTester.bat
@   cd ..
@cd ..


REM FINISHED COMPILE
call beep.bat

