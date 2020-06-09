const int sensor = A0;
const float t0 = 20.0;

void setup() {
  Serial.begin(9600);

  for (int i = 2; i < 5; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

}

void loop() {
  int sensorVal = analogRead(sensor);

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float v = (sensorVal/1024.0) * 5.0;

  Serial.print(",   Volts: ");
  Serial.print(v);

  float t = (v - .5) * 100;
  Serial.print(",   Degrees C: ");
  Serial.print(t);

  if (t < t0) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if (t >=  t0 + 2 && t < t0 + 5) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if (t >=  t0 + 5 && t < t0 + 8) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if (t >=  t0 + 8) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }

  delay(1);

}
