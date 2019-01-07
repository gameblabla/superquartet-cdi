#ifndef __ROUTINES_H
#define	__ROUTINES_H

void InitializeSystem();	/* Initialize system */
void CloseSystem();			/* Close system */
void InitInput();			/* Setup input */
void CloseInput();			/* Close input */
void UpdateInput();			/* Update input */
uint16_t ReadJoystickA();		/* Read joystick A */
uint16_t ReadJoystickB();		/* Read joystick B */
void WaitVBlank();			/* Wait VBlank */
void SetupSprite();			/* Setup sprite */
void RemoveSprite();		/* Remove sprite */
void SetSpritePosition();	/* Set sprite position */
void SetSpriteTile();		/* Set sprite tile */
void ClearSpriteList();		/* Clear sprite list */
void ClearTextBlocks();		/* Clear text blocks */
void DrawNumber();			/* Draw number */
void DrawString();			/* Draw string */
void InitVideo();			/* Init video */
void DisplayTitle();		/* Display title */
void SeedRandomNumber();	/* Seed random number */
char *GetInput();			/* Get input */

#endif
