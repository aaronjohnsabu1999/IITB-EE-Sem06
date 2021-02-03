#include "mgos.h"
#include "mgos_pwm.h"

#define R_PIN 23
#define G_PIN 22
#define B_PIN 21

int i = 0;
const int n_colors = 4;

void setLED(int r_lvl, int b_lvl, int g_lvl) {
  mgos_gpio_write(R_PIN, r_lvl);
  mgos_gpio_write(G_PIN, b_lvl);
  mgos_gpio_write(B_PIN, g_lvl);
}

void glowRed() {
  LOG(LL_INFO, ("Glowing red"));
  setLED(0, 1, 1);
}

void glowGreen() {
  LOG(LL_INFO, ("Glowing green"));
  setLED(1, 0, 1);
}

void glowBlue() {
  LOG(LL_INFO, ("Glowing blue"));
  setLED(1, 1, 0);
}

void glowOff() {
  LOG(LL_INFO, ("Glowing off"));
  setLED(1, 1, 1);
}

void blink() {
  int color = i++ % n_colors;
  if (color == 0) {
    glowRed();
  }
  else if (color == 1) {
    glowGreen();
  }
  else if (color == 2) {
    glowBlue();
  }
  else if (color == 3) {
    glowOff();
  }
}

enum mgos_app_init_result mgos_app_init(void) {
  mgos_gpio_set_mode(R_PIN, MGOS_GPIO_MODE_OUTPUT);
  mgos_gpio_set_mode(G_PIN, MGOS_GPIO_MODE_OUTPUT);
  mgos_gpio_set_mode(B_PIN, MGOS_GPIO_MODE_OUTPUT);

  setLED(1, 1, 1);
  
  mgos_pwm_set(R_PIN, mgos_sys_config_get_color_synth_freq(), 1.0 - mgos_sys_config_get_color_synth_r_int() / 255.0);
  mgos_pwm_set(G_PIN, mgos_sys_config_get_color_synth_freq(), 1.0 - mgos_sys_config_get_color_synth_g_int() / 255.0);
  mgos_pwm_set(B_PIN, mgos_sys_config_get_color_synth_freq(), 1.0 - mgos_sys_config_get_color_synth_b_int() / 255.0);

  // mgos_set_timer(1000, true, blink, NULL);

  return MGOS_APP_INIT_SUCCESS;
}