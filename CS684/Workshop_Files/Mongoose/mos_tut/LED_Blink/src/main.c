#include "mgos.h"

int LED_PIN = 18;

enum mgos_app_init_result mgos_app_init(void) {
	
	mgos_gpio_set_mode(LED_PIN, MGOS_GPIO_MODE_OUTPUT);				// MGOS_GPIO_MODE_OUTPUT = 1
	// mgos_gpio_setup_output(LED_PIN, 0);							// Assigns LED_PIN as OUTPUT and sets initial value as 0 (0V) instead of 1 (5V)

	mgos_gpio_write(LED_PIN, 0);									// Sets initial value of LED_PIN value as 0
	mgos_msleep(5000);												// Sets delay of 5000ms
	mgos_gpio_write(LED_PIN, 1);									// Sets initial value of LED_PIN value as 1
	mgos_msleep(5000);												// Sets delay of 5000ms

	return MGOS_APP_INIT_SUCCESS;
}