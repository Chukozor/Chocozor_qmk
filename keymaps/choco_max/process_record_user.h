// ==============================================
//           SCROLLING WITH TRACKPAD
// ------------ For 40mm TRACKPAD ---------------
// Modify these values to adjust the scrolling speed
float aux_dpi = 0;
#define SCROLL_DIVISOR_H_BASE 45.0   // Horizontal scroll speed
#define SCROLL_DIVISOR_V_BASE 25.0   // Vertical scroll speed

float scroll_divisor_h = SCROLL_DIVISOR_H_BASE;
float scroll_divisor_v = SCROLL_DIVISOR_V_BASE;

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;
// -------
// VOLUME CONTROL WITH TRACKPAD
// Define how sensitive the trackpad is for volume control
#define VOLUME_DIVISOR 18  // Adjust for volume control sensitivity (higher = more movement required)
#define VOLUME_THRESHOLD 1  // Threshold for triggering volume change

// ------------ For 35mm TRACKPAD ---------------
// // Modify these values to adjust the scrolling speed
// #define SCROLL_DIVISOR_H 30.0   // Horizontal scroll speed
// #define SCROLL_DIVISOR_V 15.0   // Vertical scroll speed

// // Variables to store accumulated scroll values
// float scroll_accumulated_h = 0;
// float scroll_accumulated_v = 0;
// // -------
// // VOLUME CONTROL WITH TRACKPAD
// // Define how sensitive the trackpad is for volume control
// #define VOLUME_DIVISOR 15.0  // Adjust for volume control sensitivity (higher = more movement required)
// #define VOLUME_THRESHOLD 1.0  // Threshold for triggering volume change
// -------------------------------------------------

// Variables to store accumulated volume movement
float volume_accumulated_v = 0;
// -------------------------------------------------
// -------------------------------------------------

// #include "timer.h"
// static uint8_t nav_interrupted = 0;
// static bool spc_is_held = false;
bool alt_tab_menu = false;
bool ky_webnav = false;
bool ky_spc = false;
bool set_scrolling = false;
bool web_aux = false;

