#include "simpleoled.h"



SimpleOLED::SimpleOLED(void)
  : mu32_Value{0}
{
}



SimpleOLED::ERc SimpleOLED::begin(void)
{
  return RcOK;
}



void SimpleOLED::end(void)
{
}



uint32_t SimpleOLED::getValue(void)
{
  return mu32_Value;
}



void SimpleOLED::setValue(const uint32_t u32_Value)
{
  mu32_Value = u32_Value;
}
