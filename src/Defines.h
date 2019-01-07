#ifndef __DEFINES_H
#define	__DEFINES_H

#define	JOYA_RIGHT		0x0001
#define	JOYA_LEFT		0x0002
#define	JOYA_UP			0x0004
#define	JOYA_DOWN		0x0008
#define	JOYA_A			0x0010
#define	JOYA_B			0x0020

#define	uint8_t			unsigned char
#define	uint16_t			unsigned short
#define	uint32_t			unsigned int

#define	int8_t			char
#define	int16_t			short
#define	int32_t			int

#define	FALSE			0
#define	TRUE			1

#ifndef NULL
#define	NULL			0
#endif

/* Maximum screen w\idth */
#define	SCREENWIDTH		384	

/* Maximum screen height */
#define	SCREENHEIGHT	280	

/* Maximum number of sprites */
#define	MAXSPRITES		18

/* Maximum number of text characters */
#define	MAXTEXT			64

/* Delay between credit screens */
#define	SCREENDELAY		(1 * 60)

/* Joystick tolerance */
#define	TOLERANCEX		3
#define	TOLERANCEY		4

#endif
