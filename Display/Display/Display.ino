#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask");

  lcd.setCursor(0,1);
  lcd.print("Crystal Ball");
}

void loop() {
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(4);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says: ");
      lcd.setCursor(0, 1);

      switch(reply) {
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("Dorou");
        break;
        case 2:
        lcd.print("Y");
        break;
        case 3:
        lcd.print("s");
        break;
      }
    }
  }

  prevSwitchState = switchState;
}
