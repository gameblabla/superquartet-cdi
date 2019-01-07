** @name viddcp.d Defines video DCP layout constants.
*
* The layout described by these constants is the conventional one
* established by the video functions, but it is not mandatory and
* programs can use other arrangements if necessary.
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

** FCT instruction numbers.
FCT_BCOL	equ	0
FCT_PO		equ	1
FCT_ICM		equ	2
FCT_DPRM	equ	3
FCT_TCTL	equ	4
FCT_TCOL	equ	5
FCT_MCOL	equ	6
FCT_PHLD	equ	7
FCT_WFAC	equ	8
FCT_YUV		equ	9
FCT_RCTL	equ	10
FCT_VSR		equ	18
FCT_INT		equ	20
FCT_CLUT	equ	21

** FCT length (instructions).
FCTLEN		equ	151

** LCT instruction numbers.
LCT_VSR		equ	0
LCT_INT		equ	7			* Also used by DC_LLnk.

** LCT length (lines).
LCTLEN		equ	2*280+2

