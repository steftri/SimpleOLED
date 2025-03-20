#ifndef FONT_H
#define FONT_H

#include <inttypes.h>

class Font
{  
public:
  typedef struct 
  {
    uint32_t u32_CodePoint;
    uint16_t u16_CharPos;
    uint8_t u8_CharWidth;
  } SUtf8CharPos;

private:  
  uint8_t mu8_Height;
  uint8_t mu8_Baseline;

  uint16_t mu16_SizeOfCharData;
  const uint8_t *mpu8_CharData;

  uint16_t mu16_NumberOfContCharaters;
  const uint16_t *mpu16_ContCharPos;

  uint16_t mu16_NumberOfUtf8Characters;
  const SUtf8CharPos *mp_Utf8CharPos;

protected:
  Font(const uint8_t mu8_Height, 
       const uint16_t u16_SizeOfCharData, const uint8_t *pu8_CharData, 
       const uint16_t u16_NumberOfContCharaters, const uint16_t *pu16_ContCharPos, 
       const uint16_t u16_NumberOfUtf8Characters, const SUtf8CharPos *p_Utf8CharPos);

public:
  enum class ERc
  {
    OK,
    Error
  };

  uint8_t getFontHeight(void);
  ERc getCharacterData(const uint8_t **ppu8_CharDataAddress, uint8_t *pu8_CharWidth, const uint32_t u32_CodePoint);
};


#endif