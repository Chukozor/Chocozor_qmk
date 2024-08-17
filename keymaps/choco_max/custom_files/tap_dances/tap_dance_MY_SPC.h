// ================= NAV_F_KEYS TAPDANCE ================
// bool nav_already_activated = false;
// -------------------------------------------------------
static tap spc_tap_state = {
  .is_press_action = true,
  .state = 0
};
// -------------------------------------------------------
void spc_finished (tap_dance_state_t *state, void *user_data);
void spc_reset (tap_dance_state_t *state, void *user_data);
// -------------------------------------------------------
void spc_finished (tap_dance_state_t *state, void *user_data) {
  spc_tap_state.state = ma_cur_dance(state);
  switch (spc_tap_state.state) {
    case SINGLE_TAP: 
      tap_code(KC_SPC);
      break;
    // case DOUBLE_TAP: 
    //   if (IS_LAYER_ON(_NAV)) {
    //     layer_off(_NAV);
    //   } else { 
    //     layer_move(_COLEMAK_FR);
    //     layer_on(_NAV);
    //   }
    //   break;
    case SINGLE_HOLD:
      // if (IS_LAYER_ON(_NAV)) {
      //   nav_already_activated = true;
      // } else {
      //   nav_already_activated = false;
      // }
      set_oneshot_layer(_ACCENTS, ONESHOT_START);
      break;
    // case DOUBLE_HOLD:
    //   layer_on(_F_KEYS);
    //   break;
    default:
      break;
  }
}
// -------------------------------------------------------
void spc_reset (tap_dance_state_t *state, void *user_data) {
  switch (spc_tap_state.state) {
    // case SINGLE_TAP: 
    //   clear_oneshot_layer_state(ONESHOT_PRESSED);
    //   break;
    case SINGLE_HOLD:
      clear_oneshot_layer_state(ONESHOT_PRESSED);
      break;
    // case DOUBLE_HOLD:
    //   layer_off(_F_KEYS);
    //   spc_tap_state.state = 0;
    //   break;
  }
  spc_tap_state.state = 0;
}
// ================= END NAV_F_KEYS TAPDANCE ================