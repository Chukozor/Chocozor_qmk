        // case MY_BNAV:
        //   if (record->tap.count) { // tapped
        //     // if (record->event.pressed) {
        //     //   // your logic when pressed
        //     //   set_oneshot_layer(_OP_NAV, ONESHOT_START);
        //     //   return false;
        //     // }
        //     // if (!record->event.pressed) {
        //     //   clear_oneshot_layer_state(ONESHOT_PRESSED);
        //     //   // your logic when released
        //     //   return false;
        //     // }
        //     // // if (is_colemak_layer()) {
        //     // //   tap_code(KC_SPC);
        //     // // } else {
        //     // //   // tap_code(KC_NO);
        //     // //   tap_code(KC_SPC);
        //     // // }
        //     // // if (is_accent_layer()) {
        //     // // 	tap_e_aigue();
        //     // // } else {
        //     // // 	tap_code(KC_SPC);
        //     // // }

        //   } else { // held
        //     if (record->event.pressed) {
        //       if (record->tap.interrupted) {
        //         nav_interrupted = 1;
        //       }
        //       if (IS_LAYER_ON(_NAV)) {
        //         //if already set, then switch it off
        //         layer_off(_NAV);
        //       } else { 
        //         //if not already set, then switch the layer on
        //         // layer_clear();
        //         layer_move(_COLEMAK_FR);
        //         layer_on(_NAV);
        //       }
        //       // if (record->tap.interrupted) {
        //       // // if (is_colemak_layer()) {
        //       //   layer_on(_ACCENTS);
        //       // // } else {
        //       // //   tap_code(KC_NO);
        //       // // }
        //       // } else {
        //       //   layer_on(_ACCENTS);
        //       // }
        //     } else {
        //         if (nav_interrupted == 1) {
        //           layer_off(_NAV);
        //           nav_interrupted = 0;
        //         } else {
        //           // layer_move(_COLEMAK_FR);
        //           // layer_on(_NAV);
        //         }
        //     }
        //   }

        // return false;

        // case COMBO_SHIFT:
	      //   // if (record->tap.count) { // tapped
	      //   	if (!record->event.pressed) {
        //       unregister_mods(MOD_BIT_LSHIFT);
        //       // your logic when released
        //       layer_off(_SFT_COLEMAK_FR);
	      //   		return false;
	      //   	} else {
        //       add_mods(MOD_BIT_LSHIFT);
        //       layer_on(_SFT_COLEMAK_FR);
        //     }
        //     // if (is_colemak_layer()) {
        //     //   tap_code(KC_SPC);
        //     // } else {
        //     //   // tap_code(KC_NO);
        //     //   tap_code(KC_SPC);
        //     // }
	      //   	// if (is_accent_layer()) {
	      //   	// 	tap_e_aigue();
	      //   	// } else {
	      //   	// 	tap_code(KC_SPC);
	      //   	// }

	      //   // } else { // held
        //   //   if (record->event.pressed) {
        //   //     if (record->tap.interrupted) {
        //   //     // if (is_colemak_layer()) {
        //   //       layer_on(_ACCENTS);
        //   //     // } else {
        //   //     //   tap_code(KC_NO);
        //   //     // }
        //   //     } else {
        //   //       layer_on(_ACCENTS);
        //   //     }
        //   //   } else if (!record->event.pressed) {
        //   //     layer_off(_ACCENTS);
        //   //     return false;
        //   //   }
	      //   // }
	
	      //   return false;

        // case MY_PVIRG:
        //   if (!record->event.pressed) {
        //     return false;
        //   }
        //   if (is_shift_layer()) {
        //     tap_point_virgule();
        //   } else {
        //     tap_point_virgule(); // TPDP nothing better to put atm here, maybe later
        //   }
        //   return false;

        // case HT_SPC:
            // if (record->tap.count) { // tapped
          //   	if (!record->event.pressed) {
          //   		return false;
          //   	}
          //   		tap_code(KC_SCP);
          //   } else { // held
          //   	if (!record->event.pressed) {
          //   		return false;
          //   	}
          //   		tap_code(KC_LGUI);
          //   }
           
          //   return false;
      // case CUSTOM_OSL_WITH_MOD:
      //   if (record->event.pressed) {
      //       // Activate one-shot layer when the key is pressed.
      //       // Replace '#' with the target layer number you want to activate.
      //       set_oneshot_layer(_SFT_COLEMAK_FR, ONESHOT_START);
      //       // Set the desired modifier(s) to be active while the layer is active.
      //       // Replace 'mod' with the actual modifier you want, e.g., MOD_LSFT for left shift.
      //       set_oneshot_mods(MOD_BIT(KC_LSFT)); // Example: Applying left shift as the modifier.
      //   } else {
      //       // Remove the modifier(s) when the key is released.
      //       clear_oneshot_mods();
      //       // Optionally, clear the one-shot layer state if needed.
      //       // This line is not strictly necessary unless you want to immediately cancel the layer state upon key release.
      //       // clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      //   }
      //   break;
        // case MY_PAST:
        //   tap_code(KC_PAST);
        //   wait_ms(15);
        //   layer_off(_OP_NAV);
        //   // return false;

        // case MY_PSLS:
        //   tap_code(KC_PSLS);
        //   wait_ms(15);
        //   layer_off(_OP_NAV);
        //   // return false;

        // case MY_PPLS:
        //   tap_code(KC_PPLS);
        //   wait_ms(15);
        //   layer_off(_OP_NAV);
        //   // return false;

        // case MY_PMNS:
        //   tap_code(KC_PMNS);
        //   wait_ms(15);
        //   layer_off(_OP_NAV);
        //   // return false;

        // case MY_SOLU:
        //   layer_off(_OP_NAV);
        //   wait_ms(15);
        //   // return false;