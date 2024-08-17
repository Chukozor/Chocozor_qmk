#include "action.h"
#include "action_util.h"

void tap_e_grave(void) {
	add_mods(MOD_BIT_LALT);
	tap_code(KC_KP_1);
	tap_code(KC_KP_3);
	tap_code(KC_KP_8);
	unregister_mods(MOD_BIT_LALT);
}

void tap_e_aigue(void) {
	add_mods(MOD_BIT_LALT);
	tap_code(KC_KP_1);
	tap_code(KC_KP_3);
	tap_code(KC_KP_0);
	unregister_mods(MOD_BIT_LALT);
}

void tap_e_circ(void) {
	add_mods(MOD_BIT_LALT);
	tap_code(KC_KP_1);
	tap_code(KC_KP_3);
	tap_code(KC_KP_6);
	unregister_mods(MOD_BIT_LALT);
}

void tap_c_ced(void) {
	add_mods(MOD_BIT_LALT);
	tap_code(KC_KP_1);
	tap_code(KC_KP_3);
	tap_code(KC_KP_5);
	unregister_mods(MOD_BIT_LALT);
}

void tap_a_grave(void) {
	add_mods(MOD_BIT_LALT);
	tap_code(KC_KP_1);
	tap_code(KC_KP_3);
	tap_code(KC_KP_3);
	unregister_mods(MOD_BIT_LALT);
}

void tap_a_circ(void) {
	add_mods(MOD_BIT_LALT);
	tap_code(KC_KP_1);
	tap_code(KC_KP_3);
	tap_code(KC_KP_1);
	unregister_mods(MOD_BIT_LALT);
}

void tap_i_circ(void) {
	add_mods(MOD_BIT_LALT);
	tap_code(KC_KP_1);
	tap_code(KC_KP_4);
	tap_code(KC_KP_0);
	unregister_mods(MOD_BIT_LALT);
}

void tap_i_trema(void) {
	add_mods(MOD_BIT_LALT);
	tap_code(KC_KP_0);
	tap_code(KC_KP_2);
	tap_code(KC_KP_3); 
	tap_code(KC_KP_9); 
	unregister_mods(MOD_BIT_LALT);
}

void tap_u_grave(void) {
	add_mods(MOD_BIT_LALT);
	tap_code(KC_KP_1);
	tap_code(KC_KP_5);
	tap_code(KC_KP_1);
	unregister_mods(MOD_BIT_LALT);
}

void tap_u_circ(void) {
	add_mods(MOD_BIT_LALT);
	tap_code(KC_KP_1);
	tap_code(KC_KP_5);
	tap_code(KC_KP_0);
	unregister_mods(MOD_BIT_LALT);
}

void tap_o_circ(void) {
	add_mods(MOD_BIT_LALT);
	tap_code(KC_KP_1);
	tap_code(KC_KP_4);
	tap_code(KC_KP_7);
	unregister_mods(MOD_BIT_LALT);
}