#include "custom_files/functions_record_user.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // #include "obsolete/my_old_accents_char.h"
    // #include "obsolete/my_old_specials_char.h"
    #include "custom_files/french_symbols/my_accents_char_precuser.h"
    #include "custom_files/my_specials_char_precuser.h"
    // #include "custom_files/french_symbols/accents_for_combo.h"

    case MY_PRT_S:
      if (record->event.pressed) {
        tap_code(KC_PSCR);
        // here we override its «press» behavior (hence, return false)
        return false;
      } else {
        // here we don't alter its «release» default behavior (hence, return true)
        return true;
      }
      break;

    case MY_PRT_Z:
      if (record->event.pressed) {
        add_mods(MOD_BIT_RCTRL);
        tap_code(KC_PSCR);
        unregister_mods(MOD_BIT_RCTRL);
        // here we override its «press» behavior (hence, return false)
        return false;
      } else {
        // here we don't alter its «release» default behavior (hence, return true)
        return true;
      }
      break;

    case MY_PRT_P:
      if (record->event.pressed) {
        add_mods(MOD_BIT_LSHIFT);
        tap_code(KC_PSCR);
        unregister_mods(MOD_BIT_LSHIFT);
        // here we override its «press» behavior (hence, return false)
        return false;
      } else {
        // here we don't alter its «release» default behavior (hence, return true)
        return true;
      }
      break;

    case MY_COMENT:
      if (record->event.pressed) {
        add_mods(MOD_BIT_RCTRL);
        tap_code(KC_DOT);
        unregister_mods(MOD_BIT_RCTRL);
        // here we override its «press» behavior (hence, return false)
        return false;
      } else {
        // here we don't alter its «release» default behavior (hence, return true)
        return true;
      }
      break;

    case MY_COPY:
      if (record->event.pressed) {
        my_copy();
      }
      return false;
      
    case MY_CUT:
      if (record->event.pressed) {
        my_cut();
      }
      return false;

    case MY_PASTE:
      if (record->event.pressed) {
        my_paste();
      }
      return false;

    case MY_UNDO:
      if (record->event.pressed) {
        my_undo_down();
      } else {
        my_undo_up();
      }
      return false;

    case MY_REDO:
      if (record->event.pressed) {
        my_redo_down();
      } else {
        my_redo_up();
      }
      return false;

    case MY_SAVE:
      if (record->event.pressed) {
        my_save();
      }
      return false;

    case CSTM_ENT:
      if (record->tap.count) { // Tap
        if (record->event.pressed) {
          // your logic when pressed
          if (is_accent_layer()) {
            SEND_STRING(SS_LSFT(SS_TAP(X_ENT)));
          } else {
            tap_code(KC_ENT);
          }
        }
      } else { // Hold
        if (record->event.pressed) { // pressed
          // if (!record->tap.interrupted) {
            if (is_accent_layer()) {
              // layer_on(_RGB);
            } else {
              layer_on(_REG_SPE);
            }
          // } 
        //   else { // interrupted
        //     if (is_accent_layer()) {
        //       layer_on(_RGB);
        //     } else {
        //       layer_on(_CAPS_LOCK);
        //     }
        //   }
        }
        else { // released
          layer_off(_REG_SPE);
          // layer_off(_RGB);
        }
        return false;
      }
      return false;

    // case HT_SPC:
    //   if (record->tap.count) { // tapped
    //     if (!record->event.pressed) {
    //       // your logic when released
    //       return false;
    //     }
    //     if (is_colemak_layer()) {
    //       tap_code(KC_SPC);
    //     } else {
    //       // tap_code(KC_NO);
    //       tap_code(KC_SPC);
    //     }
    //     // if (is_accent_layer()) {
    //     // 	tap_e_aigue();
    //     // } else {
    //     // 	tap_code(KC_SPC);
    //     // }
    //     // spc_is_held = false;
    //   } else { // held
    //     if (record->event.pressed) {
    //       if (record->tap.interrupted) {
    //       // if (is_colemak_layer()) {
    //         layer_on(_ACCENTS);
    //       // } else {
    //       //   tap_code(KC_NO);
    //       // }
    //       } else {
    //         layer_on(_ACCENTS);
    //       }
    //       // spc_is_held = true;
    //     } else if (!record->event.pressed) {
    //       // SEND_STRING(SS_DELAY(300));
    //       layer_off(_ACCENTS);
    //       return false;
    //       // spc_is_held = false;
    //     }
    //   }
    //   return false;

    // case MY_ESC:
    //   if (record->event.pressed) {
    //     tap_code(KC_ESC);
    //     // soft_reset_keyboard();
    //     // eeconfig_init();
    //     clear_mods();
    //     layer_clear();
    //     nav_already_activated = false;
    //     capslock_was_activated = false;
    //     alt_tab_menu = false;
    //     ky_webnav = false;
    //     caps_lock_activated = false;
    //     shift_activated = false;
    //     trace_op_nav = false;
    //     // spc_is_held = false;
    //     layer_move(_COLEMAK_FR);
    //   } else {
    //     // nothing needed here
    //   }
    //   return false;

    case WEB_D:
      // if (spc_is_held) {
      //   if (record->event.pressed) {
      //     my_copy();
      //   }
      //   return false;
      // } else {
      if (get_mods() != MOD_BIT(KC_LALT)) {
        if (record->event.pressed) {
          register_code(KC_LCTL);
        } else {
          unregister_code(KC_LCTL);
        }
      }
      if (web_aux){
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_WFWD));
        } else {
          SEND_STRING(SS_UP(X_WFWD));
        }
      } else {
        if (record->event.pressed) {
          tap_code(KC_TAB);
        }
      }
      return false;

    case WEB_G:
      // if (spc_is_held) {
      //   if (record->event.pressed) {
      //     my_selec_all();
      //   }
      //   return false;
      // } else {
      if (get_mods() != MOD_BIT(KC_LALT)) {
        if (record->event.pressed) {
          register_code(KC_LCTL);
        } else {
          unregister_code(KC_LCTL);
        }
      }
      
      if (web_aux){
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_WBAK));
        } else {
          SEND_STRING(SS_UP(X_WBAK));
        }
      } else {
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_TAP(X_TAB)));
        }
      }
      return false;

    case WEB_TAB:
      if (record->tap.count) { // tapped
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL));
          SEND_STRING(SS_DELAY(1));
          SEND_STRING(SS_TAP(X_Z));// CTRL + W, ici Z pcq langue francaise KC_Z = FR_W
          SEND_STRING(SS_UP(X_LCTL));
        }
      } else { // held
        if (record->event.pressed) {
          // if (record->tap.interrupted) {
          // } else {
          //   layer_on(_ACCENTS);
          // }
          SEND_STRING(SS_DOWN(X_LCTL));
          SEND_STRING(SS_DOWN(X_LSFT));
          SEND_STRING(SS_DELAY(1));
          SEND_STRING(SS_TAP(X_T));
          SEND_STRING(SS_UP(X_LSFT));
          SEND_STRING(SS_UP(X_LCTL));
        }
      }
      return false;

    case SEL_ALL:
      if (record->event.pressed) {
        my_selec_all();
      }
      return false;

    case TEST1:
      if (record->event.pressed) {
        // À (a majuscule accent) = Ctrl + Alt + 7 puis Maj + A (le 7 est celui situé en haut du clavier et non celui du pavé numérique)
        SEND_STRING(SS_DOWN(X_LCTL));
        SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_DELAY(1));
        SEND_STRING(SS_TAP(X_7));
        SEND_STRING(SS_UP(X_LALT));
        SEND_STRING(SS_UP(X_LCTL));
        SEND_STRING(SS_LSFT(SS_TAP(X_Q)));// KC_Q = FR_A 
      }
      return false;

    case TEST2:
      if (record->event.pressed) {
        // É (e majuscule accent aigu) = Ctrl + 4 puis Maj + E
        SEND_STRING(SS_DOWN(X_LCTL));
        // SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_DELAY(1));
        SEND_STRING(SS_TAP(X_4));
        // SEND_STRING(SS_UP(X_LALT));
        SEND_STRING(SS_LSFT(SS_TAP(X_E)));// KC_Q = FR_A 
        SEND_STRING(SS_UP(X_LCTL));
      }
      return false;

    case TEST3:
      if (record->event.pressed) {
        // È (e majuscule accent grave) = Ctrl + Alt + 7 puis Maj + E
        SEND_STRING(SS_DOWN(X_LCTL));
        SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_DELAY(1));
        SEND_STRING(SS_TAP(X_7));
        SEND_STRING(SS_UP(X_LALT));
        SEND_STRING(SS_UP(X_LCTL));
        SEND_STRING(SS_LSFT(SS_TAP(X_E)));
      }
      return false;

    case TEST4:
      if (record->event.pressed) {
        // Ç (c cédille majuscule) = Ctrl+, puis Maj + C
        SEND_STRING(SS_DOWN(X_LCTL));
        // SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_DELAY(1));
        SEND_STRING(SS_TAP(X_M));// KC_M = "FR_VIRGULE"
        // SEND_STRING(SS_UP(X_LALT));
        SEND_STRING(SS_UP(X_LCTL));
        SEND_STRING(SS_LSFT(SS_TAP(X_C)));
      }
      return false;

    case TEST5:
      if (record->event.pressed) {
        // Ê = Ctrl + Alt + 9 puis Maj + E (le 9 est celui situé en haut du clavier et non celui du pavé numérique)
        SEND_STRING(SS_DOWN(X_LSFT));
        SEND_STRING(SS_DOWN(X_RSFT));
        SEND_STRING(SS_DELAY(1));
        SEND_STRING(SS_TAP(X_LBRC));
        SEND_STRING(SS_UP(X_RSFT));
        SEND_STRING(SS_UP(X_LSFT));
        SEND_STRING(SS_TAP(X_E));
        // SEND_STRING(SS_LSFT(SS_TAP(X_E)));
      }
      return false;

    case MY_ALT_T:
      if (record->event.pressed) {
        alt_tab_menu = true;
        SEND_STRING(SS_DOWN(X_LALT));
        tap_code(KC_TAB);
      } else {
        SEND_STRING(SS_UP(X_LALT));
        alt_tab_menu = false;
      }
      return false;

    case KY_P1:
      if (record->event.pressed) {
        if (alt_tab_menu) {
          tap_code(KC_LEFT);
        } else {
          tap_code(KC_P1);
        }
      }
      return false;

    case KY_P2:
      if (record->event.pressed) {
        if (alt_tab_menu) {
          tap_code(KC_DOWN);
        } else {
          tap_code(KC_P2);
        }
      }
      return false;

    case KY_P3:
      if (record->event.pressed) {
        if (alt_tab_menu) {
          tap_code(KC_RIGHT);
        } else {
          tap_code(KC_P3);
        }
      }
      return false;

    case KY_P5:
      if (record->event.pressed) {
        if (alt_tab_menu) {
          tap_code(KC_UP);
        } else {
          tap_code(KC_P5);
        }
      }
      return false;

    case KY_P8:
      if (record->event.pressed) {
        if (alt_tab_menu) {
          tap_code(KC_DEL);
        } else {
          tap_code(KC_P8);
        }
      }
      return false;

    case KY_WEBNAV:
      if (record->event.pressed) {
        ky_webnav = true;
        SEND_STRING(SS_DOWN(X_LCTL));
        // tap_code(KC_TAB);
      } else {
        SEND_STRING(SS_UP(X_LCTL));
        ky_webnav = false;
      }
      return false;

    case KY_SPC:
      if (record->event.pressed) {
        ky_spc = true;
        // SEND_STRING(SS_DOWN(X_LCTL));
        // tap_code(KC_TAB);
      } else {
        // SEND_STRING(SS_UP(X_LCTL));
        ky_spc = false;
      }
      return false;
    
    case KY_LEFT:
      if (ky_webnav) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LSFT));
          SEND_STRING(SS_DOWN(X_TAB));
        } else {
          SEND_STRING(SS_UP(X_TAB));
          SEND_STRING(SS_UP(X_LSFT));
        }
      } else if (ky_spc) {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LSFT));
          SEND_STRING(SS_DOWN(X_SPC));
        } else {
          SEND_STRING(SS_UP(X_SPC));
          SEND_STRING(SS_UP(X_LSFT));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LEFT));
        } else {
          SEND_STRING(SS_UP(X_LEFT));
        }
      }
      return false;
    
    case KY_RIGHT:
      if (ky_webnav) {
        if (record->event.pressed) {
          // SEND_STRING(SS_DOWN(X_LSFT));
          SEND_STRING(SS_DOWN(X_TAB));
        } else {
          SEND_STRING(SS_UP(X_TAB));
          // SEND_STRING(SS_UP(X_LSFT));
        }
      } else if (ky_spc) {
        if (record->event.pressed) {
          // SEND_STRING(SS_DOWN(X_LSFT));
          SEND_STRING(SS_DOWN(X_SPC));
        } else {
          SEND_STRING(SS_UP(X_SPC));
          // SEND_STRING(SS_UP(X_LSFT));
        }
      } else {
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_RIGHT));
        } else {
          SEND_STRING(SS_UP(X_RIGHT));
        }
      }
      return false;

    case MY_NAV_FROM_OP:
      if (record->event.pressed) {
        layer_on(_NAV);
        trace_op_nav = true;
      } else {
        layer_off(_NAV);
      }
      // layer_move(_COLEMAK_FR);
      // set_oneshot_layer(_NAV, ONESHOT_START);
      return false;

    case TG_GAME:
      if (record->event.pressed) {
          // logic when pressed
          if (game_mode == false) {
            game_mode = true;
            layer_on(_GAME);
          } else if (IS_LAYER_ON(_COLEMAK_FR)) {
            layer_on(_GAME);
          } else {
            game_mode = false;
            layer_off(_GAME);
          }
        } else {
          // logic when released
        }
      return false;

    case FAST_SWITCH_GAME_COLEMAK:
      if (game_mode == true) {
        if (record->event.pressed) {
          layer_invert(_GAME);
        }
        return false;
      } else {
        if (record->event.pressed) {
          // logic when pressed
          SEND_STRING(SS_DOWN(X_LCTL));
          SEND_STRING(SS_DOWN(X_LSFT));
          // SEND_STRING(SS_DELAY(1));
          // SEND_STRING(SS_TAP(X_T));
        } else {
          SEND_STRING(SS_UP(X_LCTL));
          SEND_STRING(SS_UP(X_LSFT));
          // logic when released
        }
        // press(MY_LCTL AND MY_LSFT)
        return false;
      }

    case HALF_PAGE_DOWN:
      if (IS_LAYER_ON(_WEB_BROWSER)) {
        if (record->event.pressed) {
          if (get_mods() != MOD_BIT(KC_LALT)) {
            if (record->event.pressed) {
              register_code(KC_LCTL);
              SEND_STRING(SS_TAP(X_TAB));
              unregister_code(KC_LCTL);
            } else {
            SEND_STRING(SS_TAP(X_TAB));
            }
          }
        }
      } else {
        if (record->event.pressed) {
          // Send multiple KC_DOWN keycodes to simulate "half page down"
          for (int i = 0; i < 10; i++) { // Adjust 10 to the number of lines you want to scroll
              tap_code(KC_DOWN);
          }
        }
      }
      return false; // Skip further processing of this key

    case HALF_PAGE_UP:
      if (IS_LAYER_ON(_WEB_BROWSER)) {
        if (record->event.pressed) {
          if (get_mods() != MOD_BIT(KC_LALT)) {
            if (record->event.pressed) {
              register_code(KC_LCTL);
              SEND_STRING(SS_LSFT(SS_TAP(X_TAB)));
              unregister_code(KC_LCTL);
            } else {
            SEND_STRING(SS_TAP(X_TAB));
            }
          }
        }
      } else {
        if (record->event.pressed) {
          // Send multiple KC_DOWN keycodes to simulate "half page down"
          for (int i = 0; i < 10; i++) { // Adjust 10 to the number of lines you want to scroll
              tap_code(KC_UP);
          }
        }
      }
      return false; // Skip further processing of this key

    case WEB_OFF:
      if (IS_LAYER_ON(_WEB_BROWSER)) {
        layer_off(_WEB_BROWSER);
      }
      return false;

    case DPI_INC: /* Increase trackpad DPI*/
      if (record->event.pressed) {
        pointing_device_set_cpi(pointing_device_get_cpi()+100);
      }
      return false;
    case DPI_DEC: /* Decrease trackpad DPI*/
      if (record->event.pressed) {
        pointing_device_set_cpi(pointing_device_get_cpi()-100);
      }
      return false;
    case K_SNIPE: /* Decrease trackpad DPI*/
      if (record->event.pressed) {
        if (get_mods() == MOD_BIT(KC_LCTL)) {
          unregister_mods(MOD_BIT_LCTRL);
          alt_tab_menu = true;
          SEND_STRING(SS_DOWN(X_LALT));
          tap_code(KC_TAB);
          wait_ms(5);
          SEND_STRING(SS_UP(X_LALT));
        } else if (set_scrolling || IS_LAYER_ON(_F_KEYS)) {
          aux_dpi = pointing_device_get_cpi();
          pointing_device_set_cpi(200);
          scroll_divisor_h =  SCROLL_DIVISOR_H_BASE * 2.0;
          scroll_divisor_v =  SCROLL_DIVISOR_V_BASE * 2.0;
        } else {
          pointing_device_set_cpi(pointing_device_get_cpi()-300);
        }
      } else {
        if (set_scrolling || IS_LAYER_ON(_F_KEYS)) {
          pointing_device_set_cpi(aux_dpi);
          scroll_divisor_h = SCROLL_DIVISOR_H_BASE;
          scroll_divisor_v = SCROLL_DIVISOR_V_BASE;
        } else {
          if (alt_tab_menu == true) {
            alt_tab_menu = false;
          } else {
            pointing_device_set_cpi(pointing_device_get_cpi()+300);
          }
        }
      }
      return false;

    case K_BLITZ: /* Decrease trackpad DPI*/
      if (set_scrolling || IS_LAYER_ON(_F_KEYS)) {
        if (record->event.pressed) {
          aux_dpi = pointing_device_get_cpi();
          pointing_device_set_cpi(1000);
          scroll_divisor_h = SCROLL_DIVISOR_H_BASE / 2.0;
          scroll_divisor_v = SCROLL_DIVISOR_V_BASE / 2.0;
        } else {
          pointing_device_set_cpi(aux_dpi);
          scroll_divisor_h = SCROLL_DIVISOR_H_BASE;
          scroll_divisor_v = SCROLL_DIVISOR_V_BASE;
        }
      } else if (record->event.pressed) {
        pointing_device_set_cpi(pointing_device_get_cpi()+300);
      } else {
        pointing_device_set_cpi(pointing_device_get_cpi()-300);
      }
      return false;
    
    case K_SCROL:
      if (record->event.pressed) {
        set_scrolling = true;
      } else {
        set_scrolling = false;
      }
      return false;
    
    case MO_NUMPAD:
      if (record->event.pressed) {
        combo_nav_activated = true;
        layer_on(_NAV);
      } else if (!nav_verrouillee) {
        layer_off(_NAV);
        combo_nav_activated = false;
      }
      return false;
    
    case DBL_SHIFT:
      if (record->event.pressed) {
        if (layer_state_is(_CAPS_LOCK)) {
          //if already set, then switch it off
          layer_off(_CAPS_LOCK);
          caps_lock_activated = false;
        } else if (game_mode == false) {
          //if not already set, then switch the layer on
          layer_on(_CAPS_LOCK);
          caps_lock_activated = true;
        }
      }
      return false;

    case ZOOM_TR:
      if (record->event.pressed) {
          // logic when pressed
          set_scrolling = true;
          SEND_STRING(SS_DOWN(X_LCTL));
          // SEND_STRING(SS_DOWN(X_LSFT));
          // SEND_STRING(SS_DELAY(1));
          // SEND_STRING(SS_TAP(X_T));
        } else {
          set_scrolling = false;
          SEND_STRING(SS_UP(X_LCTL));
          // SEND_STRING(SS_UP(X_LSFT));
          // logic when released
        }
        // press(MY_LCTL AND MY_LSFT)
        return false;

    case AUX_WEB:
      if (record->event.pressed) {
          // logic when pressed
          web_aux = true;
          SEND_STRING(SS_DOWN(X_WFWD));
        } else {
          web_aux = false;
          SEND_STRING(SS_UP(X_WFWD));
        }
        return false;
        
    case TG_SCROL:
      if (record->event.pressed) {
          // logic when pressed
          set_scrolling = !set_scrolling;
        }
        return false;

    case MY_ESC:
      if (record->tap.count) { // Tap
        if (record->event.pressed) {
          // logic when pressed
          tap_code(KC_ESC);
          // soft_reset_keyboard();
          // eeconfig_init();
        } else {
          // logic when released
        }
      } else { // Hold
        if (record->event.pressed) {
          clear_mods();
          layer_clear();
          nav_already_activated = false;
          capslock_was_activated = false;
          alt_tab_menu = false;
          ky_webnav = false;
          caps_lock_activated = false;
          shift_activated = false;
          trace_op_nav = false;
          game_mode = false;
          set_scrolling = false;
          nav_verrouillee = false;
          combo_nav_activated = false;
          web_aux = false;
          // spc_is_held = false;
          layer_move(_COLEMAK_FR);
          if (record->tap.interrupted) {
            // logic when interrupted
          } else {
            // logic when not interrupted
          }
        } else {
          // logic when released
        }
      }
      return false;
  }
  return true;
}


