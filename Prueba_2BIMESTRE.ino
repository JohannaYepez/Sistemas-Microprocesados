/*
   UTN FICA CIERCOM
   Nombre: Johanna Yépez
   Fecha:22/01/2019
   Evaluación
   Emular el funcionamiento de un control de auto ChevyStar
*/
#include <MsTimer2.h> //Librería Timer
#include <avr/wdt.h> //librería avr
#include <EEPROM.h> //librería EEPROM
int i = 0;
int val;
boolean estado = true; //cambio de estado
String contra; //variable de contraseña
int len; //variable de validación tamaño
int k = 0; //variable para el reinicio
int z = 0; //variable para imprimir contraseña
int j = 0;
int pos1;
int pos2;
int pos3;
int pos4;
int pos5;
int pass[5] = {pos1, pos2, pos3, pos4, pos5}; //contraseña almacenada
int pass2[5] ;
int l = 0;
int n1;
int n2;
int n3;
int n4;
int n5;
void setup() {
  Serial.begin(9600); //inicio CAD
  attachInterrupt(0, master, LOW); //pulsador master
  pinMode(3, INPUT); //Pin para pulsador 1
  pinMode(4, INPUT); //Pin para pulsador 2
  pinMode(5, INPUT); //Pin para pulsador 3
  pos1 = EEPROM.read(0); //leer EEPROM y almacenar en cada posición
  pos2 = EEPROM.read(1);
  pos3 = EEPROM.read(2);
  pos4 = EEPROM.read(3);
  pos5 = EEPROM.read(4);
  int pass[5] = {pos1, pos2, pos3, pos4, pos5}; 
  Serial.println("La contrasenia es: ");
  for (; z < 5; z++) { //imprimir contraseña
    Serial.print(pass[z]);
  }
  Serial.println();
}

void loop() {
  if (i == 1) {
    if (estado == false) { //activar control
      Serial.println("Activado");
      i++; //aumento contador
    }
  }
  if (i == 2) { //escribir contrasenia
    if (digitalRead(3) == LOW && digitalRead(4) == HIGH && digitalRead(5) == HIGH ) {
      delay(200); //Delay anti rebotes
      pass2[l] = 1; //almacenar dato en posicion de vector
      l++;
      Serial.print("1"); //escribir 1
    }
    if (digitalRead(3) == HIGH && digitalRead(4) == LOW && digitalRead(5) == HIGH ) {
      delay(200); //Delay anti rebotes
      pass2[l] = 2;
      l++;
      Serial.print("2"); //escribir 2
    }
    if (digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == LOW ) {
      delay(200); //Delay anti rebotes
      pass2[l] = 3;
      l++;
      Serial.print("3"); //escribir 3
    }
  }
  if (i == 3) {
    if (l == 5) { //validar 5 posiciones
      if (pass[0] == pass2[0] && pass[1] == pass2[1] && pass[2] == pass2[2] && pass[3] == pass2[3] && pass[4] == pass2[4]) { //validar contraseña
        Serial.println("Puede encender el auto"); //imprimir mensaje
      } else {
        Serial.println("Error intente de nuevo "); //contraseña mal ingresada
        i = 2; //regresar a ingresar contraseña
        l = 0; //resetear posición del vector pass2
        k++; //aumentar numero de intentos
        if (k == 3) { //enviar al reinicio
          reinicio(); //metodo de reinicio
        }
      }
    } else {
      Serial.println("Error intente de nuevo"); //error faltan o sobran numeros
      i = 2; //regresar al ingreso
      l = 0; //resetear posición del vector pass2
      k++; //aumentar numero de intentos
      if (k == 3) { //enviar al reinicio
        reinicio(); //metodo de reinicio
      }
    }
  }
}
void master() { //metodo de interrupcion
  switch (i) { //menu para cada caso
    case 0: //activar control
      i++;
      estado = !estado; //cambio de estado
      break;
    case 2: //ingreso de pass
      i++;
      break;
  }
}
void reinicio() { //metodo de reinicio
  n1= random(1,3);
  n2= random(1,3);
  n3= random(1,3);
  n4= random(1,3);
  n5= random(1,3);
  EEPROM.write(n1,0); //actualizar contraseña pos1
  EEPROM.write(n2,1); //actualizar contraseña pos2
  EEPROM.write(n3,2); //actualizar contraseña pos3
  EEPROM.write(n4,3); //actualizar contraseña pos4
  EEPROM.write(n5,4); //actualizar contraseña pos5
  wdt_enable(WDTO_1S); //activación wdt a 1 segundo
}
