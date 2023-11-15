//
// scoop.c
//
// Controls scoop
//

const int SCOOP_UP = 100;
const int SCOOP_DOWN = -100;
const int SCOOP_MIDDLE = 0;
const int SCOOP_FAST = 10;
const int SCOOP_SLOW = 5;
const int SCOOP_COOLDOWN = 20;

task scoop()
{
	motor[scoop_servo] = SCOOP_MIDDLE;
	int current_position = 0;

	for(;;)
	{
		// Move servo slowly
		if(vexRT[Btn6U] == 1)
		{
			current_position+= SCOOP_SLOW;
		}
		if(vexRT[Btn6D] == 1)
		{
			current_position-= SCOOP_SLOW;
		}

		// Move servo quickly
		if(vexRT[Btn5U] == 1)
		{
			current_position+= SCOOP_FAST;
		}
		if(vexRT[Btn5D] == 1)
		{
			current_position-= SCOOP_FAST;
		}

		// Constrain positions
		if(current_position > SCOOP_UP) current_position = SCOOP_UP;
		if(current_position < SCOOP_DOWN) current_position = SCOOP_DOWN;

		// Move motor
		motor[scoop_servo] = current_position;

		wait1Msec(SCOOP_COOLDOWN);
	}
}
