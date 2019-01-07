#include <cdfm.h>
#include <csd.h>
#include <modes.h>

#include "Defines.h"

/* Sounds */
#define	MAXSOUNDS	4

int	 Sound;						/* Audio device handle */
int	 SoundID[MAXSOUNDS * 2];	/* Soundmap IDs. Create a set for each frog */
uint16_t SoundLengths[MAXSOUNDS] =	/* Length of each sound */
{
	2304*2, 2304, 2304, 2304*2
};

extern	char *SoundData;		/* Pointer to sound data, allocated in LoadScreen2 */

void CreateSoundMap(Index, Filename, Length);

void InitSound()
{
	uint16_t	Loop;
	char	*DeviceName;
	char	*Data	= SoundData;

#ifdef DEBUG
	printf("Initialize Sound\n");
#endif

	/* Set the audio device handle to invalid */
	Sound	= -1;

	/* Set sound id handle to invalid */
	for (Loop = 0; Loop < MAXSOUNDS * 2; Loop++)
	{
		SoundID[Loop]	= -1;
	}

	/* Find the audio device */
	DeviceName	= csd_devname(DT_AUDIO, 1);

	if (NULL == DeviceName)
	{
#ifdef DEBUG
		printf("Unable to find audio device\n");
#endif
		return;
	}

	/* Open the audio device */
	Sound	= open(DeviceName, S_IREAD | S_IWRITE);

	/* Unable to open the sound device */
	if (-1 == Sound)
	{
#ifdef DEBUG
		printf("Unable to open audio device\n");
#endif
		/* Release the memory for the device name */
		free(DeviceName);
		
		return;
	}

	/* Release the memory for the device name, as it's no longer needed. */
	free(DeviceName);

	/* Set maximum volume in left-left and right-right channels */
	sc_atten(Sound, 0x00800080);

	/* Create soundmap for both frogs, using the same sound data */
	for (Loop = 0; Loop < MAXSOUNDS; Loop++)
	{
		CreateSoundMap(Loop, (uint32_t *)Data, SoundLengths[Loop]);
	
		/* Advance the sound pointer to the next sound */
		Data	+= SoundLengths[Loop];
	}
}

void CloseSound()
{
	uint16_t	Loop;

	/* If the Sound device isn't invalid, free the sound device, and sounds */
	if (Sound != -1)
	{
		for (Loop = 0; Loop < MAXSOUNDS; Loop++)
		{
			if (SoundID[Loop] != -1)
			{
				sm_close(Sound, SoundID[Loop]);
			}
		}

		/* Stop sound device */
		sm_off(Sound);

		/* Close the sound device */
		close(Sound);

		/* Mark the sound device as invalid */
		Sound	= -1;
	}
}

void CreateSoundMap(Index, Data, Length)
	uint16_t Index; char *Data; uint16_t Length;
{
	uint16_t	Loop;
	char	*Buffer;

	/* Create the sound map for the first frog */
#ifdef DEBUG
	printf("Creating sound map %d\n", Index + 1);
#endif

	/* Create a sound map, based on the length of the sound */
	SoundID[Index]	= sm_creat(Sound, D_CMONO, Length * 18 / 2304, &Buffer);

	/* If the sound map invalid, fail out. */
	if (-1 == SoundID[Index])
	{
#ifdef DEBUG
		printf("Unable to create sound map %d\n", Index + 1);
#endif

		return;
	}

	/* Copy data to sound buffer */
	memcpy(Buffer, Data, Length);

	/* Create the sound map for the second frog */
	Index	+= MAXSOUNDS;

#ifdef DEBUG
	printf("Creating sound map %d\n", Index + 1);
#endif

	/* Create a sound map, based on the length of the sound */
	SoundID[Index]	= sm_creat(Sound, D_CMONO, Length / 128 * 18, (char *)&Buffer);

	/* If the sound map invalid, fail out. */
	if (-1 == SoundID[Index])
	{
#ifdef DEBUG
		printf("Unable to create sound map %d\n", Index + 1);
#endif
		return;
	}

	/* Copy data to sound buffer */
	memcpy(Buffer, Data, Length);
}

void PlaySound(SoundNumber)
	uint16_t SoundNumber;
{
	static	STAT_BLK	Status;

#ifdef DEBUG
	printf("Playing sound %d\n", SoundNumber + 1);
#endif

	/* Play sound */
	sm_out(Sound, SoundID[SoundNumber], &Status);
}
