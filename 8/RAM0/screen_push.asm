PUBLIC _copy_buffer
_copy_buffer:

	;entering SP = #BFFC
	di
	call push_pop

return:
	ei
end_push_it:
ret

push_pop:

	ld BC, 0000
	; uses the B register to calculate pixel row
	push BC		;save to stack for when we update the loop


	ld IX, $4000 + $10
	;since Data is pushed to the screen in backwards order
    ; and we can only move $10 bytes at a time
    ; we start with the scren data + $10

    ld IY, _screen_buffer
	;iy holds our buffer data
	; start at the beginning of DATA

	;I of IR is going to be our loop data
	ld A, 192   ; there are 192 lines in a ZX Spectrum display
	ld (iterations), A
	;so at this point
	;IX is holding the screen address
	;IY is holding out image buffer
	;I (of IR) is holding our loop info

	;lets save our original stack
	ld (originalStack), sp

	jp _push_it_loop
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
PUBLIC _restore_stack
_restore_stack:

;;;;;;;;;;;;;;;;
    ;restore original stack
    ld sp, (originalStack)
    ;sp = #5FE6

    ;restore the BC register that we used to count the loop
	pop BC
ret

end_of_draw_buffer:
