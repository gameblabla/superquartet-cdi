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
#ifndef __MAIN_H
#define	__MAIN_H
/*
char* title_img = "data/title.bmp";
char* all_img = "data/all.bmp";
char* ready_img = "data/ready.bmp";
char* score_img = "data/score.bmp";
char* start_img = "data/startbutton.bmp";
char* background_img = "data/background.bmp";
	
char* gameover_sfx = "data/gameover.wav";
char* miss_sfx = "data/miss.wav";
char* move_sfx = "data/move.wav";*/

void InitializeGame();

void GameLoop();

void Show_Square();
void Move_Square();

void Show_highscore();
void Show_startbutton();

void Show_Game();

short reset_case();

void lose_a_life();
void add_allsprites();

void calcul_score();
void Titlescreen();
void RESET_EVERYTHING();

void go_back_titlescreen();
void go_ingame();

void Reset();

void Load_Sounds();

short rand_a_b(a, b);

void Load_score();
void Save_score();

void Update_highscore();

#endif
