
;optimized by andy dansby
;using DE/HL
PUBLIC _joffa_plot
_joffa_plot:
    ld DE, (_gfx_xy)
PUBLIC _joffa_plot1
_joffa_plot1:

    ld A, D

    rrca
    rrca
    rrca

    and %00011000   ;24 = 0x18
    or  %01000000   ;64 = 0x40

    ld H, A
    ld A, D
    and 7
    or H
    ld H, A

    ld A, D
    add A, A
    add A, A
    and %11100000
    ld L, A

    ld A, E

    rrca
    rrca
    rrca
	and %00011111

    or L
    ld L, A  ; hl = screen address.

    ld A, E
    and 7

    ld DE, X_PositionBits
    add A, E
    ld E, A
    ld A, (DE)

    ;adjust address
    ld DE, $8000
    add HL, DE

    ;output to screen
    or (HL)
    ld (HL),A       ;push pixel to screen
ret


PUBLIC _joffa_unplot
_joffa_unplot:
    ld DE, (_gfx_xy)

    PUBLIC _joffa_unplot1
_joffa_unplot1:
    ld A, D

    rrca
    rrca
    rrca

    and %00011000   ;24 = 0x18
    or  %01000000   ;64 = 0x40

    ld H, A
    ld A, D
    and 7
    or H
    ld H, A

    ld A, D
    add A, A
    add A, A
    and %11100000
    ld L, A

    ld A, E

    rrca
    rrca
    rrca
	and %00011111

    or L
    ld L, A  ; hl = screen address.

    ld A, E
    and 7

    ld DE, X_PositionBits
    add A, E
    ld E, A
    ld A, (DE)

    ;adjust address
    ld DE, $8000
    add HL, DE

    ;output to screen
    cpl         ;invert bitmask
    and (HL)    ;push pixel to screen
    ld (HL),A
ret



