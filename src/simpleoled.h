#ifndef _LIB_SIMPLEOLED_H_
#define _LIB_SIMPLEOLED_H_

#include <inttypes.h>



class SimpleOLED
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
  SimpleOLED(void);

  ERc begin(void);
  void end(void);

  uint32_t getValue(void);
  void setValue(const uint32_t u32_Value);
};

#endif
