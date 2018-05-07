
#include "globals.h"
#include "GUI.h"

MainStateMachine smMain;
GuideStateMachine smGuide;
FocusableListItem * fliFocusableItemsHead = NULL;
FocusableListItem * fliCurrentFocusItem = NULL;


#define ID_TimerData 0
#define ID_TimerTime 1

void Globals_InitGlobal() {
	/*设置Button默认式样*/
	BUTTON_SetDefaultBkColor(GUI_WHITE, BUTTON_CI_UNPRESSED); 
	BUTTON_SetDefaultBkColor(GUI_BLUE, BUTTON_CI_PRESSED);
	BUTTON_SetDefaultBkColor(GUI_GRAY, BUTTON_CI_DISABLED);
	BUTTON_SetDefaultFocusColor(GUI_RED);
	/*设置UTF8用于汉字解码*/
	GUI_UC_SetEncodeUTF8(); 
	/*初始时间，仅用于模拟日历*/
	RTCalendar.w_year = 2018;
	RTCalendar.w_month = 01;
	RTCalendar.w_date = 01;
	RTCalendar.hour = 10;
	RTCalendar.min = 03;
	RTCalendar.sec = 15;
}

void SM_InitMainStateMachine () {
	
	smMain.States[0] = LogoWindow = CreateWindowLogo();
	smMain.States[1] = GuideMainWindow = CreateWindow1();
	smMain.States[2] = DataShowWindow = CreateWindow2();
	StateBarWindow = CreateWindow4();
	
	WM_HTIMER hTimerTime;
	hTimerTime = WM_CreateTimer(StateBarWindow, 0, 1000, 0);

	WM_HTIMER hTimerData;
	hTimerData = WM_CreateTimer(DataShowWindow, 0, 1000, 0);


	for (int i = 0; i < MainStatesCount; i++)
		if (smMain.States[i] != NULL)
			WM_HideWindow(smMain.States[i]);

	WM_HideWindow(StateBarWindow);
	MSM_AutoSwitchState(LogoWindow);
	MSM_SwitchState(GuideMainWindow);
	WM_ShowWindow(StateBarWindow);
	
}

void SM_InitGuideStateMachine() {
	smGuide.States[0] = GStep1Window = CreateWindow1_1();
	smGuide.States[1] = GStep2Window = CreateWindow1_2();
	smGuide.States[2] = GStep7Window = CreateWindow1_7();

	for (int i = 0; i < GuideStatesCount; i++)
		if (smGuide.States[i] != NULL)
			WM_HideWindow(smGuide.States[i]);

	GSM_SwitchState(GStep1Window);
}

void MSM_SwitchState(WM_HWIN win) {
	if (smMain.CurrentState != NULL) {
		WM_HideWindow(smMain.CurrentState);
		WM_SendMessageNoPara(smMain.CurrentState, WM_MAIN_STATE_LEAVE);
	}
	smMain.CurrentState = win;
	WM_ShowWindow(win);
	if (smMain.CurrentState != NULL)
		WM_SendMessageNoPara(smMain.CurrentState, WM_MAIN_STATE_ENTER);
}

void MSM_AutoSwitchState(WM_HWIN win) {
	WM_ShowWindow(win);
	GUI_Delay(DelayTime);
	WM_HideWindow(win);
}

WM_HWIN MSM_GetCurrentState() {
	return smMain.CurrentState;
}

void GSM_SwitchState(WM_HWIN win) {
	if (smGuide.CurrentState != NULL) {
		WM_HideWindow(smGuide.CurrentState);
		WM_SendMessageNoPara(smMain.CurrentState, WM_GUIDE_STATE_LEAVE);
		WM_SendMessageNoPara(smGuide.CurrentState, WM_GUIDE_STATE_LEAVE);
	}
	smGuide.CurrentState = win;
	WM_ShowWindow(win);
	if (smGuide.CurrentState != NULL) {
		WM_SendMessageNoPara(smMain.CurrentState, WM_GUIDE_STATE_ENTER);
		WM_SendMessageNoPara(smGuide.CurrentState, WM_GUIDE_STATE_ENTER);
	}
}

