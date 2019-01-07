NAME	= CDI_FROG
BUILD	= Release
CC 		= C:\OS9C\bin\xcc
CCFLAGS = -S -R=$(BUILD) -T=$(BUILD) -TO=osk -TP=68kI
ASFLAGS = -O=0 -S -R=$(BUILD) -T=$(BUILD) -TO=osk -TP=68kI
LD 		= C:\OS9C\bin\l68
FILES	= $(BUILD)\Main.r $(BUILD)\Cursor.r $(BUILD)\Graphics.r $(BUILD)\Input.r $(BUILD)\Routines.r $(BUILD)\Screens.r $(BUILD)\Sound.r $(BUILD)\Sprites.r $(BUILD)\Text.r $(BUILD)\Video.r $(BUILD)\csdfind.r
PATH	= C:\OS9C\bin;%PATH%

all : $(NAME)

$(NAME): $(FILES)
	$(LD) -z=link.txt
	C:\OS9C\bin\fixmod -uo=0.0 Disk\$(NAME)

$(BUILD)\Main.r : Main.c
	$(CC) $(CCFLAGS) -O=2 Main.c

$(BUILD)\Cursor.r : Cursor.a
	$(CC) $(ASFLAGS) Cursor.a

$(BUILD)\Graphics.r : Graphics.a
	$(CC) $(ASFLAGS) Graphics.a

$(BUILD)\Input.r : Input.c
	$(CC) $(CCFLAGS) -O=2 Input.c

$(BUILD)\Routines.r : Routines.a
	$(CC) $(ASFLAGS) Routines.a

$(BUILD)\Screens.r : Screens.a
	$(CC) $(ASFLAGS) Screens.a

$(BUILD)\Sound.r : Sound.c
	$(CC) $(CCFLAGS) -O=2 Sound.c

$(BUILD)\Sprites.r : Sprites.c
	$(CC) $(CCFLAGS) -O=2 Sprites.c

$(BUILD)\Text.r : Text.c
	$(CC) $(CCFLAGS) -O=2 Text.c

$(BUILD)\csdfind.r : csdfind.a
	$(CC) $(ASFLAGS) csdfind.a

$(BUILD)\Video.r : Video.a
	$(CC) $(ASFLAGS) Video.a

CLEAN :
	-@erase $(BUILD)\*.r
	-@erase Disk\$(NAME)

