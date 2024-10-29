#ifndef EXTERNS_H
#define EXTERNS_H
//UNCONTENDED RAM
/*
__fastcall__
 Fastcall linkage allows one parameter
 to be passed by register in a subset of DEHL.
 So if the parameter is 8-bit, the value will
 be in L.  If the parameter is 16-bit,
 the value is in HL and if it is
 32-bit the value is in DEHL.
*/


/*SDCC allows to specify preserved registers in
function declarations, to enable further
optimizations on calls to functions implemented
in assembler. Example for the Z80 architecture
specifying that a function will preserve
register pairs bc and iy:*/
//void f(void) __preserves_regs(b, c, iyl, iyh);
//void f (unsigned int) __z88dk_fastcall;

//in ram0.asm
extern unsigned int buffer_address;
extern void dzx0_standard(void) __z88dk_fastcall;

extern void Bresenham_Line(void) __z88dk_fastcall;
extern unsigned char line_x1;
extern unsigned char line_y1;
extern unsigned char line_x2;
extern unsigned char line_y2;
extern unsigned char eraseLine;


//in ram0.asm
extern unsigned int *screen_buffer;

//in contended.asm
extern unsigned int zx0_temp_storage;
extern unsigned int zx0_source;
extern unsigned int zx0_destination;
extern void copy_buffer(void) __z88dk_fastcall;
extern void set_attributes (void)  __z88dk_fastcall;

extern unsigned char keypress;
extern unsigned char Read_Controls (void) __z88dk_fastcall;

//found in uncontended_section.asm
extern void border_Change_uncontended(unsigned char color) __z88dk_fastcall;

//found in im2.asm
extern void SETUP_IM2(void) __z88dk_fastcall;

//found in RAM0Z.asm


//found in random.asm
extern unsigned int random_number_16;
extern void xorshift_prng (void) __z88dk_fastcall;

//found in RAM6

extern void copy_memory (void) __z88dk_fastcall;


//asm CONSTANTS
//in graphics.asm
extern unsigned int screenAddress;
extern unsigned int screenSize;
extern unsigned int attributeSize;
extern unsigned int attribute_address;


//ASM KEYBOARD Variables
//in keyboard.asm
extern unsigned char keypress;


//found in GRAPHICS.asm
extern unsigned char attribute_width;
extern unsigned char attribute_height;

extern unsigned int attribute_address;

//found in GRAPHICS.asm
extern unsigned char character_X;
extern unsigned char character_Y;
extern unsigned int character_address;
extern unsigned int pixel_address;
extern unsigned char pixel_position;





//ASM KEYBOARD routines
extern unsigned char Read_Controls (void) __z88dk_fastcall;
extern unsigned char Read_Keyboard (void);



//found in uncontended.asm
extern unsigned int character_address;
extern unsigned char attribute_color;






extern void Main_program (void) __z88dk_fastcall;
extern void wait_for_scanline (void) __z88dk_fastcall;

extern void Black_border (void) __z88dk_fastcall;
extern void Red_Border (void) __z88dk_fastcall;


extern unsigned char line_x1;
extern unsigned char line_y1;
extern unsigned char line_x2;
extern unsigned char line_y2;
extern void Bresenham_Line (void) __z88dk_fastcall;

extern void joffa_plot (void) __z88dk_fastcall;
extern void joffa_unplot (void) __z88dk_fastcall;

extern unsigned int gfx_xy;

extern void clear_buffer (void) __z88dk_fastcall;


#endif
