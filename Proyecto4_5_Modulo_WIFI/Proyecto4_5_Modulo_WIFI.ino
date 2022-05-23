int TRIG = 12;      //Defino trigger en pin D6 que es el 12.
int ECO = 13;      // echo en pin D7 que es el 13.

int DURACION; //Crear las variables para luego calcularlas 
int DISTANCIA;


void setup() {
  pinMode(TRIG, OUTPUT);  // trigger como salida
  pinMode(ECO, INPUT);    // echo como entrada
  Serial.begin(9600);     // inicializacion de comunicacion serial a 115200 bps

}

void loop() {
  digitalWrite(TRIG, HIGH);     // generacion del pulso a enviar
  delay(1);                     // al pin conectado al trigger
  digitalWrite(TRIG, LOW);      // del sensor
  
  DURACION = pulseIn(ECO, HIGH);  // con funcion pulseIn se espera un pulso
                                  // alto en Echo. Devuelve un tiempo en microsegundos
                                  
  DISTANCIA = DURACION / 58.2;    // distancia medida en centimetros 
                                  //valor especificado por el fabricante

  Serial.println(DISTANCIA); 
                      // envio de valor de distancia por monitor serial
  delay(500);       // demora entre datos para mejor visualización
}
