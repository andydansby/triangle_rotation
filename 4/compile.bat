cls

rem zcc +zx trianglerotation.c -o trianglerotation -compiler=sccz80 -clib=default -lndos -lm -create-app

zcc +zx trianglerotation.c -o trianglerotation -compiler=sccz80 -clib=default -lndos --math16 --math32 -create-app