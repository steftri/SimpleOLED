#include <Arduino.h>
#include "font.h"




static const uint8_t UNKNOWN_CHAR_DATA[] PROGMEM =
{
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101,
  0b10101010,
  0b01010101
};



Font::Font(const uint8_t u8_Height, 
           const uint16_t u16_SizeOfCharData, const uint8_t *pu8_CharData, 
           const uint16_t u16_NumberOfContCharaters, const uint16_t *pu16_ContCharPos, 
           const uint16_t u16_NumberOfUtf8Characters, const SUtf8CharPos *p_Utf8CharPos)
  : mu8_Height(u8_Height)
  , mu16_SizeOfCharData(u16_SizeOfCharData)
  , mpu8_CharData(pu8_CharData)
  , mu16_NumberOfContCharaters(u16_NumberOfContCharaters)
  , mpu16_ContCharPos(pu16_ContCharPos)
  , mu16_NumberOfUtf8Characters(u16_NumberOfUtf8Characters)
  , mp_Utf8CharPos(p_Utf8CharPos)
{
}


uint8_t Font::getFontHeight(void)
{
  return mu8_Height;
}



Font::ERc Font::getCharacterData(const uint8_t **ppu8_CharDataAddress, uint8_t *pu8_CharWidth, const uint32_t u32_CodePoint)
{
  const uint8_t *pu8_CharDataAddress = UNKNOWN_CHAR_DATA;
  uint8_t u8_CharWidth = 8;
  ERc rc = ERc::Error;

  if(u32_CodePoint<mu16_NumberOfContCharaters)
  {
    // the character is in the range of the first 256 characters, don't use the mapping table

    // ok, we found the character, now we have to calculate the width and the address of the character data
    if(u32_CodePoint>0)
    {
      pu8_CharDataAddress = &mpu8_CharData[pgm_read_word(&mpu16_ContCharPos[u32_CodePoint-1])];
      u8_CharWidth = pgm_read_word(&mpu16_ContCharPos[u32_CodePoint])-pgm_read_word(&mpu16_ContCharPos[u32_CodePoint-1]);
    }
    else
    {
      pu8_CharDataAddress = mpu8_CharData;
      u8_CharWidth = pgm_read_word(&mpu16_ContCharPos[0]);
    }

    rc = ERc::OK;
  }
  else
  {
    // search for the character in the mapping table
    for(uint16_t i=0; i<mu16_NumberOfUtf8Characters; i++)
    {
      if(pgm_read_dword(&mp_Utf8CharPos[i].u32_CodePoint)==u32_CodePoint)
      {
        pu8_CharDataAddress = &mpu8_CharData[pgm_read_word(&mp_Utf8CharPos[i].u16_CharPos)];
        u8_CharWidth = pgm_read_byte(&mp_Utf8CharPos[i].u8_CharWidth);
        rc = ERc::OK;
        break;
      }
    }
  }

  if(ppu8_CharDataAddress)
    *ppu8_CharDataAddress = pu8_CharDataAddress;
  if(pu8_CharWidth)
    *pu8_CharWidth = u8_CharWidth;

  return rc;
}
