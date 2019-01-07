#ifndef __TEXT_H
#define	__TEXT_H

typedef struct
{
	uint32_t	PlaneOffset;	/* Plane offset */
	uint32_t	DataOffset;		/* Data offset */
	uint32_t	Used;			/* Is this TextBlock used? */
} tagTextBlock;

#endif
