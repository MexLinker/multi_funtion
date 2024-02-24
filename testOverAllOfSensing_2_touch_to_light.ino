#define beep_pin  33
char g_i=0;

// check again

// #define S1pG0 35
#define S1pG0 19
#define S1nG0 32


#define S1pG1 25
#define S1nG1 33

#define S1pG2 18
#define S1nG2 27

#define S2p 17
#define S2n 5

#define S3pG0 15
#define S3nG0 4

#define S3pG1 22
#define S3nG1 16

// important
#define l1 34

#define LED_BUILTIN 2

unsigned long previousMicros = 0;
unsigned long timeInterval = 0;

int lv = 1;


void setup() {
  Serial.begin(9600);  //设置波特率

  pinMode(beep_pin, OUTPUT);//设置引脚为输出模式
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(S1pG0, OUTPUT);
  pinMode(S1nG0, OUTPUT);

  pinMode(S1pG1, OUTPUT);
  pinMode(S1nG1, OUTPUT);

  pinMode(S1pG2, OUTPUT);
  pinMode(S1nG2, OUTPUT);

  pinMode(S2p, OUTPUT);
  pinMode(S2n, OUTPUT);

  pinMode(S3pG0, OUTPUT);
  pinMode(S3nG0, OUTPUT);

  pinMode(S3pG1, OUTPUT);
  pinMode(S3nG1, OUTPUT);

  pinMode(l1, INPUT);

  
  
}



void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(LED_BUILTIN,0);

  state0();
  delay(100);

  digitalWrite(LED_BUILTIN,0);

  state1();
  delay(10);

  // unsigned long currentMicros = micros() / 1000000;

  previousMicros = micros();

  digitalWrite(LED_BUILTIN,0);

  state2();
  delay(100);

  // // # 单位是微秒

  // // timeInterval = previousMicros - micros();
  
  // // Serial.println(micros());
  // // Serial.println(timeInterval);

  // previousMicros = micros();

  // lv = digitalRead(l1);

  // if(lv = 1){
  //   lv = digitalRead(l1);
  // }else{
  //   digitalWrite(LED_BUILTIN,1);
  //   Serial.println(previousMicros - micros());
  // }
  // lv = 1;
}

void state0(){
  digitalWrite(S1pG0,0);
  digitalWrite(S1nG0,1);

  digitalWrite(S2p,0);
  digitalWrite(S2n,1);
}

void state1(){
  digitalWrite(S1pG0,1);
  digitalWrite(S1nG0,0);

  digitalWrite(S2p,1);
  digitalWrite(S2n,0);
}

void state2(){
  int lv = digitalRead(l1);
  Serial.println(lv);
  digitalWrite(LED_BUILTIN,!lv);

  // 低电平触发中断
}





