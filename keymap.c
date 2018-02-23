#include "chimera_ls.h"

// layer names for readability
enum chimera_lets_split_layers
{
  _MODS,

  _QWERTY,
  _DVORAK,
  _COLEMAK,

  _CAPS,
  _NUMPAD,
  _SYMBOLS,
  _MACROS,
  _NAV
};

// layout toggles
#define KC_QWER M(0)
#define KC_DVOR M(1)
#define KC_COLE M(2)
// layer toggles
#define KC_NMPD TG(_NUMPAD)
#define KC_SYMB TG(_SYMBOLS)
#define KC_NAV  TG(_NAV)
// layer taps
#define KC_MESC LT(_MACROS, KC_ESC)
// mod taps
#define KC_SCTL MT(MOD_LCTL, KC_LBRC)
#define KC_SCTR MT(MOD_RCTL, KC_RBRC)
#define KC_SPLT MT(MOD_LALT, KC_MINS)
// macros
#define KC_SCAP M(3)
#define KC_SCOF M(4)
#define KC_CAD LALT(LCTL(KC_DEL))

#define LONGPRESS_DELAY 150
//#define LAYER_TOGGLE_DELAY 300

// fillers to make layering more clear
#define ____ KC_TRNS
#define XXXX KC_NO
#define KC_ KC_TRNS 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MODS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     MESC,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     TAB ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,ENT ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSPO,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,RSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,SCTL,LALT,LGUI,    ,BSPC,     SPC ,    ,RGUI,RALT,SCTR,     
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),



  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         , Q  , W  , E  , R  , T  ,      Y  , U  , I  , O  , P  ,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         , A  , S  , D  , F  , G  ,      H  , J  , K  , L  ,SCLN,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         , Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,     
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_DVORAK] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,QUOT,COMM,DOT , P  , Y  ,      F  , G  , C  , R  , L  ,SLSH,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         , A  , O  , E  , U  , I  ,      D  , H  , T  , N  , S  ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,SCLN, Q  , J  , K  , X  ,      B  , M  , W  , V  , Z  ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,     
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_COLEMAK] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         , Q  , W  , F  , P  , G  ,      J  , L  , U  , Y  ,SCLN,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         , A  , R  , S  , T  , D  ,      H  , N  , E  , I  , O  ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         , Z  , X  , C  , V  , B  ,      K  , M  ,COMM,DOT ,SLSH,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,     
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),



  [_CAPS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,     
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),


  [_NUMPAD] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,         ,  7 ,  8 ,  9 ,MINS,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,  4 ,  5 ,  6 ,PLUS, ENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,    ,         ,  1 ,  2 ,  3 ,ASTR, EQL,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,  0 ,  0 , DOT,SLSH,     
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_SYMBOLS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,EXLM, AT ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,RPRN,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      F1 , F2 , F3 , F4 , F5 , F6 ,     TILD,EQL ,UNDS,LCBR,RCBR,PIPE,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      F7 , F8 , F9 , F10, F11, F12,     GRV ,PLUS,MINS,LBRC,RBRC,BSLS,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    , NO ,BSPC,     SPC ,    ,    ,    ,    ,     
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_NAV] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    , DEL,BSPC,         ,HOME, UP , END, INS,PSCR,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,LSFT,LCTL, ENT,         ,LEFT,DOWN,RGHT, DEL,   ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,PGUP,PGDN,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,DEL ,         ,    ,    ,    ,    ,     
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_MACROS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,CAD ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     SCAP,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,SCAP,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,     
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

};


const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    /* include some kind of library or header */
    case 0:
      if (record->event.pressed) {
        print("layout: QWERTY");
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    case 1:
      if (record->event.pressed) {
        print("layout: DVORAK");
        set_single_persistent_default_layer(_DVORAK);
      }
      break;
    case 2:
      if (record->event.pressed) {
        print("layout: COLEMAK");
        set_single_persistent_default_layer(_COLEMAK);
      }
      break;
    case 3:
      if (record->event.pressed) {
        print("mode: caps (on)");
        layer_on(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      break;
    case 4:
      if (record->event.pressed) {
        print("mode: caps (off)");
        layer_off(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      break;
  }
  return MACRO_NONE;
};

// colors: off, red, blue, green, yellow, magenta, cyan, white
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    
    switch (layer) {
      case _QWERTY:
        set_led_green;
        break;
      case _DVORAK:
        set_led_red;
        break;
      case _COLEMAK:
        set_led_blue;
        break;
      default:
        set_led_white;
        break;
    }
};