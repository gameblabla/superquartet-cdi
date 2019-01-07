/*
	Copyright (C) 2018 Gameblabla
	Licensed under the MIT License.
	See LICENSE file for more details.
	If a LICENSE file was not provided, you can ask the copyright holder for a copy at :
	<gameblabla@protonmail.com>
		
	This Program is distributed without WITHOUT ANY WARRANTY; 
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
	
	The MIT license covers :
	Main.c
	Main.h
	The graphics files in Graphics/

	The following files are covered by the LGPL, and must be distributed in
	accordance with the terms of this license :
	Defines\csdtype.d
	Defines\dcpins.d
	Defines\viddcp.d
	csdfind.a

	These files copyrighted by cdoty are also covered under the same license (as an exemption allowed by him) :
	Cursor.a
	Video.a
	
	See LGPL for more details

	Some of the source code belongs to cdoty.
	Unfortunately, some of the code there is non-free as it disallows any reproduction of Frog Feast for commercial use.
	These are :
	Sprites.c
	Text.c
	Input.c
	Part of Sound.c
	Graphics.a
	
	"The source code is copyright 2007 by Charles Doty. You may use any/all of
	the enclosed code in any freeware/commercial application. The ony
	limitation is that the source code cannot be recompiled to create a copy of
	the Frog Feast CD. You can create a modified version of Frog Feast, and
	give instructions about burning a new CD using the files from the Frog
	Feast CD. None of the data files from the CD may be included with a
	modified version of Frog Feast."
	
	Though the game is not affected by the restriction in practice, this makes it non-free.
	Eventually this code will be got rid of anyway since it won't be suitable for future projects.
*/


#include "Defines.h"
#include "Main.h"
#include "Routines.h"
#include "main.h"

short right_spot[5], left_spot[5], up_spot[5], down_spot[5];

short CaseX;
short CaseY;
short Case_pos;

short reload = 0;
short gamemo = 0;
short frame_gamemo = 0;
char good = 1;

char lives = 3;
unsigned long score = 0;
unsigned long highscore = 0;

short gamemode = 0;
short rtime , lowtime = 10;
short go_time = 0;

unsigned int game_id = 0;
unsigned short check_square_score();

uint16_t JoyVal1;

char* itoa(val)
int val;
{
	static char buf[32] = {0};
	int base = 10;
	int i = 30;
	
	if (val == 0) return "0";
	
	for(; val && i ; --i, val /= base)
	{
		buf[i] = "0123456789abcdef"[val % base];
	}
	
	return &buf[i+1];
	
}


void InitializeSystem()
{
	/* Disable front panel buttons */
	DisableUserControls();
	
	/* Initialize video subsystem */
	InitVideo();

	/* Initialize cursor subsystem */
	InitCursor();

	/* Initialize input */
	InitInput();
}

void CloseSystem()
{
	/* Close cursor */
	CloseCursor();

	/* Close input */
	CloseInput();

	/* Close input */
	CloseSound();

	/* Close video */
	CloseVideo();

	/* Close screens */
	CloseScreens();

	/* Enable front panel buttons */
	EnableUserControls();
}

int SetRealSpritePos(index, x, y)
int index;
int x;
int y;
{
	SetSpritePosition(index, x, y);
}

int SetRealSpriteTile(index, idx)
int index;
int idx;
{
	switch(idx)
	{
		default:
			SetSpriteTile(index, 4096+(256*3));
		break;
		case 1:
		case 2:
		case 3:
		case 4:
			SetSpriteTile(index, 4096);
		break;
		case 5:
		case 6:
		case 7:
		case 8:
			SetSpriteTile(index, 4096+(256*1));
		break;
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
			SetSpriteTile(index, 4096+(256*2));
		break;
		
	}
}


unsigned char rl_f = 1;

int main(argc, argv)
int argc;
char* argv[];
{
	
	/* Initialize CD-I */
	InitializeSystem();
	
	/* Preload data */
	PreloadData();
	
	/* Initialize sound */
	InitSound();

	/* Seed random number */
	SeedRandomNumber();

	/* Clear TextBlocks */
	ClearTextBlocks();

	/* Clear sprite list */
	ClearSpriteList();
	
	InitializeGame();
	
	DisplayTitle();
	
	while (1)
	{
		JoyVal1	= ReadJoystickA();
		
		GameLoop();
		
		WaitVBlank();
	}

	CloseSystem();

	return 0;
}

