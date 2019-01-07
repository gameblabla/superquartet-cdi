* CD-I Frog Feast (c) RasterSoft

* Maximum screen width
SCREENWIDTH			equ	384	

* Maximum screen height
SCREENHEIGHT		equ	280	

* Maximum image height
IMAGEHEIGHT			equ	240	

* Size of PALETTES.BIN
PALETTE_FILESIZE	equ	4096

* Size of SCREEN1.BIN, SCREEN2.BIN and, CREDITS.BIN
SCREEN_FILESIZE		equ (SCREENWIDTH*240)

* Size of PLANEA.bin
PLANEA_FILESIZE		equ	12288

* Size of PLANEB.bin
PLANEB_FILESIZE		equ	184320

* Size of palette data loaded into FCT
PALETTE_SIZE		equ	520

* Size of sound data
SOUND_FILESIZE		equ	14336

* Maximum number of TextBlocks
MAXTEXT				equ	28

* Size of a TextBlock
TEXTBLOCKSIZE		equ	3*4

* Maximum number of SpriteBlocks
MAXSPRITES			equ	6

* Size of a TextBlock
SPRITEBLOCKSIZE		equ	6*4

*Joystick values
JOYA_RIGHT			equ	$0001
JOYA_LEFT			equ	$0002
JOYA_UP				equ	$0004
JOYA_DOWN			equ	$0008
JOYA_A				equ	$0010
JOYA_B				equ	$0020

* Stack arguments define
ARGS				equ	4
