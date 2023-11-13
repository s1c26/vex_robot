//
// scoop.c
//
// Controls scoop
//

// TODO: make servo move slower

const int SCOOP_UP = 100;
const int SCOOP_DOWN = -100;
const int SCOOP_MIDDLE = 0;
const int SERVO_SPEED = 10;

void setServoSpeed(int current_pos, int new_pos, int speed)
{
	if(new_pos == current_pos)
	{
		return;
	}
	else if(new_pos < current_pos)
	{
		for(int i = current_pos; i < new_pos; i++)
		{
			motor[scoop_servo] = i;
			delay(1000 / speed);
		}
	}
	else if(new_pos > current_pos)
	{
		for(int i = current_pos; i > new_pos; i--)
		{
			motor[scoop_servo] = i;
			delay(1000 / speed);
		}
	}
}

task scoop()
{
	int current_position = 0;
	for(;;)
	{
		// Set servo position
		if(vexRT[Btn6U])
		{
			setServoSpeed(current_position, SCOOP_UP, SERVO_SPEED);
		}
		else if(vexRT[Btn6D])
		{
			setServoSpeed(current_position, SCOOP_DOWN, SERVO_SPEED);
		}
		else if(vexRT[Btn6D])
		{
			setServoSpeed(current_position, SCOOP_MIDDLE, SERVO_SPEED);
		}
	}
}
