const int EN = 10;
const int btn= 2;
const int IN1 = 8;
const int IN2 = 9;
const int potpin=A0;

int mins = 100, maxs = 200;
void setup() {
  pinMode(btn, INPUT_PULLUP);
  pinMode(potpin, INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
if (!digitalRead(btn)) {
    unsigned long t = millis();
    int d = constrain(map(millis() - t, 0, 5000, maxs, mins), mins, maxs);
    if(d>=0&&d<100)
    {
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
    }
    if(d>=100&&d<200){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }
}
int potValue = analogRead(potpin);
int speed = map(potValue, 0, 1023, 0, 200);
analogWrite(EN,speed);
}