int TRIG = 10;      //Defino trigger en pin 10 (importante que coincida en el montaje)
int ECO = 9;      // echo en pin 9
int buzzer = 3; //buzzer to arduino pin 9
   
int DURACION; //Crear las variables para luego calcularlas 
int DISTANCIA;

void setup()
{
  pinMode(TRIG, OUTPUT);  // trigger como salida
  pinMode(ECO, INPUT);    // echo como entrada
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 3 as an output
  Serial.begin(9600);     // inicializacion de comunicacion serial a 9600 bps

  for(int pinNumber = 5; pinNumber<8; pinNumber++){ //definir salidas para los LED
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop()
{
  
  digitalWrite(TRIG, HIGH);     // generacion del pulso a enviar
  delay(1);                     // al pin conectado al trigger
  digitalWrite(TRIG, LOW);      // del sensor
  
  DURACION = pulseIn(ECO, HIGH);  // con funcion pulseIn se espera un pulso
                                  // alto en Echo. Devuelve un tiempo en microsegundos
                                  
  DISTANCIA = DURACION / 58.2;    // distancia medida en centimetros 
                                  //valor especificado por el fabricante

  if(DISTANCIA >= 50 && DISTANCIA < 75){  //condiciones para encender los LED según la distancia
    digitalWrite(5, LOW); //detectada por el sendor
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }
  else if( 25 <DISTANCIA && DISTANCIA<50){
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }
  else if( DISTANCIA <= 25 && DISTANCIA > 0 ){
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if( DISTANCIA > 75 ){
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  
  Serial.println(DISTANCIA); 
                      // envio de valor de distancia por monitor serial
  delay(250);       // demora entre datos para mejor visualización

 if(DISTANCIA < 75 && DISTANCIA > 0 ){  //para valores lejanos o negativos
                                         // no ocurrirá habrá pitido

  tone(buzzer, 1000); // señal sonora de tantos HZ
  delay(DISTANCIA*10);        //Pita más rápido según las distancia
  noTone(buzzer);     // Stop SONIDO
  delay(DISTANCIA*10);        
 }
}