#define WEB_BROWSER_LAYER_TIMEOUT 10000  //configure your timeout in milliseconds

void matrix_scan_user(void) {
  if (IS_LAYER_ON(_WEB_BROWSER)) {
    if (last_input_activity_elapsed() > WEB_BROWSER_LAYER_TIMEOUT) {
      layer_off(_WEB_BROWSER);
    }
  }
}

// void matrix_scan_user(void) {
//   if (get_highest_layer(layer_state) == _WEB_BROWSER) {
//     if (last_input_activity_elapsed() > WEB_BROWSER_LAYER_TIMEOUT) {
//       layer_off(_WEB_BROWSER);
//     }
//   }
// }

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case SFT_T(KC_SPC):
        //    return g_tapping_term + 1250;
        case MY_ESC:
            return 200;
        case MY_LSFT:
            return 160;
        case HT_SPC:
            return 210;
        case MY_NAV:
            return 180;
        case HT_A:
            return 200;
        case HT_E:
            return 160;
        case MY_BNAV:
            return 230;
        case WEB_TAB:
            return 230;
        default:
            return g_tapping_term;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HT_E:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case HT_I:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case HT_U:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case HT_O:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        case HT_A:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        default:
            // Force the dual-role key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return true;
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // // decide by combo->keycode
    // switch (combo->keycode) {
    //     case KC_X:
    //         return 50;
    // }

    // or with combo index, i.e. its name from enum.
    switch (index) {
        case COMBO_OSM_SHIFT:
          return 50;
        case FAST_SWITCH_GAME_COLEMAK:
          return 50;
        case COMBO_ACTIVE_NUMPAD:
        case COMBO_ACTIVE_NUMPAD2:
          return 25;
        // case COMBO_OSM_SHIFT2:
        //   return 30;
        case COMBO_PRINT_SCREEN:
          return 25;
        default:
          return COMBO_TERM;
    }

    // // And if you're feeling adventurous, you can even decide by the keys in the chord,
    // // i.e. the exact array of keys you defined for the combo.
    // // This can be useful if your combos have a common key and you want to apply the
    // // same combo term for all of them.
    // if (combo->keys[0] == KC_ENT) { // if first key in the array is Enter
    //     return 150;
    // }

    return COMBO_TERM;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
          return 10;
            // return QUICK_TAP_TERM - 20;
        default:
          return QUICK_TAP_TERM;
    }
}

// case MY_NAV: { // I am an alias for MO(_NAV)
//     static uint8_t pressed_count = 0;

//     if (record->event.pressed) {
//         pressed_count++;
//     } else {
//         pressed_count--;
//         if (pressed_count) {
//             return false;
//         }
//     }
//     return true;
// }