                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           /*
  PAM2 controller firmware
  
  Команды управления устройством
  ==============================
  PAM2            - возвращает версию, значение коснстанты VERSION
  LSAT?           - возвращает значеие переменной LSAT -якркость синих светодиодов 
  LACT?           - возвращает значеие переменной LACT -якркость синих светодиодов в актиничном режиме
  LADD?           - возвращает значеие переменной LADD -якркость красных светодиодов
  LSAT=value      - устанавливает значеие переменной LSAT -якркость синих светодиодов
  LACT=value      - устанавливает значеие переменной LACT -якркость синих светодиодов в актиничном режиме
  LADD =value     - устанавливает значеие переменной LADD -якркость красных светодиодов
  SAT?            - возвращает текущее состояние синих светодиодов (0- выкл, 1- вкл)
  ACT?            - возвращает текущее состояние синих светодиодов (0- выкл, 1- вкл) в актиничном режиме
  ADD?            - возвращает текущее состояние красных светодиодов (0- выкл, 1- вкл)
  SAT=value       - устанавливает текущее состояние синих светодиодов (0- выкл, 1- вкл)
  ACT=value       - устанавливает текущее состояние синих светодиодов (0- выкл, 1- вкл) в актиничном режиме
  ADD=value       - устанавливает текущее состояние красных светодиодов (0- выкл, 1- вкл)
  EXP?            - возвращает значеие переменной EXP время экспозиции видеокамеры в микросекундах
  EXP=value       - устанавливает значеие переменной EXP время экспозиции видеокамеры в микросекундах
  GAIN?           - возвращает значеие переменной GAIN усиление видеокамеры в децибеллах
  GAIN=value      - устанавливает значеие переменной GAIN усиление видеокамеры в децибеллах
  LFLASH?         - возвращает значение переменной LFLASH длинтельность вспышки в микросекундах   
  LFLASH?         - возвращает значение переменной LFLASH длинтельность вспышки в микросекундах   
  ACTINIC(br,t)   - актиничный свет яркостью br на время t в миллисекундах
  SATURATION(br,t)- насыщающий свет яркостью br на время t в миллисекундах 
  ADDITIONAL(br,t)- дополнительный свет яркостью br на время t в миллисекундах
  FLASH           - кадр во время насыщающей вспышки LFLASH - длительность вспышки в микросекндах
  DARK            - темновой кадр, выключаются все светодиоды и включается видеокамера. 
  DARKNESS(t)     - темнота на заданное время t в миллисекундах
  F0FM(t)         - получение пары изображений Fo и Fm  
  FT1FM1(t)       - получение пары изображений F(t) и Fm(t)  
*/

#define BLUE_PIN    9
#define RED_PIN     10
#define CAMERA_PIN  11

#define __SWITCH_OFF__ \
      int oldBlue = SAT;\
      int oldRed  = ADD;\    
      int oldAct  = ACT;\
      SAT = LOW;\
      ACT = LOW;\
      digitalWrite(BLUE_PIN, SAT);\
      ADD = LOW;\
      digitalWrite(RED_PIN, ADD);\

#define __SWITCH_ON__ \
  if (oldBlue == HIGH)\
  {\
      SAT = HIGH;\
      int value = 255*LSAT / 100;\
      analogWrite(BLUE_PIN, value);\    
  }\
  if (oldRed == HIGH)\
  {\
      ADD = HIGH;\
      int value = 255*LADD / 100;\
      analogWrite(RED_PIN, value);\
  }\
  if (oldAct == HIGH)\
  {\
      ACT = HIGH;\
      int value = 255*LACT / 1000;\
      analogWrite(BLUE_PIN, value);\
  }\


