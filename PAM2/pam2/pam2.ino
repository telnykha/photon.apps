/*
  PAM2 controller firmware
  
  Команды управления устройством
  ==============================
  PAM2            - возвращает версию, значение коснстанты VERSION
  BRBLUE?         - возвращает значеие переменной BRBLUE -якркость синих светодиодов 
  BRRED?          - возвращает значеие переменной BRRED -якркость красных светодиодов
  BRBLUE=value    - устанавливает значеие переменной BRBLUE -якркость синих светодиодов
  BRRED=value     - устанавливает значеие переменной BRRED -якркость красных светодиодов
  SBLUE?          - возвращает текущее состояние синих светодиодов (0- выкл, 1- вкл)
  SRED?           - возвращает текущее состояние красных светодиодов (0- выкл, 1- вкл)
  SBLUE=value     - устанавливает текущее состояние синих светодиодов (0- выкл, 1- вкл)
  SRED=value      - устанавливает текущее состояние красных светодиодов (0- выкл, 1- вкл)
  EXP?            - возвращает значеие переменной EXP время экспозиции видеокамеры в микросекундах
  EXP=value       - устанавливает значеие переменной EXP время экспозиции видеокамеры в микросекундах
  ACTINIC(br,t)   - актиничный свет яркостью br на время t в миллисекундах
  SATURATION(br,t)- насыщающий свет яркостью br на время t в миллисекундах 
  ADDITIONAL(br,t)- дополнительный свет яркостью br на время t в миллисекундах
  FLASH(t)         - кадр во время насыщающей вспышки t - длительность вспышки в % от времени экспозиции
  DARK             - темновой кадр
  F0               - 
  FM               -
  FT               - 
  FT1              -
  F0FM             -  
  FT1FM1           - 
*/

#define BLUE_PIN    9
#define RED_PIN     10
#define CAMERA_PIN  12

#define __SWITCH_OFF__ \
      SBLUE = LOW;\
      digitalWrite(BLUE_PIN, SBLUE);\
      SRED = LOW;\
      digitalWrite(RED_PIN, SRED);\



const char*  VERSION        = "2.0.0";
const String _error         = "ERROR"; 
const String _unknown       = "UNKNOWN COMMAND";

int BRBLUE   = 20;    /*якорсть синего светодиода 0-100%  */
int BRRED    = 30;    /*яркость красного светодиода 0-100%*/
int SBLUE    = LOW;   /*состояние синего светодиода       */
int SRED     = LOW;   /*состояние красного светодиода     */
int EXP      = 75;    /*время экспозиции видеокамеры в микросекундах*/

/*буфер команд*/
int  COMMANDSLEN = 0;
long COMMANDS[2048];

/*возвращает версию программного обеспечения.
*/
void pamVersioin()
{
  String result(VERSION);
  Serial.println(result);
}
/*возвращает яркость синего светодиода.
*/
void pamGetBRBLUE()
{
  String result(BRBLUE);
  Serial.println(result);
}
/*устанавливает яркость синего светодиода.
*/
void pamSetBRBLUE(String str)
{
  int index = str.indexOf('=');
  if (index == -1)
    Serial.println(_error);
  else
  {
    String substr = str.substring(index + 1, str.length());
    int value = substr.toInt();
    if (value > 0 && value <= 100)
    {
      BRBLUE = value;
      if (SBLUE == HIGH)
      {
        int value = 255*BRBLUE / 100;
        analogWrite(BLUE_PIN, value);
      }
      Serial.println(value);
    }
    else
      Serial.println(_error);
  }
}
/*состояние синего светодиода
*/
void pamGetSBLUE()
{
  String result(SBLUE);
  Serial.println(result);
}
/*переключение синего светодиода
*/
void pamSetSBLUE(String str)
{
  int index = str.indexOf('=');
  if (index == -1)
    Serial.println(_error);
  else
  {
    String substr = str.substring(index + 1, str.length());
    int value = substr.toInt();
    if (value == 0)
    {
      SBLUE = LOW;
      digitalWrite(BLUE_PIN, SBLUE);
    }
    else
    {
      SBLUE = HIGH;
      int value = 255*BRBLUE / 100;
      analogWrite(BLUE_PIN, value);
    }
  }
}
/*
    состояние красного светодиода
*/
void pamGetSRED()
{
  String result(SRED);
  Serial.println(result);
}
/*переключение красного светодиода
*/
void pamSetSRED(String str)
{
  int index = str.indexOf('=');
  if (index == -1)
    Serial.println(_error);
  else
  {
    String substr = str.substring(index + 1, str.length());
    int value = substr.toInt();
    if (value == 0)
    {
      SRED = LOW;
      digitalWrite(RED_PIN, SRED);
    }
    else
    {
      SRED = HIGH;
      int value = 255*BRRED / 100;
      analogWrite(RED_PIN, value);
    }
  }
}

