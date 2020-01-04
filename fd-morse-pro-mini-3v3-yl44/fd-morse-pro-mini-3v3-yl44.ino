int led = 13;
int speakerPin = 3;
int numTones = 26;
int tones[] = {261, 349, 392, 440, 392, 330, -10, 261, 349, 392, 440, 392, -10, -10, 261, 349, 392, 440, 392, 330, -10, 330, 349, 330, 261, 261};

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  for (int i = 0; i < numTones; i++)
  {
    digitalWrite(led, HIGH);
    tone(speakerPin, tones[i]);
    delay(550);
  }
  digitalWrite(led, LOW);
  tone(speakerPin, -10);
  delay(2500);
}
