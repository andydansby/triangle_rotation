PUBLIC _push_it_loop
_push_it_loop:

;each loop, we need to push 32 columns, but only 16 at a time

; sp = #5FE4
	ld sp, IY; 		10t
	;our stack is set to image buffer
	;== 10 t-states

	;move 16 bytes from front to back
	;pop moves stack pointer forward
	pop AF	;2 bytes        10t
	pop BC	;4 bytes        10t
	pop DE	;6 bytes        10t
	pop HL	;8 bytes        10t
	exx     ;               04t
	ex AF, AF' ;            04t
	pop AF	;10 bytes       10t
	pop BC	;12 bytes       10t
	pop DE	;14 bytes       10t
	pop HL	;16 bytes       10t
	;88 T states
	;16 Bytes in total

	ld sp, IX; 		        10t
	;== 10 t-states

	;push moves stack pointer backwards
	; push 16 bytes from front to back
	push HL	;16 bytes
	push DE	;14 bytes
	push BC	;12 bytes
	push AF	;10 bytes
	exx
	ex AF, AF'
	push HL	;8 bytes
	push DE	;6 bytes
	push BC	;4 bytes
	push AF	;2 bytes
	;== 88 T states
    ;16 bytes moved so far
    ;need to move another 16


    ;iy needs to increase by 16
    ;ix needs to increase by 16
    ld BC, $10;load 16      10t
    add IX, BC;ix is 4020   15t
    ;adjust our buffer
    add IY, BC;iy = #C010   15t
    ld sp, IY ; 		    10t
    ;== 50 T states

    ;move 16 bytes from front to back
	;pop moves stack pointer forward
	pop AF	;2 bytes
	pop BC	;4 bytes
	pop DE	;6 bytes
	pop HL	;8 bytes
	exx
	ex AF, AF'
	pop AF	;10 bytes
	pop BC	;12 bytes
	pop DE	;14 bytes
	pop HL	;16 bytes
	;== 88 T states
    ;16 Bytes in total

	ld sp, IX; 		10t
	;== 10 t-states

	;push moves stack pointer backwards
	; push 16 bytes from front to back
	push HL	;16 bytes
	push DE	;14 bytes
	push BC	;12 bytes
	push AF	;10 bytes
	exx
	ex AF, AF'
	push HL	;8 bytes
	push DE	;6 bytes
	push BC	;4 bytes
	push AF	;2 bytes
	;== 88 T states
; 1 full line has been copied

    ld BC, $10;load 16      10t
    add IX, BC;ix is 4020   15t
    ;adjust our buffer
    add IY, BC;iy = #C010   15t
    ;ld sp, iy;
    ;== 40 T states

;loop around


loop:
	ld A, (iterations);     13t
	dec A;                  4t
	ld (iterations), A;     13t
	cp 0;                   7t

	jp nz, _push_it_loop;   10t
    ;== 47 T states

	;;519 T states per line

	jp _restore_stack


