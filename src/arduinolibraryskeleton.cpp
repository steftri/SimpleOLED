#include "arduinolibraryskeleton.h"



ArduinoLibrarySkeleton::ArduinoLibrarySkeleton(void)
  : mu32_Value{0}
{
}



ArduinoLibrarySkeleton::ERc ArduinoLibrarySkeleton::begin(void)
{
  return RcOK;
}



void ArduinoLibrarySkeleton::end(void)
{
}



uint32_t ArduinoLibrarySkeleton::getValue(void)
{
  return mu32_Value;
}



void ArduinoLibrarySkeleton::setValue(const uint32_t u32_Value)
{
  mu32_Value = u32_Value;
}
