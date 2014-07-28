const int led0 = 10;  // LED 핀 번호 설정
const int led1 = 9;   // LED 핀 번호 설정
const int led2 = 11;  // LED 핀 번호 설정

int lightSensor = A0;
int ledDelay = 256/3;

int firefly0 = 0;
int firefly1 = 0 - ledDelay;
int firefly2 = 0 - ledDelay*2;

int increment0 = 1;
int increment1 = 1;
int increment2 = 1;

void setup() {       
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(lightSensor);
  Serial.println(sensorValue);
  if(sensorValue < 200) {
    if(firefly0 > 255)
    {
      increment0 = -2;
    }  
    else if(firefly0 < 1)
    {
      increment0 = 2;
    }

    if(firefly1 > 255)
    {
      increment1 = -2;
    }  
    else if(firefly1 < 1)
    {
      increment1 = 2;
    }

    if(firefly2 > 255)
    {
      increment2 = -2;
    }  
    else if(firefly2 < 1)
    {
      increment2 = 2;
    }

    firefly0 = firefly0 + increment0;
    firefly1 = firefly1 + increment1;
    firefly2 = firefly2 + increment2;

    analogWrite(led0, constrain(firefly0, 0, 255));    // LED의 밝기를 PWM으로 조절
    analogWrite(led1, constrain(firefly1, 0, 255));
    analogWrite(led2, constrain(firefly2, 0, 255));

    delay(10);
  } else {
    analogWrite(led0, 0);
    analogWrite(led1, 0);
    analogWrite(led2, 0);

    firefly0 = 0;
    firefly1 = 0 - ledDelay;
    firefly2 = 0 - ledDelay*2;
  }
}

