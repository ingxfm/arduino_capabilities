const int sensorPin = A0;
const float baselineTemp = 18.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //open a serial port with 9600 baud per sec
  for(int pinNumber=2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);    
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  float voltageValue = (sensorVal*5.0)/1024.0;
  Serial.print("  Voltage value, Volts: ");
  Serial.print(voltageValue);
  float temp = (voltageValue - .5)*100;
  Serial.print(", degrees ºC: ");  
  Serial.println(temp);

  if(temp<baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    }
  else if(temp>=baselineTemp+2 && temp<baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);    
    }
  else if(temp>=baselineTemp+4 && temp<baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);    
    }
  else if(temp>=temp<baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);    
    }
  delay(2);
}
