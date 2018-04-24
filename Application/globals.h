#pragma once

#include <stdio.h>
#include "DIALOG.h"
#include "Test_StateMachine.h"
#include "Test_Settings.h"

#define GUI_KEY_Num0                0x30
#define GUI_KEY_Num1                0x31
#define GUI_KEY_Num2                0x32
#define GUI_KEY_Num3                0x33

typedef int bool;
#define TRUE 1;
#define FALSE 0;


WM_HWIN CreateWindow1(void);
WM_HWIN CreateWindow2(void);
WM_HWIN CreateWindow4(void);
WM_HWIN CreateWindow1_1(void);
WM_HWIN CreateWindow1_2(void);
WM_HWIN CreateWindow1_7(void);

extern WM_HWIN GuideMainWindow;
extern WM_HWIN DataShowWindow;
extern WM_HWIN StateBarWindow;
extern WM_HWIN GStep1Window;
extern WM_HWIN GStep2Window;
extern WM_HWIN GStep7Window;


extern MainStateMachine smMain;
extern GuideStateMachine smGuide;
