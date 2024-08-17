// case MY_SLASHES:
        // // if (record->event.pressed && get_mods() & MOD_BIT(KC_LCTL)) {
        //   if (record->event.pressed) {
        //     if (IS_LAYER_ON(LAYER_SHIFT)){
        //         unregister_mods(MOD_BIT_LSHIFT);
        //         unregister_mods(MOD_BIT_RSHIFT);
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_4) SS_TAP(X_KP_7))); // 47 Slash
        //       } else {
        //       if (get_mods() & MOD_BIT(KC_LCTL)) {
        //         // unregister_mods(MOD_BIT_LCTRL);
        //         SEND_STRING(SS_LCTL(SS_TAP(X_DOT)));
        //         // SEND_STRING(SS_LALT(SS_TAP(X_KP_5) SS_TAP(X_KP_8))); // 58 deux points
        //         // register_mods(MOD_BIT_LCTRL);
        //       } else {
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_9) SS_TAP(X_KP_2))); // 92 backslash 
        //       }
        //     }
        // } else {
        //   unregister_mods(MOD_BIT_LSHIFT);
        //   unregister_mods(MOD_BIT_RSHIFT);
        // }
        // return false;
        // break;

        case MY_SLH:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_4);
            tap_code(KC_KP_7);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_BSLH:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_8);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_DOLL:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_3);
            tap_code(KC_KP_6);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_DIESE:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_3);
            tap_code(KC_KP_5);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_EURO:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_0);
            tap_code(KC_KP_1);
            tap_code(KC_KP_2);
            tap_code(KC_KP_8);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_TILD:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_1);
            tap_code(KC_KP_2);
            tap_code(KC_KP_6);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
        case MY_BQUOT:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_9);
            tap_code(KC_KP_6);
            unregister_mods(MOD_BIT_LALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }