const int sensorPin = A0;
// temperatura ambiente en Celsius
const float baselineTemp = 20.0;
int switchState = 0;
int Pulsado = 0;

void setup(){
  // abrimos conexión en serie para mostrar los valores
  Serial.begin(9600);
  // LED = OUTPUTS 
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop(){
  switchState = digitalRead(6); //Hay voltage es valor de 1 y sino es valor de 0   
  //Lectura de la entrada analógica
  //Guardo el valor de lectura en una variable

  
  int sensorVal = analogRead(sensorPin);
  // convertir el valor ADC a voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;


  if(switchState == HIGH and Pulsado == 0){
    Pulsado = 1;
    delay(1000);
  }
  else if(switchState ==HIGH and Pulsado == 1){
    Pulsado = 0;
    delay(1000);
  }
  
  if(Pulsado == 0){
    Serial.println("No hay toma de datos");
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(Pulsado == 1){
    // enviar el valor del sensor para verlo en el monitor
    Serial.println("sensor Value: ");
    Serial.println(sensorVal); 

    // Valor de voltage a lectura en monitor
    Serial.println(", Volts: ");
    Serial.println(voltage);

    // Conversion de voltage a temperatura según hoja de especificaciones
    Serial.println(", degrees C: "); 
    Serial.println(temperature);
  

    // LEDs apagados si la temperatura baja del valor base
    if(temperature < baselineTemp){
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    } // Un LED encendido si la temperatura sube entre 2 y 4 grados
    else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    } // Dos LED encendidos si la temperatura sube entre 4 y 8 grados
    else if(temperature >= baselineTemp+4 && temperature < baselineTemp+8){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
    } // Tres LED encendidos si la temperatura sube más de 8 grados
    else if(temperature >= baselineTemp+8){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
    }
  }
  delay(250); //delay para mejorar el comportamiento global y la lectura de datos
}
