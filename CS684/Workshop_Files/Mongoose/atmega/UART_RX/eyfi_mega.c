/*
* 
* Name:           eYFi-Mega Header file (eyfi_mega.c)
* Version:        0.1
* Author Name:    e-Yantra Team (Rutuja Ekatpure, Kalind Karia)
* Last Modified:  24-01-2020
* 
*/


#include "eyfi_mega.h"


/**************************************************************************************************
								void rgb_led_init()
***************************************************************************************************
* 
* Input arguments:  None
* Return value:     None
* Description:      Initialize the RGB LED (Common Anode) Port Pins and initially turn it OFF
* 
***************************************************************************************************/
void rgb_led_init()
{
    // update the data directions of RED_LED_PIN, GREEN_LED_PIN, BLUE_LED_PIN as OUTPUT
    update_bit( RGB_LED_DDR_REG, RED_LED_PIN, PIN_OUTPUT );
    update_bit( RGB_LED_DDR_REG, GREEN_LED_PIN, PIN_OUTPUT );
    update_bit( RGB_LED_DDR_REG, BLUE_LED_PIN, PIN_OUTPUT );
    
    // update the initial state of RED_LED_PIN, GREEN_LED_PIN, BLUE_LED_PIN as OFF
    // the RGB LED is Common Anode type
    update_bit( RGB_LED_PORT_REG, RED_LED_PIN, PIN_HIGH );
    update_bit( RGB_LED_PORT_REG, GREEN_LED_PIN, PIN_HIGH );
    update_bit( RGB_LED_PORT_REG, BLUE_LED_PIN, PIN_HIGH );
}


/**************************************************************************************************
								void red_led_on()
***************************************************************************************************
* 
* Input arguments:  None
* Return value:     None
* Description:      Turn the RED LED ON
* 
***************************************************************************************************/
void red_led_on()
{
    // update the state of RED_LED_PIN as ON
    // the RGB LED is Common Anode type
    update_bit( RGB_LED_PORT_REG, RED_LED_PIN, PIN_LOW );
}


/**************************************************************************************************
								void red_led_off()
***************************************************************************************************
* 
* Input arguments:  None
* Return value:     None
* Description:      Turn the RED LED OFF
* 
***************************************************************************************************/
void red_led_off()
{
    // update the state of RED_LED_PIN as OFF
    // the RGB LED is Common Anode type
    update_bit( RGB_LED_PORT_REG, RED_LED_PIN, PIN_HIGH );
}


/**************************************************************************************************
								void green_led_on()
***************************************************************************************************
* 
* Input arguments:  None
* Return value:     None
* Description:      Turn the GREEN LED ON
* 
***************************************************************************************************/
void green_led_on()
{
    // update the state of GREEN_LED_PIN as ON
    // the RGB LED is Common Anode type
    update_bit( RGB_LED_PORT_REG, GREEN_LED_PIN, PIN_LOW );
}


/**************************************************************************************************
								void green_led_off()
***************************************************************************************************
* 
* Input arguments:  None
* Return value:     None
* Description:      Turn the GREEN LED OFF
* 
***************************************************************************************************/
void green_led_off()
{
    // update the state of GREEN_LED_PIN as OFF
    // the RGB LED is Common Anode type
    update_bit( RGB_LED_PORT_REG, GREEN_LED_PIN, PIN_HIGH );
}


/**************************************************************************************************
								void blue_led_on()
***************************************************************************************************
* 
* Input arguments:  None
* Return value:     None
* Description:      Turn the BLUE LED ON
* 
***************************************************************************************************/
void blue_led_on()
{
    // update the state of BLUE_LED_PIN as ON
    // the RGB LED is Common Anode type
    update_bit( RGB_LED_PORT_REG, BLUE_LED_PIN, PIN_LOW );
}


/**************************************************************************************************
								void blue_led_off()
***************************************************************************************************
* 
* Input arguments:  None
* Return value:     None
* Description:      Turn the BLUE LED OFF
* 
***************************************************************************************************/
void blue_led_off()
{
    // update the state of BLUE_LED_PIN as OFF
    // the RGB LED is Common Anode type
    update_bit( RGB_LED_PORT_REG, BLUE_LED_PIN, PIN_HIGH );
}


