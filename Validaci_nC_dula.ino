/*
   UTN FICA CIERCOM
   Nombre: Johanna Yépez
   Fecha: 13/11/2018
   Deber: Comunicación Serial #1
   Realizar un programa que permita ingresar el número
   de cédula con el guión y posteriormente validarlo.
   El dato se lo ingresa por comunicación serial.
*/
String ced; //variable para tomar datos ingresados
int len; //lector del tamaño del dato
char dato; //variable para validar enteros
int i = 0; //ciclo for
int j = 0;
int sum = 0;
int com = 0;
int igual = 0;
int numero; //convertir char to int
int dos;
int tres;
int cuatro;
int diez;
char tercer;
char primer;
char segundo;
char director;
char tercero;
void setup() {
  Serial.begin(9600); //habilitar Cx Serial
}

void loop() {
  if (Serial.available() > 0) { //confirmar datos
    ced = Serial.readString(); //leemos cédula
    len = ced.length(); //tomar el tamaño
    if (len == 11) { //validar tamaño de la cedula
      char cedula[len];//declarar un vector
      ced.toCharArray(cedula, len + 1); //convertimos datos en vector
      if (isDigit(cedula[10])) { //validar que la ultima posición sea entero
        for (; i < 9; i++) { //recorrer vector los primeros 9 digitos
          dato = cedula[i]; //se almacena posicion del vector en variable
          if (isDigit(dato)) { //validar enteros
            if (i == 8) {
              if (cedula[9] == '-') { //validamos el guión en la cédula
                tercer = cedula[2];
                numero = atoi(&tercer);
                if (numero < 6) { //validamos tercer digito
                  primer = cedula[0]; //asignamos posición a una variable
                  dos = atoi(&primer); //convertimos a entero
                  dos = dos / 10;
                  switch (dos) {  //validamos primer y segundo digito
                    case 0: //validacion en el caso que el primer digito sea 0
                      j = 0;
                      sum = 0;
                      for (; j < 9; j++) { //recorremos el vector para realizar calculos de los pares
                        segundo = cedula[j];
                        tres = atoi(&segundo); //convertimos a entero
                        if (tres * 2 > 10) {
                          sum = sum + (tres * 2 - 9); //tomamos los pares y multiplicamos por 2 y restamos 9 si la cantidad pasa de 9
                          j++; //aumentamos en 1 unidad
                        } else {
                          sum = sum + tres * 2; //multiplicacion por 2 a los pares que no pasen de 9
                          j++;//aumentamos en 1 unidad
                        }
                      }
                      j = 1;
                      for (; j < 9; j++) { //recorremos el vector para impares
                        segundo = cedula[j];
                        tres = atoi(&segundo); //convertimos a int
                        sum = sum + tres; //multiplicamos por 1 y sumamos
                        j++;//aumentamos en 1 unidad
                      }
                      com = sum / 10; //sacamos las decenas
                      igual = (com + 1) * 10 - sum;//sacamos el residuo de la resta
                      director = cedula[10];
                      diez = atoi(&director); //convertimos ultimo digito en entero
                      if (igual == diez) { //evaluamos si es igual al calculo
                        Serial.println();
                        Serial.println("Cedula correcta");
                      } else {
                        Serial.println();
                        Serial.println("Decimo digito no valido");
                      }
                      break;
                    case 1://validacion en el caso que el primer digito sea 1
                      j = 0;
                      sum = 0;
                      for (; j < 9; j++) { //recorremos el vector para realizar calculos de los pares
                        segundo = cedula[j];
                        tres = atoi(&segundo); //convertimos a entero
                        if (tres * 2 > 10) {
                          sum = sum + (tres * 2 - 9); //tomamos los pares y multiplicamos por 2 y restamos 9 si la cantidad pasa de 9
                          j++; //aumentamos en 1 unidad
                        } else {
                          sum = sum + tres * 2; //multiplicacion por 2 a los pares que no pasen de 9
                          j++; //aumentamos en 1 unidad
                        }
                      }
                      j = 1;
                      for (; j < 9; j++) { //recorremos el vector para impares
                        segundo = cedula[j];
                        tres = atoi(&segundo); //convertimos a entero
                        sum = sum + tres; //multiplicamos por 1 y sumamos
                        j++; //aumentamos en 1 unidad
                      }
                      com = sum / 10; //sacamos las decenas
                      igual = (com + 1) * 10 - sum; //sacamos el residuo de la resta
                      director = cedula[10];
                      diez = atoi(&director); //convertimos a entero ultimo digito
                      if (igual == diez) { //evaluamos si es igual al calculo
                        Serial.println();
                        Serial.println("Cedula correcta");
                      } else {
                        Serial.println();
                        Serial.println("Decimo digito no valido");
                      }
                      break;
                    case 2://validacion en el caso que el primer digito sea 2
                      tres = 0;
                      segundo = cedula[1];//asignamos posición a una variable
                      tres = atoi(&segundo);//convertimos a entero
                      Serial.println(tres); //error tercer digito
                      if (tres < 5) { //evaluamos si es menor a 4 para que llegue solo a 24
                        j = 0;
                        sum = 0;
                        for (; j < 9; j++) {
                          tercero = cedula[j];
                          cuatro = atoi(&tercero);
                          if (cuatro * 2 > 10) {
                            sum = sum + (cuatro * 2 - 9);//tomamos los pares y multiplicamos por 2 y restamos 9 si la cantidad pasa de 9
                            j++; //aumentamos en 1 unidad
                          } else {
                            sum = sum + cuatro * 2; //multiplicacion por 2 a los pares que no pasen de 9
                            j++; //aumentamos en 1 unidad
                          }
                        }
                        j = 1;
                        for (; j < 9; j++) { //recorremos el vector para impares
                          tercero = cedula[j];
                          cuatro = atoi(&tercero);
                          sum = sum + cuatro; //multiplicamos por 1 y sumamos
                          j++; //aumentamos en 1 unidad
                        }
                        com = sum / 10; //sacamos las decenas
                        igual = (com + 1) * 10 - sum; //sacamos el residuo de la resta
                        director = cedula[10];
                        diez = atoi(&director); //convertimos a entero ultimo digito
                        if (igual == diez) { //evaluamos si es igual al calculo
                          Serial.println();
                          Serial.println("Cedula correcta");
                        } else {
                          Serial.println();
                          Serial.println("Decimo digito no valido");
                        }
                      } else { //se pasa de 24 los 2 digitos
                      Serial.println();
                      Serial.println("Primer y Segundo digito mayor a 24"); //error tercer digito
                  }
                  break;
                default://si el primer digito es mayor a 2 se pasa de 24
                  Serial.println();
                  Serial.println("Primer y Segundo digito mayor a 24"); //error tercer digito
                  break;
                }
              } else { //el tercer digito sobrepasa el 6
                Serial.println();
                Serial.println("Tercer digito mayor a 6"); //error tercer digito
              }
            } else { //no contiene guión
              Serial.println();
              Serial.println("Ingrese con guion"); //error falta guión
            }
          }
        }
        else {
          Serial.println();
          Serial.print("La posicion[");
          Serial.print(i);
          Serial.println("] no es entero");
          break; //forzar cierre de condición
        }
      }
    } else {
      Serial.println();
      Serial.println("La posicion[10] no es entero");
    }
    i = 0;
  } else {
    Serial.println();
    Serial.println("Cedula incorrecta");
  }
}
}
