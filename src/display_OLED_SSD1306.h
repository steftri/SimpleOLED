//
//  DISPLAY_OLED_SSD1306.hpp
//  SimpleOLED
//
//  Created by Stefan on 2021-02-23.
//

#ifndef DISPLAY_OLED_SSD1306_hpp
#define DISPLAY_OLED_SSD1306_hpp

#include <stdio.h>
#include <string.h>


typedef enum { DisplayCommand = 0x00, DisplayData = 0x40 } EContent;

class display
{
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
  
public:
  display(uint8_t u8_WireAddr, uint8_t u8_Width, uint8_t u8_Height);
  
  int32_t init(const bool b_Enable = true);
  int32_t enable(const bool b_Enable);
  
  int32_t clear(void);
  int32_t setFont(const char *pu8_Name, const bool b_DoubleHeight = false);
  int32_t setCursor(const uint8_t u8_Column, const uint8_t u8_Row);  // in characters
  int32_t print(const char *puc_String);
  int32_t println(const char *puc_String);

  int32_t setDrawRegion(const uint8_t u8_Segment, const uint8_t u8_StartPage, const uint8_t u8_Pages = 1);
  int32_t drawBuffer(const uint8_t u8_Bytes, const uint8_t *pu8_Buffer);

private:
  int32_t _send(const EContent e_Content, const uint8_t u8_BufferSize, const uint8_t *pu8_Buffer);
};


#endif /* DISPLAY_OLED_SSD1306_hpp */
