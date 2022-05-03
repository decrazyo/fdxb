#include "FdxB.h"

FdxB::Fifo::Fifo(uint8_t size) {
  mBuffer = (uint8_t *) malloc(size);
  mSize = size - 1;
}

FdxB::Fifo::~Fifo() {
  free(mBuffer);
}

void FdxB::Fifo::push(uint8_t value) {
  mBuffer[mWrite] = value;
  next(&mWrite);
  if (empty())
    next(&mRead);
}

bool FdxB::Fifo::pop(uint8_t *value) {
  bool status = peek(value);
  if(status)
    next(&mRead);
  return status;
}

bool FdxB::Fifo::peek(uint8_t *value) {
  if (empty())
    return false;
  *value = mBuffer[mRead];
  return true;
}

bool FdxB::Fifo::empty() {
  return mRead == mWrite;
}

inline void FdxB::Fifo::next(uint8_t *index) {
  if (*index)
    (*index)--;
  else
    *index = mSize;
}
