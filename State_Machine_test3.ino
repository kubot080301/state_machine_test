
class Flasher{
  // 腳位定義
  int led_Pin;

  // 狀態 
  int led_State;             

  // 狀態條件變數
  unsigned long previousMillis;

  // 狀態改變條件
  long OnTime;
  long OFFTime;

  // 發佈初始化狀態
  public:
    Flasher(int pin, long on, long off){
      led_Pin = pin;
      pinMode(led_Pin, OUTPUT);

      OnTime = on;
      OFFTime = off;

      led_State = LOW;
      previousMillis = 0;
    }


void Update(){
/*
  計算條件是否變化 
  對時間狀態機
  變化條件 : 時間差
  條件來源 : 系統時間
  定義開機到現在的時間等於currentMillis
  unsigned long 計算4294967295秒=50天溢位
*/

  unsigned long currentMillis = millis();
  
/* 
  若現在時間-起始時間>=目標變化時間
  則起始時間變化為現在時間
  並執行
    若現在LED狀態為LOW   (狀態1)
    則變為HIGH          (變為狀態2) 
    否則為LOW           (狀態2變為狀態1)
*/

  if((led_State == HIGH) && (currentMillis - previousMillis >= OnTime)){
    previousMillis = currentMillis; 
    led_State = LOW;  
    digitalWrite(led_Pin, led_State);
  }
  else if ((led_State == LOW) && (currentMillis - previousMillis >= OFFTime)){
    previousMillis = currentMillis;
    led_State = HIGH;
    digitalWrite(led_Pin, led_State);
  }  
}
};

// 類組 (腳位, 改變為狀態1時間差, 改變為狀態2時間差(1+2))
Flasher led1(12, 500, 500);
Flasher led2(13, 10, 990);

void setup() {
}

void loop() {
  led1.Update();
  led2.Update();
}
