
void cls(void) {
    #asm
    call 3435;
    #endasm
}

void cls2()
{
    #asm
    ld hl, 16384+2048
    ld de, 16384+2048+1
    ld bc, 2047
    ldir
    #endasm
}
