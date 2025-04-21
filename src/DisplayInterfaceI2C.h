#ifndef _DISPLAY_INTERFACE_I2C_H_
#define _DISPLAY_INTERFACE_I2C_H_

#include <Wire.h>

#include <stdlib.h>
#include <inttypes.h>

#include "TinyDisplay.h"



class DisplayInterfaceI2C : public DisplayInterface 
{
  TwoWire *mp_TwoWire;
  uint32_t mu32_clkDuring;
  uint32_t mu32_ClkAfter;
  uint8_t mu8_Address;

public:
  DisplayInterfaceI2C(const uint8_t u8_Address = 0x3C);
  DisplayInterfaceI2C(TwoWire *p_TwoWire = &Wire, const uint8_t u8_Address = 0x3C, const uint32_t u16_clkDuring = 400000UL, const uint32_t u16_ClkAfter = 100000UL);
 
  void begin(void) override;           
  void end(void) override;
  
  void sendCmd(const uint8_t *pu8_CmdBuffer, const size_t cmdSize) override;
  void sendData(const uint8_t *pu8_DataBuffer, const size_t dataSize) override;
};


#endif