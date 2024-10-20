cd codemaps
	del contended.o
cd ..

rem compiling string for SDCC object file
zcc +zx -vn -clib=sdcc_iy @ramlow.lst -c -o contended.o -m

@if not exist "contended.o" (
call error.bat
)

copy "contended.o" "..\"
move "contended.o" "codemaps\"

@REM Cleanup
del zcc_opt.def

REM a nice map view
cd codemaps
	echo on
	@REM all these objects match up
	z88dk-z80nm contended.o
	z88dk-z80nm contended.o > contended.txt
	copy "contended.txt" "..\"
	echo off
cd ..

@call beep.bat
