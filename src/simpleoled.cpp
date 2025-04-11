#include <Arduino.h>


#include "simpleoled.h"





SimpleOLED::SimpleOLED(DisplayInterface *p_DisplayInterface, uint8_t u8_Width, uint8_t u8_Height)
 : m_DisplayController(p_DisplayInterface)
{
  mu8_Width    = u8_Width;
  mu8_Height   = u8_Height;
  
#if USE_DEFAULT_FONT == 1
  mp_CurrentFont = &m_FontDefault;
#elif USE_TOPAZ_FONT == 1
  mp_CurrentFont = &m_FontTopaz;
#elif USE_TOPAZ_SERIF_FONT == 1
  mp_CurrentFont = &m_FontTopazSerif;
#elif USE_TOPAZ_PROPORTIONAL_FONT == 1
  mp_CurrentFont = &m_FontTopazProportional;
#elif USE_C64_FONT == 1
  mp_CurrentFont = &m_FontC64;
#else
  mp_CurrentFont = &m_FontDefault;
#endif

  mu8_CursorX = 0;
  mu8_CursorY = 0;
}



SimpleOLED::ERc SimpleOLED::begin(const bool b_Enable)
{
  m_DisplayController.setMultiplexRatio(mu8_Height-1);
  m_DisplayController.setDisplayOffset(0);  
  m_DisplayController.setDisplayStartLine(0);

  m_DisplayController.setSegmentRemap(true);
  m_DisplayController.setComOutputScanDirection(DisplayControllerSSD1306::EScanDirection::Remapped);
  m_DisplayController.setComPinsHardwareConfig((mu8_Height==64)?true:false, false); 
  
  m_DisplayController.setContrastControl(0x7f);  
  m_DisplayController.setEntireDisplayOn(false);
  m_DisplayController.setInverseDisplay(false);
  m_DisplayController.setDisplayClock(1, 8);
  m_DisplayController.setChargePumpRegulator(true);

  m_DisplayController.setMemoryAddressingMode(DisplayControllerSSD1306::EAddressingMode::Vertical);

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
  m_DisplayController.setDisplayOn(b_Enable);
  return RcOK;
}



SimpleOLED::ERc SimpleOLED::clear(void)
{
  m_DisplayController.setColumnAddress(0, mu8_Width-1);

  for(uint8_t u8_Page=0; u8_Page<(uint8_t)(mu8_Height>>3); u8_Page++)
  {
    m_DisplayController.setPageAddress(u8_Page, u8_Page);
    m_DisplayController.sendData(nullptr, mu8_Width);
  }
  setCursor(0, 0);
  
  return RcOK;
}



SimpleOLED::ERc SimpleOLED::setCursor(const uint8_t u8_Column, const uint8_t u8_Row)
{
  mu8_CursorX = u8_Column * mp_CurrentFont->getCharacterWidth('8');
  mu8_CursorY = u8_Row * mp_CurrentFont->getFontHeight();
  setDrawRegion(mu8_CursorX, mu8_CursorY, mp_CurrentFont->getFontHeight());
  return RcOK;
}



SimpleOLED::ERc SimpleOLED::setFont(const SimpleOLED::EFont e_Font, const uint8_t u8_ScaleX, const uint8_t u8_ScaleY)
{
  switch(e_Font)
  {
#if USE_DEFAULT_FONT == 1
  case Default:
  {
    mp_CurrentFont = &m_FontDefault;
    mp_CurrentFont->setScale(u8_ScaleX, u8_ScaleY);
    return RcOK;
  }
#endif
#if USE_TOPAZ_FONT == 1
  case TopazSerif:
  {
    mp_CurrentFont = &m_FontTopazSerif;
    mp_CurrentFont->setScale(u8_ScaleX, u8_ScaleY);
    return RcOK;
  }
#endif
#if USE_TOPAZ_FONT == 1
  case Topaz:
  {
    mp_CurrentFont = &m_FontTopaz;
    mp_CurrentFont->setScale(u8_ScaleX, u8_ScaleY);
    return RcOK;
  }
#endif
#if USE_TOPAZ_PROPORTIONAL_FONT == 1
  case TopazProportional:
  {
    mp_CurrentFont = &m_FontTopazProportional;
    mp_CurrentFont->setScale(u8_ScaleX, u8_ScaleY);
    return RcOK;
  }
#endif
#if USE_C64_FONT == 1
  case C64:
  {
    mp_CurrentFont = &m_FontC64;
    mp_CurrentFont->setScale(u8_ScaleX, u8_ScaleY);
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
  uint32_t u32_CharacterCode;
  uint8_t u8_CharacterDataSize;
  uint8_t au8_CharacterData[10*4*4];  // buffer for one character with a width of 10 pixels with scaling x*4, y*4
  uint8_t u8_FontHeight = mp_CurrentFont->getFontHeight();

  uint16_t u16_StringLenth;
  u16_StringLenth = Utf8::strLength(pc_String);

  for(uint8_t i=0; i<u16_StringLenth; i++)
  {
    u32_CharacterCode=Utf8::toCodepoint(pc_String, i);
    
    if(u32_CharacterCode=='\n')
    {
      mu8_CursorY += u8_FontHeight;
      setDrawRegion(mu8_CursorX, mu8_CursorY, u8_FontHeight);
      continue;
    }
    
    mp_CurrentFont->getCharacterData(&u8_CharacterDataSize, au8_CharacterData, sizeof(au8_CharacterData), u32_CharacterCode);
    drawBuffer(u8_CharacterDataSize, au8_CharacterData);
  }

  return RcOK;
}



SimpleOLED::ERc SimpleOLED::println(const char *pc_String)
{
  print(pc_String);
  print("\n");
  
  return RcOK;
}



SimpleOLED::ERc SimpleOLED::setDrawRegion(const uint8_t u8_Segment, const uint8_t u8_StartPage, const uint8_t u8_Height)
{
  m_DisplayController.setPageAddress(u8_StartPage/8, (u8_StartPage+u8_Height-1)/8);
  m_DisplayController.setColumnAddress(u8_Segment, 0x7f);  
  return RcOK;
}



SimpleOLED::ERc SimpleOLED::drawBuffer(const uint8_t u8_BufferSize, const uint8_t *pu8_Buffer)
{
  m_DisplayController.sendData(pu8_Buffer, u8_BufferSize);
  return RcOK; 
}
