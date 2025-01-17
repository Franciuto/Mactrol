#include QMK_KEYBOARD_H

enum custom_keycodes {
    // Mac OS
    SCREENSHOT,                         // Screenshot using default macOS shortcut
    ARC,                                // Launch Browser
    SPOTIFY,                            // Open Spotify
    NOTION,                             // Open Notion
    SHUTDOWN = SAFE_RANGE,              // Shutdown option
    QUITAPP,                            // Quit app with CMD + Q
    LAUNCHPAD,                          // Open Launchpad
    MINIMIZE,                           // Minimize with CMD + H
    DELETE,                             // Delete a file with CMD + Backspace
    CHATGPT,                            // Execute chatGPT
    UNDO,                               // Simple undo
    FULLSCR,                            // Toggle fullscreen

    // Mactrol features
    LAYER_CYCLE,                        // Change layer                            
   
    //Windows
    FILE_EXPLOERER,                     // Open Windows file explorer 
    CLOSE_WINDOW,                       // Close window with alt + f4
};

enum layers {
    MACOSX_LAYER,                       // To use with macOS with some custom settings applied
    WINDOWS_LAYER,                      // To use with Windows (Work in progress)
    DAVINCI_LAYER,                      // To video edit with DaVinci Resolve
};

// Keycap definition
#define command X_LEFT_GUI
#define option X_LEFT_ALT
#define control X_LEFT_CTRL
#define shift X_LEFT_SHIFT
#define windowskey X_LEFT_GUI

static uint8_t current_layer = MACOSX_LAYER;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    // MacOS
    case SCREENSHOT:
        if (record->event.pressed) {    
            SEND_STRING(SS_DOWN(X_LEFT_ALT) SS_DELAY(50) SS_TAP(X_SPACE) SS_UP(X_LEFT_ALT));
        }
        break;
    case ARC:
        if (record->event.pressed) {    
            SEND_STRING(SS_DOWN(command) SS_DOWN(option) SS_DOWN(control) SS_DOWN(shift) SS_TAP(X_1) SS_UP(command) SS_UP(option) SS_UP(control) SS_UP(shift));
        }
        break;
    case SPOTIFY:
        if (record->event.pressed) {    
            SEND_STRING(SS_DOWN(command) SS_DOWN(option) SS_DOWN(control) SS_DOWN(shift) SS_TAP(X_2) SS_DELAY(20)SS_UP(command) SS_UP(option) SS_UP(control) SS_UP(shift));
        }
        break;
    case NOTION:
        if (record->event.pressed) {    
            SEND_STRING(SS_DOWN(command) SS_DOWN(option) SS_DOWN(control) SS_DOWN(shift) SS_TAP(X_3) SS_DELAY(20)SS_UP(command) SS_UP(option) SS_UP(control) SS_UP(shift));
        }
        break;
    case SHUTDOWN:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(command) SS_DOWN(option) SS_DOWN(control) SS_DOWN(shift) SS_TAP(X_4) SS_DELAY(20)SS_UP(command) SS_UP(option) SS_UP(control) SS_UP(shift));
        }
        break;
    case QUITAPP:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(command) SS_TAP(X_Q) SS_DELAY(20)SS_UP(command));
        }
        break;
    case LAUNCHPAD:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(command) SS_DOWN(option) SS_TAP(X_L) SS_DELAY(20)SS_UP(command) SS_UP(option));
        }
        break;
    case MINIMIZE:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(command) SS_TAP(X_H) SS_DELAY(20)SS_UP(command));
        }
        break;
    case DELETE:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(command) SS_TAP(X_BACKSPACE) SS_DELAY(20)SS_UP(command));
        }
        break;
    case CHATGPT:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(option) SS_TAP(X_TAB) SS_DELAY(20)SS_UP(option));
        }
        break;
    case FULLSCR:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(command) SS_TAP(X_NONUS_BACKSLASH) SS_DELAY(20)SS_UP(command));
        }
        break; 
    case LAYER_CYCLE: 
        if (record->event.pressed) {
            switch (current_layer) {
                case MACOSX_LAYER:
                    current_layer = WINDOWS_LAYER;
                    layer_move(WINDOWS_LAYER);
                    break;
                case WINDOWS_LAYER:
                    current_layer = DAVINCI_LAYER;
                    layer_move(DAVINCI_LAYER);
                    break;
                case DAVINCI_LAYER:
                    current_layer = MACOSX_LAYER;
                    layer_move(MACOSX_LAYER);
                    break;
            }
        }
        break;
    case UNDO:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(command) SS_TAP(X_Z) SS_DELAY(20)SS_UP(command));
        }
        break;
    case FILE_EXPLOERER:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(windowskey) SS_TAP(X_E) SS_DELAY(20)SS_UP(windowskey));
        }
        break;
    case CLOSE_WINDOW:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(option) SS_TAP(X_F4) SS_DELAY(20)SS_UP(option));
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MACOSX_LAYER] = LAYOUT_ortho_3x4(
        ARC,               SPOTIFY,                   NOTION,
        FULLSCR,           SCREENSHOT,                MINIMIZE,
        LAYER_CYCLE,       LAUNCHPAD,                 QUITAPP,
        KC_2,              KC_MEDIA_PLAY_PAUSE,       KC_MUTE 
    ),

    // WORK IN PROGRESS
    [WINDOWS_LAYER] = LAYOUT_ortho_3x4(
        FILE_EXPLOERER,    KC_2,                     KC_3,
        KC_1,              KC_0,                     KC_ENTER,
        LAYER_CYCLE,       KC_LEFT_GUI,              CLOSE_WINDOW ,
        KC_2,              KC_MEDIA_PLAY_PAUSE,      KC_MUTE 
    ),

    [DAVINCI_LAYER] = LAYOUT_ortho_3x4(
        KC_F2,             KC_F3,                    UNDO,
        KC_F5,             KC_F6,                    KC_F,
        LAYER_CYCLE,       KC_SPACE,                 KC_7,
        KC_2,              KC_MEDIA_PLAY_PAUSE,      KC_MUTE  
    ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MACOSX_LAYER]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),     ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)},
    [WINDOWS_LAYER] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),     ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK)},
    [DAVINCI_LAYER] = {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),    ENCODER_CCW_CW(KC_F1, KC_F4)},
};
#endif
