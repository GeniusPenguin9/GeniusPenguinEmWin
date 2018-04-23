/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2014  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.26 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : GUIDEMO_Start.c
Purpose     : GUIDEMO initialization
----------------------------------------------------------------------
*/

//#include "GUIDEMO.h"

/*********************************************************************
*
*       MainTask
*/
//void MainTask(void) {
//  #if GUI_WINSUPPORT
//    WM_SetCreateFlags(WM_CF_MEMDEV);
//  #endif
//  GUI_Init();
//  #if GUI_WINSUPPORT
//    WM_MULTIBUF_Enable(1);
//  #endif
//  GUIDEMO_Main();
//}

/*************************** End of file ****************************/

#include "globals.h"
#include "dialog.h"
#include "GUI.h"

WM_HWIN GuideMainWindow;
WM_HWIN DataShowWindow;
WM_HWIN GStep1Window;
WM_HWIN GStep2Window;
WM_HWIN GStep7Window;


static U8 motor_open_flag; //电机开关标志 0-关 1-开
static U8 sound_disable_flag; //静音标志 0-蜂鸣 1-静音
static U8 sound_level; //声音报警等级 0-无报警 1-低等级 2-中等级 3-高等级
static U8 SD_OK_Flag; //SD卡状态 0-异常 1-正常
static U32 motor_open_time; //电机上电时间，以s为单位的RTC时间
static U32 timestamp; //时间戳
static U16 ADC_FLOW = 0; //流量原始数据
static U16 ADC_MOTORSPEED = 0; //转速原始数据
static struct calendar //日历
{
	U8 hour;
	U8 min;
	U8 sec;
	U16 w_year;
	U8 w_month;
	U8 w_date;
	U8 week;
};



void MainTask(void)
{
	
	GUI_Init();//初始化emWin/ucGUI
	//CreateFramewin(WM_HBKWIN); //创建窗体,父窗体是桌面背景

	SM_InitMainStateMachine();
	SM_InitGuideStateMachine();

	while (1) { GUI_Delay(20); } //调用GUI_Delay函数延时20MS(最终目的是调用GUI_Exec()函数)
}