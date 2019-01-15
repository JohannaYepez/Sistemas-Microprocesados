/*
   UTN FICA CIERCOM
   Nombre: Johanna Yépez
   Fecha:15-01-2019
   Realice un sistema que guarde en una posición de
   la memoria EEPROM solo cuando su valor exceda a
   la anterior lectura.
*/
#include <EEPROM.h>
int t = 0; //variable contador posiciones
int i = 0; //variable almacenar entero
String dato;
void setup() {
  Serial.begin(9600); //iniciar Cx Serial
  //se ejecuta solo al inicio del programa para limpiar memoria
//  for (; t < 256; t++) { //sobreescribir los datos en cada posición
//    EEPROM.write(t, 0);
//    delay(10);
//  }
//  t = 0; //reinicio de variable
}

void loop() {
  Serial.println("Ingrese dato:"); //mensaje de reinicio sistema
  delay(1000); //delay para escribir datos
  if (Serial.available() > 0) { //Comprueba que hay datos
    dato = Serial.readString(); //recibir dato
    i = dato.toInt(); // convertir dato a entero
    if (t < 256) { //validaciòn para memoria llena
      if (i > EEPROM.read(t)) { //validar que sea mayor
        t++; //aumentar posición
        EEPROM.write(t, i); //guardar dato en posición
        delay(100);
        Serial.print("Se almaceno: "); //imprimir dato almacenado y posicion
        Serial.print(i);
        Serial.print(" en la posicion: ");
        Serial.println(t);
      } else {
        Serial.println("Dato menor"); //mensaje para cuando es menor o igual
      }
    } else {
      Serial.println("memoria llena"); //error por memoria llena
    }
  }
}
