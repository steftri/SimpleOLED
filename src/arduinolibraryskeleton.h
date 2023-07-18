#ifndef _LIB_ARDUINO_LIBRARY_SKELETON_H_
#define _LIB_ARDUINO_LIBRARY_SKELETON_H_

#include <inttypes.h>



class ArduinoLibrarySkeleton
{
public:
  typedef enum
  {
    RcOK = 0,
    RcError = -1
  } ERc;

private:
  uint32_t mu32_Value;

public:
  ArduinoLibrarySkeleton(void);

  ERc begin(void);
  void end(void);

  uint32_t getValue(void);
  void setValue(const uint32_t u32_Value);
};

#endif
