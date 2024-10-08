

X_PositionBits: defb $80,$40,$20,$10,$08,$04,$02,$01

PUBLIC _gfx_xy
_gfx_xy:    defw 0

;optimized by andy dansby
;using DE/HL
PUBLIC _joffa_pixel2
_joffa_pixel2:

    ld de, (_gfx_xy)
    ld a, d

    rrca
    rrca
    rrca


    and %00011000   ;24 = 0x18
    or  %01000000   ;64 = 0x40

    ld h, a
    ld a, d
    and 7
    or h
    ld h, a

    ld a, d
    add a, a
    add a, a
    and %11100000
    ld l, a

    ld a, e

    rrca
    rrca
    rrca
	and %00011111

    or l
    ld l, a  ; hl = screen address.

    ld a, e
    and 7

    ;LD d, a

    ld de, X_PositionBits
    add a, e
    ld e, a
    ld a, (de)

    ;output to screen
    or (hl)
    ld (hl),a
ret

















