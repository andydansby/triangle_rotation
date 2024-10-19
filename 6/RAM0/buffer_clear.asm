PUBLIC _clear_buffer
_clear_buffer:

    ld HL, _screen_buffer        ; buffer start
    ld DE, _screen_buffer + 1    ;
    ld BC, $1800			     ; Length of bitmap memory to clear
    ld (HL), 0			         ; Set the first byte to 0
    ldir
ret
