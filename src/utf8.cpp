#include "utf8.h"




size_t Utf8::strLength(const char *pc_Utf8String)
{
  size_t length = 0;

  for(size_t i=0; pc_Utf8String[i]; i++)
  {
    if((pc_Utf8String[i]&0x80)==0)
    {
      // 1 byte character
      length++;
    }
    else if((pc_Utf8String[i]&0xe0)==0xc0)
    {
      // 2 byte character
      if(pc_Utf8String[i+1]==0)
        break;
      i++;
      length++;
    }
    else if((pc_Utf8String[i]&0xf0)==0xe0)
    {
      // 3 byte character
      if((pc_Utf8String[i+1]==0) || (pc_Utf8String[i+2]==0))
        break;
      i+=2;
      length++;
    }
    else if((pc_Utf8String[i]&0xf8)==0xf0)
    {
      // 4 byte character
      if((pc_Utf8String[i+1]==0) || (pc_Utf8String[i+2]==0) || (pc_Utf8String[i+3]==0))
        break;
      i+=3;
      length++;
    }
  }

  return length;
}


uint32_t Utf8::toCodepoint(const char *pc_Utf8Char)
{
  uint32_t u32_Codepoint = 0;

  if(pc_Utf8Char==nullptr)
    return 0;

  if((pc_Utf8Char[0]&0x80)==0)
  {
    // 1 byte character
    u32_Codepoint = pc_Utf8Char[0];
  }
  else if((pc_Utf8Char[0]&0xe0)==0xc0)
  {
    // 2 byte character
    u32_Codepoint = ((pc_Utf8Char[0]&0x1f)<<6) | (pc_Utf8Char[1]&0x3f);
  }
  else if((pc_Utf8Char[0]&0xf0)==0xe0)
  {
    // 3 byte character
    u32_Codepoint = ((pc_Utf8Char[0]&0x0f)<<12) | ((pc_Utf8Char[1]&0x3f)<<6) | (pc_Utf8Char[2]&0x3f);
  }
  else if((pc_Utf8Char[0]&0xf8)==0xf0)
  {
    // 4 byte character
    u32_Codepoint = ((pc_Utf8Char[0]&0x07)<<18) | ((pc_Utf8Char[1]&0x3f)<<12) | ((pc_Utf8Char[2]&0x3f)<<6) | (pc_Utf8Char[3]&0x3f);
  }

  return u32_Codepoint;
}


uint32_t Utf8::toCodepoint(const char *pc_Utf8String, const uint16_t u16_Position)
{
  return toCodepoint(getCharPointer(pc_Utf8String, u16_Position));
}


const char * Utf8::getCharPointer(const char *pc_Utf8String, const uint16_t u16_Position)
{
  size_t i;
  uint16_t u16_CharCount = 0;

  for(i=0; u16_CharCount<u16_Position && pc_Utf8String[i]; i++)
  {
    if((pc_Utf8String[i]&0x80)==0)
    {
      // 1 byte character
      u16_CharCount++;
    }
    else if((pc_Utf8String[i]&0xe0)==0xc0)
    {
      // 2 byte character
      if(pc_Utf8String[i+1]==0)
        return nullptr;
      i++;
      u16_CharCount++;
    }
    else if((pc_Utf8String[i]&0xf0)==0xe0)
    {
      // 3 byte character
      if((pc_Utf8String[i+1]==0) || (pc_Utf8String[i+2]==0))
        return nullptr;
      i+=2;
      u16_CharCount++;
    }
    else if((pc_Utf8String[i]&0xf8)==0xf0)
    {
      // 4 byte character
      if((pc_Utf8String[i+1]==0) || (pc_Utf8String[i+2]==0) || (pc_Utf8String[i+3]==0))
        return nullptr;
      i+=3;
      u16_CharCount++;
    }
  }
  if(pc_Utf8String[i]==0)
    return nullptr;

  return &pc_Utf8String[i];
}

