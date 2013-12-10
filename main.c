#include <msp430.h> 
#include "RobotSensing.h"
#include "movement.h"
/*
 * main.c
 */


int main(void) {

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    initSensors();

        for (;;)
      {
    	LeftSensorScan();
        if (ADC10MEM < 0x2FF)
//        	Stop();
        	RobotMovement(LEFT);
//        	_delay_cycles(200000);
        CenterSensorScan();
        if (ADC10MEM > 0x200)
//        	Stop();
        	RobotMovement(RIGHT);                      // Set P1.0 LED on
//        	_delay_cycles(200000);
        	else
        		Stop();
        		RobotMovement(FORWARD);
        		_delay_cycles(200000);

      }
        return 0;
}
