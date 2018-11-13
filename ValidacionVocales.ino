/*
 * UTN FICA CIERCOM
 *Nombre: Johanna Yépez
 *Fecha: 13/11/2018  
 *Deber: Comunicación Serial #2
 *Realizar un sistema que permite determinar 
 *el número de vocales dentro de una palabra. 
 *Este dato es ingresado por comunicación serial 
 *y la respuesta del mismo de igual manera. 
 */
String fra; //variable para tomar datos ingresados
int len; //lector del tamaño del dato
char dato; //variable para validar enteros
int i = 0; //ciclo for
int j=0;
void setup() {
  Serial.begin(9600); //habilitar Cx Serial
}

void loop() {
  if(Serial.available()>0){ //confirmar datos
    fra = Serial.readString();
    len = fra.length(); //tomar el tamaño
    char frase[len];//declarar un vector
    fra.toCharArray(frase, len + 1); //convertimos datos en vector
    for(;i<len;i++){ //recorrer vector según el tamaño
      dato = frase[i]; //tomar caracter del vector en una variable
      switch(dato){ //evaluar en switch
        case 'a': //cuando existen vocal a
        j++; //Se aumenta en 1 unidad
        break;
        case 'e'://cuando existen vocal e
        j++; //Se aumenta en 1 unidad
        break;
        case 'i'://cuando existen vocal i
        j++; //Se aumenta en 1 unidad
        break;
        case 'o'://cuando existen vocal o
        j++; //Se aumenta en 1 unidad
        break;
        case 'u': //cuando existen vocal u
        j++; //Se aumenta en 1 unidad
        break;
        case 'A'://cuando existen vocal A
        j++; //Se aumenta en 1 unidad
        break;
        case 'E'://cuando existen vocal E
        j++; //Se aumenta en 1 unidad
        break;
        case 'I'://cuando existen vocal I
        j++; //Se aumenta en 1 unidad
        break;
        case 'O'://cuando existen vocal O
        j++; //Se aumenta en 1 unidad
        break;
        case 'U'://cuando existen vocal U
        j++; //Se aumenta en 1 unidad
        break;
        default:
        break;
      }
    }
    i=0; //se reinicia el vector
    Serial.println();
    Serial.println(j); //se imprime el dato de las vocales
    j=0; //se reinicia j
  }
}
