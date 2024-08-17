bool shift_activated = false;
bool caps_lock_activated = false;

      // case MY_VIRG:
      //   if (record->event.pressed) {
      //     tap_code(KC_PSCR);
      //     // here we override its «press» behavior (hence, return false)
      //     return false;
      //   } else {
      //     // here we don't alter its «release» default behavior (hence, return true)
      //     return true;
      //   }
      //   break;