#include <Arduino.h>
#include <LiquidCrystal.h>


const unsigned long MESURE_TIMEOUT = 25000UL;
const float SOUND_SPEED = 340.0/1000;

LiquidCrystal lcd(12,11,5,4,3,2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  Serial.begin(9600);
  pinMode(A0,OUTPUT);
  pinMode(A1,INPUT);
  digitalWrite(A0,LOW);
  pinMode(13,INPUT_PULLUP);

  lcd.begin(16,2);
  pinMode(switchPin, INPUT);
  lcd.print("ready");
}

void loop() {
  if (digitalRead(13)==0){
    digitalWrite(A0,HIGH);
    digitalWrite(A0,LOW);
    long mesure = pulseIn(A1, HIGH, MESURE_TIMEOUT);
    float distance_mm = mesure/2*SOUND_SPEED;
    Serial.println(distance_mm);
    lcd.clear();
    lcd.print(distance_mm);
    lcd.print(" mm");
    delay(200);
  }
}





