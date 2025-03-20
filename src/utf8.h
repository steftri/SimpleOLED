#ifndef UTF8_H
#define UTF8_H

#include <inttypes.h>

class Utf8
{
private:
  static const char *getCharPointer(const char *pc_Utf8String, const uint16_t u16_Position);

public:
  static size_t strLength(const char *pc_Utf8String);
  static uint32_t toCodepoint(const char *pc_Utf8Char);
  static uint32_t toCodepoint(const char *pc_Utf8String, const uint16_t u16_Position);
};

#endif