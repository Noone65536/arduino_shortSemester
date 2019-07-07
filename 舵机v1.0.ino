#include <Servo.h>
#include<SoftwareSerial.h>
#include<Stepper.h>
#define SAFEDIS 20
const int stepsPerRevolution = 500;
// 初始化步进电机要使用的Arduino的引脚编号
int safeDistance=0;
int inputPin=8; // 定义超声波信号接收接口echo
int outputPin=9; // 定义超声波信号发出接口
int distance[2] = {0,0};
int finalDis=0;
void objDet(int count);
Servo myservo; 
int pos = 0; // 用于存储舵机位置的变量
int dis();
void setup()
{
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  myservo.attach(10); // 舵机控制信号引脚
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);

  for (int i = 2 ;i < 6; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  int i=0;
  int dist;
  int height;
  myservo.write(90);
  dist = dis();
  if(dist <= SAFEDIS){
    i=djmoving(90,180);
    if(i==0)
    {
      i=djmoving(90,0);
      if(i==0)
      {
        myservo.write(90);
        height= calculatehei();
        Serial.print("The height is ");
        Serial.println(height); //输出距离值
      }
      else{
        myservo.write(i);
        delay(3000);
      }
    }
    else{
       myservo.write(i);
        delay(3000);
    }
  }
  else{
   //let the dog go straight
  }
}

int calculatehei(){
  safeDistance=dis();
  int derta;
  int height;
  for(int i=0; i<50;i++){
    distance[0]=dis();
    moving();
    distance[1]=dis();
    derta=abs(distance[1]-distance[0]);
    if(derta>SAFEDIS){
      finalDis=min(distance[0],distance[1]);
      height=sqrt(finalDis*finalDis-safeDistance*safeDistance);
      return height;
      }
    delay(50);
   }
 }

int dis()
{
  digitalWrite(outputPin, LOW); // 使发出发出超声波信号接口低电平2μs
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH); // 使发出发出超声波信号接口高电平10μs，这里是至少10μs
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW); // 保持发出超声波信号接口低电平
  int distance = pulseIn(inputPin, HIGH); // 读出脉冲时间
  distance = distance/58; // 将脉冲时间转化为距离（单位：厘米）
  Serial.println(distance); //输出距离值
  delay(90);
  return distance;
}

void moving()
{
  for (int count = 0; count < 3; count++)
  {
    for (int i = 2; i < 6; i++)
    {
      digitalWrite(i, HIGH);
      delay(1);
      digitalWrite(i, LOW);
    }
  }
}
int djmoving(int preangle,int lastangle){
  int dist=0;
  int height=0;
  int pos;
  if(preangle<lastangle)
  {
      for(pos = preangle; pos < lastangle; pos += 1){
     myservo.write(pos); // 输入对应的角度值，舵机会转到此位置
     delay(10); // 15ms后进入下一个位置
     dist = dis();
     if(dist>SAFEDIS){
        return pos;
     }
   }
  }
  else{
    for(pos = preangle; pos > lastangle; pos -= 1){
     myservo.write(pos); // 输入对应的角度值，舵机会转到此位置
     delay(10); // 15ms后进入下一个位置
     dist = dis();
     if(dist>SAFEDIS)
     {
        return pos;
     }
    }
   }
   return 0;
 }
