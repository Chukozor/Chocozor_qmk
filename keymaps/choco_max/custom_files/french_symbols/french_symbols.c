#include "action.h"
#include "action_util.h"

void tap_e_grave(void) {
	tap_code(KC_7);
}

void tap_e_aigue(void) {
	tap_code(KC_2);
}

void tap_e_circ(void) {
  tap_code(KC_LBRC);
	tap_code(KC_E);
}

void tap_c_ced(void) {
	tap_code(KC_9);
}

void tap_a_grave(void) {
	tap_code(KC_0);
}

void tap_a_circ(void) {
  tap_code(KC_LBRC);
	tap_code(KC_Q);
}

void tap_i_circ(void) {
  tap_code(KC_LBRC);
	tap_code(KC_I);
}

void tap_i_trema(void) {
	register_code(KC_LSFT);
  tap_code(KC_LBRC);
  unregister_code(KC_LSFT);
	tap_code(KC_I);
}

void tap_u_grave(void) {
	tap_code(KC_QUOTE);
}

void tap_u_circ(void) {
  tap_code(KC_LBRC);
	tap_code(KC_U);
}

void tap_o_circ(void) {
  tap_code(KC_LBRC);
	tap_code(KC_O);
}
