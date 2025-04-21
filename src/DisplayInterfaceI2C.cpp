#include <Arduino.h>
#include <Wire.h>

#include "DisplayInterfaceI2C.h"

static constexpr uint8_t TWI_DISPLAY_COMMAND = 0x00; 
static constexpr uint8_t TWI_DISPLAY_DATA = 0x40;
static constexpr uint8_t MAX_BYTES_PER_TANSMISSION = 30;



DisplayInterfaceI2C::DisplayInterfaceI2C(const uint8_t u8_Address)
 : mp_TwoWire(&Wire)
  , mu32_clkDuring(400000UL)
  , mu32_ClkAfter(100000UL)
  , mu8_Address(u8_Address)
{
}



DisplayInterfaceI2C::DisplayInterfaceI2C(TwoWire *p_TwoWire, const uint8_t u8_Address, const uint32_t u32_clkDuring, const uint32_t u32_ClkAfter)
 : mp_TwoWire(p_TwoWire)
 , mu32_clkDuring(u32_clkDuring)
 , mu32_ClkAfter(u32_ClkAfter)
 , mu8_Address(static_cast<uint8_t>(u8_Address))
{
}



void DisplayInterfaceI2C::begin(void)
{
}



void DisplayInterfaceI2C::end(void)
{
}



void DisplayInterfaceI2C::sendCmd(const uint8_t *pu8_CmdBuffer, const size_t cmdSize)
{
  mp_TwoWire->setClock(mu32_clkDuring); // set I2C clock to 400kHz (fast mode)

  mp_TwoWire->beginTransmission(mu8_Address);
  mp_TwoWire->write(TWI_DISPLAY_COMMAND);           // write DisplayCommand or DisplayData
  for(uint8_t i=0; i<cmdSize; i++)
  {
    mp_TwoWire->write(pu8_CmdBuffer?pu8_CmdBuffer[i]:0); // write zeros if pu8_Buffer is NULL
  }
  mp_TwoWire->endTransmission();

  mp_TwoWire->setClock(mu32_ClkAfter); // set I2C clock back to 100kHz (standard mode)
}



void DisplayInterfaceI2C::sendData(const uint8_t *pu8_DataBuffer, const size_t dataSize)
{
  mp_TwoWire->setClock(mu32_clkDuring); // set I2C clock to 400kHz (fast mode)

  for(uint8_t u8_x=0; u8_x<dataSize; u8_x+=MAX_BYTES_PER_TANSMISSION)
  {
    size_t packetSize = (dataSize-u8_x>MAX_BYTES_PER_TANSMISSION)?MAX_BYTES_PER_TANSMISSION:(dataSize-u8_x);

    mp_TwoWire->beginTransmission(mu8_Address);

    mp_TwoWire->write(TWI_DISPLAY_DATA);          
    for(uint8_t i=0; i<packetSize; i++)
    {
      mp_TwoWire->write(pu8_DataBuffer?pu8_DataBuffer[u8_x+i]:0);   // write zeros if pu8_Buffer is NULL
    }
    mp_TwoWire->endTransmission();    
  }

  mp_TwoWire->setClock(mu32_ClkAfter); // set I2C clock back to 100kHz (standard mode)
}
