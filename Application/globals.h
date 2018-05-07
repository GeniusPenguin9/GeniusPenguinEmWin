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

static U8 motor_open_flag; //������ر�־ 0-�� 1-��
static U8 sound_disable_flag; //������־ 0-���� 1-����
static U8 sound_level; //���������ȼ� 0-�ޱ��� 1-�͵ȼ� 2-�еȼ� 3-�ߵȼ�
static U8 SD_OK_Flag; //SD��״̬ 0-�쳣 1-����
static U32 motor_open_time; //����ϵ�ʱ�䣬��sΪ��λ��RTCʱ��
static U32 timestamp; //ʱ���
static U16 ADC_FLOW = 0; //����ԭʼ����
static U16 ADC_MOTORSPEED = 0; //ת��ԭʼ����
typedef struct Calendar //����
{
	U8 hour;
	U8 min;
	U8 sec;
	U16 w_year;
	U8 w_month;
	U8 w_date;
	U8 week;
}Calendar;
Calendar RTCalendar;


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

extern GUI_CONST_STORAGE GUI_FONT GUI_FontCNFont;
