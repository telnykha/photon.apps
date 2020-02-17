const int bluePin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(bluePin, OUTPUT);
}
/*
   delay the Arduino board for t MICROseconds

void microDelay(unsigned long t)
{
  unsigned long t0 = micros();
  while (micros() - t0 < t)
  {
  }
}*/

void microDelay(unsigned long t)
{
  unsigned long mils = t / 1000; 
  if (mils > 0)
    delay(mils);
  unsigned long t0 = micros();
  unsigned long t1 = t - mils*1000;
  while (micros() - t0 < t1)
  {
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  microDelay(25);
  digitalWrite(bluePin, HIGH);
  microDelay(50);
  digitalWrite(bluePin, LOW);
  microDelay(25);
}
