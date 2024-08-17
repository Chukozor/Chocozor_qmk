// // This is a thin wrapper around rgb_matrix_set_color which allows you to put
// // the same firmware on both halves of the keyboard (other than a #define for
// // `MASTER_LEFT` or `MASTER_RIGHT`) and still have the correct LEDs light up
// // regardless of which half has the USB cable in it.
// //
// // This complexity behind this logic is explained in the comments within the
// // function itself.
// void set_color_split(uint8_t index_code, uint8_t r, uint8_t g, uint8_t b) {
// // When using defines for MASTER_LEFT and MASTER_RIGHT, is_keyboard_left()
// // will be inaccurate. For example, (is_keyboard_left() &&
// // !is_keyboard_master()) can NEVER be true.
//   #ifdef MASTER_LEFT
//     bool is_left = true;
//   #endif
//   #ifdef MASTER_RIGHT
//     bool is_left = false;
//   #endif

//   bool left_is_master = (is_keyboard_master() && is_left) || (!is_keyboard_master() && !is_left);

//   // Note on constants: 23 is the number of LEDs on each side (24) minus 1.
//   // 27 is the number of LEDs that the Corne normally has with six columns.

//   // Rule #1: you must set the LED based on what the master's range is. So if
//   // the USB cable is in the left half, then the range is 0-23, otherwise it's
//   // 27-50.

//   // Rule #2: each half of the keyboard can only set its own LEDs, it's just
//   // that the codes change according to Rule #1.

//   // Rule #2
//   if ((is_left && index_code >= 27) || (!is_left && index_code < 27)) {
//     return;
//   }

//   // Rule #1
//   if (left_is_master && index_code >= 27)
//     index_code -= 27;
//   else if (!left_is_master && index_code < 27)
//     index_code += 27;
//   rgb_matrix_set_color(index_code, r, g, b);
// }

// ==========================================================
// actual function for leds on layers
// #include <stdio.h>
int  index_deplacement_gaming_leds[] = {19, 16, 11, 15, 43, 46, 49};
size_t size_deplacement_gaming_leds  = sizeof(index_deplacement_gaming_leds) / sizeof(index_deplacement_gaming_leds[0]);

int  index_CapsLock_leds[] = {18, 17, 16, 15, 44, 43, 45};
size_t size_CapsLock_leds     = sizeof(index_CapsLock_leds) / sizeof(index_CapsLock_leds[0]);

bool rgb_matrix_indicators_user(void) {
  HSV hsv;
  RGB rgb;
  #ifdef RGB_MATRIX_ENABLE
    switch (get_highest_layer(layer_state)) {
      // case _COLEMAK_FR:
      //   rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
      //   break;
      case _GAME:
        hsv = (HSV){255, 255, rgb_matrix_get_val()};
        rgb = hsv_to_rgb(hsv);
        for (int i = 0; i < size_deplacement_gaming_leds; ++i) {
          // rgb_matrix_set_color(index_deplacement_gaming[i], rgb.r, rgb.g, rgb.b);
          rgb_matrix_set_color(index_deplacement_gaming_leds[i], rgb.r, rgb.g, rgb.b);
        }
        break;
      case _AUX_GAME:
        hsv = (HSV){170, 255, rgb_matrix_get_val()};
        rgb = hsv_to_rgb(hsv);
        for (int i = 0; i < size_CapsLock_leds; ++i) {
          // rgb_matrix_set_color(index_deplacement_gaming[i], rgb.r, rgb.g, rgb.b);
          rgb_matrix_set_color(index_CapsLock_leds[i], rgb.r, rgb.g, rgb.b);
        }
        break;
      case _MOUSE_LAYER:
        hsv = (HSV){140, 255, rgb_matrix_get_val()};
        rgb = hsv_to_rgb(hsv);
        for (int i = 6; i <= 26; ++i) {
          // rgb_matrix_set_color(index_deplacement_gaming[i], rgb.r, rgb.g, rgb.b);
          rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
          rgb_matrix_set_color(i+27, rgb.r, rgb.g, rgb.b);
        }
        break;
      case _CAPS_LOCK:
        hsv = (HSV){215, 255, rgb_matrix_get_val()};
        rgb = hsv_to_rgb(hsv);
        for (int i = 6; i <= 26; ++i) {
          // rgb_matrix_set_color(index_deplacement_gaming[i], rgb.r, rgb.g, rgb.b);
          rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
          rgb_matrix_set_color(i+27, rgb.r, rgb.g, rgb.b);
        }
        break;
      // case _NAV:
      //   hsv = (HSV){45, 255, rgb_matrix_get_val()};
      //   rgb = hsv_to_rgb(hsv);
      //   for (int i = 6; i <= 26; ++i) {
      //     // rgb_matrix_set_color(index_deplacement_gaming[i], rgb.r, rgb.g, rgb.b);
      //     rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      //     rgb_matrix_set_color(i+27, rgb.r, rgb.g, rgb.b);
      //   }
      //   break;
    }
  #endif
  return false;
}