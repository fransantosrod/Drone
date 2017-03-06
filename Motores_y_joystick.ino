
//Variable para indicar el PIN donde vamos a conectar el driver del motor de pasos
const int pinDriverMotor1 = 9;
//Variable para indicar el PIN donde vamos a conectar el pin SW del JoyStick
const int pinJoyStickSW = 8;
//Variable para indicar los dos PINES donde vamos a conectar la referencia X e Y del joystick
const int pinEjeX = A0;
const int pinEjeY = A1;

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
  //Indicamos que queremos ese PIN como pin de entrada
  pinMode(pinJoyStickSW,INPUT);
  //Ponemos el PIN a nivel alto
  digitalWrite(pinJoyStickSW, HIGH);
  //Iniciamos la comunicación serie
  Serial.begin(9600);
}

void loop() {

  //for (int a = 0; a<=255; a+=25){

    
    int valor_leido =  analogRead(pinEjeX);
    int valor_mapeado = map(valor_leido, 0, 1023, limite_inferior+5, limite_superior);
    
    //Representamos los valores por la terminal serie
    Serial.print("X: ");
    Serial.println(valor_leido);
    Serial.print("Valor del PWM: ");
    Serial.println(valor_mapeado);
    digitalWrite(pinDriverMotor1, LOW);
    delay(8);
    digitalWrite(pinDriverMotor1, HIGH);
    delay(20);
/*    
    //Comprobamos si los valores estan entre los límite
    if (valor_mapeado >= limite_inferior && valor_mapeado <=limite_superior){ 
      //Comproamos si hemos arrancado ya los motores
      if (bandera_arranque == 0){
          //Cambiamos el valor para indicar que hemos arrancado el motor
          bandera_arranque = 10;
          //Creamos la señal digital durante 50 microsegundos
          digitalWrite(pinDriverMotor1, HIGH);
          delay(100);
      }
      analogWrite(pinDriverMotor1, valor_mapeado);
      //Retraso de prueba para mantenernos un tiempo en ese estado
      delay(100);
    }
    
    //Si los valores sobrepasan los límites
    else {
      bandera_arranque = 0;
      digitalWrite(pinDriverMotor1, LOW);
    }
    //Retraso de prueba para mantenernos un tiempo en ese estado
    //  delay(5000);
*/  
}
