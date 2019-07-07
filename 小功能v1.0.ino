/**
 * 温湿度传感器，超声波传感器，亮度传感器，红外线接收，遥控器
 * 人体热释电
 */

#include <dht.h>//调用温湿度库文件
#include <IRremote.h>//调用红外库文件
#define DHT11_PIN 8//温湿度传感器串口

dht DHT;
IRrecv irrecv(RECV_PIN);   
decode_results results;//解码结果放在 decode results结构的 result中

int echoPin=8;//定义超声波信号接收接口
int trigPin=9;//定义超声波信号发出接口
int sensorInPin = A0;//定义亮度传感器模拟接口0
int sensorValue = 0;// 亮度传感器模拟输入变量
int RECV_PIN = 10;//定义红外接收器的引脚
int pirPin = 7;//设置人体热释电感应端口
int pirValue;//人体热释电感应变量

void setup()
{
  Serial.begin(9600);

  pinMode(echoPin, INPUT);//超声波传感器echo
  pinMode(trigPin, OUTPUT);//超声波传感器trig
  irrecv.enableIRIn(); // 启动接收器  

}

void loop()
{
  dis();
  brightness();
  ht();
  induction();
}

//返回当前距离
int dis()
{
  digitalWrite(trigPin, LOW); // 使发出发出超声波信号接口低电平2μs
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // 使发出发出超声波信号接口高电平10μs，这里是至少10μs
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // 保持发出超声波信号接口低电平
  int distance = pulseIn(echoPin, HIGH); // 读出脉冲时间
  distance= distance/58; // 将脉冲时间转化为距离（单位：厘米）
  Serial.println(distance);
  return distance;
}

//返回当前亮度
int brightness()
{
  sensorValue=analogRead(sensorInPin);// 读取传感器的模拟值并赋值给val
  Serial.println(sensorValue);//显示val 变量
  return sensorValve;
}

//打印当前温湿度
void ht()
{
  int chk = DHT.read11(DHT11_PIN); 
  Serial.print("Humidity: ");
  Serial.println(DHT.humidity, 1);
  Serial.print("Temperature: ");
  Serial.println(DHT.temperature, 1);
}

//红外接收+遥控器
void remote()
{
  if (irrecv.decode(&results))//解码成功，收到一组红外讯号   
    {  
      Serial.println(results.value, HEX);//以16进制换行输出接收代码  
      if (results.value == 0xFF30CF){  //按1
        Serial.println("test"); 
      }
      irrecv.resume(); // 接收下一个值
    }
}

//人体热释电
void induction()
{
  pirValue = digitalRead(pirPin);//读取感应数值赋值给变量
  if(HIGH == pirValue){
    Serial.println("People here!");
  }
}


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
