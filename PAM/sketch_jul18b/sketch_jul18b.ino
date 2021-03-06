const int redPin  = 13;       /*номер порта для красного светодиода*/
const int bluePin = 12;       /*номер порта для синего светодиода*/
const int camPin  = 11;       /*номер порта для камеры*/
unsigned char sketchStatus = '0';      /*Глобальная переменная. Статус программы. 0 - ожидание, 1 - эксперимент*/
int counter = 0;              /*Счетчик текущих событий эксперимента*/

bool redPinOn  = false;
bool bluePinOn = false;

int  blueBright = 100;
int  redBright  = 100;
/**
Описание команды. 
  int command    - код команды
  int pinStatus  - яркость источника излучения 
  unsigned long pinDelay;
*/
struct expEvent
{
  int command;
  int pinStatus;
  unsigned long pinDelay;
};
/**
Файл config.h - переменная часть микропрограммы. 
Формироуется приложением PAM.exe и загружается в микроконтроллер 
с использованием приложения arduino_debug 
*/
#include "config.h"

void setup()
{
  Serial.begin(9600); /*установка соединения на скорости 9600 бод*/
  pinMode(redPin,  OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(camPin,  OUTPUT);
}

/*
   delay the Arduino board for t MICROseconds
*/
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
/**
Интерпретатор команд. 
int command - код команды. см. "описание команд" 
int value - яркость источника излучения 
unsigned long timeDelay - время выполнения команды. 
*/
void DoCommand(int cammand, int value, unsigned long timeDelay)
{
  switch (cammand)
  {
    case TURNON460:
        BlueFlash(timeDelay, value);
      break;
    case TURNON660:
        RedFlash(timeDelay, value);
      break;
    case TURNON_CAM_660:
        RedFlashWithCamera(timeDelay, value);
      break;
    case TURNON_CAM_460:
        BlueFlashWithCamera(timeDelay, value);
      break;

    case TURNON_CAM:
      {
        digitalWrite(redPin, LOW);
        digitalWrite(bluePin, LOW);
        
        digitalWrite(camPin, HIGH);
        microDelay(timeDelay);
        digitalWrite(camPin, LOW);
      }
      break;
    case TURN_OFF:
      {
        digitalWrite(camPin, LOW);
        digitalWrite(redPin, LOW);
        digitalWrite(bluePin, LOW);
        microDelay(timeDelay);
      }
      break;
      case TURNON_CAM_460_ACT:
        BlueFlashWithCameraAct(timeDelay, value);
      break;
      case TURNON460_ACT:
        BlueFlashAct(timeDelay, value);
      break;
      case TURNON_CAM_FLASH:
        BlueFlashWithCameraDark(timeDelay);
      break;
  }
}
/**
 процесс выполнения последовательности команд, заданной пользователем. 
 Последовательность команд находится в переменной Events, которая 
 объявлена в заголовочном файле config.h
*/
void Porcess()
{
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
  counter = 0;
  while (counter < progSize)
  {
    if (Serial.available() > 0)
    {
      sketchStatus = Serial.read();
      if (sketchStatus == '0')
        break;
    }
    
    unsigned char value = '4';
    Serial.write(&value, 1);
    DoCommand(Events[counter].command,
              Events[counter].pinStatus,
              1000 * Events[counter].pinDelay);
    counter++;
  }
  unsigned char value = '5';
  Serial.write(&value, 1);
  sketchStatus = '0';
}

//Flash blue LED brightness aBrightness and time aTime
void BlueFlash(unsigned long aTime, int aBrightness)
{
    int t1 =  10*aBrightness;
    unsigned long t = micros();
    while(micros() - t <= aTime)
    {
      digitalWrite(bluePin, HIGH);
      delayMicroseconds(t1);
      digitalWrite(bluePin, LOW);
      delayMicroseconds(1000 - t1);
    }
}
//  Flash blue LED brightness aBrightness and time aTime
// switch on camera 
void BlueFlashWithCamera(unsigned long aTime, int aBrightness)
{
   digitalWrite(camPin, HIGH);
   delayMicroseconds(flash_delay);
   digitalWrite(bluePin, HIGH);
   delayMicroseconds(flash_lenght);
   digitalWrite(bluePin, LOW);
   digitalWrite(camPin, LOW);
   microDelay(exposure - flash_lenght - flash_delay);
   unsigned long t = 0;
   if (aTime < exposure)
    t = 70000;
   else if (aTime - exposure < 70000)
    t = 70000;
   else
    t = aTime - exposure; 
   BlueFlash(t, aBrightness); 
}

void BlueFlashAct(unsigned long aTime, int aBrightness)
{
    int t1=aBrightness; 
    unsigned long t = micros();
    while(micros() - t <= aTime)
    {
      digitalWrite(bluePin, HIGH);
      delayMicroseconds(t1);
      digitalWrite(bluePin, LOW);
      delayMicroseconds(1000 - t1);
    }
}

//Flash red LED brightness aBrightness and time aTime
void RedFlash(unsigned long aTime, int aBrightness)
{
    unsigned long t = micros();
    while(micros() - t <= aTime)
    {
      digitalWrite(redPin, HIGH);
      delayMicroseconds(aBrightness*10);
      digitalWrite(redPin, LOW);
      delayMicroseconds(1000 - aBrightness*10);
    }
}

// Flash red LED brightness aBrightness and time aTime
// switch on camera 
void RedFlashWithCamera(unsigned long aTime, int aBrightness)
{

   digitalWrite(camPin, HIGH);
   delayMicroseconds(flash_delay);
   digitalWrite(redPin, HIGH);
   delayMicroseconds(flash_lenght);
   digitalWrite(redPin, LOW);
   digitalWrite(camPin, LOW);
   microDelay(exposure - flash_lenght - flash_delay); 
   unsigned long t = 0;
   if (aTime < exposure)
    t = 70000;
   else if (aTime - exposure < 70000)
    t = 70000;
   else
    t = aTime - exposure; 
   RedFlash(t, aBrightness);          
}


// Flash blue LED brightness aBrightness and time aTime
// switch on camera 
void BlueFlashWithCameraAct(unsigned long aTime, int aBrightness)
{
   digitalWrite(camPin, HIGH);
   delayMicroseconds(flash_delay);
   digitalWrite(bluePin, HIGH);
   delayMicroseconds(flash_lenght);
   digitalWrite(bluePin, LOW);
   digitalWrite(camPin, LOW);
   microDelay(exposure - flash_lenght - flash_delay);
   unsigned long t = 0;
   if (aTime < exposure)
    t = 70000;
   else if (aTime - exposure < 70000)
    t = 70000;
   else
    t = aTime - exposure; 
   BlueFlashAct(t, aBrightness); 
}

void BlueFlashWithCameraDark(unsigned long aTime)
{
   digitalWrite(camPin, HIGH);
   delayMicroseconds(flash_delay);
   digitalWrite(bluePin, HIGH);
   delayMicroseconds(flash_lenght);
   digitalWrite(bluePin, LOW);
   digitalWrite(camPin, LOW);
   microDelay(exposure - flash_lenght - flash_delay);
   microDelay(70000);
}
void Lighting()
{
  if (bluePinOn && redPinOn)
  {
    digitalWrite(bluePin, HIGH); 
    digitalWrite(redPin, HIGH); 
    int tBlue  = blueBright*1000 /100;
    int tRed   = redBright*1000 / 100;
    int mDelay = tRed <= tBlue ? tRed : tBlue;
    int lDelay = tRed <= tBlue ? tBlue - mDelay:tRed - mDelay;
    int firstPin = tRed <= tBlue ? redPin:bluePin;
    int secondPin = firstPin == redPin?bluePin:redPin;
    delayMicroseconds(mDelay);
    digitalWrite(firstPin, LOW); 
    delayMicroseconds(lDelay );
    digitalWrite(secondPin, LOW); 
    delayMicroseconds(1000 - mDelay - lDelay);
  }
  else if (bluePinOn && !redPinOn)
  {
    digitalWrite(bluePin, HIGH);
    delayMicroseconds(blueBright*1000/100);
    digitalWrite(bluePin, LOW);
    delayMicroseconds(1000 - blueBright*1000/100);
  }
  else if (redPinOn && !bluePinOn)
  {
    digitalWrite(redPin, HIGH); 
    delayMicroseconds(redBright*1000/100);
    digitalWrite(redPin, LOW);
    delayMicroseconds(1000 - redBright*1000/100);
  }
  else
  {
    digitalWrite(bluePin, LOW); 
    digitalWrite(redPinOn, LOW); 
  }
}

void loop()
{
  if (sketchStatus == '0')
  {
    int num = 0;
    do
    {
      num =  Serial.available();
      Lighting();
    }
    while (num == 0);
    // read num bytes from serinal
    for(int i = 0; i < num; i++)
    {
      int v = Serial.read();
      // We consider the first byte as a command, 
      // and ignore the rest
      if (i == 0)
        sketchStatus = v;     
    }
  }
  else
  {
    if (sketchStatus != '1')
    {
      unsigned char s_status = 0x0F & sketchStatus;
      unsigned char bright = sketchStatus >> 4; 
      
      char value = '5';
      Serial.write(&value,1);

      if (s_status == 0x02)
      {
        redPinOn = true;
        redBright = bright * 100 / 16;
      }
      else if (s_status  == 0x03)
        redPinOn = false;
      else if (s_status == 0x04)
      {
        bluePinOn = true;
        blueBright = bright * 100 / 16;
      }
      else if (s_status == 0x05)
        bluePinOn = false;

      sketchStatus = '0';
    }
    else
    {
      Porcess();
      sketchStatus = '0';
    }
  }
}
