
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
	
	
	//CreateFramewin(WM_HBKWIN); //��������,�����������汳��
	Globals_InitGlobal();
	SM_InitMainStateMachine();
	SM_InitGuideStateMachine();

	while (1) { GUI_Delay(20); } //����GUI_Delay������ʱ20MS(����Ŀ���ǵ���GUI_Exec()����)
}