// ================= SHIFT TAPDANCE ================
static tap sft_tap_state = {
  .is_press_action = true,
  .state = 0
};
// -------------------------------------------------------
void sft_finished (tap_dance_state_t *state, void *user_data);
void sft_reset (tap_dance_state_t *state, void *user_data);
// -------------------------------------------------------
//Functions that control what our tap dance key does
void sft_finished (tap_dance_state_t *state, void *user_data) {
  sft_tap_state.state = ma_cur_dance(state);
  switch (sft_tap_state.state) {
    // case SINGLE_TAP: 
    //   tap_code(KC_QUOT);
    //   break;
    case SINGLE_TAP: 
      //check to see if the layer is already set
      if (layer_state_is(_CAPS_LOCK)) {
        //if already set, then switch it off
        layer_off(_CAPS_LOCK);
        caps_lock_activated = false;
      } else if (game_mode == false) {
        //if not already set, then switch the layer on
        layer_on(_CAPS_LOCK);
        caps_lock_activated = true;
      } else {
        // on fait rien si on est en "game mode"
      }
      break;    
    case SINGLE_HOLD: 
      // layer_on(_SFT_COLEMAK_FR);
      layer_on(_COLEMAK_FR);
      // TODO moi
      register_mods(MOD_BIT_LSHIFT);
      // add_mods(MOD_BIT_LSHIFT);
      // tap_code(KC_PSCR);
      // TODO moi
      shift_activated = true;
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
    // case DOUBLE_HOLD:
    //   tap_code(KC_M);
  }
}
// -------------------------------------------------------
void sft_reset (tap_dance_state_t *state, void *user_data) {
  switch (sft_tap_state.state) {
    // case SINGLE_TAP:
    //   caps_lock_activated = false;
    //   break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT_LSHIFT);
      shift_activated = false;
      break;
  }
  sft_tap_state.state = 0;
}

// ================= END SHIFT TAPDANCE ================