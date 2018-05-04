#include "GUI.h"
#include "DIALOG.h"
#include "WM.h"
#include <stddef.h>

#define ID_WINDOW_0    (GUI_ID_USER + 0x00)
#define ID_TEXT_0    (GUI_ID_USER + 0x01)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 320, 240, 0, 0x0, 0 },
{ TEXT_CreateIndirect, "Text", ID_TEXT_0, 0, 0, 80, 20, 0, 0x64, 0 },
// USER START (Optionally insert additional widgets)
// USER END
};

int i = 0;
static void _cbDialog(WM_MESSAGE * pMsg) {
	WM_HWIN hItem;
	WM_HWIN hWin;

	char TextCont[2];
	// USER START (Optionally insert additional variables)
	// USER END

	switch (pMsg->MsgId) {
	case WM_PAINT:
		//
		// Initialization of 'Text'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
		
		i++;
		sprintf(TextCont, "%d", i);
		TEXT_SetText(hItem, TextCont);
		
		break;
		
	case WM_TIMER:
		hWin = pMsg->hWin;
		WM_RestartTimer(pMsg->Data.v, 1000);
		WM_InvalidateWindow(hWin);
		break;
	default:
		WM_DefaultProc(pMsg);
		break;
	}
}

WM_HWIN CreateWindow(void);
WM_HWIN CreateWindow(void) {
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

void MainTask(void)
{
	WM_HTIMER hTimer;
	WM_HWIN win;

	GUI_Init();
	win = CreateWindow();
	hTimer = WM_CreateTimer(win, 0, 2000, 0);
	
	while (1)
	{
		GUI_Exec();
		GUI_X_Delay(1000);
	}
}

//
//
//GUI_COLOR _acColor[3] = { GUI_BLUE, GUI_RED, GUI_YELLOW };
//static char ucBkColor;
//
//static void _cbBkWindow(WM_MESSAGE * pMsg)
//{
//	WM_HWIN hWin = pMsg->hWin;
//	switch (pMsg->MsgId)
//	{
//	case WM_PAINT:
//		ucBkColor++;
//			if (ucBkColor == 3) 
//			{ 
//				ucBkColor = 0; }
//			GUI_SetBkColor(_acColor[ucBkColor]);
//			GUI_Clear();
//			break;
//	case WM_TIMER:
//		WM_RestartTimer(pMsg->Data.v, 1000);
//		WM_InvalidateWindow(hWin);
//		break;
//	default:
//		WM_DefaultProc(pMsg);
//	}
//}
//
//void MainTask(void)
//{
//	WM_HTIMER hTimer;
//
//	GUI_Init();
//	hTimer = WM_CreateTimer(WM_HBKWIN, 0, 1000, 0);
//	WM_SetCallback(WM_HBKWIN, _cbBkWindow);
//	while (1)
//	{
//		GUI_Delay(500);
//	}
//}