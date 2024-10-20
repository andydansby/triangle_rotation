
rem compile to a TAP file

rem --------------------------------------------------------------
@rem sccz80
rem zcc +zx -vn -m -startup=30 -clib=new ramALL.o -o compiled -pragma-include:zpragma.inc

@rem zSDCC
@rem zcc +zx -vn -SO3 -m --math16 -startup=1 -clib=sdcc_iy ramALL.o -o compiled -pragma-include:zpragma.inc
@rem zcc +zx -vn -SO3 -m --math48 -startup=1 -clib=sdcc_iy ramALL.o -o compiled -pragma-include:zpragma.inc

zcc +zx -vn -m -startup=1 -lm -clib=sdcc_iy --max-allocs-per-node200000 ramALL.o -o compiled -pragma-include:zpragma.inc
rem check above for errors
rem --------------------------------------------------------------

move "compiled_BANK_00.bin" "..\magic"
move "compiled_CODE.bin" "..\magic"
move "compiled_CONTENDED.bin" "..\magic"
move "compiled_IM2_VECTOR_PLACEMENT.bin" "..\magic"


@rem have at the end
rem call cleanup.bat
call beep.bat
