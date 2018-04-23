
#include "globals.h"

MainStateMachine smMain;
GuideStateMachine smGuide;
FocusableListItem * fliFocusableItemsHead = NULL;
FocusableListItem * fliCurrentFocusItem = NULL;

void SM_InitMainStateMachine () {
	smMain.States[0] = GuideMainWindow = CreateWindow1();
	smMain.States[1] = DataShowWindow = CreateWindow2();

	for (int i = 0; i < MainStatesCount; i++)
		if (smMain.States[i] != NULL)
			WM_HideWindow(smMain.States[i]);

	MSM_SwitchState(GuideMainWindow);
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
	if (smMain.CurrentState != NULL)
		WM_HideWindow(smMain.CurrentState);
	smMain.CurrentState = win;
	WM_ShowWindow(win);
}

void GSM_SwitchState(WM_HWIN win) {
	if (smGuide.CurrentState != NULL) 
		WM_HideWindow(smGuide.CurrentState);
	smGuide.CurrentState = win;
	WM_ShowWindow(win);
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
			(next->GuideState == NULL || next->GuideState == smGuide.CurrentState)) 
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
			(previous->GuideState == NULL || previous->GuideState == smGuide.CurrentState))
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
	if (key_info->PressedCnt == 0 && 
		(key_info->Key == GUI_KEY_LEFT || key_info->Key == GUI_KEY_UP)) 
	{
		SM_PreviousFocuableItem();
	}
	else if (key_info->PressedCnt == 0 && 
		(key_info->Key == GUI_KEY_RIGHT || key_info->Key == GUI_KEY_DOWN)) 
	{
		SM_NextFocuableItem();
	}
	else if (key_info->PressedCnt == 0 && key_info->Key == GUI_KEY_ENTER) 
	{
		GUI_SendKeyMsg(hWin, 1);
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