/*
  возвращает яркость красного светодиода.
*/
void pamGetBRRED()
{
  String result(BRRED);
  Serial.println(result);
}
/*Устанавливает яркость красного светодиода.
*/
void pamSetBRRED(String str)
{
  int index = str.indexOf('=');
  if (index == -1)
    Serial.println(_error);
  else
  {
    String substr = str.substring(index + 1, str.length());
    int value = substr.toInt();
    if (value > 0 && value <= 100)
    {
      BRRED = value;
      int value = 255*BRRED / 100;
      analogWrite(RED_PIN, value);
    }
    else
      Serial.println(_error);
  }
}
/*возвращает время экспозиции
*/
void pamGetEXP()
{
  String result(EXP);
  Serial.println(result);
}
/*для реализации актиничтоно света используется ШИМ (PCM) сигнал 
  на выходе BLUE_PIN у которого яркость может изменяться от 
  1 до 32. Параметр brightness может принимать значения от 1 до 100,
  Параметр duration может принимать значения от 1 до 65535 миллисекунд
  Процедура, перед началом выполнения  устанавливает переменные SBLUE и 
  SRED в значение LOW
 */
void _pamActinic(int brightness, int duration)
{
      __SWITCH_OFF__
      
      int value = 32*brightness / 100;
      unsigned long total_delay = duration; // -- задержка в миллисекундах 
      analogWrite(BLUE_PIN, value);              // -- запуск ШИМ 
      delay(total_delay);                        // -- задержка 
      digitalWrite(BLUE_PIN, SBLUE);             // -- остановка 
}

#define _BEGIN_OBTAIN_PARAMS_                                 \
    int index1 = command.indexOf('(');                        \
    int index2 = command.indexOf(')');                        \
    if (index1 == -1 || index2 == -1)                         \
      Serial.println(_error);                                 \
    else                                                      \
    {                                                         \
      String params = command.substring(index1 + 1, index2);  \
      int index3 = params.indexOf(',');                       \
      if(index3 == -1)                                        \
        Serial.println(_error);                               \
      else                                                    \
      {                                                       \
         String p1 = params.substring(0, index3);             \
         String p2 = params.substring(index3+1, params.length());\
         int brightness = p1.toInt();                         \
         int duration   = p2.toInt();                         \
         if (brightness < 1 || brightness > 100 || duration < 0)\
            Serial.println(_error);                           \
         else                                                 \
         {                                                    \

#define _END_OBTAIN_PARAMS_                                   \
         }                                                    \
      }                                                       \
    }                                                         \

/*
*/
void pamActicinc(String command)
{
       _BEGIN_OBTAIN_PARAMS_            
            
            _pamActinic(brightness, duration);     
            Serial.println("ACTINIC DONE");

      _END_OBTAIN_PARAMS_

}


void pamSaturation(String command)
{
       _BEGIN_OBTAIN_PARAMS_   
       
            _pamSaturation(brightness, duration);     
            Serial.println("SATURATION DONE");
            
       _END_OBTAIN_PARAMS_

}
/*для реализации насыщающего света используется ШИМ (PCM) сигнал 
  на выходе BLUE_PIN у которого яркость может изменяться от 
  33 до 255 Параметр brightness может принимать значения от 1 до 100,
  Параметр duration может принимать значения от 1 до 65535 миллисекунд
  Процедура, перед началом выполнения  устанавливает переменные SBLUE и 
  SRED в значение LOW*/
