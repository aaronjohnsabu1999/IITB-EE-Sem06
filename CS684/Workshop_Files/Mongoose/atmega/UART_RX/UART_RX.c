#include "eyfi_mega.h"
#include "oled.h"
#include "uart.h"

char print_buffer[100];
uint16_t rx_byte;

uint8_t sensorVal = 140;
char buffer[8];

int main(void) {

	uart0_init(UART_BAUD_SELECT(115200, F_CPU));
	uart0_flush();
	uart0_puts("ATMega 2560 UART0 says Hi \n");

	sprintf(buffer, "%d\n", sensorVal);

	oled_init(OLED_DISP_ON);    	// init oled and turn on
	oled_clrscr();

	oled_charMode(DOUBLESIZE);
	oled_puts("e-Yantra");  		// put string from RAM to display (TEXTMODE) or buffer (GRAPHICMODE)

	oled_charMode(NORMALSIZE);

	rgb_led_init();
	
	while(1){

		uart0_puts(buffer);
		
		_delay_ms(500);

		rx_byte = uart0_getc();
		if(rx_byte != UART_NO_DATA){

			rx_byte = rx_byte & 0x00FF;
			uart0_putc((char)rx_byte);

			oled_gotoxy(0,3);          		// set cursor to first column at line 4
			oled_putc((char)rx_byte);

			switch ((char)rx_byte)
			{
				case 'R':
				{
					red_led_on();
					green_led_off();
					blue_led_off();
					break;
				}
				
				case 'G':
				{
					green_led_on();
					red_led_off();
					blue_led_off();
					break;
				}
				
				case 'B':
				{
					blue_led_on();
					red_led_off();
					green_led_off();
					break;
				}
				
				case 'Y':
				{
					red_led_on();
					green_led_on();
					blue_led_off();
					break;
				}
				
				case 'C':
				{
					green_led_on();
					blue_led_on();
					red_led_off();
					break;
				}
				
				case 'M':
				{
					red_led_on();
					blue_led_on();
					green_led_off();
					break;
				}
				
				case 'W':
				{
					red_led_on();
					green_led_on();
					blue_led_on();
					break;
				}

				default:
				{
					break;
				}
			}
		}

	}

	return 0;	
}