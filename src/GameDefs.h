#ifndef __GAMEDEFINES_H
#define	__GAMEDEFINES_H

/* Sprite frames */
#define	SPRITE			4096
#define	SPRITE2			4096*2
#define	BACKGROUNDCOLOR	24

/* Position offsets */
#define	FROG1X			(82+32)
#define	FROG2X			(222+32)

/* Screen defines */
#define	SCREENLEFT		0+32
#define	SCREENRIGHT		384-32
#define	LEFTEDGE		(18+32)
#define RIGHTEDGE		(278+32)
#define	MIDDLELEFT		(118+32)
#define	MIDDLERIGHT		(184+32)

/* Sprite offsets */
#define	FONTOFFSET		0
#define	SWIMSPRITE		(7*256)
#define	FACESPRITE		(8*256)
#define	JUMPSPRITE		(1*256)
#define	FLYSPRITE		(6*256)

/* Score defines */
#define	SCOREY			26
#define	SCORE1X			(4+4)
#define	SCORE2X			(35+4)
#define	FONTPAL			2
#define	TIMEX			(16+4)
#define	TIMEY			(SCOREY+1)
#define	STARTX			(15+4)
#define	STARTY			20
#define	STARTSPRY		20
#define	GAMEOVERX		(15+4)
#define	GAMEOVERY		13
#define	PLAYER1X		(112+32)
#define	PLAYER2X		(192+32)
#define	PLAYERY			((GAMEOVERY+4)*8)
#define	ENDSCORE1X		(15+4)
#define	ENDSCORE2X		(25+4)
#define	ENDSCOREY		GAMEOVERY+7
#define	TIEX			(16+4)

/* Sound defines */
#define	SND_FROG1		0		/* Frog sound */
#define	SND_TONGUE1		1		/* Tongue sound */
#define	SND_GRAB1		2		/* Grab sound */
#define	SND_WATER1		3		/* Water sound */
#define	SND_FROG2		4		/* Frog sound */
#define	SND_TONGUE2		5		/* Tongue sound */
#define	SND_GRAB2		6		/* Grab sound */
#define	SND_WATER2		7		/* Water sound */

#endif
