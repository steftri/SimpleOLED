#include <Arduino.h>

#include "font_topaz_proportional.h"


static const uint8_t FONT_HEIGHT = 8;


static const uint8_t CHAR_DATA[] PROGMEM =
{
   // 0x41, A
   B00000000,
   B01111110,
   B01111111,
   B00001001,
   B00001001,
   B01111111,
   B01111110,
   B00000000
};


static const uint16_t CONTINUOUS_CHAR_POS[] PROGMEM = 
{
  0
}; 


static const Font::SUtf8CharPos UTF8_CHAR_POS[] PROGMEM = 
{
  {0, 0, 0}
};



FontTopazProportional::FontTopazProportional()
 : Font(FONT_HEIGHT, sizeof(CHAR_DATA), CHAR_DATA, 
        sizeof(CONTINUOUS_CHAR_POS)/sizeof(CONTINUOUS_CHAR_POS[1]), CONTINUOUS_CHAR_POS, 
        sizeof(UTF8_CHAR_POS)/sizeof(UTF8_CHAR_POS[1]), UTF8_CHAR_POS)
{
}
