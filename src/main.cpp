#include <Arduino.h>

String correctPassword = "1234";  //  Change this to your password
String inputPassword;
int tries = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Bitte Passwort eingeben:");
}

void loop() {
  if (Serial.available() > 0) {
    inputPassword = Serial.readStringUntil('\n');
    inputPassword.trim(); // Entfernt Leerzeichen oder Zeilenumbrüche

    if (inputPassword == correctPassword) {
      Serial.println("Zugang erlaubt ");
      while (true); // Stoppt das Programm
    } 
    else {
      tries++;
      Serial.println("Falsches Passwort ");

      if (tries >= 3) {
        Serial.println("Zugang verweigert ");
        while (true); // Stoppt das Programm
      } 
      else {
        Serial.print("Versuch ");
        Serial.print(tries);
        Serial.println("/3 — Bitte erneut versuchen:");
      }
    }
  }
}
