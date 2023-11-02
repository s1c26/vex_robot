
// const int SCALE_FACTOR = 4;

task tracks()
{
	int r_motor = 0;
	int l_motor = 0;

	for(;;)
	{
		// Normal control joystick
		if(vexRT[Ch1] != 0 || vexRT[Ch2] != 0)
		{
			r_motor = vexRT[Ch1] + vexRT[Ch2];
			l_motor = -vexRT[Ch1] + vexRT[Ch2];

			// Constrain values
			if(r_motor > 127) r_motor = 127;
			if(r_motor < -127) r_motor = -127;
			if(l_motor > 127) l_motor = 127;
			if(l_motor < -127) l_motor = -127;
		}

		// Set motor speed
		motor[right_motor] = r_motor;
		motor[left_motor] = l_motor;

		delay(50);
	}
}
