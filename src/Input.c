#include <cdi.h>
#include <csd.h>
#include <modes.h>

#include "Defines.h"

int32_t		JoystickA;
int32_t		JoystickB;
int16_t	LastXA;
int16_t	LastXB;
int16_t	LastYA;
int16_t	LastYB;
uint16_t	JoystickValueA;
uint16_t	LastJoystickValueA;
uint16_t	JoystickValueB;
uint16_t	LastJoystickValueB;
uint16_t	InputDelay;

void InitInput()
{
	int8_t	*DeviceName;

#ifdef DEBUG
	printf("Initialize Input\n");
#endif

	/* Initialize all parameters */
	InputDelay			= 0;
	JoystickA			= -1;
	JoystickB			= -1;
	JoystickValueA		= 0;
	LastJoystickValueA	= 0;
	JoystickValueB		= 0;
	LastJoystickValueB	= 0;
	LastXA				= SCREENWIDTH/2;
	LastXB				= SCREENWIDTH/2;
	LastYA				= SCREENHEIGHT/2;
	LastYB				= SCREENHEIGHT/2;

	/* Get device name of the first pointer */
	DeviceName	= csd_devname(DT_PTR, 1);

	if (DeviceName != NULL)
	{
		JoystickA	= open(DeviceName, S_IWRITE | S_IREAD);

		if (-1 == JoystickA)
		{
#ifdef DEBUG
			printf("Unable to find joystick A\n");
#endif
		}

		else
		{
			pt_org(JoystickA, SCREENWIDTH/2, SCREENHEIGHT/2);
			pt_pos(JoystickA, SCREENWIDTH/2, SCREENHEIGHT/2);
		}

		/* Release the memory for the device name */
		free(DeviceName);
	}

	/* Get device name of the second pointer */
	DeviceName	= csd_devname(DT_PTR, 2);

	if (DeviceName != NULL)
	{
		JoystickB	= open(DeviceName, S_IWRITE | S_IREAD);

		if (-1 == JoystickB)
		{
#ifdef DEBUG
			printf("Unable to find joystick B\n");
#endif
		}

		else
		{
			pt_org(JoystickB, SCREENWIDTH/2, SCREENHEIGHT/2);
			pt_pos(JoystickB, SCREENWIDTH/2, SCREENHEIGHT/2);
		}

		/* Release the memory for the device name */
		free(DeviceName);
	}
}

void CloseInput()
{
	if (JoystickA != -1)
	{
		close(JoystickA);

		JoystickA	= -1;
	}

	if (JoystickB != -1)
	{
		close(JoystickB);

		JoystickB	= -1;
	}
}

void UpdateInput()
{
	int32_t	x;
	int32_t	y;
	int32_t	Buttons;
	int16_t	Newx;
	int16_t	Newy;

	InputDelay	= (InputDelay + 1) & 1;
	
	if (1 == InputDelay)
	{
		if (JoystickA != -1)
		{
			pt_coord(JoystickA, &Buttons, &x, &y);

			Newx				= x - LastXA;
			Newy				= y - LastYA;

			LastXA				= x;
			LastYA				= y;
			LastJoystickValueA	= JoystickValueA;
			JoystickValueA		= 0;

			if (Newx < -TOLERANCEX)
			{
				JoystickValueA	|= JOYA_LEFT;
			}

			else if (Newx > TOLERANCEX)
			{
				JoystickValueA	|= JOYA_RIGHT;
			}

			if (Newy < -TOLERANCEY)
			{
				JoystickValueA	|= JOYA_UP;
			}

			else if (Newy > TOLERANCEY)
			{
				JoystickValueA	|= JOYA_DOWN;
			}

			if ((Buttons & 1) != 0 && 0 == (Buttons & JOYA_A))
			{
				JoystickValueA	|= JOYA_A;
			}

			if ((Buttons & 2) != 0 && 0 == (Buttons & JOYA_B))
			{
				JoystickValueA	|= JOYA_B;
			}

			if (x < (TOLERANCEX*2) || x > (SCREENWIDTH-TOLERANCEX*2) || y < (TOLERANCEY*2) || y > (SCREENHEIGHT-TOLERANCEY*2))
			{
				pt_pos(JoystickA, SCREENWIDTH/2, SCREENHEIGHT/2);

				LastXA	= SCREENWIDTH/2;
				LastYA	= SCREENHEIGHT/2;
			}
		}
	}

	else
	{
		if (JoystickB != -1)
		{
			pt_coord(JoystickB, &Buttons, &x, &y);

			Newx				= x - LastXB;
			Newy				= y - LastYB;

			LastXB				= x;
			LastYB				= y;
			LastJoystickValueB	= JoystickValueB;
			JoystickValueB		= 0;

			if (Newx < -TOLERANCEX)
			{
				JoystickValueB	|= JOYA_LEFT;
			}

			else if (Newx > TOLERANCEX)
			{
				JoystickValueB	|= JOYA_RIGHT;
			}

			if (Newy < -TOLERANCEY)
			{
				JoystickValueB	|= JOYA_UP;
			}

			else if (Newy > TOLERANCEY)
			{
				JoystickValueB	|= JOYA_DOWN;
			}

			if ((Buttons & 1) != 0 && 0 == (Buttons & JOYA_A))
			{
				JoystickValueB	|= JOYA_A;
			}

			if ((Buttons & 2) != 0 && 0 == (Buttons & JOYA_B))
			{
				JoystickValueB	|= JOYA_B;
			}

			if (x < (TOLERANCEX*2) || x > (SCREENWIDTH-TOLERANCEX*2) || y < (TOLERANCEY*2) || y > (SCREENHEIGHT-TOLERANCEY*2))
			{
				pt_pos(JoystickB, SCREENWIDTH/2, SCREENHEIGHT/2);

				LastXB	= SCREENWIDTH/2;
				LastYB	= SCREENHEIGHT/2;
			}
		}
	}
}

uint16_t ReadJoystickA()
{
	return	JoystickValueA;
}

uint16_t ReadJoystickB()
{
	return	JoystickValueB;
}

void DisableUserControls()
{
	int8_t	*DeviceName;
	int8_t	NewDevice[32];
	int32_t		Handle	= -1;

	/* Get device name of the system */
	DeviceName	= csd_devname(DT_CDC, 1);

	if (DeviceName != NULL)
	{
		/* Append '@' to device name */
		sprintf(NewDevice, "%s@", DeviceName);

		Handle	= open(NewDevice, S_IWRITE | S_IREAD);

		if (Handle != -1)
		{
			ss_disable(Handle);
		}

		else
		{
#ifdef DEBUG
			printf("Unable to open CD device\n");
#endif
		}

		/* Release the memory for the device name */
		free(DeviceName);
	}

	if (Handle != -1)
	{
		close(Handle);
	}
}

void EnableUserControls()
{
	int8_t	*DeviceName;
	int8_t	NewDevice[32];
	int32_t		Handle	= -1;

	/* Get device name of the system */
	DeviceName	= csd_devname(DT_CDC, 1);

	if (DeviceName != NULL)
	{
		/* Append '@' to device name */
		sprintf(NewDevice, "%s@", DeviceName);

		Handle	= open(NewDevice, S_IWRITE | S_IREAD);
		if (Handle != -1)
		{
			ss_enable(Handle);
		}

		else
		{
#ifdef DEBUG
			printf("Unable to open CD device\n");
#endif
		}

		/* Release the memory for the device name */
		free(DeviceName);
	}

	if (Handle != -1)
	{
		close(Handle);
	}
}
