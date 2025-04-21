#ifndef DISPLAYCONTROLLER_SSD1306_H
#define DISPLAYCONTROLLER_SSD1306_H


#include <inttypes.h>

#include "DisplayInterface.h"


class DisplayControllerSSD1306 
{
private:
  DisplayInterface *mp_DisplayInterface;

public: 
  DisplayControllerSSD1306(DisplayInterface *p_DisplayInterface);

  // Fundamental commands
  void setContrastControl(const uint8_t u8_Contrast);
  void setEntireDisplayOn(const bool b_Enabled);
  void setInverseDisplay(const bool b_InverseEnabled);
  void setDisplayOn(const bool b_Enabled);

  // Addressing setting commands
  //void setLowerColumnStartAddress(const uint8_t u8_Address);
  //void setHigherColumnStartAddress(const uint8_t u8_Address);

  enum class EAddressingMode
  {
    Horizontal = 0x00,
    Vertical = 0x01,
    Page = 0x02,
  };
  void setMemoryAddressingMode(const EAddressingMode e_Mode);
  void setColumnAddress(const uint8_t u8_StartAddress, const uint8_t u8_EndAddress);
  void setPageAddress(const uint8_t u8_StartAddress, const uint8_t u8_EndAddress);
  void setPageStartAddress(const uint8_t u8_PageStartAddress);

  // Hardware configuration commands
  void setDisplayStartLine(const uint8_t u8_StartLine);

  void setSegmentRemap(const bool b_Enabled);
  void setMultiplexRatio(const uint8_t u8_Ratio);

  enum class EScanDirection
  {
    Normal = 0x00,
    Remapped = 0x01,
  };
  void setComOutputScanDirection(const EScanDirection e_RemappedMode);
  void setDisplayOffset(const uint8_t u8_VerticalShift);
  void setComPinsHardwareConfig(const bool b_AlternativePinConfig, const bool b_EnableLeftRightRemap);
  void setDisplayClock(const uint8_t u8_DivideRatio, const uint8_t u8_OscillatorFrequency);
  void setPrechargePeriod(const uint8_t u8_PrechargePeriod);

  // Charge pump commands
  void setChargePumpRegulator(const bool b_Enabled);

  void sendData(const uint8_t *pu8_DataBuffer, const size_t dataSize);
};


#endif