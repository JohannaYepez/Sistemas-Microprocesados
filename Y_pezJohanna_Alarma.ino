/*
   UTN FICA CIERCOM
   Nombre: Johanna Yépez
   Fecha:Martes 08/12/2019
   Realizar un Reloj  reloj mostrado en lcd con alarma que sea ingresada por comunicacion serial.
*/
#include <LiquidCrystal.h>
#include <MsTimer2.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8); //pines RS,E,D4,D5,D6,D7 en Arduino
int seg = 0; //variable segundos
int minu = 0;//variable minutos
int hora = 0;//variable hora
int i = 0; //variable de menu alarma
String hora1; //almacenar hora
int alhora = 0; //comparar hora
String minu1;//almacenar minuto
int alminu = 0; //comparar minuto
void setup() {
  MsTimer2::set(1000, rut); //configuración Timer2
  MsTimer2::start(); //inicio Timer2
  lcd.begin(16, 2); //inicio lcd
  lcd.setCursor(0, 0); //imprimir en lcd
  lcd.print("HH:MM:SS");
  lcd.setCursor(0, 1);
  lcd.print("00:00:00");
  Serial.begin(9600); //inicio Cx Serial
  attachInterrupt(0, alarm, LOW); //interrupcion para alarma
  Serial.println("Presione para ingresar la alarma");
}

void loop() {
  if (i == 1) {
    if (Serial.available() > 0) {
      hora1 = Serial.readString(); //leer hora
      alhora = hora1.toInt(); //convertir a entero
      Serial.println();
      Serial.println("Guardado");
      if (alhora > 24) { //validar que no sea mayor a 24
        Serial.println("Hora mal Ingresada"); //mensaje error
        i = 0; //reinicio contar en caso de error
      }
    }
  }
  if (i == 2) {
    if (Serial.available() > 0) {
      minu1 = Serial.readString(); //leer minuto
      alminu = minu1.toInt(); //convertir a entero
      Serial.println();
      Serial.println("Guardado");
      if (alminu > 60) { //validar que no se mayor a 60
        Serial.println("Minuto mal Ingresada"); //mensaje error
        i = 1; //regresar al menu
      }
    }
  }
  if (i == 3) {
    Serial.print(alhora); //imprimir hora guardada
    Serial.print(":");
    Serial.println(alminu);
    delay(500);
    buzz(); //ejecutar alarma
  }
}
void rut() {
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
void alarm() { //metodo alarma
  switch (i) { //menu alarma
    case 0: //ingreso de hor
      Serial.println("Ingrese Hora");
      i++;
      break;
    case 1: //ingreso de minutos
      Serial.println("Ingrese minuto");
      i++;
      break;
    case 2: //imprimir alarma configurada
      Serial.print("La alarma es:");
      i++;
      break;
    case 3: //reinicio de variables
      i = 0;
      alhora = 0;
      alminu = 0;
      Serial.print("Reinicio");
      break;
  }
}
void buzz() { //metodo para activar alarma
  if (hora == alhora && minu == alminu) { //comparar reloj con alarma
    Serial.println("ALARMA  "); //imprimir mensaje
    lcd.setCursor(0, 0); //imprimir en lcd
    lcd.print("ALARMA  ");
  } else { //volver a reloj
    lcd.setCursor(0, 0); //imprimir en lcd
    lcd.print("HH:MM:SS");
  }
}
