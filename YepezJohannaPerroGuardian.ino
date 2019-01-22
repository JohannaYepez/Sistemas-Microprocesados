/*
   UTN FICA CIERCOM
   Nombre: Johanna Yépez
   Fecha: 21/01/2019
   Deber PERRO GUARDIÁN
   Realizar un programa que permita que el conversor análogo digital
   configure al perro guardían a 10,20,30 y 40 segundos.
   Este proceso se visualiza en una lcd.
*/
#include <LiquidCrystal.h> //librería LCD
#include <MsTimer2.h> //librería TIMER
#include <avr/wdt.h> //librería AVR Watchdog
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); // RS,E,D4,D5,D6,D7 -> Pines de Arduino
int pott = A0; //pin del potenciometro
float potenciometro; //Valor del potenciómetro
float conv = 0; //transformación de CAD
int sel = 0; // Variable para seleccion
void setup() {
  lcd.begin(16, 2); //Inicia LCD 16X2
  attachInterrupt(0, select, LOW); //interrupcion
  lcd.setCursor(0, 0); //imprimir mensaje
  lcd.print("SELECCIONAR:"); //Mensaje Principal
}

void loop() {
  potenciometro = analogRead(pott); //Almancena el valor del pot. en escala
  delay(100); //Delay
  conv = ((potenciometro * 5.0) / 1023.0); //conversión CAD
  if (conv >= 0 && conv <= 1.25) { //validar para seleccion de 10
    sel = 10;
    lcd.setCursor(0, 1); //imprimir seleccion
    lcd.print(sel); 
  } else if (conv > 1.25 && conv <= 2.50) { //validar para seleccion de 20
    sel = 20;
    lcd.setCursor(0, 1); //imprimir seleccion
    lcd.print(sel);
  } else if (conv > 2.50 && conv <= 3.75) { //validar para seleccion de 30
    sel = 30;
    lcd.setCursor(0, 1); //imprimir seleccion
    lcd.print(sel);
  } else if (conv > 3.75 && conv <= 5.00) { //validar para seleccion de 40
    sel = 40;
    lcd.setCursor(0, 1); //imprimir seleccion
    lcd.print(sel); 
  }
}
void select() { //método de la interrrupcion
  switch (sel) {
    case 10:
      MsTimer2::set(6000, reset); //6s 
      MsTimer2::start(); //iniciar
      lcd.setCursor(0, 0);
      lcd.print("SELECCIONADO 10"); //imprimir mensaje
      break;
    case 20:
      MsTimer2::set(16000, reset); //16s
      MsTimer2::start(); //iniciar
      lcd.setCursor(0, 0);
      lcd.print("SELECCIONADO 20"); //imprimir mensaje
      break;
    case 30:
      MsTimer2::set(26000, reset); //26s
      MsTimer2::start();
      lcd.setCursor(0, 0);
      lcd.print("SELECCIONADO 30"); //imprimir mensaje
      break;
    case 40:
      MsTimer2::set(36000, reset); //36s
      MsTimer2::start();
      lcd.setCursor(0, 0);
      lcd.print("SELECCIONADO 40"); //imprimir mensaje
      break;
  }
}
void reset() { //método del timer
  wdt_enable(WDTO_4S); //inicio perro guardián con 4s 
  lcd.setCursor(0, 0); 
  lcd.print("REINICIA EN 4s"); //imprimir mensaje de advertencia
}
