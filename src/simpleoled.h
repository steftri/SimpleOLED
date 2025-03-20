#ifndef _LIB_SIMPLEOLED_H_
#define _LIB_SIMPLEOLED_H_

#include <inttypes.h>

#include "configSimpleOLED.h"


#include "font_default.h"
#include "font_topaz8x8.h"
#include "font_c64.h"

class DisplayInterface
{
public:  
  virtual void begin(void) = 0;
  virtual void end(void) = 0;
  virtual void sendCmd(const uint8_t *pCmdBuffer, const size_t cmdSize) = 0;
  virtual void sendData(const uint8_t *pDataBuffer, const size_t dataSize) = 0;
};


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
    Font6x8 = 0,
#endif
#if USE_TOPAZ_FONT == 1
    Topaz = 1,
#endif
#if USE_C64_FONT == 1
    C64 = 2,
#endif
  } EFont;

private:
  DisplayInterface *mp_DisplayInterface;
  uint8_t mu8_Width;
  uint8_t mu8_Height;
  uint8_t mu8_CursorX;
  uint8_t mu8_CursorY;
  bool mb_DoubleFontHeight;

#if USE_DEFAULT_FONT == 1
  FontDefault m_FontDefault;
#endif
#if USE_TOPAZ_FONT == 1
  FontTopaz8x8 m_FontTopaz8x8;
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
  ERc setFont(const EFont e_Font, const bool b_DoubleHeight = false);
  ERc setCursor(const uint8_t u8_Column, const uint8_t u8_Row);  // in characters
  ERc print(const char *pc_String);
  ERc println(const char *pc_String);

  ERc setDrawRegion(const uint8_t u8_Segment, const uint8_t u8_StartPage, const uint8_t u8_Pages = 1);
  ERc drawBuffer(const uint8_t u8_Bytes, const uint8_t *pu8_Buffer);
};

#endif
