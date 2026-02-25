#include <MIDIUSB.h>

// Pedals wired as simple switches to GND, using INPUT_PULLUP.
// Pressed = LOW, Released = HIGH.

struct Pedal {
  uint8_t pin;
  uint8_t cc;
  bool stablePressed;        // debounced state
  bool lastRawPressed;       // last raw read
  unsigned long lastChangeMs;
};

constexpr uint8_t MIDI_CH = 1;          // 1..16
constexpr unsigned long DEBOUNCE_MS = 8;

Pedal pedals[] = {
  {A0, 64, false, false, 0},  // Sustain
  {A1, 66, false, false, 0},  // Sostenuto
  {A2, 69, false, false, 0},  // Harmonic (assigned in PianoTeq)
  {A3, 67, false, false, 0},  // Una Corda / Soft
};

void sendCC(uint8_t cc, uint8_t value) {
  uint8_t status = 0xB0 | ((MIDI_CH - 1) & 0x0F);
  midiEventPacket_t evt = {0x0B, status, cc, value};
  MidiUSB.sendMIDI(evt);
  MidiUSB.flush();
}

void setup() {
  for (auto &p : pedals) {
    pinMode(p.pin, INPUT_PULLUP);
    // initialize debounced state from current reading
    bool pressed = (digitalRead(p.pin) == LOW);
    p.stablePressed = pressed;
    p.lastRawPressed = pressed;
    p.lastChangeMs = millis();
    // Optional: send initial "up" state so PianoTeq starts clean
    sendCC(p.cc, pressed ? 127 : 0);
  }
}

void loop() {
  unsigned long now = millis();

  for (auto &p : pedals) {
    bool rawPressed = (digitalRead(p.pin) == LOW);

    if (rawPressed != p.lastRawPressed) {
      p.lastRawPressed = rawPressed;
      p.lastChangeMs = now;
    }

    // If raw has been stable long enough and differs from debounced state, commit it
    if ((now - p.lastChangeMs) >= DEBOUNCE_MS && rawPressed != p.stablePressed) {
      p.stablePressed = rawPressed;
      sendCC(p.cc, p.stablePressed ? 127 : 0);
    }
  }
}