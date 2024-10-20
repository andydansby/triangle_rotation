;; UNCONTENDED

;SECTION UNCONTENDED

;;uncontended memory from 32768 to 49151
;; 16383 bytes total

;;__fastcall__ fastcall
;; Fastcall linkage allows one parameter
;; to be passed by register in a subset of DEHL.
;; So if the parameter is 8-bit, the value will
;; be in L.  If the parameter is 16-bit,
;; the value is in HL and if it is
;; 32-bit the value is in DEHL.

SECTION code_user
; assign read-only executable code to this section
;----------------------------------
;attention new, we moved
PUBLIC _border_Change_IM2
_border_Change_IM2:
    ld hl, (_asm_temp)  ; loads L of HL with the variable ada
    ld a, l             ;
    and 7               ; mask with 0000 0111
    out ($FE),a         ;change the border
    inc a               ; increment value
    ld (_asm_temp), a   ; and update variable _asm_temp
ret


PUBLIC _border_Change_uncontended
_border_Change_uncontended:
    ld A, L     ;contents of L are loaded into a
    out (254), A
ret

;;attention, need to move

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

PUBLIC _character_address
_character_address: defw $0000

PUBLIC _attribute_color
_attribute_color:   defb %00000000
                       ; %FBPPPIII
;constants
defc screenAddress = $4000
defc screenSize = 6144
defc attributeSize = 767
;defc attribute_address = $5800

;variables
PUBLIC _attribute_address
_attribute_address:
    defw $5800; $5800

;note keep these two together with width on top
PUBLIC _attribute_width
_attribute_width:   defb $00
PUBLIC _attribute_height
_attribute_height:  defb $00

PUBLIC _pixel_address
_pixel_address:     defw $0000
PUBLIC _pixel_position
_pixel_position:     defb $00

PUBLIC _character_X
_character_X: defb $00
PUBLIC _character_Y
_character_Y: defb $00


extern _copy_memory_source
extern _copy_memory_destination
extern _copy_memory_size

PUBLIC _copy_memory
_copy_memory:
    ld hl, (_copy_memory_source)
	ld de, (_copy_memory_destination)
	ld bc, (_copy_memory_size)
	ldir
ret






;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


SECTION rodata_user
; assign read-only data to this section
;; Variables
;; define C variables here to force placement in memory
PUBLIC _xyzzy2
_xyzzy2:
    defb 254
;----------------------------------

SECTION smc_user
; assign self-modifying code to this section
;----------------------------------

SECTION data_user
; assign non-zero initial data to this section
;----------------------------------

SECTION bss_user
; assign zero initial data to this section
;----------------------------------
;;attention new moved
PUBLIC _asm_temp
_asm_temp:
defb 0



