#ifndef DISPLAYCONTROLLER_SSD1306_H
#define DISPLAYCONTROLLER_SSD1306_H


#include <inttypes.h>

#include "displayinterface.h"


class DisplayControllerSSD1306 
{
private:
  DisplayInterface *mp_DisplayInterface;

public: 
  DisplayControllerSSD1306(DisplayInterface *p_DisplayInterface);

  // Fundamental commands
  void setContrastControl(const uint8_t u8_Contrast);   // \x81\x7f
  void setEntireDisplayOn(const bool b_Enabled);    // \xa4
  void setInverseDisplay(const bool b_InverseEnabled);    // \xA6
  void setDisplayOn(const bool b_Enabled); //

  // Addressing setting commands
  //void setLowerColumnStartAddress(const uint8_t u8_Address);
  //void setHigherColumnStartAddress(const uint8_t u8_Address);

  enum class EAddressingMode
  {
    Horizontal = 0x00,
    Vertical = 0x01,
    Page = 0x02,
  };
  void setMemoryAddressingMode(const EAddressingMode e_Mode);    // \x20
  void setColumnAddress(const uint8_t u8_StartAddress, const uint8_t u8_EndAddress);
  void setPageAddress(const uint8_t u8_StartAddress, const uint8_t u8_EndAddress);
  void setPageStartAddress(const uint8_t u8_PageStartAddress);

  // Hardware configuration commands
  void setDisplayStartLine(const uint8_t u8_StartLine);  // \x40

  void setSegmentRemap(const bool b_Enabled);   // \xa1
  void setMultiplexRatio(const uint8_t u8_Ratio);    // 0xa8

  enum class EScanDirection
  {
    Normal = 0x00,
    Remapped = 0x01,
  };  
  void setComOutputScanDirection(const EScanDirection e_RemappedMode);   // \xc8
  void setDisplayOffset(const uint8_t u8_VerticalShift);   // \xd3
  void setComPinsHardwareConfig(const bool b_AlternativePinConfig, const bool b_EnableLeftRightRemap);   // \xDA\x12":"\xDA\x02"
  void setDisplayClock(const uint8_t u8_DivideRatio, const uint8_t u8_OscillatorFrequency);    // \xD5\x80
  void setPrechargePeriod(const uint8_t u8_PrechargePeriod);  // \xAF":"\xAE"

  // Charge pump commands
  void setChargePumpRegulator(const bool b_Enabled);   // \x8d\x14

  void sendData(const uint8_t *pu8_DataBuffer, const size_t dataSize);
};


#endif