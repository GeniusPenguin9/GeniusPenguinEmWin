
#include "GUI.h"

#ifndef GUI_CONST_STORAGE
#define GUI_CONST_STORAGE const
#endif

/* The following line needs to be included in any file selecting the
font.
*/
extern GUI_CONST_STORAGE GUI_FONT GUI_Font½éºÚÌå33;

/* Start of unicode area <CJK Unified Ideographs> */
GUI_CONST_STORAGE unsigned char acGUI_Font½éºÚÌå33_4ECB[132] = { /* code 4ECB */
	XX__X___,__XXXXXX,X_X_X__X,__X__XX_,
	X_X_XXX_,XX_XX_XX,X_X__XXX,XXX__X__,
	_______X,_X___XX_,XX______,X__X_XX_,
	__XXXXX_,__X_X_XX,___XXXX_,__X_XXX_,
	X___X___,XXXXXXXX,XXX_X___,__X__X_X,
	_X_X_XXX,__X____X,_X__X_XX,____XX_X,
	_XXX_XX_,X_XX_XX_,_X___XX_,XXXXXX_X,
	_______X,X_XX____,_X_X_XX_,_X___X__,
	__XXX___,X__XXXX_,_XX___XX,X_XXXX_X,
	_X__XX__,X_XX_X__,XX_XX_X_,_XXXX_XX,
	XX_XXXX_,_X__X__X,_X_XXXXX,___XX_X_,
	__X___XX,X_X__X_X,X___XX_X,____XX_X,
	_XX_____,_XX_XX_X,X_X__X__,XX_XXXX_,
	X_XXX_XX,XX______,X_X___XX,X__XX___,
	X_XX____,X__XX___,X__X___X,_X_XX__X,
	__XXX_XX,X_X___X_,XXXX____,__XXXXX_,
	___X_X_X,_X__XXX_,_XX_X_X_,XXX___X_,
	X_X_X___,XX___X_X,XXXX__X_,X_XXXXXX,
	X__XX___,__XX_XXX,XXX_X_X_,_XXXXXX_,
	__XX__XX,X_X__X_X,__X_XXXX,__XX___X,
	_X_XX___,X__XXX__,X_XX_XX_,X___XX_X,
	_XXXX__X,X_XXXXX_,X_XXXXX_,_X_X__X_,
	X___XX_X,XX_X_XX_,__XXX___,_XXXX__X,
	__X_XXX_,__X_XXX_,X_X___XX,___X_XXX,
	XX_XXX_X,X_XXXXXX,____X___,__XX___X,
	_XX_X_XX,__XXX__X,__XXXXX_,_X__XX__,
	____XX_X,__XXX__X,_______X,XX_XXXX_,
	____XX__,__X_X_X_,__XXX___,___XX_X_,
	XX_XX__X,___XXX_X,_XXXXX__,XX_X__X_,
	X__XXXXX,XX__X_XX,XX_X____,X____XXX,
	XX__X_X_,_XX_X_XX,____XX_X,XXXX_X_X,
	__XX___X,X_X_XX__,___XX___,X_X_XX_X,
	_XX_XX__,__XXX___,_X___X__,_X__X_X_ };

GUI_CONST_STORAGE GUI_CHARINFO GUI_Font½éºÚÌå33_CharInfo[1] = {
	{ 32,  32,  1, acGUI_Font½éºÚÌå33_4ECB } /* code 4ECB */
};

GUI_CONST_STORAGE GUI_FONT_PROP GUI_Font½éºÚÌå33_Prop1 = {
	0x4ECB /* first character */
	,0x4ECB /* last character  */
	,&GUI_Font½éºÚÌå33_CharInfo[0] /* address of first character */
	,(GUI_CONST_STORAGE GUI_FONT_PROP *)0 /* pointer to next GUI_FONT_PROP */
};

GUI_CONST_STORAGE GUI_FONT GUI_Font½éºÚÌå33 = {
	GUI_FONTTYPE_PROP /* type of font    */
	,33 /* height of font  */
	,33 /* space of font y */
	,1 /* magnification x */
	,1 /* magnification y */
	,{ &GUI_Font½éºÚÌå33_Prop1 }
	,28 /* Baseline */
	,15 /* Height of lowercase characters */
	,22 /* Height of capital characters */
};

