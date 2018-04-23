#pragma once

// 请勿直接修改该变量, 如需修改请调用SetOriginalMotorSpeed()
extern int iOriginalMotorSpeed;
extern int iMotorSpeedIncrement;

void SetOriginalMotorSpeed(int speed);
void DecreaseOriginalMotorSpeed();
void IncreaseOriginalMotorSpeed();