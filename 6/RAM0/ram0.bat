
@cd codemaps
@	del ram0.o
@cd ..

@rem compiling string for SDCC object file
zcc +zx -vn -clib=sdcc_iy @ram0.lst -c -o RAM0.o -m

@if not exist "RAM0.o" (
call error.bat
)

copy "ram0.o" "..\"
move "ram0.o" "codemaps\"

@REM Cleanup
del zcc_opt.def

REM a nice map view
cd codemaps
	echo on
	@REM all these objects match up
	z88dk-z80nm ram0.o
	z88dk-z80nm ram0.o > ram0.txt
	copy "ram0.txt" "..\"
	echo off
cd ..

@call beep.bat
