# triangle_rotatiion
experiments in optimizations to the rotating triangle code asked in the Sinclair computing forums
https://spectrumcomputing.co.uk/forums/viewtopic.php?t=12159

Original folder, contains the orignal code posted

Folder 1, performs a reduction of calculation with converting to radians

Folder 2, uses an estimated sine / cosine

Folder 3 is an optimization by reducing the number of calls to sine/cosine to 1 call per loop, greatly increasing the speed

Folder 4 has quite a few changes.  
    1) an excellent optimization by user DFZX to use half_t instead of float for faster half sized floats
    2) Changing the calculations a bit
    3) Using a Bresenham Line routine instead of a drawto()
    4) Using the Joffa Pixel assembly routine instead of the built in plot routine

Folder 5 is using additional assembly routines.
    1) The Bresenham line routine is now pure assembler
    2) The plot assembler routine now has an unplot
    3) Most of the C code is now in seperate files for better orginization
    4) additional #defines are being used


Folder 6 has changed to the ZSDCC compiler
    1) optimized Bresenham line routine, saves some T states when drawing line
    2) not Using buffer yet, but set up for buffer to happen
Overall the code seems to run slower, which is unexpected.
going to work over time to improve code speed





