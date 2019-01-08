/*
   UTN FICA CIERCOM
   Nombre: Johanna Yépez
   Fecha:Martes 08/12/2019
   Realizar un Reloj en LCD usando Timer
*/
#include <LiquidCrystal.h> //librería lcd
#include <MsTimer2.h> //librería Timer2
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); //pines RS,E,D4,D5,D6,D7 en Arduino
int seg = 0; //variable para segundos
int minu = 0; //variable para minutos
int hora = 0; //variable para hora
void setup() {
  MsTimer2::set(1000, rut); //programar timer 2
  MsTimer2::start(); //iniciar timer 2
  lcd.begin(16, 2); //inicialización lcd
  lcd.setCursor(0, 0); //mostrar mensaje
  lcd.print("SS:MM:HH");
  lcd.setCursor(0, 1);
  lcd.print("00:00:00");
}

void loop() {

}
void rut() { //clase para timer
  seg++; //aumnetar segundos
  if (seg < 60) { //validar hasta 60
    if (seg < 10) { //imprimir posiciones menores a 10
      lcd.setCursor(0, 1);
      lcd.print("0 ");
      lcd.setCursor(1, 1);
      lcd.print(seg);
    } else { //imprimir posiciones mayores a 10
      lcd.setCursor(0, 1);
      lcd.print(seg);
    }
  } else { //reinicio contador segundos
    seg = 0; //reiniciar variable
    if (seg == 0) { //reinicio de segundos
      lcd.setCursor(0, 1);
      lcd.print("00");
    }
    minu++; //aumentar minutos
    if (minu < 60) { //validar hasta 60 minutos
      if (minu < 10) { //imprimir posiciones menores a 10
        lcd.setCursor(2, 1);
        lcd.print(":0 :");
        lcd.setCursor(4, 1);
        lcd.print(minu);
      } else { //imprimir posiciones mayores a 10
        lcd.setCursor(2, 1);
        lcd.print(":  :");
        lcd.setCursor(3, 1);
        lcd.print(minu);
      }
    } else { //reiniciar minutos
      minu = 0; //reiniciar variable
      if (minu == 0) { //imprimir reinicio
        lcd.setCursor(3, 1);
        lcd.print("00");
      }
      hora++; //aumentar hora
      if (hora < 24) { //validar hasta 24 horas
        if (hora < 10) { //imprimir posiciones menores a 10
          lcd.setCursor(6, 1);
          lcd.print("0 ");
          lcd.setCursor(7, 1);
          lcd.print(hora);
        } else { //imprimir posiciones mayores a 10
          lcd.setCursor(6, 1);
          lcd.print(hora);
        }
      } else { //reinicio hora
        hora = 0; //reinicio variable
        if (hora == 0) { //imprimo reinicio
          lcd.setCursor(6, 1);
          lcd.print("00");
        }
      }
    }
  }
}
