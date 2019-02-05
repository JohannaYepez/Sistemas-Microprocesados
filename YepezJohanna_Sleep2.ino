/*
   UTN FICA CIERCOM
   Nombre: Johanna Yépez
   Fecha: 05/02/2019
   Realizar un reloj dentro del arduino con el menor coste computacional
   que se visualiza en una LCD (apagar los periféricos que no se usen).
*/
#include <LiquidCrystal.h> //librería lcd
#include <LowPower.h> //librería LowPower
#include <avr/power.h> //librerias sleep
#include <avr/sleep.h> 
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); //pines RS,E,D4,D5,D6,D7 en Arduino
int seg = 0; //variable segundos
int minu = 0;//variable minutos
int hora = 0;//variable hora

void setup() {
    lcd.begin(16, 2); //inicio lcd
    lcd.setCursor(0, 0); //imprimir en lcd
    lcd.print("HH:MM:SS");
    lcd.setCursor(0, 1);
    lcd.print("00:00:00");
}

void loop() {
  LowPower.powerDown(SLEEP_500MS, ADC_OFF, BOD_OFF); //Modo Sleep con Timer
  power_all_enable(); //apaga todos los perifericos
  seg++; //aumenta contador segundos
  if (seg < 60) { //valida que llegue a 60
    if (seg < 10) { //valida impresion de menores a 10
      lcd.setCursor(6, 1); //impresion en lcd de datos
      lcd.print("0 ");
      lcd.setCursor(7, 1);
      lcd.print(seg);
    } else { //valores mayores a 10
      lcd.setCursor(6, 1);
      lcd.print(seg);
    }
  } else { //mayor a 60
    seg = 0; //reinicio contador segundos
    if (seg == 0) { //imprimo posicion 0
      lcd.setCursor(6, 1);
      lcd.print("00");
    }
    minu++; //aumento contador minutos
    if (minu < 60) { //valido minutos hasta 60
      if (minu < 10) { //validacion para menores a 10
        lcd.setCursor(2, 1); //imprimo datos en lcd
        lcd.print(":0 :");
        lcd.setCursor(4, 1);
        lcd.print(minu);
      } else { //mayores a 10
        lcd.setCursor(2, 1); //imprimo datos
        lcd.print(":  :");
        lcd.setCursor(3, 1);
        lcd.print(minu);
      }
    } else { //mayores a 60
      minu = 0; //reinicio contador
      if (minu == 0) { //imprimo posicion 0
        lcd.setCursor(3, 1);
        lcd.print("00");
      }
      hora++; //aumento contador hora
      if (hora < 24) { //valido hasta 24
        if (hora < 10) { //valido numeros hasta 10
          lcd.setCursor(0, 1); //imprimo datos en lcd
          lcd.print("0 ");
          lcd.setCursor(1, 1);
          lcd.print(hora);
        } else { //mayores a 10
          lcd.setCursor(0, 1); //imprimo datos en lcd
          lcd.print(hora);
        }
      } else {  //mayores a 24
        hora = 0; //reinicio contador hora
        if (hora == 0) { //imprimo posicion 0
          lcd.setCursor(0, 1);
          lcd.print("00");
        }
      }
    }
  }
}