WM_HWIN GSM_GetCurrentState() {
	return smGuide.CurrentState;
}

void GSM_NextState() {
	for (int i = 0; i < GuideStatesCount; i++)
	{
		if (smGuide.States[i] == smGuide.CurrentState && i != GuideStatesCount-1)
		{
			GSM_SwitchState(smGuide.States[i + 1]);
			break;
		}
	}
}

void GSM_PreviousState() {
	for (int i = 0; i < GuideStatesCount; i++)
	{
		if (smGuide.States[i] == smGuide.CurrentState && i != 0)
		{
			GSM_SwitchState(smGuide.States[i - 1]);
			break;
		}
	}
}

void GSM_DisableButton(HBWIN hItem) {
	WM_DisableWindow(hItem);
	BUTTON_SetFocussable(hItem, 0);
	BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_GRAY);
}

void GSM_EnableButton(HBWIN hItem) {
	WM_EnableWindow(hItem);
	BUTTON_SetFocussable(hItem, 1);
	BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_WHITE);
}

void SM_RegisterFocusableListItem(FocusableListItem* item)
{
	FocusableListItem* current = fliFocusableItemsHead;
	if (current != NULL) {
		while (current->Next != NULL) {
			current = current->Next;
		}
		item->Previous = current;
		item->Next = NULL;
		current->Next = item;
	}
	else {
		item->Next = NULL;
		fliFocusableItemsHead = item;
	}
}

void SM_NextFocuableItem() 
{
	FocusableListItem* current = fliCurrentFocusItem;
	if (current == NULL) current = fliFocusableItemsHead;
	
	while (current->Next != fliCurrentFocusItem) {
		FocusableListItem* next = current->Next;
		if (next == NULL) next = fliFocusableItemsHead;

		if (next->MainState == smMain.CurrentState &&
			(next->GuideState == NULL || next->GuideState == smGuide.CurrentState) &&
			WM_IsEnabled(next->CurrentControl))
		{
			fliCurrentFocusItem = next;
			WM_SetFocus(fliCurrentFocusItem->CurrentControl);
			break;
		}
		else
		{
			current = next;
		}
	}
}

void SM_PreviousFocuableItem()
{
	FocusableListItem* current = fliCurrentFocusItem;
	if (current == NULL) return;

	while (current->Previous != fliCurrentFocusItem) {
		FocusableListItem* previous = current->Previous;
		if (previous == NULL) {
			previous = fliFocusableItemsHead;
			while (previous->Next != NULL) previous = previous->Next;
		}

		if (previous->MainState == smMain.CurrentState &&
			(previous->GuideState == NULL || previous->GuideState == smGuide.CurrentState)&&
			WM_IsEnabled(previous->CurrentControl))
		{
			fliCurrentFocusItem = previous;
			WM_SetFocus(fliCurrentFocusItem->CurrentControl);
			break;
		}
		else
		{
			current = previous;
		}
	}
}

int SM_KeyProc(WM_KEY_INFO* key_info, WM_HWIN hWin) 
{
	if (key_info->PressedCnt == 0 && key_info->Key == GUI_KEY_LEFT) 
	{
		SM_PreviousFocuableItem();
	}
	else if (key_info->PressedCnt == 0 && key_info->Key == GUI_KEY_RIGHT) 
	{
		SM_NextFocuableItem();
	}
	else if (key_info->PressedCnt == 0 && key_info->Key == GUI_KEY_ENTER) 
	{
		GUI_SendKeyMsg(hWin, 1);

	}
	else if (key_info->PressedCnt == 0 && key_info->Key == GUI_KEY_Num0)
	{
		MSM_SwitchState(GuideMainWindow);
		GSM_SwitchState(GStep1Window);
	}
	else if (key_info->PressedCnt == 0 && key_info->Key == GUI_KEY_Num1)
	{
		MSM_SwitchState(DataShowWindow);
	}
	else {
		return 0;
	}
	return 1;
}

