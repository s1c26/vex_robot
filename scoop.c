//
// scoop.c
//
// Controls scoop
//

const int SCOOP_UP = 100;
const int SCOOP_DOWN = -100;
const int SCOOP_COOLDOWN = 50;

task scoop()
{
	for(;;)
	{
		// Set servo position
		if(vexRT[Btn6U])
		{
			motor[shovel] = SCOOP_UP;
		}
		if(vexRT[Btn6D])
		{
			motor[shovel] = SCOOP_DOWN;
		}

		delay(SCOOP_COOLDOWN);
	}
}
