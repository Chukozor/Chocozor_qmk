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

// -------------------------------------------------------
//Function associated with all tap dances
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
// -------------------------------------------------------
#include "tap_dance_MY_LSFT.h"
#include "tap_dance_MY_NAV.h"
#include "tap_dance_MY_ENT.h"
#include "tap_dance_MY_CTRL.h"
#include "tap_dance_MY_SPC.h"
// -------------------------------------------------------
enum {
  TD_CAPS_LCK = 0,     //Our custom tap dance key; add any other tap dance keys to this enum
  TD_NAV_KEYS,
  TD_SPC,
  TD_ENT,
  TD_LCTL
};
//Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
  [TD_CAPS_LCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_finished, sft_reset)
  ,[TD_NAV_KEYS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_finished, nav_reset)
  ,[TD_SPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, spc_finished, spc_reset)
  ,[TD_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_finished, ent_reset)
  ,[TD_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_finished, ctrl_reset)
};
// -------------------------------------------------------
#define MY_LSFT TD(TD_CAPS_LCK)
#define MY_NAV TD(TD_NAV_KEYS)
#define MY_SPC TD(TD_SPC)
#define MY_ENT TD(TD_ENT)
// #define MY_LCTL TD(TD_LCTL)

// -------------------------------------------------------




// UNE AUTRE DANCE : ==================
// int cur_dance (tap_dance_state_t *state); 
// -------------------------------------------------------
// UN TYPE DE DANCE :
// int cur_dance (tap_dance_state_t *state) {
//   if (state->count == 1) {
//     if (!state->pressed) {
//       return SINGLE_TAP;
//     } else {
//       return SINGLE_HOLD;
//     }
//   } else if (state->count == 2) {
//     return DOUBLE_TAP;
//   }
//   else return 8;
// }
// -------------------------------------------------------

// /* Return an integer that corresponds to what kind of tap dance should be executed.
//  *
//  * How to figure out tap dance state: interrupted and pressed.
//  *
//  * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
//  *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
//  *
//  * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
//  *  has ended, but the key is still being pressed down. This generally means the key is being "held".
//  *
//  * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
//  *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
//  *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
//  *
//  * Good places to put an advanced tap dance:
//  *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
//  *
//  * Criteria for "good placement" of a tap dance key:
//  *  Not a key that is hit frequently in a sentence
//  *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
//  *    in a web form. So 'tab' would be a poor choice for a tap dance.
//  *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
//  *    letter 'p', the word 'pepper' would be quite frustating to type.
//  *
//  * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
//  *
//  */
// int cur_dance (tap_dance_state_t *state) {
//   if (state->count == 1) {
//     if (state->interrupted || !state->pressed)  return SINGLE_TAP;
//     //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
//     else return SINGLE_HOLD;
//   }
//   else if (state->count == 2) {
//     /*
//      * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
//      * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
//      * keystrokes of the key, and not the 'double tap' action/macro.
//     */
//     if (state->interrupted) return DOUBLE_SINGLE_TAP;
//     else if (state->pressed) return DOUBLE_HOLD;
//     else return DOUBLE_TAP;
//   }
//   //Assumes no one is trying to type the same letter three times (at least not quickly).
//   //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
//   //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
//   if (state->count == 3) {
//     if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
//     else return TRIPLE_HOLD;
//   }
//   else return 8; //magic number. At some point this method will expand to work for more presses
// }

// FIN D'UNE AUTRE DANCE : ==================