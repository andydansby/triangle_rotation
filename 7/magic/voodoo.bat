z88dk-appmake +zx -b compiled_CONTENDED.bin -o contended.tap --org 24280 --noloader --blockname contended

z88dk-appmake +zx -b compiled_CODE.bin -o uncontended.tap --org 32768 --noloader --blockname uncontended

z88dk-appmake +zx -b compiled_IM2_VECTOR_PLACEMENT.bin -o im2vector.tap --org 48573 --noloader --blockname im2vector

z88dk-appmake +zx -b compiled_BANK_00.bin -o bank00.tap --org 49152 --noloader --blockname bank00

bas2tap -a1 -s48K loader.bas basloader.tap

rem new
copy /b basloader.tap + contended.tap + uncontended.tap + im2vector.tap + bank00.tap   1output.tap

copy "1output.tap" "..\"

del "loader.bas"
del "bank00.tap"
del "uncontended.tap"
del "contended.tap"

rem new
del "im2vector.tap"

move "compiled_BANK_00.bin" "bin\"
move "compiled_CODE.bin" "bin\"
move "compiled_CONTENDED.bin" "bin\"
move "compiled_UNASSIGNED.bin" "bin\"

rem new
move "compiled_IM2_VECTOR_PLACEMENT.bin" "bin\"
