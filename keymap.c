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
  _NAV,
  _MACROS,
  _MOUSE
};

// layout toggles
#define KC_QWER M(0)
#define KC_DVOR M(1)
#define KC_COLE M(2)
// layer toggles
#define KC_NMPD MO(_NUMPAD)
#define KC_SYMB MO(_SYMBOLS)
#define KC_EMOJ MO(_EMOJI)
// layer taps
#define KC_BCNV LT(_NAV, KC_BSPC)
#define KC_MESC LT(_MACROS, KC_ESC)
#define KC_MSPC LT(_MOUSE, KC_SPC)
// mod taps
#define KC_SCTL MT(MOD_LCTL, KC_LBRC)
#define KC_SCTR MT(MOD_RCTL, KC_RBRC)
// macros
#define KC_SCAP M(3)
#define KC_SCOF M(4)
#define KC_MLOC LCTL(LGUI(KC_Q))
#define KC_ESCR LGUI(LSFT(KC_3))
#define KC_SSCR LGUI(LSFT(KC_4))

#define LONGPRESS_DELAY 150
//#define LAYER_TOGGLE_DELAY 300
//#define AUTO_SHIFT_ENABLE yes

// fillers to make layering more clear
#define ______ KC_TRNS
#define XXXXXX KC_NO
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
         ,SCTL,LALT,LGUI,NMPD,BCNV,     SPC ,SYMB,RGUI,RALT,SCTR,     
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
      NO , F1 , F2 , F3 , F4 , NO ,     LPRN,  7 ,  8 ,  9 ,MINS,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , F5 , F6 , F7 , F8 , NO ,     RPRN,  4 ,  5 ,  6 ,PLUS, ENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , F9 ,F10 ,F11 ,F12 , NO ,      NO ,  1 ,  2 ,  3 ,ASTR, EQL,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , NO , NO , NO ,    , NO ,      NO ,  0 ,  0 , DOT,SLSH, NO 
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_SYMBOLS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,    ,    ,GRV ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     QUOT,ASTR,BSLS,MINS,EQL ,SLSH,         ,LPRN,RPRN,LABK,RABK,DQUO,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     AMPR,CIRC,PIPE,UNDS,PLUS,QUES,         ,LCBR,RCBR,LBRC,RBRC, NO ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , NO , X  , NO , NO ,DEL ,      NO ,    , NO , NO ,COLN, NO  
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_NAV] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
      NO , NO ,MUTE,VOLD,VOLU, NO ,      NO ,HOME,END , NO , NO ,PSCR,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , NO ,MRWD,MPLY,MFFD, NO ,     LEFT,DOWN, UP ,RGHT, NO ,INS ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , NO , NO ,ESCR,SSCR, NO ,      NO ,PGUP,PGDN, NO , NO , NO ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , NO , NO , NO , NO ,    ,      NO , NO , NO , NO , NO , NO  
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_MACROS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         , NO ,COLE,DVOR,QWER, NO ,      NO , NO , NO , NO , NO ,MLOC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , NO , NO , NO , NO , NO ,      NO , NO , NO , NO , NO , NO , 
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     SCAP, NO , NO , NO , NO , NO ,      NO , NO , NO , NO , NO ,SCAP,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , NO , NO , NO , NO , NO ,      NO , NO , NO , NO , NO , NO  
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_MOUSE] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
      NO , NO , NO ,WH_D,WH_U, NO ,      NO , NO , NO , NO , NO , NO ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , NO , NO ,BTN1,BTN2, NO ,     MS_L,MS_D,MS_U,MS_R, NO , NO , 
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , NO , NO , NO , NO , NO ,      NO , NO , NO , NO , NO , NO ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      NO , NO , NO , NO , NO , NO ,         , NO , NO , NO , NO , NO  
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
      default:
        set_led_green;
        break;
    }
};