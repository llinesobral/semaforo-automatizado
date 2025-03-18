const int vermelho = 9;
const int amarelo = 10;
const int verde = 11;
const int sensorIR = 7;
const int buzzer = 6;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensorIR, INPUT);
}

void loop() {
  int estadoSensor = digitalRead(sensorIR);

  if (estadoSensor == LOW) {  // Se detectar um objeto
    digitalWrite(vermelho, HIGH);  
    digitalWrite(buzzer, HIGH);  
    delay(3000);

    digitalWrite(vermelho, LOW);
    digitalWrite(amarelo, HIGH);  
    delay(2000);
    
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, HIGH);  
    digitalWrite(buzzer, LOW);  
    delay(5000);

    digitalWrite(verde, LOW);  
  }
}
