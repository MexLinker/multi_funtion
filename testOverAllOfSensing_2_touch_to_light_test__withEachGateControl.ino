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

int lv = 1;
unsigned long previousMicros = 0;





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
  sensing();

}

void sensing(){
  digitalWrite(LED_BUILTIN,0);


  //state1: 重置所有开关
  s1g0(0);
  s2(0);
  delay(30);

  //state2: 打开压电片与主回路，使电流到电感
  s1g0(1);
  // s2(0); 不变
  delay(10);

  //state3: 关闭压电片与主回路
  s1g0(0);
  // s2(0); 不变
  // IMMMMMMMMM
  delay(12);

  //state4: 开启frewheeling支路
  // s1g0(0); 不变
  s2(1); 
  
  delay(10);
  previousMicros = micros();

  while(lv == 1){
    lv = digitalRead(l1);
  }

  while(lv == 0){
    Serial.println(micros() - previousMicros);

    digitalWrite(LED_BUILTIN,1);
    lv = 1;
  }



  //state4: 重置所有开关
  s1g0(0);
  s2(0);
  delay(30);
}

//s1g0 will control both the S1pG0 and S1nG0, the argument 0 will close 1 will open
void s1g0(int op){
  digitalWrite(S1pG0,op);
  digitalWrite(S1nG0,!op);
}

//s2 will control both the S2p and S2n, the argument 0 will close 1 will open
void s2(int op){
  digitalWrite(S2p,op);
  digitalWrite(S2n,!op);
}





