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
            register_code(KC_LSFT);
            tap_code(KC_DOT);
            unregister_code(KC_LSFT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }

        case MY_BSLH:
          if (record->event.pressed) {
            register_code(KC_RALT);
            tap_code(KC_8);
            unregister_code(KC_RALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }

        case MY_DOLL:
          if (record->event.pressed) {
            tap_code(KC_RBRC);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }
          
        case MY_DIESE:
          if (record->event.pressed) {
            add_mods(MOD_BIT_RALT);
            tap_code(KC_3);
            unregister_mods(MOD_BIT_RALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }

        case MY_EURO:
          if (record->event.pressed) {
            add_mods(MOD_BIT_RALT);
            tap_code(KC_E);
            unregister_mods(MOD_BIT_RALT);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }

        case MY_TILD:
          if (record->event.pressed) {
            // add_mods(MOD_BIT_LALT);
            // tap_code(KC_KP_1);
            // tap_code(KC_KP_2);
            // tap_code(KC_KP_6);
            // unregister_mods(MOD_BIT_LALT);
            add_mods(MOD_BIT_RALT);
            tap_code(KC_2);
            unregister_mods(MOD_BIT_RALT);
            add_mods(MOD_BIT_RALT);
            tap_code(KC_2);
            unregister_mods(MOD_BIT_RALT);
            tap_code(KC_BSPC);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }

        case MY_BQUOT:
          if (record->event.pressed) {
            // add_mods(MOD_BIT_LALT);
            // tap_code(KC_KP_9);
            // tap_code(KC_KP_6);
            // unregister_mods(MOD_BIT_LALT);
            add_mods(MOD_BIT_RALT);
            tap_code(KC_7);
            unregister_mods(MOD_BIT_RALT);
            add_mods(MOD_BIT_RALT);
            tap_code(KC_7);
            unregister_mods(MOD_BIT_RALT);
            tap_code(KC_BSPC);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }

        case MY_BQUOT2:
          if (record->event.pressed) {
            add_mods(MOD_BIT_LALT);
            tap_code(KC_KP_0);
            tap_code(KC_KP_9);
            tap_code(KC_KP_6);
            unregister_mods(MOD_BIT_LALT);
          }
          return false;

        // case MY_BQUOT3:
        //     if (record->event.pressed) {
        //         // Envoie le caractère Unicode pour le backquote
        //         send_unicode_string("‘");
        //     }
        //     break;

        case MY_PIPE:
          if (record->event.pressed) {
            // add_mods(MOD_BIT_LCTRL);
            add_mods(MOD_BIT_RALT);
            tap_code(KC_6);
            // tap_code(KC_KP_9);
            // tap_code(KC_KP_6);
            unregister_mods(MOD_BIT_RALT);
            // unregister_mods(MOD_BIT_LCTRL);
            // here we override its «press» behavior (hence, return false)
            return false;
          } else {
            // here we don't alter its «release» default behavior (hence, return true)
            return true;
          }