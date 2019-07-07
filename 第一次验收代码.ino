//遥控器码值如下：
//CH-  FFA25D
//CH   FF629D
//CH+  FFE21D
//|<<  FF22DD
//>>|  FF02FD
//>||  FFC23D
//-    FFE01F
//+    FFA857
//EQ   FF906F
//0    FF6897
//100+ FF9867
//200+ FFB04F
//1    FF30CF
//2    FF18E7
//3    FF7A85
//4    FF10EF
//5    FF38C7
//6    FF5AA5
//7    FF42BD
//8    FF4AB5
//9    FF52AD

#include <IRremote.h>     // IRremote库声明  
  
int RECV_PIN = 10;        //定义红外接收器的引脚为10
int LED_PIN1 = 5;
int LED_PIN5 = 6;
int LED_PIN9 = 11;
IRrecv irrecv(RECV_PIN);   
decode_results results;   //解码结果放在 decode results结构的 result中

int superSoIn = 4;      //  接超声波的 input 引脚到数字D4脚 echo
int superSoOut = 2;     //  接超声波的 output 引脚到数字D5脚 trig
int ledOut = 13;         // led灯的引脚为D13脚
int soundIN=7;          //  声音传感器的输入引脚为D7
int buzzerOut=12;       //  蜂鸣器的输出引脚为D12

void setup() 
{ //初始化串口及引脚的输入、输出模式
  Serial.begin(9600); 
  pinMode(superSoIn, INPUT); 
  pinMode(superSoOut, OUTPUT); 
  pinMode(ledOut,OUTPUT); 
  pinMode(soundIN, INPUT); 
  pinMode(buzzerOut,OUTPUT);
  digitalWrite(12,HIGH);
 
  irrecv.enableIRIn(); // 启动接收器  
  pinMode(LED_PIN1,OUTPUT);
}


void loop() 
{ 
  int soundSta = digitalRead(soundIN);   //定义声音传感器的状态
  unsigned int x1;                      //定义距离
  digitalWrite(superSoOut, LOW); //发出超声波信号接口低电平2 μs 
  delayMicroseconds(2); 
  digitalWrite(superSoOut, HIGH); //使发出超声波信号接口高电平10μs ，这里是至少10μs 
  delayMicroseconds(10); 
  digitalWrite(superSoOut, LOW);  // 保持发出超声波信号接口低电平
  float time = pulseIn(superSoIn, HIGH);  //  读出接收脉冲的时间 

  int distance1 = time/58;       // 将脉冲时间转化为距离（单位：厘米） 
  x1 = distance1 * 100.0;
  distance1 = x1 / 100.0;  //保留两位小数 
  Serial.print("距离（厘米） = "); 
  Serial.print(distance1);  //输出距离值     
  Serial.println("是否有声音 = ");
  Serial.print(soundSta);  //输出是否有声音
  delay(50);

  if (distance1 <= 5) 
  {  
    digitalWrite(ledOut,HIGH);  //灯亮起
    tone(buzzerOut,50,50);//蜂鸣器发声
    delay(50);
    digitalWrite(ledOut,LOW);

  }else if(distance1 > 5 && distance1 < 10){
    digitalWrite(ledOut,HIGH);  //灯亮起
    tone(buzzerOut,150,50);//蜂鸣器发声
    delay(50);
    digitalWrite(ledOut,LOW);

  }else if(distance1 > 10 && distance1 < 15){
    digitalWrite(ledOut,HIGH);  //灯亮起
    tone(buzzerOut,250,50);//蜂鸣器发声
    delay(50);
    digitalWrite(ledOut,LOW);

  }else if(distance1 > 15 && distance1 < 20){
    digitalWrite(ledOut,HIGH);  //灯亮起
    tone(buzzerOut,350,50);//蜂鸣器发声
    delay(50);
    digitalWrite(ledOut,LOW);

  }else if(distance1 > 20 && distance1 < 25){
    digitalWrite(ledOut,HIGH);  //灯亮起
    tone(buzzerOut,450,50);//蜂鸣器发声
    delay(50);
    digitalWrite(ledOut,LOW);

  }else if(distance1 > 25 && distance1 < 30){
    digitalWrite(ledOut,HIGH);  //灯亮起
    tone(buzzerOut,550,50);//蜂鸣器发声
    delay(50);
    digitalWrite(ledOut,LOW);

  }else if(distance1 > 25 && distance1 < 30){
    digitalWrite(ledOut,HIGH);  //灯亮起
    tone(buzzerOut,650,50);//蜂鸣器发声
    delay(50);
    digitalWrite(ledOut,LOW);
}
//    if (soundSta == 1){
//    digitalWrite(buzzerOut,LOW);
//    delay(500);
//    digitalWrite(buzzerOut,HIGH);
//    Serial.print("test");}

if (irrecv.decode(&results))//解码成功，收到一组红外讯号   
    {  
      Serial.println(results.value, HEX);//以16进制换行输出接收代码  
      if (results.value == 0xFF30CF){  //按1，5口灯亮
        digitalWrite(LED_PIN1,HIGH);
        Serial.println("test"); 
      }
      else if(results.value == 0xFF18E7){//按2，5口灯灭
        digitalWrite(LED_PIN1,LOW);
      }
      else if(results.value == 0xFF38C7){//按5，6口灯亮
        digitalWrite(LED_PIN5,HIGH);
      }
      else if(results.value == 0xFF5AA5){//按6，6口灯灭
        digitalWrite(LED_PIN5,LOW);
      }
       else if(results.value == 0xFF52AD){//按9，11口灯亮
        digitalWrite(LED_PIN9,HIGH);
      }
      else if(results.value == 0xFF4AB5){//按8，11口灯灭
        digitalWrite(LED_PIN9,LOW);
      }
      irrecv.resume(); // 接收下一个值  
    }    


}
