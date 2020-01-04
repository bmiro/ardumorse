#include "pitches.h"

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

#define BUTTON_STICKYNESS 10

int led_pin = 13;
int buzzer_pin = 3;
int tx_pin = 7;
int rx_pin = 8;
int button_pin = 4;

int collision_note = NOTE_C4;
int note = NOTE_C6;

int tx = 0;
int rx = 0;

void setup() {
    pinMode(led_pin, OUTPUT);
    pinMode(button_pin, INPUT);
    pinMode(rx_pin, INPUT);
    pinMode(tx_pin, OUTPUT);
}

void loop() {
    tx = digitalRead(button_pin) == LOW;
    rx = digitalRead(rx_pin) == LOW;

    if (tx && !rx) {
        digitalWrite(led_pin, HIGH);
        digitalWrite(tx_pin, HIGH);
        tone(buzzer_pin, note);
    if (!tx && rx) {
        digitalWrite(led_pin, HIGH);
        tone(buzzer_pin, collision_note);
    } else if (tx && rx)
        tone(buzzer_pin, note);
    } else {
        digitalWrite(led_pin, LOW);
        tone(buzzer_pin, MUTE);
    }
  delay(BUTTON_STICKYNESS);
}
