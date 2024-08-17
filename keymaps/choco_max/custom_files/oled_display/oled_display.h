// =============================== OLED DISPLAY ===============================
#ifdef OLED_ENABLE

// // rotate oled
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   return OLED_ROTATION_90;
// }

// Draw to OLED
bool oled_task_user() {
  // Set cursor position
  oled_set_cursor(0,1);

  // // Write text to OLED
  // oled_write("Hello World!", false);

  switch (get_highest_layer(layer_state)){
    case _COLEMAK_FR :
      oled_write("COLEMAK FR   ", false);
      break;
    case _GAMING :
      oled_write("GAMING       ", false);
      break;
    case _LATEX :
      oled_write("LATEX        ", false);
      break;
    // case _SFT_COLEMAK_FR :
    //   oled_write("SFT          ", false);
    //   break;
    case _CAPS_LOCK :
      oled_write("CAPS_LOCK    ", false);
      break;
    // case _OSL_SHIFT :
    //   oled_write("OSL_SHIFT    ", false);
    //   break;
    case _F_KEYS :
      oled_write("F_KEYS       ", false);
      break;
    case _WEB_BROWSER :
      oled_write("WEB_BROWSER  ", false);
      break;
    case _NOTHING_FOR_THE_MOMENT :
      oled_write("NOTHING      ", false);
      break;
    case _NAV :
      oled_write("NAV          ", false);
      break;
    case _OP_NAV :
      oled_write("OP_NAV       ", false);
      break;
    case _ACCENTS :
      oled_write("ACCENTS      ", false);
      break;
    case _REG_SPE :
      oled_write("REG_SPE      ", false);
      break;
    case _MULTIMEDIA :
      oled_write("_MULTIMEDIA  ", false);
      break;
    case _RGB :
      oled_write("RGB          ", false);
      break;
    case _RIEN :
      oled_write("RIEN          ", false);
      break;
    // case 4 :
    //   oled_write("", false);
    //   break;
  }
  
  return false;
}

#endif
// =============================== END OLED DISPLAY ===============================