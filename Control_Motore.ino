
//Variable para indicar el PIN donde vamos a conectar el driver del motor de pasos
const int pinDriverMotor1 = 9;
/*Bandera para indicar que si estamos en el momento de arranque se envie una señal digital
para que el motor comience a funcionar*/
int bandera_arranque;


/* El motor funciona para valores del PWM entre 150
y 255 luego por debajo de los límites no arrancaremos el motor*/
const int limite_inferior = 150;
const int limite_superior = 255;
    
void setup() {
  //Inicializamos las variables
  bandera_arranque = 0;
  //Indicamos que el pin queremos que sea de salida
  pinMode(pinDriverMotor1, OUTPUT);
  //Iniciamos la comunicación serie
  Serial.begin(9600);
}

void loop() {

  for (int a = 0; a<=255; a+=25){

    //Representamos los valores por la terminal serie
    Serial.print("Valor del PWM: ");
    Serial.println(a);
    
    //Comprobamos si los valores estan entre los límite
    if (a >= limite_inferior && a <=limite_superior){ 
      //Comproamos si hemos arrancado ya los motores
      if (bandera_arranque == 0){
          //Cambiamos el valor para indicar que hemos arrancado el motor
          bandera_arranque = 10;
          //Creamos la señal digital durante 50 microsegundos
          digitalWrite(pinDriverMotor1, HIGH);
          delay(50);
      }
      analogWrite(pinDriverMotor1, a);
      //Retraso de prueba para mantenernos un tiempo en ese estado
      delay(5000);
    }
    //Si los valores sobrepasan los límites
    else {
      bandera_arranque = 0;
      digitalWrite(pinDriverMotor1, LOW);
    }
    //Retraso de prueba para mantenernos un tiempo en ese estado
      delay(5000);
  }
}
