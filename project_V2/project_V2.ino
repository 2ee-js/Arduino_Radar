#include <Servo.h>
#include <LiquidCrystal_I2C.h>
const uint8_t TRIG = 22U;
const uint8_t ECHO = 23U;
Servo servo;
int a=0;
class LiquidCrystal_I2C lcd(0x27, 16, 2);
const uint8_t BUZZER_PIN = 7U;
const uint8_t LED = 2U;
byte robot1[8] = {
  B01110,
  B01110,
  B01110,
  B10100,
  B11111,
  B00101,
  B11100,
  B10111
};
byte robot2[8] = {
  B01110,
  B01110,
  B01110,
  B00101,
  B11111,
  B10100,
  B00111,
  B11101
};

void setup() {
    lcd.init();  //lcd 초기화.
    Serial.begin(115200UL);
    lcd.home();
    lcd.backlight();
    lcd.clear(); //화면을 한번 지워 주세요.
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED, OUTPUT);
    lcd.createChar(1, robot1);
    lcd.createChar(2, robot2);
    servo.attach(8);
    servo.write(a);
}
void loop() {
    for(a=0; a<180; a++){
      servo.write(a);
      delay(30UL);
      digitalWrite(TRIG, LOW);
      delayMicroseconds(2);
      digitalWrite(TRIG, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIG, LOW);
      long dis = pulseIn(ECHO, HIGH)/58; 
    if (dis <= 150 && dis >= 140){
      tone(BUZZER_PIN, 50, 1200);
      delay(1200UL);
      digitalWrite(LED, HIGH);
      delay(1200UL);
      digitalWrite(LED, LOW);
      delay(1200UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(1,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("150cm내에 물체가 있습니다.");
    } else if (dis <= 140 && dis >= 130){
      tone(BUZZER_PIN, 50, 1100);
      delay(1100UL);
      digitalWrite(LED, HIGH);
      delay(1100UL);
      digitalWrite(LED, LOW);
      delay(1100UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(2,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("140cm내에 물체가 있습니다.");
    } else if (dis <= 130 && dis >= 120){
      tone(BUZZER_PIN, 50, 1000);
      delay(1000UL);
      digitalWrite(LED, HIGH);
      delay(1000UL);
      digitalWrite(LED, LOW);
      delay(1000UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(3,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("130cm내에 물체가 있습니다.");
    } else if (dis <= 120 && dis >= 110){
      tone(BUZZER_PIN, 50, 900);
      delay(900UL);
      digitalWrite(LED, HIGH);
      delay(900UL);
      digitalWrite(LED, LOW);
      delay(900UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(4,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("120cm내에 물체가 있습니다.");
    } else if (dis <= 100 && dis >= 90){
      tone(BUZZER_PIN, 50, 800);
      delay(800UL);
      digitalWrite(LED, HIGH);
      delay(800UL);
      digitalWrite(LED, LOW);
      delay(800UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(5,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("100cm내에 물체가 있습니다.");
    } else if (dis <= 90 && dis >= 80){
      tone(BUZZER_PIN, 50, 700);
      delay(700UL);
      digitalWrite(LED, HIGH);
      delay(700UL);
      digitalWrite(LED, LOW);
      delay(700UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(6,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("90cm내에 물체가 있습니다.");
    } else if (dis <= 80 && dis >= 70){
      tone(BUZZER_PIN, 50, 600);
      delay(600UL);
      digitalWrite(LED, HIGH);
      delay(600UL);
      digitalWrite(LED, LOW);
      delay(600UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(7,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("80cm내에 물체가 있습니다.");
    } else if (dis <= 70 && dis >= 60){
      tone(BUZZER_PIN, 50, 500);
      delay(500UL);
      digitalWrite(LED, HIGH);
      delay(500UL);
      digitalWrite(LED, LOW);
      delay(500UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(8,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("70cm내에 물체가 있습니다.");
    } else if (dis <= 60 && dis >= 50){
      tone(BUZZER_PIN, 50, 400);
      delay(400UL);
      digitalWrite(LED, HIGH);
      delay(400UL);
      digitalWrite(LED, LOW);
      delay(400UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(9,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("60cm내에 물체가 있습니다.");
    } else if (dis <= 50 && dis >= 40){
      tone(BUZZER_PIN, 50, 300);
      delay(300UL);
      digitalWrite(LED, HIGH);
      delay(300UL);
      digitalWrite(LED, LOW);
      delay(300UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(10,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("50cm내에 물체가 있습니다.");
    } else if (dis <= 40 && dis >= 30){
      tone(BUZZER_PIN, 50, 200);
      delay(200UL);
      digitalWrite(LED, HIGH);
      delay(200UL);
      digitalWrite(LED, LOW);
      delay(200UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(11,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("40cm내에 물체가 있습니다.");
    } else if (dis <= 30 && dis >= 20){
      tone(BUZZER_PIN, 50, 100);
      delay(100UL);
      digitalWrite(LED, HIGH);
      delay(100UL);
      digitalWrite(LED, LOW);
      delay(100UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(12,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("30cm내에 물체가 있습니다.");
    } else if (dis <= 20 && dis >= 10){
      tone(BUZZER_PIN, 50, 70);
      delay(50UL);
      digitalWrite(LED, HIGH);
      delay(50UL);
      digitalWrite(LED, LOW);
      delay(50UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(13,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("20cm내에 물체가 있습니다.");
    } else if (dis <= 10 && dis >= 0){
      tone(BUZZER_PIN, 50, 50);
      delay(20UL);
      digitalWrite(LED, HIGH);
      delay(20UL);
      digitalWrite(LED, LOW);
      delay(20UL);
      a--;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(14,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("위험!!");
    }
  }
    if(a==180){
    for(a=180; a>0; a--){
      servo.write(a);
      delay(30UL);
      digitalWrite(TRIG, LOW);
      delayMicroseconds(2);
      digitalWrite(TRIG, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIG, LOW);
      long dis = pulseIn(ECHO, HIGH)/58;
    if (dis <= 150 && dis >= 140){
      tone(BUZZER_PIN, 50, 1200);
      delay(1200UL);
      digitalWrite(LED, HIGH);
      delay(1200UL);
      digitalWrite(LED, LOW);
      delay(1200UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(1,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("150cm내에 물체가 있습니다.");
    } else if (dis <= 140 && dis >= 130){
      tone(BUZZER_PIN, 50, 1100);
      delay(1100UL);
      digitalWrite(LED, HIGH);
      delay(1100UL);
      digitalWrite(LED, LOW);
      delay(1100UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(2,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("140cm내에 물체가 있습니다.");
    } else if (dis <= 130 && dis >= 120){
      tone(BUZZER_PIN, 50, 1000);
      delay(1000UL);
      digitalWrite(LED, HIGH);
      delay(1000UL);
      digitalWrite(LED, LOW);
      delay(1000UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(3,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("130cm내에 물체가 있습니다.");
    } else if (dis <= 120 && dis >= 110){
      tone(BUZZER_PIN, 50, 900);
      delay(900UL);
      digitalWrite(LED, HIGH);
      delay(900UL);
      digitalWrite(LED, LOW);
      delay(900UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(4,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("120cm내에 물체가 있습니다.");
    } else if (dis <= 100 && dis >= 90){
      tone(BUZZER_PIN, 50, 800);
      delay(800UL);
      digitalWrite(LED, HIGH);
      delay(800UL);
      digitalWrite(LED, LOW);
      delay(800UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(5,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("100cm내에 물체가 있습니다.");
    } else if (dis <= 90 && dis >= 80){
      tone(BUZZER_PIN, 50, 700);
      delay(700UL);
      digitalWrite(LED, HIGH);
      delay(700UL);
      digitalWrite(LED, LOW);
      delay(700UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(6,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("90cm내에 물체가 있습니다.");
    } else if (dis <= 80 && dis >= 70){
      tone(BUZZER_PIN, 50, 600);
      delay(600UL);
      digitalWrite(LED, HIGH);
      delay(600UL);
      digitalWrite(LED, LOW);
      delay(600UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(7,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("80cm내에 물체가 있습니다.");
    } else if (dis <= 70 && dis >= 60){
      tone(BUZZER_PIN, 50, 500);
      delay(500UL);
      digitalWrite(LED, HIGH);
      delay(500UL);
      digitalWrite(LED, LOW);
      delay(500UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(8,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("70cm내에 물체가 있습니다.");
    } else if (dis <= 60 && dis >= 50){
      tone(BUZZER_PIN, 50, 400);
      delay(400UL);
      digitalWrite(LED, HIGH);
      delay(400UL);
      digitalWrite(LED, LOW);
      delay(400UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(9,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("60cm내에 물체가 있습니다.");
    } else if (dis <= 50 && dis >= 40){
      tone(BUZZER_PIN, 50, 300);
      delay(300UL);
      digitalWrite(LED, HIGH);
      delay(300UL);
      digitalWrite(LED, LOW);
      delay(300UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(10,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("50cm내에 물체가 있습니다.");
    } else if (dis <= 40 && dis >= 30){
      tone(BUZZER_PIN, 50, 200);
      delay(200UL);
      digitalWrite(LED, HIGH);
      delay(200UL);
      digitalWrite(LED, LOW);
      delay(200UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(11,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("40cm내에 물체가 있습니다.");
    } else if (dis <= 30 && dis >= 20){
      tone(BUZZER_PIN, 50, 100);
      delay(100UL);
      digitalWrite(LED, HIGH);
      delay(100UL);
      digitalWrite(LED, LOW);
      delay(100UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(12,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("30cm내에 물체가 있습니다.");
    } else if (dis <= 20 && dis >= 10){
      tone(BUZZER_PIN, 50, 70);
      delay(50UL);
      digitalWrite(LED, HIGH);
      delay(50UL);
      digitalWrite(LED, LOW);
      delay(50UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(13,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("20cm내에 물체가 있습니다.");
    } else if (dis <= 10 && dis >= 0){
      tone(BUZZER_PIN, 50, 50);
      delay(20UL);
      digitalWrite(LED, HIGH);
      delay(20UL);
      digitalWrite(LED, LOW);
      delay(20UL);
      a++;
      lcd.setCursor(0,0);
      lcd.print("DISTANCE : ");
      lcd.print(dis);
      lcd.print("cm");
      lcd.setCursor(14,1);
      lcd.write(byte(2));
      lcd.setCursor(15,1);
      lcd.write(byte(1));
      delay(500UL);
      lcd.clear();
      Serial.println("위험!!");
      }
    }
  }
  delay(100UL);
}