/**************************************************************************************************
								void user_sw_init()
***************************************************************************************************
* 
* Input arguments:  None
* Return value:     None
* Description:      Initialize the USER_SW (Push Button) Port Pin and activate its pull-up resistor
* 
***************************************************************************************************/
void user_sw_init()
{
    // update the data directions of USER_SW_PIN as INPUT
    update_bit( USER_SW_DDR_REG, USER_SW_PIN, PIN_INPUT );
    
    // activate the pull-up resistor of USER_SW_PIN
    update_bit( USER_SW_PORT_REG, USER_SW_PIN, PIN_HIGH );
}


/**************************************************************************************************
							unsigned char get_user_sw_status()
***************************************************************************************************
* 
* Input arguments:  None
* Return value:     None
* Description:      Get the USER_SW (Push Button) Pin status whether it is in released state
* 
***************************************************************************************************/
unsigned char get_user_sw_status()
{
    // get the USER_SW (Push Button) status whether it is in released state
    return get_bit_status( USER_SW_PIN_REG, USER_SW_PIN );
}


/**************************************************************************************************
				void adc_input(unsigned char *channels, unsigned char no_channels)
***************************************************************************************************
* 
* Input arguments:  Array of channels, Number of Channels
* Return value:     None
* Description:      Initialize all ADC channel pins as Input
* 
***************************************************************************************************/
void adc_input(unsigned char *channels, unsigned char no_channels)
{
    int i;
    
    // Initialise all channels as Input
    for (i = 0; i < no_channels; i++)
    {
        if (channels[i] > 15);
        // Initialise DDRF Register if channels is less than 9
        else if (channels[i] < 8)
            update_bit(ADC_DDR_REG_LOW, channels[i], PIN_LOW);
        
        // Initialise DDRk Register if channels is greater than 8
        else
            update_bit(ADC_DDR_REG_HIGH, channels[i], PIN_LOW);
    }
}


/**************************************************************************************************
								void adc_init()
***************************************************************************************************
* 
* Input arguments:  None
* Return value:     None
* Description:      Initialize the ADC with left adjustment result readout
* 
***************************************************************************************************/
void adc_init()
{
    // Disable Analog Comparator; else ADC wont work
    update_bit(ACSR, ACD, PIN_HIGH);
    
    // Enable Left Adjustment to read only 8 bit data from 10 bit ADC
    update_bit(ADMUX, ADLAR, PIN_HIGH);
    
    // (turn ADC ON) | (set prescalar to 64 110)
    ADCSRA |= ( get_bit_mask(ADEN) | get_bit_mask(ADPS2) | get_bit_mask(ADPS1) );
}


/**************************************************************************************************
				unsigned char get_adc_channel_data(unsigned char channel_no)
***************************************************************************************************
* 
* Input arguments:  Channel Number
* Return value:     ADC 8 bit Converted data
* Description:      Get the input from the channel and convert to digital form
* 
***************************************************************************************************/
unsigned char get_adc_channel_data(unsigned char channel_no)
{
    // Declare a variable to store the converted data
    unsigned char a;
    
    // Extract Last 3 bits from Ch for ADMUX
	channel_no = channel_no & 0b00000111; //0x07
	// (Left Adjusted Output) | (ADMUX4:0)
	ADMUX = 0x20 | channel_no; 
	
	// If channel number is greater than 7 then SET MUX5
	if(channel_no > 7){
		update_bit(ADCSRB, MUX5, PIN_HIGH); // set MUX5 = 1
	}
	
	//Start Conversion 
	update_bit(ADCSRA, ADSC, PIN_HIGH);
	
	// Wait for ADC conversion to complete; ADIF = 0, conversion going on; ADIF = 1, conversion complete
	while(is_bit_cleared(ADCSRA, ADIF));
	
	// store ADC value in variable.
	a = ADCH;
	
	// ADIF is set when ADC conversion is complete and Data Registers are updated
	// ADIF needs to be cleared before starting next conversion. Clear ADIF (ADC Interrupt Flag) by writing 1
	update_bit(ADCSRA, ADIF, PIN_HIGH); 
	// clear MUX5 so that other ADC channels can use this function
	update_bit(ADCSRB, MUX5, PIN_LOW);
	
	return a;
}