void InitializeGame()
{
	unsigned char i;

	CaseX = 141;
	CaseY = 117;

	Load_score();
	reset_case();
}

void GameLoop()
{
	switch(gamemode)
	{
		case 0:
			Titlescreen();
		break;

		case 1:
			Show_Square();
			if (gamemo == 0) Move_Square();
			Show_Game();
		break;
	}
}

void Titlescreen()
{
	unsigned char i;

	/*DrawString("PRESS A TO START", 16, 20);*/
	
	DrawString("    ", 9, 1);
	DrawString("    ", 26, 1);
	DrawString("    ", 39, 1);
	DrawString("HIGHSCORE : ", 17, 28);
	DrawString(itoa(highscore), 29, 28);
	
	if (JoyVal1 & JOYA_A)
	{
		ClearTextBlocks();
		ClearSpriteList();
			
		SetupSprite(1, 0, 0, 16, 4096+(256*4));
		
		for(i=2;i<18;i++)
		{
			SetupSprite(i, 0, 0, 16, 4096+(256*4));
		}
		
		go_ingame();
	}
}

/*176, 120*/

void Show_Square()
{
	static short frame = 0;
	unsigned char X_add, Y_add;
	
	switch(frame)
	{
		case 2:
		case 6:
		case 10:
			X_add = 16;
			Y_add = 0;
		break;
		case 3:
		case 7:
		case 11:
			X_add = 0;
			Y_add = 16;
		break;
		case 4:
		case 8:
		case 12:
			X_add = 16;
			Y_add = 16;
		break;
		default:
			X_add = 0;
			Y_add = 0;
		break;
	}
	

	switch(gamemo)
	{
		case 2:
			go_time++;

			frame = 21;

			if (go_time > 180) go_back_titlescreen();
		break;
		
		case 1:
			frame = 20;
			
			if (frame_gamemo > 70)
			{
				gamemo = 0;
				frame_gamemo = 0;
			}
			else frame_gamemo++;
		break;
		
		default:
			frame = Case_pos;
		break;
	}

	SetRealSpriteTile(1, frame);
	SetSpritePosition(1, 176+X_add, 120+Y_add);

}

void Show_Game()
{
	unsigned char i;
	
	rtime = reload;

	if (rtime < 33) 
	{
		lowtime = 10;
	}
	else 
	{
		lowtime = 0;
	}

	DrawString("      ", 9, 1);
	DrawString(itoa(score), 9, 1);
	
	DrawString("   ", 26, 1);
	DrawString(itoa(rtime), 26, 1);
	
	DrawString("  ", 39, 1);
	DrawString(itoa(lives), 39, 1);
	
	if (reload > 100)
	{
		DrawString(" READY ?  ", 20, 28);
	}
	else if (gamemo == 1)
	{
		DrawString(" MISS !   ", 20, 28);
	}
	else if (gamemo == 2)
	{
		DrawString("GAMEOVER ", 20, 28);
	}
	else
	{
		DrawString("         ", 20, 28);
	}

	/* 
	 * The following put the squares on screen
	 * If the square is empty then it is not shown
	*/

	/* Left */

	SetRealSpriteTile(2, left_spot[0]);
	SetSpritePosition(2, 124, 120);

	SetRealSpriteTile(3, left_spot[1]);
	SetSpritePosition(3, 124+16, 120);

	SetRealSpriteTile(4, left_spot[2]);
	SetSpritePosition(4, 124, 120+16);

	SetRealSpriteTile(5, left_spot[3]);
	SetSpritePosition(5, 124+16, 120+16);
	
	/* Right */
	
	SetRealSpriteTile(6, right_spot[0]);
	SetSpritePosition(6, 228, 120);

	SetRealSpriteTile(7, right_spot[1]);
	SetSpritePosition(7, 228+16, 120);

	SetRealSpriteTile(8, right_spot[2]);
	SetSpritePosition(8, 228, 120+16);

	SetRealSpriteTile(9, right_spot[3]);
	SetSpritePosition(9, 228+16, 120+16);
	
	/* Up */
	
	SetRealSpriteTile(10, up_spot[0]);
	SetSpritePosition(10, 176, 68);

	SetRealSpriteTile(11, up_spot[1]);
	SetSpritePosition(11, 176+16, 68);

	SetRealSpriteTile(12, up_spot[2]);
	SetSpritePosition(12, 176, 68+16);

	SetRealSpriteTile(13, up_spot[3]);
	SetSpritePosition(13, 176+16, 68+16);
	
	/* Down */
	
	SetRealSpriteTile(14, down_spot[0]);
	SetSpritePosition(14, 176, 172);

	SetRealSpriteTile(15, down_spot[1]);
	SetSpritePosition(15, 176+16, 172);

	SetRealSpriteTile(16, down_spot[2]);
	SetSpritePosition(16, 176, 172+16);

	SetRealSpriteTile(17, down_spot[3]);
	SetSpritePosition(17, 176+16, 172+16);

}

