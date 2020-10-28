#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

// 조도센서를 아날로그 0핀(A0)에 연결합니다.
int cds = A0;
// LED를 3번핀에 연결합니다.
int led_1 = 3;
int led_2 = 4;
int led_3 = 5;
int led_4 = 6;
int led_5 = 7;
int pdlc = 11;
int i = 0;

//LCD SDA A4
//LCD SDL A5
int buzzer = 9;
void setup() 
{
  
      lcd.init();
      lcd.backlight();
      Serial.begin(9600);
      pinMode(led_1, OUTPUT);
      pinMode(led_2, OUTPUT);
      pinMode(led_3, OUTPUT);
      pinMode(led_4, OUTPUT);
      pinMode(led_5, OUTPUT);
      pinMode(pdlc, OUTPUT);
      pinMode(buzzer, OUTPUT);
}

char ser;
void loop() 
{
        if(Serial.available()){ser=Serial.read();}
        if(ser=='A'){
          Serial.println("Warning");
          
          lcd.setCursor(1,1);
          lcd.print("Warning");
          ser='f';
          tone(buzzer, 394);
        }
        else if(ser=='N'){
          noTone(buzzer);
          lcd.setCursor(1,1);
          lcd.print("       ");
        }
        // 조도센서로 부터 측정된 밝기 값을 읽습니다.
        // 조도센서로 부터 입력되어지는 전압의 크기 (0~5V)에 따라 0~1023 범위의 값으로 변환되어 반환합니다.
        int cdsValue = analogRead(cds);
 
        // 측정된 밝기 값를 시리얼 모니터에 출력합니다.
        Serial.print("cds =  ");
        Serial.println(cdsValue);
        //lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("sensor:");
        lcd.setCursor(7,0);
        lcd.print(cdsValue);
        digitalWrite(pdlc, LOW);
        digitalWrite(led_1, LOW); 
        digitalWrite(led_2, LOW); 
        digitalWrite(led_3, LOW); 
        digitalWrite(led_4, LOW); 
        digitalWrite(led_5, LOW);
      
      
        analogWrite(pdlc,i);
            
            
                                                      

        
        
        
 
        // 조도센서로 부터 측정된 밝기 값이 220보다 크다면, 아래의 블록을 실행합니다.
        if (cdsValue >200) 
        {    
                // LED가 연결된 핀의 로직레벨을 HIGH (5V)로 설정하여, LED가 켜지도록 합니다.
                digitalWrite(led_1, HIGH); 
                i = 220;    
                
        }
        if (cdsValue >400) 
        {    
                // LED가 연결된 핀의 로직레벨을 HIGH (5V)로 설정하여, LED가 켜지도록 합니다.
                digitalWrite(led_2, HIGH); 
                i=200;    
                
        }
        if (cdsValue >600) 
        {    
                // LED가 연결된 핀의 로직레벨을 HIGH (5V)로 설정하여, LED가 켜지도록 합니다.
                digitalWrite(led_3, HIGH);     
                i=185;
        }
        if (cdsValue >800) 
        {    
                // LED가 연결된 핀의 로직레벨을 HIGH (5V)로 설정하여, LED가 켜지도록 합니다.
                digitalWrite(led_4, HIGH); 
                i=155;    
                
        }
        if(cdsValue > 900)
        {    
               digitalWrite(led_5, HIGH);  
               i=135;   
        }
        
        
        
}
