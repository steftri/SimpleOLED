#include <Arduino.h>

#include "simpleoled.h"


#include "font_topaz_proportional.h"
#include "font_topaz8x8.h"
#include "font_default.h"
#include "font_c64.h"


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
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101
};


SimpleOLED::SimpleOLED(DisplayInterface *m_DisplayInterface, uint8_t u8_Width, uint8_t u8_Height)
{
  mp_DisplayInterface = m_DisplayInterface;
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

  if(!mp_DisplayInterface)
    return RcError;

  mp_DisplayInterface->begin();
  
  // Set MUX ratio
  au8_Cmd[0] = 0xa8; au8_Cmd[1] = mu8_Height-1;
  mp_DisplayInterface->sendCmd(au8_Cmd, 2);
  
  // Set Display Offset
  mp_DisplayInterface->sendCmd((const uint8_t *)"\xd3\x00", 2);
  
  // Set Display Start Line
  mp_DisplayInterface->sendCmd((const uint8_t *)"\x40", 1);

  // Additional: Set memory addressing mode
  mp_DisplayInterface->sendCmd((const uint8_t *)"\x20\x00", 2);

  // Set Segment re-map
  mp_DisplayInterface->sendCmd((const uint8_t *)"\xa1", 1);   // column address 0 is mapped to SEG0 (default); ardafruit nimmt hier 0xa1

  // Set COM Output Scan Direction
  mp_DisplayInterface->sendCmd((const uint8_t *)"\xc8", 1);   // normal scan direction would be 0xc0
  
  // Set COM Pins hardware configurarion
  mp_DisplayInterface->sendCmd((const uint8_t *)((mu8_Height==64)?"\xDA\x12":"\xDA\x02"), 2);
  
  // Set Contrast Control
  mp_DisplayInterface->sendCmd((const uint8_t *)"\x81\x7f", 2);

  // Disable Entire Display On
  mp_DisplayInterface->sendCmd((const uint8_t *)"\xa4", 1);

  // Set Normal Display
  mp_DisplayInterface->sendCmd((const uint8_t *)"\xA6", 1);
  
  // Set Osc Frequency
  mp_DisplayInterface->sendCmd((const uint8_t *)"\xD5\x80", 2);
  
  // Enable charge pump regulator
  mp_DisplayInterface->sendCmd((const uint8_t *)"\x8d\x14", 2);  // EXERNAL VCC = 0x10, sonst 0x14

  // Set address mode
  mp_DisplayInterface->sendCmd((const uint8_t *)"\x20\x01", 2);  // vertical address mode

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
  if(!mp_DisplayInterface)
    return RcError;

  // Display On
  mp_DisplayInterface->sendCmd((const uint8_t *)(b_Enable?"\xAF":"\xAE"), 1);

  return RcOK;
}



SimpleOLED::ERc SimpleOLED::clear(void)
{
  uint8_t au8_CommandX[3]={0x21, 0, 0x7f};  // width = 0x7f = 127
  uint8_t au8_CommandY[3]={0x22};

  if(!mp_DisplayInterface)
    return RcError;

  // Set Column address
  mp_DisplayInterface->sendCmd(au8_CommandX, 3);

  for(uint8_t u8_Page=0; u8_Page<(uint8_t)(mu8_Height>>3); u8_Page++)
  {
    // Set Page address
    au8_CommandY[1]=u8_Page;
    au8_CommandY[2]=u8_Page;
    mp_DisplayInterface->sendCmd(au8_CommandY, 3);

    for(uint8_t u8_x=0; u8_x<mu8_Width; u8_x+=16)
    {
      mp_DisplayInterface->sendData((const uint8_t *)"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
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

  if(!mp_DisplayInterface)
    return RcError;

  if(u8_Pages>1)
    au8_CommandY[2]=(uint8_t)((u8_StartPage>>3)+(u8_Pages-1));

  // Set address mode
  //mp_DisplayInterface->sendCmd(3, (const uint8_t *)"\x20\x01");

  // Set Page address
  mp_DisplayInterface->sendCmd(au8_CommandY, 3);
  
  // Set Column address
  mp_DisplayInterface->sendCmd(au8_CommandX, 3);

  return RcOK;
}



SimpleOLED::ERc SimpleOLED::drawBuffer(const uint8_t u8_BufferSize, const uint8_t *pu8_Buffer)
{
  if(!mp_DisplayInterface)
    return RcError;

  mp_DisplayInterface->sendData(pu8_Buffer, u8_BufferSize);

  return RcOK; 
}

