#pragma once

#define MainStatesCount 4
#define GuideStatesCount 7
#define DelayTime 10000

#define WM_MAIN_STATE_ENTER 0x0401
#define WM_MAIN_STATE_LEAVE 0x0402
#define WM_GUIDE_STATE_ENTER 0x0403
#define WM_GUIDE_STATE_LEAVE 0x0404


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

WM_HWIN MSM_GetCurrentState();
void MSM_SwitchState(WM_HWIN win);
void MSM_AutoSwitchState(WM_HWIN win);
WM_HWIN GSM_GetCurrentState();
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
void GSM_DisableButton(HBWIN hItem);
void GSM_EnableButton(HBWIN hItem);