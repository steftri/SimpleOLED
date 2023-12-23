#include <Arduino.h>
#include <Wire.h>

#include "simpleoled.h"


#if USE_DEFAULT_FONT == 1
#include "display_font_default.h"
#endif

#if USE_TOPAZ_FONT == 1
#include "display_font_topaz.h"
#endif

#if USE_C64_FONT == 1
#include "display_font_C64.h"
#endif

static const uint8_t gau8_UnknownChar[8] PROGMEM = {
  B10101010,
  B01010101,
  B10101010,
  B01010101,
  B10101010,
  B01010101,
  B10101010,
  B01010101
};


SimpleOLED::SimpleOLED(uint8_t u8_WireAddr, uint8_t u8_Width, uint8_t u8_Height)
{
 mu8_WireAddr = u8_WireAddr;
  mu8_Width    = u8_Width;
  mu8_Height   = u8_Height;
  
#if USE_DEFAULT_FONT == 1
  mpu8_Font = (uint8_t*)gau8_CharDefault;
  mu8_NumberOfChars = sizeof(gau8_CharDefault)>>3;
  mu8_FontWidth = WIDTH_OF_DEFAULT_CHARS;
#elif USE_TOPAZ_FONT == 1
  mpu8_Font = (uint8_t*)gau8_CharTopaz;
  mu8_NumberOfChars = sizeof(gau8_CharTopaz)>>3;
  mu8_FontWidth = WIDTH_OF_TOPAZ_CHARS;
#elif USE_C64_FONT == 1
  mpu8_Font = (uint8_t*)gau8_CharC64;
  mu8_NumberOfChars = sizeof(gau8_CharC64)>>3;
  mu8_FontWidth = WIDTH_OF_C64_CHARS;
#else
  mpu8_Font = (void*)0;
  mu8_NumberOfChars = 0;
  mu8_FontWidth = WIDTH_OF_DEFAULT_CHARS;
#endif

  mb_DoubleFontHeight = false;

  mu8_CursorX = 0;
  mu8_CursorY = 0;
}



SimpleOLED::ERc SimpleOLED::begin(const bool b_Enable)
{
  uint8_t au8_Cmd[2];
  Wire.begin(); // join i2c bus (address optional for master)
  
  // Set MUX ratio
  au8_Cmd[0] = 0xa8; au8_Cmd[1] = mu8_Height-1;
  _send(DisplayCommand, 2, au8_Cmd);
  
  // Set Display Offset
  _send(DisplayCommand, 2, (const uint8_t *)"\xd3\x00");
  
  // Set Display Start Line
  _send(DisplayCommand, 1, (const uint8_t *)"\x40");

  // Additional: Set memory addressing mode
  _send(DisplayCommand, 2, (const uint8_t *)"\x20\x00");

  // Set Segment re-map
  _send(DisplayCommand, 1, (const uint8_t *)"\xa1");   // column address 0 is mapped to SEG0 (default); ardafruit nimmt hier 0xa1

  // Set COM Output Scan Direction
  _send(DisplayCommand, 1, (const uint8_t *)"\xc8");   // normal scan direction would be 0xc0
  
  // Set COM Pins hardware configurarion
  _send(DisplayCommand, 2, (const uint8_t *)((mu8_Height==64)?"\xDA\x12":"\xDA\x02"));
  
  // Set Contrast Control
  _send(DisplayCommand, 2, (const uint8_t *)"\x81\x7f");

  // Disable Entire Display On
  _send(DisplayCommand, 1, (const uint8_t *)"\xa4");

  // Set Normal Display
  _send(DisplayCommand, 1, (const uint8_t *)"\xA6");
  
  // Set Osc Frequency
  _send(DisplayCommand, 2, (const uint8_t *)"\xD5\x80");
  
  // Enable charge pump regulator
  _send(DisplayCommand, 2, (const uint8_t *)"\x8d\x14");  // EXERNAL VCC = 0x10, sonst 0x14

  // Set address mode
  _send(DisplayCommand, 2, (const uint8_t *)"\x20\x01");  // vertical address mode

  clear();
  enable(b_Enable);

  return RcOK;
}



