/*
 * UTN FICA CIERCOM
 * Nombre: Johanna Yépez
 * Fecha: 6/11/2018
 * Deber: Display 7 Segmentos #2
 * Realizar un programa que medienta un pulsador se aumente el valor de un contador (1 al 40) 
 * y mediante otro pulsador se reste ese valor. El visualización del proceso se lo hace en displays. 
 */
 int a=5; //declaramos variables del decodificador
 int b=4;
 int c=3;
 int d=2;
 int i=0; //contador
 int k=0;
 int sum=6; //variable para sumar
 int res=7; //varable para restar
 int dec=9; //decenas
 int uni=8; //unidades
 int decenas;
 int unidades;
void setup() {
  pinMode(a,OUTPUT); //declaramos como salidaspara el decodificador
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(sum,INPUT); //declaramos como entrada para suma y resta 
  pinMode(res,INPUT);
  pinMode(dec,OUTPUT);
  pinMode(uni,OUTPUT);
}

void loop() {
  if(digitalRead(sum)==HIGH && digitalRead(res)==LOW){ //si cumple la condición, suma
    delay(200); 
    if(i<41){ //condición para limitar a 40
      i++; //sumar la variable en 1 unidad
      decenas=i/10; //operación para decenas
      unidades=i-(decenas*10); //operación para unidades, que dependen de las decenas
      k=i; //guardamos el dato en otra variable
    }
    else if(i>=41){ //condición para cuando es mayor a 40
      i=0; //regresar a cero el contador
    }
  }
  else if (digitalRead(sum)==LOW && digitalRead(res)==HIGH){ //si cumple la condición, resta
     delay(200);
    if(k<41){ //condición para limitar a 40
      k--; //restar la variable en 1 unidad
      decenas=k/10; //operación para decenas
      unidades=k-(decenas*10); //operación para unidades, dependientes de las decenas
      i=k; //guardar el dato en otra variable
    }
    else if(i>=41){ //condición para cuando es mayor a 40
      k=0; //regresar a cero el contador
    }
  }
  else if (digitalRead(sum)==HIGH && digitalRead(res)==HIGH){ // si cumple está condición, se mantiene
  }
   digitalWrite (uni,HIGH); //encendemos las unidades
   digitalWrite (dec,LOW);
   display(unidades); //envíamos dato al método display
   delay(100);//espera rápida
   digitalWrite (uni,LOW); 
   digitalWrite (dec,HIGH);//encendemos las decenas
   display(decenas); //envíamos dato al método display
   delay(100); //espera rápida
}
void display (int j){ //método del display
  switch(j){ //sentencia para menú
    case 0: //cuando la variable es 0
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  break;
  case 1://cuando la variable es 1
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  break;
  case 2://cuando la variable es 2
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  break;
  case 3://cuando la variable es 3
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  break;
  case 4://cuando la variable es 4
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  break;
  case 5://cuando la variable es 5
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  break;
   case 6://cuando la variable es 6
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  break;
   case 7://cuando la variable es 7
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  break;
  case 8://cuando la variable es 8
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  break;
  case 9://cuando la variable es 9
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  break;
  }
} //FIN DEL MÉTODO
