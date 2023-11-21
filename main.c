#pragma config(Motor,  port1,           left_motor,    tmotorVex393_HBridge, openLoop, driveLeft)
#pragma config(Motor,  port9,           scoop_servo,   tmotorNone, openLoop)
#pragma config(Motor,  port10,          right_motor,   tmotorVex393_HBridge, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "tracks.c"
#include "scoop.c"

task main()
{
	// Start all control tasks
	startTask(tracks);
	startTask(scoop);

	// Keep program running
	for(;;)
	{
		wait1Msec(1);
	}
}
