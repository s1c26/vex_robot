//
// tracks.c
//
// Controls tracks
//

const int MOTOR_COOLDOWN = 50;
const int MOTOR_MAX = 127;

task tracks()
{
	int r_motor = 0;
	int l_motor = 0;

	for(;;)
	{
		// Read joystick
		r_motor = vexRT[Ch2] - vexRT[Ch1];
		l_motor = vexRT[Ch2] + vexRT[Ch1];

		// Constrain values
		if(r_motor > MOTOR_MAX) r_motor = MOTOR_MAX;
		if(r_motor < -MOTOR_MAX) r_motor = -MOTOR_MAX;
		if(l_motor > MOTOR_MAX) l_motor = MOTOR_MAX;
		if(l_motor < -MOTOR_MAX) l_motor = -MOTOR_MAX;

		// Set motor speed
		motor[right_motor] = r_motor;
		motor[left_motor] = l_motor;

		// Small delay to prevent motor speed from changing too quickly
		wait1Msec(MOTOR_COOLDOWN);
	}
}
