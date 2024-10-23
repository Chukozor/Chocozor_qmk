// ================= NAV_F_KEYS TAPDANCE ================
bool nav_already_activated = false;
bool trace_op_nav = false;
bool combo_nav_activated = false;
bool nav_verrouillee= false;
// -------------------------------------------------------
static tap nav_tap_state = {
  .is_press_action = true,
  .state = 0
};
// -------------------------------------------------------
void nav_finished (tap_dance_state_t *state, void *user_data);
void nav_reset (tap_dance_state_t *state, void *user_data);
// -------------------------------------------------------
void nav_finished (tap_dance_state_t *state, void *user_data) {
  nav_tap_state.state = ma_cur_dance(state);
  switch (nav_tap_state.state) {
    case SINGLE_TAP: 
      set_oneshot_layer(_OP_NAV, ONESHOT_START);
      break;
    case DOUBLE_TAP: 
      if (IS_LAYER_ON(_NAV) && !combo_nav_activated) {
        layer_off(_NAV);
      } else { 
        layer_move(_COLEMAK_FR);
        layer_on(_NAV);
        nav_verrouillee = true;
      }
      break;
    case SINGLE_HOLD:
      if (IS_LAYER_ON(_NAV)) {
        nav_already_activated = true;
      } else {
        nav_already_activated = false;
      }
      layer_on(_NAV);
      break;
    case DOUBLE_HOLD:
      layer_on(_F_KEYS);
      break;
    default:
      break;
  }
}
// -------------------------------------------------------
void nav_reset (tap_dance_state_t *state, void *user_data) {
  switch (nav_tap_state.state) {
    case SINGLE_TAP: 
      clear_oneshot_layer_state(ONESHOT_PRESSED);
      break;
    case SINGLE_HOLD:
      if (!nav_already_activated && !combo_nav_activated) {
        layer_off(_NAV);
      }
      break;
    case DOUBLE_HOLD:
      layer_off(_F_KEYS);
      break;
  }
  if (trace_op_nav == true) {
    layer_off(_NAV);
    trace_op_nav = false;
  }
  nav_tap_state.state = 0;
}
// ================= END NAV_F_KEYS TAPDANCE ================