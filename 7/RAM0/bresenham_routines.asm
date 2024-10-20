
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;from http://z80-heaven.wikidot.com/math#toc12
absA:
     or A
     ret p
     neg         ;or you can use      cpl \ inc a
ret


