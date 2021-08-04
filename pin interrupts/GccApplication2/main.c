/*
 * Interrupt
 *
 * Created: 09/04/2021 12:13:24
 * Author : Muthomi
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#define LED_ON  PINB |= (1<<PINB7)
#define LED_OFF  PINB &= ~(1<<PINB7)
#define LED_TOGGLE  PINH |= (1<<PINH5)//external LED
#define SWITCH !(PINB & (1<<PINB4))

//interrupt function
ISR(PCINT0_vect){
	if (SWITCH)
	{
		LED_ON;
		LED_TOGGLE;
	}
	else
	{
		LED_OFF;
	}
}

int main(void)
{
    /* Replace with your application code */
	DDRB |= (1<<DDB7);
	DDRB &= ~ (1<<DDB4);
	DDRH |= (1<<DDH5);

	//low power mode section
	//PRR = 0xFF;
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	
	//pin change interrupts.
	PCMSK0 |= (1<<PCINT4); 
	PCICR  |= (1<<PCIE0);
	
	sei();
    while (1) 
    {
		sleep_mode(); //initializes sleep mode
		//LED_ON;
		//_delay_ms(300);
		
		/*
		if (!(PINB & (1<<PINB4)))
		{
			LED_ON;
			LED_TOGGLE;
		} 
		else
		{
			LED_OFF;
		}
		*/
		
		
    }
}

