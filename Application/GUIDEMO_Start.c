
#include "globals.h"
#include "dialog.h"
#include "GUI.h"

WM_HWIN GuideMainWindow;
WM_HWIN DataShowWindow;
WM_HWIN StateBarWindow;
WM_HWIN GStep1Window;
WM_HWIN GStep2Window;
WM_HWIN GStep7Window;
WM_HWIN LogoWindow;


void MainTask(void)
{
	
	
	//CreateFramewin(WM_HBKWIN); //创建窗体,父窗体是桌面背景
	Globals_InitGlobal();
	SM_InitMainStateMachine();
	SM_InitGuideStateMachine();

	while (1) { GUI_Delay(20); } //调用GUI_Delay函数延时20MS(最终目的是调用GUI_Exec()函数)
}