const char*  VERSION        = "2.0.0";
const String _error         = "ERROR: "; 
const String _unknown       = "UNKNOWN COMMAND";
const String _success       = "SUCCESS: ";
/*глобальные переменные*/
int LSAT     = 20;    /*якорсть синего светодиода 0-100%  */
int LACT     = 50;    /*актиничная якорсть синего светодиода 0-100%  */
int LADD     = 30;    /*яркость красного светодиода 0-100%*/
int SAT      = LOW;   /*состояние синего светодиода       */
int ACT      = LOW;   /*состояние синего светодиода  в актиничном режиме*/
int ADD      = LOW;   /*состояние красного светодиода     */
int EXP      = 75;    /*время экспозиции видеокамеры в микросекундах*/
int LFLASH   = 20;    /*время измерительной вспышки в микроукундах*/
int GAIN     = 20;    /*усиление видеокамеры*/
int TRANSFER = 100; /*передача данных с видеокамеры на ПК в миллисекундах*/ 

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
void pamGetLSAT()
{
  String result(LSAT);
  Serial.println(result);
}
/*устанавливает яркость синего светодиода.
*/
void pamSetLSAT(String str)
{
  int index = str.indexOf('=');
  if (index == -1)
    Serial.println(_error);
  else
  {
    String substr = str.substring(index + 1, str.length());
    int value = substr.toInt();
    if (value >= 0 && value <= 100)
    {
      LSAT = value;
      if (SAT == HIGH)
      {
        int value = 255*LSAT / 100;
        analogWrite(BLUE_PIN, value);
      }
      Serial.println(_success + str);
    }
    else
      Serial.println(_error);
  }
}
/*состояние синего светодиода
*/
void pamGetSAT()
{
  String result(SAT);
  Serial.println(result);
}
/*переключение синего светодиода
*/
void pamSetSAT(String str)
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
      SAT = LOW;
      digitalWrite(BLUE_PIN, SAT);
    }
    else
    {
      SAT = HIGH;
      ACT = LOW;
      digitalWrite(BLUE_PIN, ACT);
      int value = 255*LSAT / 100;
      analogWrite(BLUE_PIN, value);
    }
    Serial.println(_success + str);
  }
}
/*------------------------------------------*/
/*возвращает яркость синего светодиода в актиничном режиме
*/
void pamGetLACT()
{
  String result(LACT);
  Serial.println(result);
}
/*устанавливает яркость синего светодиода.
*/
void pamSetLACT(String str)
{
  int index = str.indexOf('=');
  if (index == -1)
    Serial.println(_error);
  else
  {
    String substr = str.substring(index + 1, str.length());
    int value = substr.toInt();
    if (value >= 0 && value <= 100)
    {
      LACT = value;
      if (ACT == HIGH)
      {
        int value = 255*LACT / 1000;
        analogWrite(BLUE_PIN, value);
      }
      Serial.println(_success + str);
    }
    else
      Serial.println(_error);
  }
}
/*состояние синего светодиода
*/
void pamGetACT()
{
  String result(ACT);
  Serial.println(result);
}
/*переключение синего светодиода
*/
void pamSetACT(String str)
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
      ACT = LOW;
      digitalWrite(BLUE_PIN, ACT);
    }
    else
    {
      ACT = HIGH;
      SAT = LOW;
      digitalWrite(BLUE_PIN, SAT);
      int value = 255*LACT / 1000;
      analogWrite(BLUE_PIN, value);
    }
    Serial.println(_success + str);
  }
}
/*------------------------------------------*/
/*
    состояние красного светодиода
*/
void pamGetADD()
{
  String result(ADD);
  Serial.println(result);
}
/*переключение красного светодиода
*/
void pamSetADD(String str)
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
      ADD = LOW;
      digitalWrite(RED_PIN, ADD);
    }
    else
    {
      ADD = HIGH;
      int value = 255*LADD / 100;
      analogWrite(RED_PIN, value);
      Serial.println(_success + str);
    }
  }
}

/*
  возвращает яркость красного светодиода.
*/
void pamGetLADD()
{
  String result(LADD);
  Serial.println(result);
}
/*Устанавливает яркость красного светодиода.
*/
void pamSetLADD(String str)
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
      LADD = value;
      if (ADD == HIGH)
      {
        int value = 255*LADD / 100;
        analogWrite(RED_PIN, value);
      }
      Serial.println(_success + str);
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
/*Устанавливает время экспозции.
*/
void pamSetEXP(String str)
{
  int index = str.indexOf('=');
  if (index == -1)
    Serial.println(_error);
  else
  {
    String substr = str.substring(index + 1, str.length());
    int value = substr.toInt();
    if (value >= 50  && value <= 32000)
    {
      EXP = value;
      Serial.println(_success + str);
    }
    else
      Serial.println(_error);
  }
}
/*Возвращает длительность вспышки в микросекундах
*/
void       pamGetLFLASH()
{
  String result(LFLASH);
  Serial.println(result);
}