void _pamSaturation(int brightness, unsigned int duration)
{
    __SWITCH_OFF__

    int value = 32+223*brightness / 100;
    unsigned long total_delay = duration; // -- задержка в миллисекундах 
    analogWrite(BLUE_PIN, value);              // -- запуск ШИМ 
    delay(total_delay);            // -- задержка 
    digitalWrite(BLUE_PIN, SBLUE);             // -- остановка     
}
void pamAdditional(String command)
{
       _BEGIN_OBTAIN_PARAMS_   
       
            _pamAdditional(brightness, duration);     
            Serial.println("ADDITIONAL DONE");
            
       _END_OBTAIN_PARAMS_
  
}
/*для реализации насыщающего света используется ШИМ (PCM) сигнал 
  на выходе RED_PIN у которого яркость может изменяться от 
  1 до 255 Параметр brightness может принимать значения от 1 до 100,
  Параметр duration может принимать значения от 1 до 65535 миллисекунд
  Процедура, перед началом выполнения  устанавливает переменные SBLUE и 
  SRED в значение LOW*/
void _pamAdditional(int brightness, unsigned int duration)
{
    __SWITCH_OFF__

    int value = 255*brightness / 100;
    unsigned long total_delay =  duration;  // -- задержка в миллисекундах 
    analogWrite(RED_PIN, value);                // -- запуск ШИМ 
    delay(total_delay);             // -- задержка 
    digitalWrite(RED_PIN, SRED);                // -- остановка       
}
void pamFlash(String command)
{
    _pamFlash(50);
}

/* измерительная вспышка. 
*/
void _pamFlash(int t)
{
    __SWITCH_OFF__

    Serial.println("FLASH UNDER CONSRUCTION");
    
}
/*темновой кадр
*/
void pamDark()
{
    __SWITCH_OFF__ 
    
    digitalWrite(CAMERA_PIN, HIGH);   
    delayMicroseconds(EXP);
    digitalWrite(CAMERA_PIN, LOW);   

    Serial.println("DARK DONE");

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       /*установка соединения на скорости 9600 бод*/
  Serial.setTimeout(100);   /*установка таймаута для получения строки  */
  pinMode(BLUE_PIN,    OUTPUT);
  pinMode(RED_PIN,     OUTPUT);
  pinMode(CAMERA_PIN,  OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    // read the incoming string:
    String incomingString = Serial.readString();
    if (incomingString.indexOf('=') != -1)
    {
      if (incomingString.indexOf("BRBLUE=") != -1)
        pamSetBRBLUE(incomingString);
      else if (incomingString.indexOf("BRRED=") != -1)
        pamSetBRRED(incomingString);
      else if (incomingString.indexOf("SBLUE=") != -1)
        pamSetSBLUE(incomingString);
      else if (incomingString.indexOf("SRED=") != -1)
        pamSetSRED(incomingString);
      else
        Serial.println(_unknown);
    }
    else if (incomingString.equals("PAM2"))
      pamVersioin();
    else if (incomingString.equals("BRBLUE?"))
      pamGetBRBLUE();
    else if (incomingString.equals("BRRED?"))
      pamGetBRRED();
    else if (incomingString.equals("EXP?"))
      pamGetEXP();
    else if (incomingString.equals("SBLUE?"))
      pamGetSBLUE();
    else if (incomingString.equals("SRED?"))
      pamGetSRED();
    else if (incomingString.indexOf("ACTINIC(") != -1)
      pamActicinc(incomingString);
    else if (incomingString.indexOf("SATURATION(") != -1)
      pamSaturation(incomingString);   
    else if (incomingString.indexOf("ADDITIONAL(") != -1)
      pamAdditional(incomingString);           
    else if (incomingString.indexOf("DARK") != -1)
      pamDark();           
    else if (incomingString.indexOf("FLASH(") != -1)
      pamFlash(incomingString);           
    else
      Serial.println(_unknown);
  }
}
