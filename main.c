#include <msp430.h> 
#include "RobotSensing.h"
#include "movement.h"
/*
 * main.c
 */


int main(void) {

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    initTimer();
    initSensors();
    RobotMovement(LEFT);
        for (;;)
      {

       		CenterSensorScan();
       		if (ADC10MEM > 0x3BB)
       			RobotMovement(SHARPRIGHT);
       	        else if (ADC10MEM < 0x200)
       	   			RobotMovement(REVERSE);

        	LeftSensorScan();
        	if (ADC10MEM > 0x2DD)
				RobotMovement(RIGHT);
				else if (ADC10MEM < 0x2CC)
					RobotMovement(LEFT);
					RobotMovement(REVERSE);



      }
        return 0;
}
