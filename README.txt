===========================
Super Quartet (Philips CDI)
===========================

This is the source code for Super Quartet on the Philips-CDI.

To compile it, you need the OS9 C compiler as well as some more tools that you need to put in the img folder inside of src.

You can find these at https://gameblabla.nl/files/cdi/

This will only fully compile on Windows 32-bits, due to an error in the C compiler that requests a unix path on Windows.

This won't work on Dosbox for example (even though it can run the binaries) but /dd/ will default to C: on Windows.

This corner case also still won't work on ReactOS.

The source code is based on Frog Feast's source code, which without it, this project wouldn't be possible.

Make sure to also have make.exe and to set the environment variable to C:/OS9C/bin.

I couldn't figure out why the sound effects won't work completely so the related code is completely removed.

I might put it back some later time though.


=========
LICENSES
=========

Here's the legalese fun.

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

The following files are covered by the LGPL, and must be distributed in accordance with the terms of this license (Copyright cdifan) :
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
the enclosed code in any freeware/commercial application. The only
limitation is that the source code cannot be recompiled to create a copy of
the Frog Feast CD. You can create a modified version of Frog Feast, and
give instructions about burning a new CD using the files from the Frog
Feast CD. None of the data files from the CD may be included with a
modified version of Frog Feast."
	
Though the game is not affected by the restriction in practice, this makes it non-free.
Eventually this code will be got rid of anyway since it won't be suitable for future projects.
