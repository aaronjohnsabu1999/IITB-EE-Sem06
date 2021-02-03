#include "mgos.h"

int LED_PIN = 18;

static void blink(void *arg) {
	static bool s_tick_tock = true;
	LOG(LL_INFO, ("%s", (s_tick_tock ? "Tick" : "Tock")));
	s_tick_tock = !s_tick_tock;
	mgos_gpio_toggle(LED_PIN);
}

enum mgos_app_init_result mgos_app_init(void) {
	
	mgos_gpio_setup_output(LED_PIN, 0);

	mgos_set_timer(500, MGOS_TIMER_REPEAT, blink, NULL);						// mgos_set_time(int msecs, int flags, timer_callback cb, void *cb_arg); msecs = delay, cb = callback function
	// mgos_set_hw_timer(2000000, MGOS_TIMER_REPEAT, blink, NULL);				// mgos_set_time(int usecs, int flags, timer_callback cb, void *cb_arg); usecs = delay, cb = callback function

	return MGOS_APP_INIT_SUCCESS;
}