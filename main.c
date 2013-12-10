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
		if (ADC10MEM > 0x200)

			RobotMovement(RIGHT);                      // Set P1.0 LED on
			RobotMovement(REVERSE);
			LeftSensorScan();
        if (ADC10MEM > 0x2A0)
        	RobotMovement(RIGHT);
        	RobotMovement(REVERSE);

        RightSensorScan();
         if (ADC10MEM < 0x2A0)
             RobotMovement(LEFT);
         	 RobotMovement(REVERSE);



      }
        return 0;
}