/*Устанавливает длительность вспышки в микросекундах
*/
void  pamSetLFLASH(String str)
{
  int index = str.indexOf('=');
  if (index == -1)
    Serial.println(_error + str);
  else
  {
    String substr = str.substring(index + 1, str.length());
    int value = substr.toInt();
    if (value >= 20  && value <= 50)
    {
      LFLASH = value;
      Serial.println(_success + str);
    }
    else
      Serial.println(_error + str);
  }
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
      digitalWrite(BLUE_PIN, SAT);             // -- остановка 

  // возвращаем освещение в исходное состояние 
  __SWITCH_ON__ 
      
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
            Serial.println(_success + command);

      _END_OBTAIN_PARAMS_

}


void pamSaturation(String command)
{
       _BEGIN_OBTAIN_PARAMS_   
       
            _pamSaturation(brightness, duration);     
            Serial.println(_success + command);
            
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
    digitalWrite(BLUE_PIN, SAT);             // -- остановка     

  // возвращаем освещение в исходное состояние 
  __SWITCH_ON__ 
    
}
void pamAdditional(String command)
{
       _BEGIN_OBTAIN_PARAMS_   
       
            _pamAdditional(brightness, duration);     
            Serial.println(_success + command);
            
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
    digitalWrite(RED_PIN, ADD);                // -- остановка       

  // возвращаем освещение в исходное состояние 
  __SWITCH_ON__ 
    
}
void pamFlash()
{
    _pamFlash();

    Serial.println(_success + "FLASH");    
}

