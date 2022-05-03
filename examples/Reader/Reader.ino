#include <FdxB.h>

#define INTERRUPT_PIN 2

FdxB::Parser parser;

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  noInterrupts();
  setupPwmSquareWave();
  setupPinChangeInterrupt();
  interrupts();

  Serial.println("Ready!");
}

void loop() {
  FdxB::tag_t tag;

  if (!parser.getTag(&tag))
    return;

  Serial.println("Success!");

  char buffer[16]; // 15 digit unique id plus a null terminator.

  // printf cannot format integers larger then 32-bits.
  // The id field is 38-bits so we need to do some additional processing to it.
  uint32_t idMsd = tag.id / 1000000000;
  uint32_t idLsd = tag.id % 1000000000;

  // This is the format that pet microchip lookup websites expect.
  sprintf(buffer, "%03u%03lu%09lu", (uint16_t) tag.country, idMsd, idLsd);
  Serial.println(buffer);

  if (tag.flags & FdxB::Flag::APPLICATION) {
    Serial.print("This tag is intended for animal use ");
  }
  else {
    Serial.print("This tag is NOT intended for animal use ");
  }

  if (tag.flags & FdxB::Flag::DATA) {
      Serial.println("and contains extra data.");
      sprintf(buffer, "0x%02X%02X%02X", tag.data[0], tag.data[1], tag.data[2]);
      Serial.println(buffer);
  }
  else {
    Serial.println("and does not contain extra data.");
  }

  Serial.println("========================================");
}

void setupPwmSquareWave() {
  // Setup timer 1 of a 16mHz Arduino Nano to output a square wave on pin 9.

  // Set PB1 to be an output.
  DDRB |= (1 << PB1);

  // Clear Timer/Counter Control Registers.
  TCCR1A = 0;
  TCCR1B = 0;

  // Set non-inverting mode.
  TCCR1A |= (1 << COM1A1);

  // Set fast PWM Mode 14.
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << WGM13);

  // Prescaler 1 (base clock).
  TCCR1B |= (1 << CS10);

  // Set PWM frequency.
  // ISO 11784/11785 RFID tag carrier frequency 134.2kHz.
  // Arduino PWM can achieve 134.454kHz which is close enough.
  ICR1 = F_CPU / 134200 / 1 - 1;
  OCR1A = ICR1 / 2;
}

void setupPinChangeInterrupt() {
  pinMode(INTERRUPT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN),
                  pinChangeInterrupt,
                  CHANGE);
}

void pinChangeInterrupt() {
  parser.putStateChange();
}
