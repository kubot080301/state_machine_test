// 腳位定義
const int led1_Pin = 5;
const int led2_Pin = 6;

// 起始狀態 (狀態1)
int led1_State = LOW;             // ledState used to set the LED
int led2_State = LOW;

// 狀態條件變數
unsigned long previousMillis = 0;        // will store last time LED was updated

// 狀態改變條件
const long led1_interval = 1000;           // interval at which to blink (milliseconds)
const long led2_interval = 1500;


void setup() {
  // 初始化
  pinMode(led1_Pin, OUTPUT);
  pinMode(led2_Pin, OUTPUT);
}

void loop() {
  //計算條件是否變化 
  //對時間狀態機
  //變化條件 : 時間差

  //開機到現在的時間等於currentMillis
  //unsigned long 計算4294967295秒=50天溢位
  unsigned long currentMillis = millis();
/*
  若現在時間-起始時間>=目標變化時間
  則起始時間變化為現在時間
  並執行
    若現在LED狀態為LOW   (狀態1)
    則變為HIGH          (變為狀態2) 
    否則為LOW           (狀態2變為狀態1)
*/

  if((led1_State == HIGH) && (currentMillis - previousMillis >= led1_interval)){
    previousMillis = currentMillis;
    led1_State = LOW;
    digitalWrite(led1_Pin, led1_State);
  }
  else if ((led1_State == LOW) && (currentMillis - previousMillis >= led1_interval)){
    previousMillis = currentMillis;
    led1_State = HIGH;
    digitalWrite(led1_Pin, led1_State);
  }
  if((led2_State == HIGH) && (currentMillis - previousMillis >= led2_interval)){
    previousMillis = currentMillis;
    led2_State = LOW;
    digitalWrite(led2_Pin, led2_State);
  }
  else if ((led2_State == LOW) && (currentMillis - previousMillis >= led2_interval)){
    previousMillis = currentMillis;
    led2_State = HIGH;
    digitalWrite(led2_Pin, led2_State);
  }
}
