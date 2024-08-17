void my_copy(void) {
  add_mods(MOD_BIT_LCTRL);
  tap_code(KC_C);
  unregister_mods(MOD_BIT_LCTRL);
}

void my_cut(void) {
  add_mods(MOD_BIT_LCTRL);
  tap_code(KC_X);
  unregister_mods(MOD_BIT_LCTRL);
}

void my_paste(void) {
  add_mods(MOD_BIT_LCTRL);
  tap_code(KC_V);
  unregister_mods(MOD_BIT_LCTRL);
}

void my_undo_down(void) {
  add_mods(MOD_BIT_LCTRL);
  SEND_STRING(SS_DOWN(X_W));// KC_W = FR_Z
  // tap_code(KC_W);
}

void my_undo_up(void) {
  SEND_STRING(SS_UP(X_W));
  unregister_mods(MOD_BIT_LCTRL);
}

void my_redo_down(void) {
  add_mods(MOD_BIT_LCTRL);
  SEND_STRING(SS_DOWN(X_Y));
  // tap_code(KC_W);
}

void my_redo_up(void) {
  SEND_STRING(SS_UP(X_Y));
  unregister_mods(MOD_BIT_LCTRL);
}

void my_save(void) {
  add_mods(MOD_BIT_LCTRL);
  tap_code(KC_S);
  unregister_mods(MOD_BIT_LCTRL);
}

void my_selec_all(void) {
  SEND_STRING(SS_LCTL("q"));// select all (KC_Q = KC_A en francais)
}