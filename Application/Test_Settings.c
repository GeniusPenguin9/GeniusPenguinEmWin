
// 请勿直接修改该变量, 如需修改请调用SetOriginalMotorSpeed()
int iOriginalMotorSpeed = 2500;
int iMotorSpeedIncrement = 50;

const int iMaxMotorSpeed = 4000;
const int iMinMotorSpeed = 1000;

void SetOriginalMotorSpeed(int speed) {
	if (speed > iMaxMotorSpeed) speed = iMaxMotorSpeed;
	if (speed < iMinMotorSpeed) speed = iMinMotorSpeed;
	iOriginalMotorSpeed = speed;
	// TODO: Send to hardware
}

void IncreaseOriginalMotorSpeed() {
	SetOriginalMotorSpeed(iOriginalMotorSpeed + iMotorSpeedIncrement);
}

void DecreaseOriginalMotorSpeed() {
	SetOriginalMotorSpeed(iOriginalMotorSpeed - iMotorSpeedIncrement);
}

