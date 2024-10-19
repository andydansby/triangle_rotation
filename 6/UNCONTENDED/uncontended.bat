
cd codemaps
	del uncontended.o
cd ..

rem compiling string for SDCC object file
zcc +zx -vn -clib=sdcc_iy -c -o uncontended.o -m @ramMain.lst



@if not exist "uncontended.o" (
call error.bat
)

copy "uncontended.o" "..\"
move "uncontended.o" "codemaps\"



REM a nice map view
cd codemaps
	echo on
	@REM all these objects match up
	z88dk-z80nm uncontended.o
	z88dk-z80nm uncontended.o > uncontended.txt
	copy "uncontended.txt" "..\"
	echo off
cd ..


call beep.bat