void SimpleOLED::end(void)
{
  enable(false);
}



SimpleOLED::ERc SimpleOLED::enable(const bool b_Enable)
{
  // Display On
  _send(DisplayCommand, 1, (const uint8_t *)(b_Enable?"\xAF":"\xAE"));

  return RcOK;
}



SimpleOLED::ERc SimpleOLED::clear(void)
{
  uint8_t au8_CommandX[3]={0x21, 0, 0x7f};  // width = 0x7f = 127
  uint8_t au8_CommandY[3]={0x22};
    
  // Set Column address
  _send(DisplayCommand, 3, au8_CommandX);

  for(uint8_t u8_Page=0; u8_Page<(uint8_t)(mu8_Height>>3); u8_Page++)
  {
    // Set Page address
    au8_CommandY[1]=u8_Page;
    au8_CommandY[2]=u8_Page;
    _send(DisplayCommand, 3, au8_CommandY);

    for(uint8_t u8_x=0; u8_x<mu8_Width; u8_x+=16)
    {
      _send(DisplayData, 16, NULL);
    }
  }
  setCursor(0, 0);
  
  return RcOK;
}



SimpleOLED::ERc SimpleOLED::setCursor(const uint8_t u8_Column, const uint8_t u8_Row)
{
  mu8_CursorX = u8_Column*mu8_FontWidth;
  mu8_CursorY = u8_Row*(mb_DoubleFontHeight?16:8);
  setDrawRegion(mu8_CursorX, mu8_CursorY, mb_DoubleFontHeight?2:1);
  return RcOK;
}



SimpleOLED::ERc SimpleOLED::setFont(const SimpleOLED::EFont e_Font, const bool b_DoubleHeight)
{
  mb_DoubleFontHeight = b_DoubleHeight;
  
  switch(e_Font)
  {
#if USE_DEFAULT_FONT == 1
  case Font6x8:
  {
    mpu8_Font = (uint8_t*)gau8_CharDefault;
    mu8_NumberOfChars = sizeof(gau8_CharDefault)>>3;
    mu8_FontWidth = WIDTH_OF_DEFAULT_CHARS;
    return RcOK;
  }
#endif
#if USE_TOPAZ_FONT == 1
  case Topaz:
  {
    mpu8_Font = (uint8_t*)gau8_CharTopaz;
    mu8_NumberOfChars = sizeof(gau8_CharTopaz)>>3;
    mu8_FontWidth = WIDTH_OF_TOPAZ_CHARS;
    return RcOK;
  }
#endif
#if USE_C64_FONT == 1
  case C64:
  {
    mpu8_Font = (uint8_t*)gau8_CharC64;
    mu8_NumberOfChars = sizeof(gau8_CharC64)>>3;
    mu8_FontWidth = WIDTH_OF_C64_CHARS;
    return RcOK;
  }
#endif  
  default:
    break;
  }

  return RcError;
}



