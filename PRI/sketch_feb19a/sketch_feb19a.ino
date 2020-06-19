int pin1 = 12;
int pin2 = 11;
int pin3 = 13;
int val  = 0;
int _delay = 300;
void setup() {
  // put your setup code here, to run once:
   pinMode(pin2, OUTPUT);
   pinMode(pin1, OUTPUT);
   pinMode(pin3, OUTPUT);
   Serial.begin(9600);
}
void Capture()
{

    digitalWrite(pin3, LOW);
  
    digitalWrite(pin2, HIGH);
    delay(_delay);
    digitalWrite(pin2, LOW);
    
    digitalWrite(pin1, HIGH);
    delay(_delay);
    digitalWrite(pin1, LOW);
    
    digitalWrite(pin3, HIGH);
    delay(3);
    
    digitalWrite(pin2, HIGH);
    delay(_delay);
    digitalWrite(pin2, LOW);
    
    digitalWrite(pin1, HIGH);
    delay(_delay);

    digitalWrite(pin1, LOW);
    digitalWrite(pin3, LOW);
    Serial.write('2');
}
void loop() 
{
   if (Serial.available() > 0)
  {
    val = Serial.read();
    if (val == '1')
      Capture();
    else if (val == '2')
      digitalWrite(pin3, HIGH);
   else if (val == '3')
      digitalWrite(pin3, LOW);    
  }
}
