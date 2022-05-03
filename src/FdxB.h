
#ifndef FDXB_H
#define FDXB_H

#include <Arduino.h>

// ISO 11784/11785 RFID tag carrier frequency 134.2kHz.
// 134.454kHz is as close as Arduino PWM can achieve.
#ifndef FDXB_CARRIER_HZ
#define FDXB_CARRIER_HZ 134454
#endif

// Header requires 21 state changes.
// Control bits require 13 state changes.
// All other data will require 208 state changes at most.
// Plus 1 for the trailing state change.
// 21 + 13 + 208 + 1 = 243
// Enough space to store an entire tag in the worst case.
// This is probably overkill.
#ifndef FDXB_BUFFER_SIZE
#define FDXB_BUFFER_SIZE 243
#endif

namespace FdxB {
  #pragma pack(1)
  typedef struct Tag {
    uint64_t id : 38;
    uint64_t country : 10;
    uint64_t flags : 16; // 2 flag bits, 14 reserved bits
    uint16_t checksum; // crc16
    uint8_t data[3];
  } tag_t;

  typedef enum Flag {
    DATA = (1 << 0),
    APPLICATION = (1 << 15),
  } flag_t;

  class Fifo {
  // Simple first in, first out (FIFO) ring buffer.
  public:
    Fifo(uint8_t size=FDXB_BUFFER_SIZE);
    ~Fifo();

    void push(uint8_t value);
    bool pop(uint8_t *value);
    bool peek(uint8_t *value);
    bool empty();

  private:
    uint8_t mSize;
    uint8_t *mBuffer;
    volatile uint8_t mRead = 0;
    uint8_t mWrite = 0;

    inline void next(uint8_t *index);
  };

  class Decoder {
  public:
    Decoder(uint32_t carrierHz=FDXB_CARRIER_HZ,
            uint8_t bufferSize=FDXB_BUFFER_SIZE);
    ~Decoder();

    inline void putStateChange() {putStateChange(micros());}
    void putStateChange(uint16_t time);
    bool getBit(uint8_t *value);

  private:
    Fifo *mFifo;
    uint16_t mMicros;
    float mBaud;

    void getDelta(uint8_t *value);
  };

  class Parser {
  public:
    Parser(uint32_t carrierHz=FDXB_CARRIER_HZ,
           uint8_t bufferSize=FDXB_BUFFER_SIZE);
    ~Parser();

    inline void putStateChange() {putStateChange(micros());}
    void putStateChange(uint16_t time);
    bool getTag(tag_t *tag);

  private:
    Decoder *mDecoder;

    void findHeader();
    bool getByte(uint8_t *value);
    uint16_t crc16k(uint16_t crc, uint8_t *mem, uint8_t len);
    bool getData(uint8_t *data);
  };
}

#endif
