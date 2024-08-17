        case HT_E:
	        if (record->tap.count) { // tapped
	        	if (!record->event.pressed) {
              // your logic when released
	        		return false;
	        	}

	        	if (is_accent_layer()) {
	        		tap_e_aigue();
	        	} else {
	        		tap_code(KC_E);
	        	}
	        } else { // held
	        	if (!record->event.pressed) {
              // your logic when released
	        		return false;
	        	}
            
            if (record->tap.interrupted) {
              if (is_accent_layer()) {
                tap_e_aigue();
              } else {
                tap_code(KC_E);
              }
            } else {
              if (is_accent_layer()) {
	        	  	tap_e_circ();
	        	  } else {
	        	  	tap_e_grave();
	        	  }
            }
	        }
	
	        return false;
            
        case HT_C:
	        // if (record->tap.count) { // tapped
	        	if (!record->event.pressed) {
	        		return false;
	        	}

	        	if (is_accent_layer()) {
	        		tap_c_ced();
	        	} else {
	        		tap_code(KC_C);
	        	}
	        // } else { // held
	        	  // if (!record->event.pressed) {
	        	  // 	return false;
	        	  // }
              // if (is_accent_layer()) {
	        		//   tap_code(KC_C);
	        	  // } else {
	        		//   tap_code(KC_C);
	        	  // }
	        // }
	        return false;

        case C_CEDIL:
	        // if (record->tap.count) { // tapped
	        	if (!record->event.pressed) {
	        		return false;
	        	}
	        		tap_c_ced();
	        // } else { // held
	        	  // if (!record->event.pressed) {
	        	  // 	return false;
	        	  // }
              // if (is_accent_layer()) {
	        		//   tap_code(KC_C);
	        	  // } else {
	        		//   tap_code(KC_C);
	        	  // }
	        // }
	        return false;

        case HT_A:
            if (record->tap.count) { // tapped
                if (record->event.pressed) {
                    tap_a_grave();
                }
            } else {
              if (!record->event.pressed) {
              // your logic when released
	        		return false;
	        	  }
              if (record->tap.interrupted) {
                // logic when interrupted
                tap_a_grave();
              } else {
                tap_a_circ();
                // logic when not interrupted
              }
            }
        
            return false;
        
        case HT_U:
          if (record->tap.count) { // tapped
	        	if (!record->event.pressed) {
	        		return false;
	        	}

	        	if (is_accent_layer()) {
	        		tap_u_grave();
	        	} else {
	        		tap_code(KC_U);
	        	}
	        } else { // held

            if (record->event.pressed) {
              // logic when pressed
              if (record->tap.interrupted) {
                // logic when interrupted
                tap_u_grave();
              } else {
                // logic when not interrupted
                if (is_accent_layer()) {
	        		    tap_u_circ();
	        	}
              }
            } else {
              // logic when released
              return false;
            }
	        }
	        return false;
        
        case HT_I:
	        if (record->tap.count) { // Tap
	        	if (!record->event.pressed) {
              // your logic when pressed
	        		return false;
	        	}
        
	        	if (is_accent_layer()) {
	        		tap_i_circ();
	        	} else {
	        		tap_code(KC_I);
	        	}
	        } else { // held

            if (record->event.pressed) {
              // logic when pressed
              if (record->tap.interrupted) {
                // logic when interrupted
                tap_i_circ();
              } else {
                // logic when not interrupted
                if (is_accent_layer()) {
	        		    tap_i_trema();
	        	}
              }
            } else {
              // logic when released
              return false;
            }
	        }
	        return false;

        case HT_O:
        	if (record->tap.count) {
        		if (!record->event.pressed) {
        			return false;
        		}
        
        		if (is_accent_layer()) {
        			tap_o_circ();
        		} else {
        			tap_code(KC_O);
        		}
        	} else {
        		if (record->event.pressed) {
              if (is_accent_layer()) {
        			  tap_o_circ();
              }
        		}
        	}
        
        	return false;

        case MY_OCIRC:
        	// if (record->tap.count) {
        		if (!record->event.pressed) {
        			return false;
        		}
        
        		// if (is_accent_layer()) {
        			tap_o_circ();
        		// } else {
        			// tap_code(KC_O);
        		// }
        	// } else {
        	// 	if (record->event.pressed) {
          //     if (is_accent_layer()) {
        	// 		  tap_o_circ();
          //     }
        	// 	}
        	// }
        
        	return false;