SimpleOLED::ERc SimpleOLED::print(const char *pc_String)
{
  unsigned char uc_Char;
  const uint8_t *pu8_PgmBitmap;
  
  uint8_t au8_Bitmap[16];
  uint8_t u8_Bitmap;
  
  for(uint8_t i=0; pc_String[i]; i++)
  {
    uc_Char=(unsigned char)pc_String[i];
    
    if(uc_Char=='\n')
    {
      mu8_CursorY += (mb_DoubleFontHeight?16:8);
      setDrawRegion(mu8_CursorX, mu8_CursorY, mb_DoubleFontHeight?2:1);
      continue;
    }
    
    // if the character is printable
    if(mpu8_Font && (uc_Char>=0x20) && (uc_Char<=0x7f) && ((uc_Char-0x20)<mu8_NumberOfChars))
      pu8_PgmBitmap=&mpu8_Font[(uc_Char-0x20)*mu8_FontWidth];
    else if(mpu8_Font && (uc_Char>=0xa0) && ((uc_Char-0x40)<mu8_NumberOfChars))
      pu8_PgmBitmap=&mpu8_Font[(uc_Char-0x40)*mu8_FontWidth];
    else
      pu8_PgmBitmap=gau8_UnknownChar;
    
    // we have to copy the font bitmap data from flash to RAM first
    if(mb_DoubleFontHeight)
    {
      for(uint8_t u8_Col=0; u8_Col<mu8_FontWidth; u8_Col++)
      {
        u8_Bitmap = pgm_read_byte(&pu8_PgmBitmap[u8_Col]);
        au8_Bitmap[u8_Col*2]  = ((u8_Bitmap&0x08)?0xC0:0x00) | ((u8_Bitmap&0x04)?0x30:0x00) | ((u8_Bitmap&0x02)?0x0C:0x00) | ((u8_Bitmap&0x01)?0x03:0x00);
        au8_Bitmap[u8_Col*2+1]= ((u8_Bitmap&0x80)?0xC0:0x00) | ((u8_Bitmap&0x40)?0x30:0x00) | ((u8_Bitmap&0x20)?0x0C:0x00) | ((u8_Bitmap&0x10)?0x03:0x00);
      }
      drawBuffer(2*mu8_FontWidth, au8_Bitmap);
    }
    else
    {
      for(uint8_t u8_Col=0; u8_Col<mu8_FontWidth; u8_Col++)
        au8_Bitmap[u8_Col]=pgm_read_byte(&pu8_PgmBitmap[u8_Col]);
      drawBuffer(mu8_FontWidth, au8_Bitmap);
    }
  }

  return RcOK;
}


SimpleOLED::ERc SimpleOLED::println(const char *pc_String)
{
  print(pc_String);
  print("\n");
  
  return RcOK;
}



SimpleOLED::ERc SimpleOLED::setDrawRegion(const uint8_t u8_Segment, const uint8_t u8_StartPage, const uint8_t u8_Pages)
{
  uint8_t au8_CommandY[3]={0x22, (uint8_t)(u8_StartPage>>3), (uint8_t)(u8_StartPage>>3)};
  uint8_t au8_CommandX[3]={0x21, u8_Segment, 0x7f};  // width = 0x7f = 127

  if(u8_Pages>1)
    au8_CommandY[2]=(uint8_t)((u8_StartPage>>3)+(u8_Pages-1));

  // Set address mode
  //_send(DisplayCommand, 3, (const uint8_t *)"\x20\x01");

  // Set Page address
  _send(DisplayCommand, 3, au8_CommandY);
  
  // Set Column address
  _send(DisplayCommand, 3, au8_CommandX);

  return RcOK;
}



SimpleOLED::ERc SimpleOLED::drawBuffer(const uint8_t u8_BufferSize, const uint8_t *pu8_Buffer)
{
  return _send(DisplayData, u8_BufferSize, pu8_Buffer);
}



SimpleOLED::ERc SimpleOLED::_send(const EContent e_Content, const uint8_t u8_BufferSize, const uint8_t *pu8_Buffer)
{
  //#if (ARDUINO >= 157) && !defined(ARDUINO_STM32_FEATHER)
  //  Wire.setClock(400000);
  //#endif
  
  Wire.beginTransmission(mu8_WireAddr);
  Wire.write((uint8_t)e_Content);           // write DisplayCommand or DisplayData
  for(uint8_t i=0; i<u8_BufferSize; i++)
  {
    Wire.write(pu8_Buffer?pu8_Buffer[i]:0); // write zeros if pu8_Buffer is NULL
  }
  Wire.endTransmission();
  
//  #if (ARDUINO >= 157) && !defined(ARDUINO_STM32_FEATHER)
//    Wire.setClock(100000);
//  #endif
  
  return RcOK;
}
