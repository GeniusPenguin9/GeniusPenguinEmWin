#pragma once

#define MainStatesCount 4
#define GuideStatesCount 7

typedef struct MainStateMachine {
	WM_HWIN States[MainStatesCount];
	WM_HWIN CurrentState;
} MainStateMachine;

typedef struct GuideStateMachine {
	WM_HWIN States[GuideStatesCount];
	WM_HWIN CurrentState;
} GuideStateMachine;

void SM_InitMainStateMachine();
void SM_InitGuideStateMachine();

void MSM_SwitchState(WM_HWIN win);

void GSM_SwitchState(WM_HWIN win);
void GSM_NextState();
void GSM_PreviousState();

int SM_KeyProc(WM_KEY_INFO* key_info, WM_HWIN hWin);



typedef struct FocusableListItem {
	WM_HWIN CurrentControl;
	WM_HWIN MainState;
	WM_HWIN GuideState;
	struct FocusableListItem * Previous;
	struct FocusableListItem * Next;
} FocusableListItem;

void SM_RegisterFocusableListItem(FocusableListItem* item);