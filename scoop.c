
task scoop()
{
	int r_motor = 0;
	int l_motor = 0;

	for(;;)
	{
		// Set servo position
	if(vexRT[Btn6U])
	{
		motor[shovel] = 100;
	}
	if(vexRT[Btn6D])
	{
		motor[shovel] = 0;
	}
		delay(50);
	}
}
