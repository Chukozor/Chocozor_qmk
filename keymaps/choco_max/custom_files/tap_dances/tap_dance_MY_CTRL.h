// ================= MY_CTRL TAPDANCE ================
bool capslock_was_activated = false;
// -------------------------------------------------------
static tap ctrl_tap_state = {
  .is_press_action = true,
  .state = 0
};
// -------------------------------------------------------
void ctrl_finished (tap_dance_state_t *state, void *user_data);
void ctrl_fx_reset (tap_dance_state_t *state, void *user_data);
// -------------------------------------------------------
//Functions that control what our tap dance key does
void ctrl_finished (tap_dance_state_t *state, void *user_data) {
  ctrl_tap_state.state = ma_cur_dance(state);
  switch (ctrl_tap_state.state) {
    case SINGLE_TAP:
      if (game_mode == false) {
        layer_invert(_WEB_BROWSER);
      }
      break;   
    case SINGLE_HOLD:
      if (layer_state_is(_CAPS_LOCK)) {
        capslock_was_activated = true;
        layer_clear();
        layer_move(_COLEMAK_FR);
      }
      SEND_STRING(SS_DOWN(X_LCTL));
      break;
  }
}
// -------------------------------------------------------
void ctrl_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  switch (ctrl_tap_state.state) {
    // case SINGLE_TAP:
    //   layer_off(_REG_SPE);
    //   layer_off(_RGB);
    //   break;
    case SINGLE_HOLD:
      if (capslock_was_activated) {
        layer_on(_CAPS_LOCK);
        capslock_was_activated = false;
      }
      SEND_STRING(SS_UP(X_LCTL));
      break;
  }
  ctrl_tap_state.state = 0;
}
// ================= END MY_ENT TAPDANCE ================