unsigned short check_square_score(sqr1, sqr2, sqr3, sqr4)
unsigned char sqr1; 
unsigned char sqr2;
unsigned char sqr3;
unsigned char sqr4;
{
	if (sqr1 == 9 && sqr2 == 10 && sqr3 == 11 && sqr4 == 12)
		return 300;
	else if (sqr1 == 5 && sqr2 == 6 && sqr3 == 7 && sqr4 == 8)
		return 300;
	else if (sqr1 == 1 && sqr2 == 2 && sqr3 == 3 && sqr4 == 4)
		return 300;
	else
		return 30;
}

void Move_Square()
{
	unsigned char i;
	unsigned short sqr_score_filled;
	
	reload--;

	if (reload < 1)	
	{
		lose_a_life();
		reset_case();
	}
	else if (reload < 90) 
	{
		if (JoyVal1 & JOYA_UP)
		{
			for(i=0;i<4;i++)
			{
				if ((Case_pos == 1+i || Case_pos == 5+i || Case_pos == 9+i || Case_pos == 13+i))
				{
					if (up_spot[i] == 0)
					{
						/*Play_SFX(3);*/
						/*PlaySound(0);*/
						up_spot[i] = Case_pos;
					}
					else if (up_spot[i] > 0)
					{
						lose_a_life();
					}
				}	
			}
			
			if (up_spot[0] > 0 && up_spot[1] > 0 && up_spot[2] > 0 && up_spot[3] > 0)
			{
				sqr_score_filled = check_square_score(up_spot[0], up_spot[1], up_spot[2], up_spot[3]);
				for(i=0;i<4;i++) 
				{
					up_spot[i] = 0;
				}
				score = score + sqr_score_filled;
			}

			reset_case();
		}

		else if (JoyVal1 & JOYA_DOWN)
		{

			for(i=0;i<4;i++)
			{
				if ((Case_pos == 1+i || Case_pos == 5+i || Case_pos == 9+i || Case_pos == 13+i))
				{
					if (down_spot[i] == 0)
					{
						/*Play_SFX(3);*/
						/*PlaySound(0);*/
						down_spot[i] = Case_pos;
					}
					else if (down_spot[i] > 0)
					{
						lose_a_life();
					}
				}	
			}
			
			if (down_spot[0] > 0 && down_spot[1] > 0 && down_spot[2] > 0 && down_spot[3] > 0)
			{
				sqr_score_filled = check_square_score(down_spot[0], down_spot[1], down_spot[2], down_spot[3]);
				for(i=0;i<4;i++) 
				{
					down_spot[i] = 0;
				}
				score = score + sqr_score_filled;
			}

			reset_case();
		}

		else if (JoyVal1 & JOYA_LEFT)
		{
			
			for(i=0;i<4;i++)
			{
				if ((Case_pos == 1+i || Case_pos == 5+i || Case_pos == 9+i || Case_pos == 13+i))
				{
					if (left_spot[i] == 0)
					{
						/*Play_SFX(3);*/
						/*PlaySound(0);*/
						left_spot[i] = Case_pos;
					}
					else if (left_spot[i] > 0)
					{
						lose_a_life();
					}
				}	
			}

			if (left_spot[0] > 0 && left_spot[1] > 0 && left_spot[2] > 0 && left_spot[3] > 0)
			{
				sqr_score_filled = check_square_score(left_spot[0], left_spot[1], left_spot[2], left_spot[3]);
				for(i=0;i<4;i++) 
				{
					left_spot[i] = 0;
				}
				score = score + sqr_score_filled;
			}

			reset_case();
		}

		else if (JoyVal1 & JOYA_RIGHT)
		{
			
				for(i=0;i<4;i++)
				{
					if ((Case_pos == 1+i || Case_pos == 5+i || Case_pos == 9+i || Case_pos == 13+i))
					{
						if (right_spot[i] == 0)
						{
							/*Play_SFX(3);*/
							/*PlaySound(0);*/
							right_spot[i] = Case_pos;
						}
						else if (right_spot[i] > 0)
						{
							lose_a_life();
						}
					}	
				}
			
				if (right_spot[0] > 0 && right_spot[1] > 0 && right_spot[2] > 0 && right_spot[3] > 0)
				{
					sqr_score_filled = check_square_score(right_spot[0], right_spot[1], right_spot[2], right_spot[3]);
					for(i=0;i<4;i++) 
					{
						right_spot[i] = 0;
					}
					score = score + sqr_score_filled;
				}

			reset_case();
		}
	}

}

