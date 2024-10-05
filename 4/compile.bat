cls

rem zcc +zx trianglerotation.c -o trianglerotation -compiler=sccz80 -clib=default -lndos -lm -create-app

rem zcc +zx -vn -SO3 -m --math16 --math32 trianglerotation.c -o trianglerotation -compiler=sccz80 -clib=default -lndos  -create-app

zcc +zx -vn -SO3 -m --math16 --math32 @program.lst -o trianglerotation -compiler=sccz80 -clib=default -lndos  -create-app
