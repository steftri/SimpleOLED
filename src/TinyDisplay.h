#ifndef _LIB_TINYDISPLAY_H_
#define _LIB_TINYDISPLAY_H_

#include <inttypes.h>
#include <8bitfonts.h>

#include "configTinyDisplay.h"

#include "DisplayInterface.h"
#include "DisplayControllerSSD1306.h"


class TinyDisplay
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
  TinyDisplay(DisplayInterface *p_DisplayInterface, const uint8_t u8_Width, const uint8_t u8_Height);

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
