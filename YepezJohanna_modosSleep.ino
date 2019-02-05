/*
   UTN FICA CIERCOM
   NOMBRE: Johanna Yépez
   FECHA: 05/02/2019
   Realizar un programa que permita poner al sistema 19 segundos en modo sleep,
   se despierte, realice un lectura del conversor análogo digital, lo imprima
   por comunicación serial y vuelva a dormir 19 segundos.
*/
#include <LowPower.h> //librería para dormir Arduino por tiempo
int tiempo = 0; //variable para contador
void setup() {
  Serial.begin(9600); //inicio CAD
}

void loop() {
  for (; tiempo < 20; tiempo++) { //ciclo para mantener apagado Arduino por 19 s
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
  }
  Serial.println(analogRead(0)); //imprimir el CAD
  delay(500); //Delay para mejor funcionamiento
  tiempo = 0; //reinicio variable
}
