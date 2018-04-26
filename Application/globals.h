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

static U8 motor_open_flag; //电机开关标志 0-关 1-开
static U8 sound_disable_flag; //静音标志 0-蜂鸣 1-静音
static U8 sound_level; //声音报警等级 0-无报警 1-低等级 2-中等级 3-高等级
static U8 SD_OK_Flag; //SD卡状态 0-异常 1-正常
static U32 motor_open_time; //电机上电时间，以s为单位的RTC时间
static U32 timestamp; //时间戳
static U16 ADC_FLOW = 0; //流量原始数据
static U16 ADC_MOTORSPEED = 0; //转速原始数据
typedef struct Calendar //日历
{
	U8 hour;
	U8 min;
	U8 sec;
	U16 w_year;
	U8 w_month;
	U8 w_date;
	U8 week;
};

WM_HWIN CreateWindow1(void);
WM_HWIN CreateWindow2(void);
WM_HWIN CreateWindow4(void);
WM_HWIN CreateWindow1_1(void);
WM_HWIN CreateWindow1_2(void);
WM_HWIN CreateWindow1_7(void);
WM_HWIN CreateWindowLogo(void);

extern WM_HWIN GuideMainWindow;
extern WM_HWIN DataShowWindow;
extern WM_HWIN StateBarWindow;
extern WM_HWIN GStep1Window;
extern WM_HWIN GStep2Window;
extern WM_HWIN GStep7Window;
extern WM_HWIN LogoWindow;



extern MainStateMachine smMain;
extern GuideStateMachine smGuide;
