;Bresenham Line Variables
;input variables
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
PUBLIC _line_x1
    _line_x1:	defb 0 		;$8080	line start point X
PUBLIC _line_y1
    _line_y1:	defb 0 		;$8082	line start point Y
PUBLIC _line_x2
    _line_x2:	defb 0  	;$8084	line end point X
PUBLIC _line_y2
    _line_y2:	defb 0  	;$8086	line end point Y
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

deltaX:
    defb 00   ;$
deltaY:
    defb 00   ;$

fraction:
    defb 00

stepX:
    defb 00         ;$
stepY:
    defb 00		    ;$
steps:
    defb 00         ;$

iterations:
    defb 00

PUBLIC _eraseLine
_eraseLine: defb 00


PUBLIC plot_x			;$
plot_x:		defb 00

PUBLIC plot_y			;$
plot_y:		defb 00


PUBLIC _gfx_xy
_gfx_xy:		defw 0000

PUBLIC X_PositionBits
X_PositionBits:
defb 128,64,32,16,8,4,2,1



