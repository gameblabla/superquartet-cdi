#ifndef __SPRITE_H
#define	__SPRITE_H

typedef struct
{
	uint32_t	EraseOffset0;	/* Erase offset Frame 0 */
	uint32_t	EraseOffset1;	/* Erase offset Frame 1 */
	uint32_t	PlaneOffset;	/* Plane offset */
	uint32_t	DataOffset;		/* Data offset */
	uint32_t	Width;			/* Sprite width */
	uint32_t	Used;			/* Is this SpriteBlock used? */
} tagSpriteBlock;

#endif
