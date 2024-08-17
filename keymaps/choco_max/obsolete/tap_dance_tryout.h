// --------------------------TAP DANCE FEATURES------------------------------
typedef struct {
  bool is_press_action;
  int state;
} tap;

//Define a type for as many tap dance states as you need
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

enum {
  TD_CAPS_LCK = 0,     //Our custom tap dance key; add any other tap dance keys to this enum
  TD_NAV_KEYS,
  TD_ENT
};

int cur_dance (tap_dance_state_t *state);

void nav_finished (tap_dance_state_t *state, void *user_data);
void nav_reset (tap_dance_state_t *state, void *user_data);

int ma_cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    if (!state->pressed) {
      return DOUBLE_TAP;
    } else {
      return DOUBLE_HOLD;
    }
  }
  else return 8;
}

static tap nav_tap_state = {
  .is_press_action = true,
  .state = 0
};

void nav_finished (tap_dance_state_t *state, void *user_data) {
  nav_tap_state.state = ma_cur_dance(state);
  switch (nav_tap_state.state) {
    case SINGLE_TAP: 
      set_oneshot_layer(_OP_NAV, ONESHOT_START);
      break;
    case DOUBLE_TAP: 
      if (layer_state_is(_NAV)) {
        layer_off(_NAV);
      } else { 
        layer_move(_COLEMAK_FR);
        layer_on(_NAV);
      }
      break;
    case SINGLE_HOLD:
      if (IS_LAYER_ON(_NAV)) {
        nav_already_activated = true;
      }
        layer_on(_NAV);
        break;
    case DOUBLE_HOLD:
      layer_on(_F_KEYS);
      break;
  }
}

void nav_reset (tap_dance_state_t *state, void *user_data) {
  if (nav_tap_state.state==SINGLE_TAP) {
    clear_oneshot_layer_state(ONESHOT_PRESSED);
  }
  if (nav_tap_state.state==SINGLE_HOLD) {
    if (!nav_already_activated) {
      layer_off(_NAV);
    }
  }
  if (nav_tap_state.state==DOUBLE_HOLD) {
    layer_off(_F_KEYS);
  }
  nav_tap_state.state = 0;
}

#include "other_tap_dances.h"

//Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
  [TD_CAPS_LCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_finished, sft_reset)
  ,[TD_NAV_KEYS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_finished, nav_reset)
  ,[TD_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_finished, ent_reset)
};
// --------------------------END OF TAP DANCE FEATURES------------------------------

#define MY_NAV TD(TD_NAV_KEYS)
#define MY_LSFT TD(TD_CAPS_LCK)
#define MY_ENT TD(TD_ENT)
