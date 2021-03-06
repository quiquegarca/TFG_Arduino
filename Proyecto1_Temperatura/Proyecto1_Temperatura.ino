const int sensorPin = A0; //Nombro la entrada analógica
// Fijo una temperatura ambiente en Celsius
const float baselineTemp = 25.0;


void setup() { //declarar las clavijas de entrada y de salida del arduino
  Serial.begin(9600); //iniciar comunicación para que muestre los datos en pantalla
  pinMode(3, OUTPUT); //Configuro las salida del LED
  digitalWrite(3, LOW); //Led inicialmente apagado
}
void loop() {
  int sensorVal = analogRead(sensorPin); //Lectura de la entrada analógica
  //Guardo el valor de lectura en una variable
  
  float voltage = (sensorVal/1024.0) * 5.0; //Convertir el valor del ADC a voltage
  //La hoja de especificaciones indica un decalaje de 500mV
  float temperature = (voltage - .5) * 100;
  //convierto el valor del voltage en temperatura


  if(temperature < baselineTemp){
    digitalWrite(3, LOW);
  }
  else if(temperature >= baselineTemp+2){
     digitalWrite(3, HIGH);
  }
}                                                                                                                                                                 
