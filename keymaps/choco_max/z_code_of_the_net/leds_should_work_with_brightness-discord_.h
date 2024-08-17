bool rgb_matrix_indicators_user(void) {
  HSV hsv;
  RGB rgb; 
  #ifdef RGB_MATRIX_ENABLE
    switch (get_highest_layer(layer_state 1 | default_layer_state)) {
      case _GAME:
        hsv = (HSV){255, 255, rgb_matrix_get_val()};
        rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
        break;
      case _CAPS_LOCK:
        hsv = (HSV){170, 255, rgb_matrix_get_val()};
        rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
        break;
      default:
        if (host_keyboard_led_state().caps_lock) {
          hsv = (HSV){85, 255, rgb_matrix_get_val()};
          rgb = hsv_to_rgb(hsv);
          rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b); 
        }
        break; 
    }
  #endif
  return false; 
} 

