#include "pitches.h"

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

#define BUTTON_STICKYNESS 10

int led_pin = 13;
int buzzer_pin = 3;
int tx_pin = 7;
int rx_pin = 8;
int button_pin = 2;

int collision_note = NOTE_C4;
int note = NOTE_C6;

int tx = 0;
int rx = 0;
int muted = 0;

void setup() {
    pinMode(led_pin, OUTPUT);
    pinMode(button_pin, INPUT);
    pinMode(rx_pin, INPUT);
    pinMode(tx_pin, OUTPUT);
}

void loop() {
    tx = digitalRead(button_pin) == HIGH;
    rx = digitalRead(rx_pin) == HIGH;

    rx = 0;

    if (tx && !rx) {
        digitalWrite(led_pin, HIGH);
        digitalWrite(tx_pin, HIGH);
        tone(buzzer_pin, note);
        muted = 0;
    } else if (!tx && rx) {
        digitalWrite(led_pin, HIGH);
        tone(buzzer_pin, note);
        muted = 0;
    } else if (tx && rx) {
        tone(buzzer_pin, collision_note);
        muted = 0;
    } else {
        digitalWrite(led_pin, LOW);
        if (!muted) {
            tone(buzzer_pin, MUTE);
        }
        muted = 1;
    }
  delay(BUTTON_STICKYNESS);

/*
    for (int i = 0; i < NELEMS(full_scale); i++) {
        tone(buzzer_pin, full_scale[i]);
        delay(1000);
    }
*/

}
