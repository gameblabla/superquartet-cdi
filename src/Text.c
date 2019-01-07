#include "Defines.h"
#include "GameDefs.h"
#include "Text.h"

tagTextBlock	TextBlock[MAXTEXT];

/* Draws a zero terminated screen */
void DrawString(String, x, y)
	char *String; uint16_t x; uint16_t y;
{
	/* PlaneOffset	= (y * 8) * 256 + (y * 8) * 128 + (x * 8) */
	uint32_t	PlaneOffset	= (((y << (8+3)) + (y << (7+3)))) | (x << 3);

	/* Add each character to the TextBlock list */
	while (*String != 0)
	{
		/* Tile offset is FONTOFFSET + (Character - 32) * 64 */
		uint16_t	DataOffset	= FONTOFFSET + ((*String - 32) << 6);
		
		AddText(PlaneOffset, DataOffset);

		PlaneOffset	+= 8;

		String++;
	}
}

/* Draws a number 0-99 */
void DrawNumber(Number, x, y)
	uint16_t Number; uint16_t x; uint16_t y;
{
	/* PlaneOffset	= (y * 8) * 256 + (y * 8) * 128 + (x * 8) */
	uint32_t	PlaneOffset	= (((y << (8+3)) + (y << (7+3)))) | (x << 3);

	/* Add the tens digit, if it's not zero */
	if (Number > 9)
	{
		AddText(PlaneOffset - 8, ((Number / 10) + 16) << 6);
	}

	/* Add the one digit */
	AddText(PlaneOffset, ((Number % 10) + 16) << 6);
}
