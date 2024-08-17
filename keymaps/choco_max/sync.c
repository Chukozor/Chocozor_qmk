#include <string.h>
#include <stdint.h>
#include "quantum.h"
#include "transactions.h"
#include "keymap.h"

typedef struct _master_to_slave_t {
    bool game_mode;
} master_to_slave_t;

master_to_slave_t sync_data;

void user_config_sync(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer,
                      uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(master_to_slave_t)) {
        memcpy(&sync_data, initiator2target_buffer, initiator2target_buffer_size);
    }
}


void keyboard_post_init_user(void) {
    transaction_register_rpc(USER_SYNC_A, user_config_sync);
}


void housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        // Interact with slave every 500ms
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 500) {
            master_to_slave_t m2s;
            m2s.game_mode = test_game_mode();
            if(transaction_rpc_send(USER_SYNC_A, sizeof(master_to_slave_t), &m2s)) {
                last_sync = timer_read32();
            } else {
                dprint("Slave sync failed!\n");
            }
        }
    } else { // slave side
       toggle_game_mode(sync_data.game_mode); 
    }
}


