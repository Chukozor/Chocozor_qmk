#pragma once

#define SPLIT_HAND_PIN B5
#define	SPLIT_HAND_PIN_LOW_IS_LEFT

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#    define SPLIT_OLED_ENABLE
#endif

// =====================================================================
#define ENCODER_RESOLUTION { 4 }
#define ENCODER_RESOLUTIONS_RIGHT { 4 }
// =====================================================================
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X
// #define POINTING_DEVICE_ROTATION_90

// #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE

#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

// Enables support for extended i16 mouse reports (instead of i8).
#define MOUSE_EXTENDED_REPORT
// Limits the frequency that the sensor is polled for motion.
#define POINTING_DEVICE_TASK_THROTTLE_MS 10

// MOUSE AUTO-LAYER
// in config.h:
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER 10
#define AUTO_MOUSE_TIME 400
#define AUTO_MOUSE_DELAY 400
#define AUTO_MOUSE_THRESHOLD 10
// =====================================================================

#undef SPLIT_OLED_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_WPM_ENABLE
#define OLED_BRIGHTNESS 1
#define SPLIT_MODS_ENABLE

#define OLED_TIMEOUT 10000

#define TAPPING_TERM 160
#define TAPPING_TERM_PER_KEY
// #define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define QUICK_TAP_TERM 0
#define QUICK_TAP_TERM_PER_KEY

#define COMBO_TERM 50
#define COMBO_TERM_PER_COMBO
// =====================================================================
#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_A