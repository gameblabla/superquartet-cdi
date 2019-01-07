** @name dcpins.d Defines video DCP instruction constants.
*
* These definitions are taken mostly from the Motorola MCD212 datasheet.
* DCP instructions not allowed from CD-i applications have been omitted.
*
* @section Copyright (c) 2005, CD-i Fan.
* This file is licensed under the GNU Library General Public License,
* version 2 or (at your option) any later version. The full terms of
* the license can be found in the file LCOPYING that you should have
* received with this file. You can also refer to the on-line version that
* can be found at http://www.fsf.org/licensing/licenses/lgpl.txt.
*
* @author CD-i Fan
*
* @version 0.5.1
*
* @history
* @rev 2005/08/20 cdifan Created.

* Plane numbers.
PA				equ	0
PB				equ	1

* No operation.
CP_NOP			equ $10000000

* Reload VSR register.
CP_VSR			equ $40000000

VSR_MASK		equ	$FFFFFF

* Generate Interrupt.
CP_INT			equ $60000000

* Reload Display Parameters.
CP_DPRM			equ	$78000400

FT_NORMAL0		equ	0
FT_NORMAL1		equ	1
FT_RUNLENGTH	equ	2				
FT_MOSAIC		equ	3

MF_X2			equ	0
MF_X4			equ	1
MF_X8			equ	2
MF_X16			equ	3

* Load CLUT Color register 0-63
CP_COLOR		equ $80000000

* Load Image Coding Method.
CP_ICM			equ	$C0001010

* Plane Off Coding Method.
CM_OFF			equ	$0

* CLUT8 Coding Method.
CM_CLUT8		equ	$1

* RGB555 Coding Method.
CM_RGB555		equ	$1

* CLUT7 Coding Method.
CM_CLUT7		equ	$3

* CLUT7+7 Coding Method.
CM_CLUT77		equ	$4

* DYUV Coding Method.
CM_DYUV			equ	$5

* CLUT4 Coding Method.
CM_CLUT4		equ	$B

* Load Transparency Control register.
CP_TCTL			equ	$C1000000

* Load Plane Order register.
CP_PO			equ	$C2000000

* Plane A in front of plane B.
PO_AB			equ	0

* Plane B in front of plane A.
PO_BA			equ	1

* Load CLUT Bank register.
CP_CBNK			equ $C3000000

* Load Transparent Color register for plane A.
CP_TCOL_A		equ $C4000000

* Load Transparent Color register for plane B.
CP_TCOL_B		equ $C6000000

* Load Mask Color register for plane A.
CP_MCOL_A		equ $C7000000

* Load Mask Color register for plane B.
CP_MCOL_B		equ $C9000000

* Load Delta YUV Start Value register for plane A.
CP_YUV_A		equ $CA000000

* Load Delta YUV Start Value register for plane B.
CP_YUV_B		equ $CB000000

* Load Region Control register 0-7.
CP_RCTL			equ $D0000000

* End of Region Control.
OP_END			equ $0

* Change Weight Factor for plane A.
OP_WF_A			equ $4

* Change Weight Factor for plane B.
OP_WF_B			equ $6

* Reset Region Flag.
OP_RES			equ $8

* Set Region Flag.
OP_SET			equ $9

* Reset Region Flag and Change Weight Factor for plane A.
OP_RES_WF_A		equ $C

* Set Region Flag and Change Weight Factor for plane A.
OP_SET_WF_A		equ $D

* Reset Region Flag and Change Weight Factor for plane B.
OP_RES_WF_B		equ $E

* Set Region Flag and Change Weight Factor for plane B.
OP_SET_WF_B		equ $F

* Load Backdrop Color register.
CP_BCOL			equ $D8000000

* Backdrop Color Brightness bit.
BCOL_Y			equ	$8

* Backdrop Color Red bit.
BCOL_R			equ	$4

* Backdrop Color Green bit.
BCOL_G			equ	$2

* Backdrop Color Blue bit.
BCOL_B			equ	$2

* Load Mosaic Pixel Hold Factor register for plane A.
CP_PHLD_A		equ $D9000000

* Load Mosaic Pixel Hold Factor register for plane B.
CP_PHLD_B		equ $DA000000

PHLD_NORM		equ	1

* Load Weight Factor register for plane A.
CP_WFAC_A		equ $DB000000

* Load Weight Factor register for plane B.
CP_WFAC_B		equ	$DC000000

* Weight Factor Minimum value
WFAC_MIN		equ	0

* Weight Factor Maximum value
WFAC_MAX		equ	63
