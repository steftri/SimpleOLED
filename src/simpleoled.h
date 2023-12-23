#ifndef _LIB_SIMPLEOLED_H_
#define _LIB_SIMPLEOLED_H_

#include <inttypes.h>

#include "configSimpleOLED.h"


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
  uint8_t mu8_WireAddr;
  uint8_t mu8_Width;
  uint8_t mu8_Height;
  uint8_t mu8_CursorX;
  uint8_t mu8_CursorY;
  const uint8_t *mpu8_Font;
  uint8_t mu8_NumberOfChars;
  uint8_t mu8_FontWidth;
  bool mb_DoubleFontHeight;

  typedef enum { DisplayCommand = 0x00, DisplayData = 0x40 } EContent;



public:
  SimpleOLED(const uint8_t u8_WireAddr, const uint8_t u8_Width, const uint8_t u8_Height);

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

private:
  ERc _send(const EContent e_Content, const uint8_t u8_BufferSize, const uint8_t *pu8_Buffer);
};

#endif
