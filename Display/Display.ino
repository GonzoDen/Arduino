//program that will randomly print a message to a LCD-display

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Hello,");

  lcd.setCursor(0,1);
  lcd.print("Dudess");
}

void loop() {
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(6);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("My ans is: ");
      lcd.setCursor(0, 1);

      switch(reply) {
        case 0:
        lcd.print("Breathe");
        break;
        case 1:
        lcd.print("Maybe");
        break;
        case 2:
        lcd.print("Maybe not");
        break;
        case 3:
        lcd.print("Depends");
        break;
        case 4:
        lcd.print("YEAS");
        break;
        case 5:
        lcd.print("NO!");
        break;
      }
    }
  }

  prevSwitchState = switchState;
}
