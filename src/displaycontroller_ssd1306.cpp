#include "displayinterface.h"

#include "displaycontroller_ssd1306.h"


enum class ECmd
{
  SetContrastControl = 0x81,
  SetEntireDisplayOn = 0xA5,
  SetEntireDisplayOff = 0xA4,
  SetNormalDisplay = 0xA6,
  SetInverseDisplay = 0xA7,
  SetDisplayOff = 0xAE,
  SetDisplayOn = 0xAF,
  SetMemoryAddressingMode = 0x20,
  SetSegmentRemapOff = 0xA0,
  SetSegmentRemapOn = 0xA1,
  SetMultiplexRatio = 0xA8,
  SetComOutputScanDirectionNormal = 0xC0,
  SetComOutputScanDirectionRemapped = 0xC8,
  SetDisplayOffset = 0xD3,
  SetComPinsHardwareConfig = 0xDA,
  SetDisplayClock = 0xD5,
  SetChargePump = 0x8D,
  SetDisplayStartLine = 0x40,
  SetColumnAddress = 0x21,
  SetPageAddress = 0x22,
};

enum class EChargePump
{
  Disable = 0x10,
  Enable = 0x14,
};



enum class EDisplayControllerCommand2
{
  SetSegmentRemap = 0xA1,
  SetComOutputScanDirection = 0xC8,
  SetComPinsHardwareConfiguration = 0xDA,
  SetContrastControl = 0x81,
  SetEntireDisplayOn = 0xA4,
  SetOscFrequency = 0xD5,
  SetChargePumpRegulator = 0x8D,
};




DisplayControllerSSD1306::DisplayControllerSSD1306(DisplayInterface *p_DisplayInterface)
 : mp_DisplayInterface{p_DisplayInterface}
{
}


void DisplayControllerSSD1306::setContrastControl(const uint8_t u8_Contrast)
{
  uint8_t au8_Cmd[2] = {(uint8_t)ECmd::SetContrastControl, u8_Contrast};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setEntireDisplayOn(const bool b_Enabled)
{
  uint8_t au8_Cmd[1] = {(uint8_t)(b_Enabled ? ECmd::SetEntireDisplayOn : ECmd::SetEntireDisplayOff)};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setInverseDisplay(const bool b_InverseEnabled)
{
  uint8_t au8_Cmd[1] = {(uint8_t)(b_InverseEnabled ? ECmd::SetInverseDisplay : ECmd::SetNormalDisplay)};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setDisplayOn(const bool b_Enabled)
{
  uint8_t au8_Cmd[1] = {(uint8_t)(b_Enabled ? ECmd::SetDisplayOn : ECmd::SetDisplayOff)};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setMemoryAddressingMode(const EAddressingMode e_Mode)
{
  uint8_t au8_Cmd[2] = {(uint8_t)ECmd::SetMemoryAddressingMode, (uint8_t)e_Mode};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setColumnAddress(const uint8_t u8_StartAddress, const uint8_t u8_EndAddress)
{
  uint8_t au8_Cmd[3] = {(uint8_t)ECmd::SetColumnAddress, u8_StartAddress, u8_EndAddress};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setPageAddress(const uint8_t u8_StartAddress, const uint8_t u8_EndAddress)
{
  uint8_t au8_Cmd[3] = {(uint8_t)ECmd::SetPageAddress, u8_StartAddress, u8_EndAddress};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setPageStartAddress(const uint8_t u8_PageStartAddress)
{
  uint8_t au8_Cmd[2] = {(uint8_t)ECmd::SetPageAddress, u8_PageStartAddress};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setDisplayStartLine(const uint8_t u8_StartLine)
{
  uint8_t au8_Cmd[1] = {(uint8_t)((uint8_t)ECmd::SetDisplayStartLine | (u8_StartLine&0x3f))};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setSegmentRemap(const bool b_Enabled)
{
  uint8_t au8_Cmd[1] = {(uint8_t)(b_Enabled ? ECmd::SetSegmentRemapOn : ECmd::SetSegmentRemapOff)};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setMultiplexRatio(const uint8_t u8_Ratio)
{
  uint8_t au8_Cmd[2] = {(uint8_t)ECmd::SetMultiplexRatio, u8_Ratio};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setComOutputScanDirection(const DisplayControllerSSD1306::EScanDirection e_ScanDirection)
{
  uint8_t au8_Cmd[1] = {(uint8_t)(e_ScanDirection==EScanDirection::Remapped ? ECmd::SetComOutputScanDirectionRemapped : ECmd::SetComOutputScanDirectionNormal)};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setDisplayOffset(const uint8_t u8_VerticalShift)
{
  uint8_t au8_Cmd[2] = {(uint8_t)ECmd::SetDisplayOffset, u8_VerticalShift};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setComPinsHardwareConfig(const bool b_AlternativePinConfig, const bool b_EnableLeftRightRemap)
{
  uint8_t au8_Cmd[2] = {(uint8_t)ECmd::SetComPinsHardwareConfig, (uint8_t)(0x02 | (b_AlternativePinConfig ? 0x10 : 0x00) | (b_EnableLeftRightRemap ? 0x20 : 0x00))};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setDisplayClock(const uint8_t u8_DivideRatio, const uint8_t u8_OscillatorFrequency)
{
  uint8_t au8_Cmd[2] = {(uint8_t)ECmd::SetDisplayClock, (uint8_t)(((u8_OscillatorFrequency&0xf)<<4) | ((u8_DivideRatio-1)&0xf))};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}


void DisplayControllerSSD1306::setPrechargePeriod(const uint8_t u8_PrechargePeriod)
{
  uint8_t au8_Cmd[2] = {(uint8_t)ECmd::SetComPinsHardwareConfig, u8_PrechargePeriod};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::setChargePumpRegulator(const bool b_Enabled)
{
  uint8_t au8_Cmd[2] = {(uint8_t)ECmd::SetChargePump, (uint8_t)(b_Enabled ? EChargePump::Enable : EChargePump::Disable)};
  mp_DisplayInterface->sendCmd(au8_Cmd, sizeof(au8_Cmd));
}

void DisplayControllerSSD1306::sendData(const uint8_t *pu8_DataBuffer, const size_t dataSize)
{
  mp_DisplayInterface->sendData(pu8_DataBuffer, dataSize);
}

