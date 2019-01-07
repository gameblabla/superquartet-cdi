BMPToCDI B 128 Graphics\InGame.bmp Data\InGame.bin Data\InGame.pal
BMPToCDI B 128 Graphics\Title.bmp Data\Title.bin Data\Title.pal
BMPToCDI A 128 Graphics\Font.bmp Data\Font.bin Data\PlaneA.pal
BMPToCDI A 128 Graphics\blocks.bmp Data\Sprites.bin
copy /b Data\Font.bin+Data\Sprites.bin Disk\PLANEA.BIN
copy /b Data\Title.bin+Data\InGame.bin Disk\PLANEB.BIN
copy /b Data\InGame.pal+Data\Title.pal+Data\PlaneA.pal+Data\PlaneA.pal Disk\PALETTES.BIN
PadFile 0 4096 Disk\PALETTES.BIN
