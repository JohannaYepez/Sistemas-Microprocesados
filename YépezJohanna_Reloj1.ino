/*
   UTN FICA CIERCOM
   Nombre: Johanna Yépez
   Fecha:Martes 08/12/2019
   Realizar un Reloj en LCD usando Timer
*/
#include <LiquidCrystal.h>
#include <MsTimer2.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); //pines RS,E,D4,D5,D6,D7 en Arduino
int seg = 0;
int minu = 0;
int hora = 0;
void setup() {
  MsTimer2::set(100, rut);
  MsTimer2::start();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("SS:MM:HH");
  lcd.setCursor(0, 1);
  lcd.print("00:00:00");
}

void loop() {

}
void rut() {
  seg++;
  if (seg < 60) {
    if (seg < 10) {
      lcd.setCursor(0, 1);
      lcd.print("0 ");
      lcd.setCursor(1, 1);
      lcd.print(seg);
    } else {
      lcd.setCursor(0, 1);
      lcd.print(seg);
    }
  } else {
    seg = 0;
    if (seg == 0) {
      lcd.setCursor(0, 1);
      lcd.print("00");
    }
    minu++;
    if (minu < 60) {
      if (minu < 10) {
        lcd.setCursor(2, 1);
        lcd.print(":0 :");
        lcd.setCursor(4, 1);
        lcd.print(minu);
      } else {
        lcd.setCursor(2, 1);
        lcd.print(":  :");
        lcd.setCursor(3, 1);
        lcd.print(minu);
      }
    } else {
      minu = 0;
      if (minu == 0) {
        lcd.setCursor(3, 1);
        lcd.print("00");
      }
      hora++;
      if (hora < 24) {
        if (hora < 10) {
          lcd.setCursor(6, 1);
          lcd.print("0 ");
          lcd.setCursor(7, 1);
          lcd.print(hora);
        } else {
          lcd.setCursor(6, 1);
          lcd.print(hora);
        }
      } else {
        hora = 0;
        if (hora == 0) {
          lcd.setCursor(6, 1);
          lcd.print("00");
        }
      }
    }
  }
}