void RESET_EVERYTHING()
{
	unsigned char i;
	
	reload = 0;
	gamemo = 0;
	frame_gamemo = 0;
	go_time = 0;
	score = 0;
	rtime = 0;
	
	lowtime = 10;
	lives = 3;
	
	gamemode = 1;
	good = 1;
	
	for (i=0;i<4;i++)
	{
		right_spot[i] = 0;
		left_spot[i] = 0;
		up_spot[i] = 0;
		down_spot[i] = 0;
	}

}


short reset_case() 
{
	good = 1;
			
	while (good)
	{
		Case_pos = rand_a_b(1,12);

		if ((up_spot[0] > 0 && right_spot[0] > 0 && left_spot[0] > 0 && down_spot[0] > 0) && (Case_pos == 1 || Case_pos == 5 || Case_pos == 9 || Case_pos == 13)) 
		{
			good = 1;
		}
		else if ((up_spot[1] > 0 && right_spot[1] > 0 && left_spot[1] > 0 && down_spot[1] > 0) && (Case_pos == 2 || Case_pos == 6 || Case_pos == 10 || Case_pos == 14)) 
		{
			good = 1;
		}
		else if ((up_spot[2] > 0 && right_spot[2] > 0 && left_spot[2] > 0 && down_spot[2] > 0) && (Case_pos == 3 || Case_pos == 7 || Case_pos == 11 || Case_pos == 15)) 
		{
			good = 1;
		}
		else if ((up_spot[3] > 0 && right_spot[3] > 0 && left_spot[3] > 0 && down_spot[3] > 0) && (Case_pos == 4 || Case_pos == 8 || Case_pos == 12 || Case_pos == 16)) 
		{
			good = 1;
		}
		else
		{
			good = 0;
		}
	}
		
	reload = 100;
	frame_gamemo = 0;

	return 1;
}

void lose_a_life()
{
	lives = lives - 1;

	if (lives < 1)
	{
		/*Play_SFX(1);*/
		gamemo = 2;
	}
	else
	{
		/*Play_SFX(2);*/
		gamemo = 1;
	}
}


static unsigned long int next = 1;

int rand()
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

short rand_a_b(a, b)
short a;
short b;
{
    return rand()%(b-a) +a;
}

void go_back_titlescreen()
{
	DrawString("    ", 9, 1);
	DrawString("    ", 26, 1);
	DrawString("    ", 39, 1);
	
	ClearTextBlocks();
	ClearSpriteList();
	ClearTextPlane();
	
	DisplayTitle();
	
	WaitVBlank();
	
	Update_highscore();
	Load_score();

	gamemode = 0;
}

void go_ingame()
{
	RESET_EVERYTHING();

	DisplayBackground();

	reload = 200;

	gamemode = 1;
}


void Load_Sounds()
{
}

void Load_score()
{
}

void Save_score()
{
}

void Update_highscore()
{
	if (score > highscore)
	{
		highscore = score;
		Save_score();
	}
}
