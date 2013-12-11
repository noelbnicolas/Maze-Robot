Maze Robot
==========

This library uses the RobotMovement Library and SensorsCode Library in order to use the IR sensors to move a robot through a maze.

Functions
=========

void initTimer()

  * This function is used in order to initialize TA0 and TA1 timers
  * TAO/1 CRR0 are used for the period of the pulse width
  * OUTMOD_5 is used for half cycles

  
Move the Right Motor Forward
============================
void moveRightMotorForward()
{
	TA0CCTL0 &= ~(OUTMOD_7);
 	TA0CCTL0 |= OUTMOD_5;
 	_delay_cycles(10000);
 	TA0CCTL1 &= ~(OUTMOD_7);
 	TA0CCTL1 |= OUTMOD_4;        
}

  * TA0 1 and 0 are used for the connections to the right motor. Applying power to 1 and ground to 0 will move the right motor forward while switching power and ground will send the motor back.

Move the Left Motor Forward
============================

void moveLeftMotorForward()
{
	TA1CCTL0 &= ~(OUTMOD_7);
 	TA1CCTL0 |= OUTMOD_5;
 	_delay_cycles(10000);
 	TA1CCTL1 &= ~(OUTMOD_7);
 	TA1CCTL1 |= OUTMOD_4;       
}

  * TA1 1 and 0 are used for the connections to the left motor. Applying power to 1 and ground to 0 will move the left motor forward while switching power and ground will send the motor back.
  

Move the Robot Forward
=======================

void RobotMovement(unsigned char direction)

  * The RobotMovement chooses the direction of the whole robot by using both motors
  * moveLeftMotorForward() and moveRightMotorForward() will cause the whole robot to move forward
  
void initSensors();

  *This initializes the sensors by enabling the ADC10 interupt and selecting SMCLK

  
Get reading from center sensor
============================
  *int CenterSensorScan(){
  *        ADC10CTL0 &= ~ENC;                                                        //Clear
  *       ADC10CTL1 = INCH_3;                       // input A3
  *       ADC10AE0 |= BIT3;                         // PA.1 ADC option select
  *        ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
  *        __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
  *    return ADC10MEM;
  *}

  * The left and right sensor have a similar code with the differences on the channels
  * First the sensor is cleared and a reading is taken which return the reading from the sensor(ADC10MEM)
  
Documentation: C2C Schriner explained his right wall following, and I used the same concept for my left wall following code. 
  
