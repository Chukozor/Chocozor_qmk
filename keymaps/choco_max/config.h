/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */


// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_RIGHT
// #define POINTING_DEVICE_ROTATION_90
// #define MASTER_RIGHT
// #define MASTER_LEFT


// #define POINTING_DEVICE_RIGHT
// #define POINTING_DEVICE_ROTATION_90
// #define CIRQUE_PINNACLE_DIAMETER_MM 40
// #define CIRQUE_PINNACLE_TAP_ENABLE
// #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

// #define EE_HANDS
// #define MASTER_RIGHT
// #define EE_HANDS
#define SPLIT_HAND_PIN B5
#define	SPLIT_HAND_PIN_LOW_IS_LEFT

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

// #define MASTER_RIGHT
// #define MASTER_LEFT
// (use MASTER_LEFT only to flash on the left side, and use MASTER_RIGHT to flash on the right side, and ALWAYS connect the USB to the right side)

// =====================================================================
// TRACKPAD
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
// #define CIRQUE_PINNACLE_CURVED_OVERLAY
#define DEBOUNCE 5
#define F_SCL 100000L


// // ========== 35mm flat ==========
// #define CIRQUE_PINNACLE_DIAMETER_MM 35
// #define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X
// #define POINTING_DEVICE_CIRQUE_PINNACLE_DPI 1150
// // #define POINTING_DEVICE_ROTATION_90
// #define AUTO_MOUSE_DEBOUNCE 10
// // ---------------------------------------------------

// ========== 40mm flat ==========
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X
#define POINTING_DEVICE_CIRQUE_PINNACLE_DPI 4500
#define POINTING_DEVICE_ROTATION_180
#define AUTO_MOUSE_DEBOUNCE 15
// ---------------------------------------------------

// #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE

// #define CIRQUE_PINNACLE_TAP_ENABLE
// #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
// #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

// Enables support for extended i16 mouse reports (instead of i8).
#define MOUSE_EXTENDED_REPORT
// Limits the frequency that the sensor is polled for motion.
#define POINTING_DEVICE_TASK_THROTTLE_MS 10

// MOUSE AUTO-LAYER
// in config.h:
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER 10
#define AUTO_MOUSE_TIME 10
#define AUTO_MOUSE_DELAY 5
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
// #define UNICODE_ENABLE
// #define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
// // #define UNICODE_SELECTED_MODES UC_LINX
// =====================================================================

// #ifdef RGB_MATRIX_ENABLE

#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash. 
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

/* Enable the animations you want/need.  You may need to enable only a small number of these because       *
 * they take up a lot of space.  Enable and confirm that you can still successfully compile your firmware. */
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS // Static dual hue, speed is hue for secondary hue
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN // Static gradient top to bottom, speed controls how much gradient changes
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT // Static gradient left to right, speed controls how much gradient changes
#    define ENABLE_RGB_MATRIX_BREATHING // Single hue brightness cycling animation
#    define ENABLE_RGB_MATRIX_BAND_SAT // Single hue band fading saturation scrolling left to right
#    define ENABLE_RGB_MATRIX_BAND_VAL // Single hue band fading brightness scrolling left to right
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT // Single hue 3 blade spinning pinwheel fades saturation
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL  // Single hue 3 blade spinning pinwheel fades brightness
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT // Single hue spinning spiral fades saturation
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL  // Single hue spinning spiral fades brightness
#    define ENABLE_RGB_MATRIX_CYCLE_ALL  // Full keyboard solid hue cycling through full gradient
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT // Full gradient scrolling left to right
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN // Full gradient scrolling top to bottom
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN // Full gradient scrolling out to in
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL // Full dual gradients scrolling out to in
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON // Full gradient Chevron shapped scrolling left to right
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL // Full gradient spinning pinwheel around center of keyboard
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL // Full gradient spinning spiral around center of keyboard
#    define ENABLE_RGB_MATRIX_DUAL_BEACON // Full gradient spinning around center of keyboard
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON // Full tighter gradient spinning around center of keyboard
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS // Full dual gradients spinning two halfs of keyboard
#    define ENABLE RGB_MATRIX_FLOWER_BLOOMING     // Full tighter gradient of first half scrolling left to right and second half scrolling right to left
#    define ENABLE_RGB_MATRIX_RAINDROPS // Randomly changes a single key's hue
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
#    define ENABLE_RGB_MATRIX_HUE_BREATHING // Hue shifts up a slight ammount at the same time, then shifts back
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM // Hue shifts up a slight ammount in a wave to the right, then back to the left
#    define ENABLE_RGB_MATRIX_HUE_WAVE // Hue shifts up a slight ammount and then back down in a wave to the right
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL // Single hue fractal filled keys pulsing horizontally out to edges
#    define ENABLE_RGB_MATRIX_PIXEL_FLOW  // Pulsing RGB flow along LED wiring with random hues
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN // Randomly light keys with random hues
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
// ======================================================================
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP // How hot is your WPM!
#define RGB_MATRIX_TYPING_HEATMAP_SPREAD 40 // Limit the distance the effect spreads to surrounding keys.
#define RGB_MATRIX_TYPING_HEATMAP_SLIM // Remove the spread effect entirely.
#define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 32 // Decreasing this value increases the number of keystrokes needed to fully heat up the key.
// ======================================================================
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN // That famous computer simulation
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE // Pulses keys hit to hue & value then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE // Static single hue, pulses keys hit to shifted hue then fades to current hue
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE // Hue & value pulse near a single key hit then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE // Hue & value pulse near multiple key hits then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS // Hue & value pulse the same column and row of a single key hit then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS // Hue & value pulse away on the same column and row of a single key hit then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#    define ENABLE_RGB_MATRIX_SPLASH // Full gradient & value pulse away from a single key hit then fades value out
#    define ENABLE_RGB_MATRIX_MULTISPLASH // Full gradient & value pulse away from multiple key hits then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH // Hue & value pulse away from a single key hit then fades value out
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH // Hue & value pulse away from multiple key hits then fades value out
#    define ENABLE_RGB_MATRIX_STARLIGHT           // LEDs turn on and off at random at varying brightness, maintaining user set color
#    define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE  // LEDs turn on and off at random at varying brightness, modifies user set hue by +- 30
#    define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT  // LEDs turn on and off at random at varying brightness, modifies user set saturation by +- 30
#    define ENABLE_RGB_MATRIX_RIVERFLOW           // Modification to breathing animation, offset's animation depending on key location to simulate a river flowing
#    define ENABLE_RGB_MATRIX_EFFECT_MAX    
// #endif

#define RGB_MATRIX_STARTUP_HUE 85
#define RGB_MATRIX_STARTUP_VAL 68
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP

#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_A

#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B6 }

#define ENCODERS_PAD_A_RIGHT { B6 }
#define ENCODERS_PAD_B_RIGHT { B2 }

#define ENCODER_RESOLUTIONS {4}
#define ENCODER_RESOLUTIONS_RIGHT {4}

