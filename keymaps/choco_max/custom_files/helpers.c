#include "quantum.h"
#include "../keymap.h"

bool is_accent_layer(void) {
  return IS_LAYER_ON(_ACCENTS);
}

// bool is_accent_layer(void) {
//   return IS_LAYER_ON(_ACCENTS);
// }

// bool is_shift_layer(void) {
//   return shift_activated == true;
// }

// bool is_caps_layer(void) {
//   return caps_lock_activated == true;
// }

// bool is_maj_layer(void) {
//   return (shift_activated == true|| caps_lock_activated == true) ;
// }

bool is_colemak_layer(void) {
  return IS_LAYER_ON(_COLEMAK_FR);
}