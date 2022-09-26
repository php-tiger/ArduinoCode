
  int red = 3;
  int green = 5;
  int yellow = 4;
  int button = 7;
  int button2 = 8;
  unsigned long time = millis();
void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}

void loop()
{ 
  delay(100);
  if(time < 9000){
  time = time + 100 ;
  }else{
    time = 1000;
  }
  if(digitalRead(button) == LOW && digitalRead(button2) == HIGH){
   digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
    delay(1000);
    RedHigh();
    time = 1000;
    delay(4000);
  } else if (digitalRead(button2) == LOW && digitalRead(button) == HIGH){
    RedHigh();
    time = 1000;
    delay(5000);
  }
  else{
  if(time < 3000){
    GreenHigh();
  }else if(time < 6000 && time > 3000){
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
  }else if(time < 9000 && time > 6000 ){
    RedHigh();
  }else{
   ResetLed();
  }
  }
  
 }

void RedHigh(){
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}

void GreenHigh(){
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
}
void ResetLed(){
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  }
