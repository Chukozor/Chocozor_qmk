// This is a thin wrapper around rgb_matrix_set_color which allows you to put
// the same firmware on both halves of the keyboard (other than a #define for
// `MASTER_LEFT` or `MASTER_RIGHT`) and still have the correct LEDs light up
// regardless of which half has the USB cable in it.
//
// This complexity behind this logic is explained in the comments within the
// function itself.
void set_color_split(uint8_t key_code, uint8_t r, uint8_t g, uint8_t b) {
    // When using defines for MASTER_LEFT and MASTER_RIGHT, is_keyboard_left()
    // will be inaccurate. For example, (is_keyboard_left() &&
    // !is_keyboard_master()) can NEVER be true.
    #ifdef MASTER_LEFT
        bool is_left = true;
    #endif
    #ifdef MASTER_RIGHT
        bool is_left = false;
    #endif

    bool left_is_master = (is_keyboard_master() && is_left) || (!is_keyboard_master() && !is_left);

    // Note on constants: 23 is the number of LEDs on each side (24) minus 1.
    // 27 is the number of LEDs that the Corne normally has with six columns.

    // Rule #1: you must set the LED based on what the master's range is. So if
    // the USB cable is in the left half, then the range is 0-23, otherwise it's
    // 27-50.

    // Rule #2: each half of the keyboard can only set its own LEDs, it's just
    // that the codes change according to Rule #1.

    // Rule #2
    if ((is_left && key_code >= NUM_LEDS_PER_SIDE) || (!is_left && key_code < NUM_LEDS_PER_SIDE)) {
        return;
    }

    // Rule #1
    if (left_is_master && key_code >= NUM_LEDS_PER_SIDE)
        key_code -= NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE;
    else if (!left_is_master && key_code < NUM_LEDS_PER_SIDE)
        key_code += NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE;
    rgb_matrix_set_color(key_code, r, g, b);
}