#include "FdxB.h"

FdxB::Parser::Parser(uint32_t carrierHz, uint8_t bufferSize) {
  mDecoder = new Decoder(carrierHz, bufferSize);
}

FdxB::Parser::~Parser() {
  delete mDecoder;
}

void FdxB::Parser::putStateChange(uint16_t time) {
  mDecoder->putStateChange(time);
}

bool FdxB::Parser::getTag(tag_t *tag) {
  return getData((uint8_t*) tag);
}

void FdxB::Parser::findHeader() {
  uint8_t bit;
  uint8_t count = 0;

  // The header starts with 10 zeros and ends with a one.
  // Don't exit this loop until we find the header.
  while (true) {
    if (!mDecoder->getBit(&bit)) {
      // bit read failed
      count = 0;
    }
    else if (bit) {
      if (count >= 10) {
        // header identified
        break;
      }
      else {
        // expected another 0, got 1
        count = 0;
      }
    }
    else if (count < 10) {
      count++;
    }
  }
}

bool FdxB::Parser::getByte(uint8_t *value) {
  uint8_t bit;

  *value = 0;

  for(uint8_t i = 0; i < 8; i++) {
    if (!mDecoder->getBit(&bit)) {
      // failed bit read
      return false;
    }
    *value |= bit << i;
  }

  if (!mDecoder->getBit(&bit)) {
    // failed control bit read
    return false;
  }
  else if (bit) {
    // valid control bit
    return true;
  }
  else {
    // invalid control bit
    return false;
  }
}

// https://stackoverflow.com/questions/57893261
uint16_t FdxB::Parser::crc16k(uint16_t crc, uint8_t *mem, uint8_t len) {
    uint8_t *data = mem;

    if (data == NULL) {
        return 0;
    }

    while (len--) {
        crc ^= *data++;
        for (uint8_t k = 0; k < 8; k++)
            crc = crc & 1 ? (crc >> 1) ^ 0x8408 : crc >> 1;
    }

    return crc;
}

bool FdxB::Parser::getData(uint8_t *data) {
  // Block until we identify a valid tag header.
  findHeader();

  tag_t *tag = (tag_t*) data;

  // Get the first 10 byte which should always exist in the tag.
  for (uint8_t i = 0; i < 10; i++) {
    if (!getByte(&data[i])) {
      // read bad data
      return false;
    }
  }

  // Get an extra 3 bytes if the tag says they exist.
  if (tag->flags & DATA) {
    for (uint8_t i = 10; i < 13; i++) {
      if (!getByte(&data[i])) {
        return false;
      }
    }
  }

  // verify checksum
  return crc16k(0, data, 8) == tag->checksum;
}
