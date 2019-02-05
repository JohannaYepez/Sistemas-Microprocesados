#include <LowPower.h>

/*
   UTN FICA CIERCOM
   Nombre: Johanna Yépez
   Fecha: 05/02/2019
    Realizar un sistema que permita configurar por comunicación serial o por pulsadores el modo
    sleep cada 25 segundos.
*/
int tiempo = 0; //variable para contador
void setup() {
  Serial.begin(9600); //inicio CAD
  Serial.println("Presione para dormir");
  attachInterrupt(0,interrupt,LOW);
}

void loop() {

}
void interrupt() {
  for (; tiempo < 25; tiempo++) { //ciclo para mantener apagado Arduino por 19 s
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
  }
  Serial.println("Despierto, presione para dormir");
  delay(350);
  tiempo=0;
}
