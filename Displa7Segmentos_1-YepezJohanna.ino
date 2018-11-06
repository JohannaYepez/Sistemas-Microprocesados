/*
 * UTN FICA CIERCOM
 * Nombre: Johanna Yépez
 * Fecha: 6/11/2018
 * Deber: Display 7 Segmentos
 * Realizar un sistema que permita contar de forma automática 
 * (sin pulsador, el sistema inicia y empieza a contar sin necesidad de una actividad del usuario). 
 * Del 1 al 200 mediante la multiplexación de displays.
 */
 int a=5;   //declaramos variables para decoder 7447
 int b=4;
 int c=3;
 int d=2;
 int i=0; //variable para recorrido
 int dec=9; //variables para multiplaxación de display
 int uni=8;
 int cen=10;
 int decenas;
 int unidades;
 int centenas;
void setup() {
  pinMode(a,OUTPUT); //declaramos con entradas a todas las variables
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(dec,OUTPUT);
  pinMode(uni,OUTPUT);
  pinMode(cen,OUTPUT);
}

void loop() {
  //CONTEO AUTOMÁTICO
 for(;i<201;i++){ //usamos un for, para recorrido automático
    delay(200); //delay antirebotes
    if(i<201){ //Tomamos la variable i y realizamos operación mientras se cumpla la sentencia
      centenas=i/100; //usamos centenas para tercer display, "/" realiza división en enteros
      decenas=(i-(centenas*100))/10; //decenas para segundo display, que depende de las centenas
      unidades=i-(centenas*100+decenas*10); //unidades para primer display, dependen de las decenas
    }
    else{ //en caso de no cumplir la sentencia se resetea la variable
     i=0;
    }
   digitalWrite (uni,HIGH); //encendemos solo unidades
   digitalWrite (dec,LOW);
   digitalWrite (cen,LOW);
   display(unidades); //enviamos datos al método display
   delay(100);//espera rápida
   digitalWrite (uni,LOW); 
   digitalWrite (dec,HIGH); //encendemos solo decenas
   digitalWrite (cen,LOW);
   display(decenas); //enviamos datos al método display
   delay(100); //espera rápida
   digitalWrite (uni,LOW);
   digitalWrite (dec,LOW);
   digitalWrite (cen,HIGH);//encendemos solo centenas
   display(centenas); //enviamos datos al método display
   delay(100); //espera rápida
 }
 i=0; //reseteamos variable para que el proceso reinicie
}
void display (int j){ //método para encender display tomando datos anteriores
  switch(j){ //inicio de menú
    case 0: // cuando la variable es 0
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  break;
  case 1:// cuando la variable es 1
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  break;
  case 2:// cuando la variable es 2
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  break;
  case 3:// cuando la variable es 3
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  break;
  case 4:// cuando la variable es 4
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  break;
  case 5:// cuando la variable es 5
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  break;
   case 6:// cuando la variable es 6
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  break;
   case 7:// cuando la variable es 7
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  break;
  case 8:// cuando la variable es 8
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  break;
  case 9:// cuando la variable es 9
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  break;
  }
} //FIN DEL MÉTODO
