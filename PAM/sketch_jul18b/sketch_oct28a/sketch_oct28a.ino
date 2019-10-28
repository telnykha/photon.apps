const int bluePin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(bluePin, OUTPUT);
}
/*
   delay the Arduino board for t MICROseconds
*/
void microDelay(unsigned long t)
{
  unsigned long t0 = micros();
  while (micros() - t0 < t)
  {
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(bluePin, HIGH);
  microDelay(100);
  digitalWrite(bluePin, LOW);
}
