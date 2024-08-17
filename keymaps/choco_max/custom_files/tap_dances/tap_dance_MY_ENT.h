// ================= MY_ENT TAPDANCE ================
static tap ent_tap_state = {
  .is_press_action = true,
  .state = 0
};
// -------------------------------------------------------
void ent_finished (tap_dance_state_t *state, void *user_data);
void ent_fx_reset (tap_dance_state_t *state, void *user_data);
// -------------------------------------------------------
//Functions that control what our tap dance key does
void ent_finished (tap_dance_state_t *state, void *user_data) {
  ent_tap_state.state = ma_cur_dance(state);
  switch (ent_tap_state.state) {
    case SINGLE_TAP:
      // // if (IS_LAYER_ON(_ACCENTS)) {
      // //   SS_DOWN(X_LSFT);
      // //   tap_code(KC_ENT);
      // //   SS_UP(X_LSFT);
      // // } else {
      //   tap_code(KC_ENT);
      // // }

      if (IS_LAYER_ON(_ACCENTS)) {
        SEND_STRING(SS_LSFT(SS_TAP(X_ENT)));
      } else {
        tap_code(KC_ENT);
      }
      break;
    case SINGLE_HOLD:
      if (IS_LAYER_ON(_ACCENTS)) {
        layer_on(_RGB);
      } else {
        layer_on(_REG_SPE);
      }
      // TODO moi
      // register_mods(MOD_BIT_LSHIFT);
      // add_mods(MOD_BIT_LSHIFT);
      // tap_code(KC_PSCR);
      // TODO moi
      break;
    // case DOUBLE_TAP: 
    //   //check to see if the layer is already set
    //   if (layer_state_is(_CAPS_LOCK)) {
    //     //if already set, then switch it off
    //     layer_off(_CAPS_LOCK);
    //   } else { 
    //     //if not already set, then switch the layer on
    //     layer_on(_CAPS_LOCK);
    //   }
    //   break;
    // // case DOUBLE_HOLD:
    // //   tap_code(KC_M);
  }
}
// -------------------------------------------------------
void ent_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (ent_tap_state.state==SINGLE_HOLD) {
    layer_off(_REG_SPE);
    layer_off(_RGB);
  }
  ent_tap_state.state = 0;
}
// ================= END MY_ENT TAPDANCE ================