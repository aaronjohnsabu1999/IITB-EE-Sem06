/*
 * TITLE:
 * DATE:
 * AUTHOR:
 */ 


#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

void rgb_led_init()
{
	DDRH  = DDRH &  0xC7;
	DDRE  = DDRE &  0x7F;

	PORTE = PORTE | 0x80;
}

int main(void) {

	rgb_led_init();
	while(1){


	}

	return 0;	
}
