#ifndef _LIB_SIMPLEOLED_H_
#define _LIB_SIMPLEOLED_H_

#include <inttypes.h>
#include <8bitfonts.h>

#include "configSimpleOLED.h"

#include "displayinterface.h"

#include "displaycontroller_ssd1306.h"




/*
  // Set MUX ratio  0xa8; au8_Cmd[1] = mu8_Height-1;
  
  // Set Display Offset \xd3\x00", 2);
  
  // Set Display Start Line \x40", 1);

  // Additional: Set memory addressing mode \x20\x00", 2);

  // Set Segment re-map \xa1", 1);   // column address 0 is mapped to SEG0 (default); ardafruit nimmt hier 0xa1

  // Set COM Output Scan Direction \xc8", 1);   // normal scan direction would be 0xc0
  
  // Set COM Pins hardware configurarion \xDA\x12":"\xDA\x02"), 2);
  
  // Set Contrast Control \x81\x7f", 2);

  // Disable Entire Display On \xa4", 1);

  // Set Normal Display \xA6", 1);
  
  // Set Osc Frequency \xD5\x80", 2);
  
  // Enable charge pump regulator \x8d\x14", 2);  // EXERNAL VCC = 0x10, sonst 0x14

  // Set address mode \x20\x01", 2);  // vertical address mode

  // Display On \xAF":"\xAE"), 1);  


   // Set Column address
   mp_DisplayInterface->sendCmd(au8_CommandX, 3);


     // Set Page address
     au8_CommandY[1]=u8_Page;
     au8_CommandY[2]=u8_Page;
     mp_DisplayInterface->sendCmd(au8_CommandY, 3); 

*/







class SimpleOLED
{
public:
  typedef enum
  {
    RcOK = 0,
    RcError = -1
  } ERc;

  typedef enum 
  { 
#if USE_DEFAULT_FONT == 1
    Default,
#endif
#if USE_TOPAZ_SERIF_FONT == 1
    TopazSerif,
#endif
#if USE_TOPAZ_FONT == 1
    Topaz,
#endif
#if USE_TOPAZ_PROPORTIONAL_FONT == 1
    TopazProportional,
#endif
#if USE_C64_FONT == 1
    C64,
#endif
  } EFont;

private:
  DisplayControllerSSD1306 m_DisplayController;
  uint8_t mu8_Width;
  uint8_t mu8_Height;
  uint8_t mu8_CursorX;
  uint8_t mu8_CursorY;

#if USE_DEFAULT_FONT == 1
  FontDefault m_FontDefault;
#endif
#if USE_TOPAZ_FONT == 1
  FontTopazSerif m_FontTopazSerif;
#endif
#if USE_TOPAZ_FONT == 1
  FontTopaz m_FontTopaz;
#endif
#if USE_TOPAZ_PROPORTIONAL_FONT == 1
  FontTopazProportional m_FontTopazProportional;
#endif
#if USE_C64_FONT == 1
  FontC64 m_FontC64;
#endif  
  Font *mp_CurrentFont;

public:
  SimpleOLED(DisplayInterface *p_DisplayInterface, const uint8_t u8_Width, const uint8_t u8_Height);

  ERc begin(const bool b_Enable = true);
  void end(void);

  ERc enable(const bool b_Enable);
  
  ERc clear(void);
  ERc setFont(const EFont e_Font, const uint8_t u8_ScaleX = 1, const uint8_t u8_ScaleY = 1);
  ERc setCursor(const uint8_t u8_Column, const uint8_t u8_Row);  // in characters
  ERc print(const char *pc_String);
  ERc println(const char *pc_String);

  ERc setDrawRegion(const uint8_t u8_Segment, const uint8_t u8_StartPage, const uint8_t u8_Pages = 1);
  ERc drawBuffer(const uint8_t u8_Bytes, const uint8_t *pu8_Buffer);
};

#endif
