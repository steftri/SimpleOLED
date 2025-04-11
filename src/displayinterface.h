#ifndef DISPLAYINTERFACE_H
#define DISPLAYINTERFACE_H

#include <stddef.h>
#include <inttypes.h>

class DisplayInterface
{
public:  
  virtual void begin(void) = 0;
  virtual void end(void) = 0;
  virtual void sendCmd(const uint8_t *pCmdBuffer, const size_t cmdSize) = 0;
  virtual void sendData(const uint8_t *pDataBuffer, const size_t dataSize) = 0;
};

#endif
