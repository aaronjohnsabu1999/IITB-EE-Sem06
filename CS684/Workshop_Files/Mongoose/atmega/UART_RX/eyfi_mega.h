
/*
* 
* Name:           eYFi-Mega Header file (eyfi_mega.h)
* Version:        0.1
* Author Name:    e-Yantra Team (Rutuja Ekatpure, Kalind Karia)
* Last Modified:  24-01-2020
* 
*/


#ifndef _eyfi_mega_h_
#define _eyfi_mega_h_


// F_CPU definition for eYFi-Mega development board
#define F_CPU 16000000UL


/**************************************************************************************************
								Include Necessary Header Files
***************************************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

/**************************************************************************************************/


/***************************************************************************************************
								Macros for Bit Manipulation
****************************************************************************************************/

#define get_bit_mask(bit)                 ( 1 << (bit) )
#define set_bit(x,bit)                    ( (x) |=  get_bit_mask(bit) )
#define clear_bit(x,bit)                  ( (x) &= ~get_bit_mask(bit) )
#define toggle_bit(x,bit)                 ( (x) ^=  get_bit_mask(bit) )
#define update_bit(x,bit,val)             ( (val) ? set_bit(x,bit) : clear_bit(x,bit) )

#define get_bit_status(x,bit)             ( ((x) & (get_bit_mask(bit))) != 0 )
#define is_bit_set(x,bit)                 ( ((x) & (get_bit_mask(bit))) != 0 )
#define is_bit_cleared(x,bit)             ( ((x) & (get_bit_mask(bit))) == 0 )

#define are_all_bits_set(x,bit_mask)      ( ((x) & (bit_mask)) == bit_mask )
#define are_any_bit_set(x,bit_mask)       ( ((x) & (bit_mask)) != 0x00 )

/**************************************************************************************************/


/**************************************************************************************************
								Common Constants Definition
***************************************************************************************************/

// Data Direction for any Port Pin
#define PIN_OUTPUT  			0x01
#define PIN_INPUT   			0x00

// Data Direction for complete Port
#define PORT_OUTPUT  		0xFF
#define PORT_INPUT   		0x00

// Status to be set on Port Pin
#define PIN_HIGH    			0x01
#define PIN_LOW     			0x00

// Status to be set on Port Pin
#define PORT_HIGH    		0xFF
#define PORT_LOW     		0x00

// Pin definitions for RGB LED (Common Anode)
#define RGB_LED_DDR_REG		DDRH
#define RGB_LED_PORT_REG   PORTH
#define RED_LED_PIN        PH3
#define GREEN_LED_PIN      PH5
#define BLUE_LED_PIN       PH4

// Pin definitions for USER_SW (Push Button)
#define USER_SW_DDR_REG    DDRE
#define USER_SW_PORT_REG   PORTE
#define USER_SW_PIN_REG    PINE
#define USER_SW_PIN        PE7

// Pin definitions for ADC channels on PORT F (Channels 0 to 7)
#define ADC_DDR_REG_LOW    DDRF
#define ADC_PORT_REG_LOW   PORTF
#define Channel_0          PF0
#define Channel_1          PF1
#define Channel_2          PF2
#define Channel_3          PF3
#define Channel_4          PF4
#define Channel_5          PF5
#define Channel_6          PF6
#define Channel_7          PF7

// Pin definitions for ADC channels on PORT K (Channels 8 to 15)
#define ADC_DDR_REG_HIGH   DDRK
#define ADC_PORT_REG_HIGH  PORTK
#define Channel_8          PK0
#define Channel_9          PK1
#define Channel_10         PK2
#define Channel_11         PK3
#define Channel_12         PK4
#define Channel_13         PK5
#define Channel_14         PK6
#define Channel_15         PK7

/**************************************************************************************************/


/***************************************************************************************************
									  Function Prototypes
***************************************************************************************************/

// Definitions for RGB LED (Common Anode Type)
void rgb_led_init();
void red_led_on();
void red_led_off();
void green_led_on();
void green_led_off();
void blue_led_on();
void blue_led_off();

// Definitions for USER_SW (Push Button)
void user_sw_init();
unsigned char get_user_sw_status();

// Definitions for ADC
void adc_input(unsigned char *channels, unsigned char no_channels);
void adc_init();
unsigned char get_adc_channel_data(unsigned char channel_no);

/**************************************************************************************************/


#endif