/* измерительная вспышка. 
*/
void _pamFlash()
{
    // выклчаем освещение 
    __SWITCH_OFF__

    digitalWrite(CAMERA_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(BLUE_PIN, HIGH);
    delayMicroseconds(LFLASH);
    digitalWrite(BLUE_PIN, LOW);
    int t = EXP-LFLASH-20;
    if (t > 4)
      delayMicroseconds(t);
    digitalWrite(CAMERA_PIN, LOW);

  // возвращаем освещение в исходное состояние 
  __SWITCH_ON__ 
    
}
/*темновой кадр
*/
void _pamDark()
{
    __SWITCH_OFF__ 
    
    digitalWrite(CAMERA_PIN, HIGH);   
    delayMicroseconds(EXP);
    digitalWrite(CAMERA_PIN, LOW);   
    
   __SWITCH_ON__ 

}
void pamDark()
{
    _pamDark();
    Serial.println(_success + "DARK");    
}
/* отколючение испточников освещения на заданный промежуток времени
*/
void pamDarkness(String command)
{
    int index1 = command.indexOf('(');                        
    int index2 = command.indexOf(')');                        
    if (index1 == -1 || index2 == -1)                         
      Serial.println(_error);                                 
    else                                                      
    {                                                         
          String params = command.substring(index1 + 1, index2);  
          int duration   = params.toInt();                         
          if (duration < 1 || duration > 60000)
            Serial.println(_error);                                 
          else
          {
            _pamDarkness(duration);
            Serial.println(_success + command);    
          }
   }
}
/* выключение освещения на delayMs миллисекунд 
*/
void _pamDarkness(int delayMs)
{
    // выклчаем освещение 
    __SWITCH_OFF__
    delay(delayMs);
    __SWITCH_ON__ 
}

/* получение серии изображений FoFm
*/
void _pamFoFm()
{
   //String s = "LSAT=0";
   // pamSetLSAT(s);
    __SWITCH_OFF__
    
    _pamDark();           //0 F0_BF
    delay(TRANSFER);
    
    _pamFlash();          //1   F0_1
    delay(TRANSFER);
 //   _pamDark();           //2 - unused
 //   delay(TRANSFER);

    _pamFlash();          //3   F0_2
    delay(TRANSFER);
  //  _pamDark();           //4   - unused
  //  delay(TRANSFER);

    _pamFlash();          //5   F0_3
    delay(TRANSFER);

   _pamSaturation(LSAT, 500);

//    _pamDark();           //6   Fm_BF
//    _pamSaturation(LSAT, 500);

    _pamFlash();              //7 - Fm_1
//    delay(TRANSFER);
    _pamSaturation(LSAT, TRANSFER);
    
//    _pamDark();               //8 - unused
//    _pamSaturation(LSAT,TRANSFER);

    _pamFlash();              //9  - Fm_2
//    delay(TRANSFER);
    _pamSaturation(LSAT, TRANSFER);   
    
//    _pamDark();               //10 - unused 
//    _pamSaturation(LSAT, 100);
    
    _pamFlash();              //11 - Fm3
    delay(TRANSFER);        
     
    __SWITCH_ON__ 
}

void pamFoFm()
{
    _pamFoFm();
    Serial.println(_success + "FOFM");    
}

/* получение серии изображений FtFm1
*/
void _pamFtFm1()
{
    __SWITCH_OFF__
   _pamDark();
    //_pamFlash();

    _pamActinic(LACT, 100);
    _pamFlash();

    _pamActinic(LACT, 100);
    _pamFlash();

    _pamActinic(LACT, 100);
    _pamFlash();
    delay(TRANSFER);

    //_pamDark();
    //_pamFlash();
    
    _pamSaturation(LSAT, 500);
    
    _pamFlash();
    _pamSaturation(LSAT, 100);
    _pamFlash();
    _pamSaturation(LSAT, 100);
    _pamFlash();
    delay(TRANSFER);        
    __SWITCH_ON__ 
}

void pamFtFm1()
{
    _pamFtFm1();
    Serial.println(_success + "FTFM1");    
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
      if (incomingString.indexOf("LSAT=") != -1)
        pamSetLSAT(incomingString);
      else if (incomingString.indexOf("LACT=") != -1)
        pamSetLACT(incomingString);
      else if (incomingString.indexOf("LADD=") != -1)
        pamSetLADD(incomingString);
      else if (incomingString.indexOf("SAT=") != -1)
        pamSetSAT(incomingString);
      else if (incomingString.indexOf("ACT=") != -1)
        pamSetACT(incomingString);
      else if (incomingString.indexOf("ADD=") != -1)
        pamSetADD(incomingString);
      else if(incomingString.indexOf("EXP=") != -1)
        pamSetEXP(incomingString);
      else if(incomingString.indexOf("LFLASH=") != -1)
        pamSetLFLASH(incomingString);
      else
        Serial.println(_unknown);
    }
    else if (incomingString.equals("PAM2"))
      pamVersioin();
    else if (incomingString.equals("LSAT?"))
      pamGetLSAT();
    else if (incomingString.equals("LACT?"))
      pamGetLACT();
    else if (incomingString.equals("LADD?"))
      pamGetLADD();
    else if (incomingString.equals("EXP?"))
      pamGetEXP();
    else if (incomingString.equals("LFLASH?"))
      pamGetLFLASH();
    else if (incomingString.equals("SAT?"))
      pamGetSAT();
    else if (incomingString.equals("ACT?"))
      pamGetACT();
    else if (incomingString.equals("ADD?"))
      pamGetADD();
    else if (incomingString.indexOf("ACTINIC(") != -1)
      pamActicinc(incomingString);
    else if (incomingString.indexOf("SATURATION(") != -1)
      pamSaturation(incomingString);   
    else if (incomingString.indexOf("ADDITIONAL(") != -1)
      pamAdditional(incomingString);           
    else if (incomingString.indexOf("DARKNESS(") != -1)
      pamDarkness(incomingString);           
    else if (incomingString.indexOf("DARK") != -1)
      pamDark();           
    else if (incomingString.indexOf("FLASH") != -1)
      pamFlash();           
    else if (incomingString.indexOf("FOFM") != -1)
      pamFoFm();           
    else if (incomingString.indexOf("FTFM1") != -1)
      pamFtFm1();           
    else
      Serial.println(_unknown);
  }
}
