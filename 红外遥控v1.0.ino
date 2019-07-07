/******人体感应模块实验******/
int redpin=3;//定义LED接口
int bluepin=4;
int greenpin=5;
int redval;//定义LED变量
int blueval;
int greenval;
int i=0;

int ledPin = 13;
int pirPin = 7;//设置感应端口
int pirValue;//感应变量

void setup()
{
  Serial.begin(9600);
  pinMode(pirPin,INPUT);//感应为输入端口
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin,LOW);

  pinMode(redpin,OUTPUT);//设置LED接口为输出接口
  pinMode(bluepin,OUTPUT);
  pinMode(greenpin,OUTPUT);  
  pinMode(redval,INPUT);//设置LED变量为输入值
  pinMode(blueval,INPUT);
  pinMode(greenval,INPUT);
  analogWrite(redpin,255);
  analogWrite(bluepin,255);
  analogWrite(greenpin,255);
}

void loop()
{
   int r=random(0,256);
   int g=random(0,256);
   int b=random(0,256);
   pirValue = digitalRead(pirPin);//读取感应数值赋值给变量
   if(HIGH == pirValue)
   {
     digitalWrite(ledPin,HIGH);
     delay(50);
     digitalWrite(ledPin,LOW);  
     led();
   }
   else
   {
      analogWrite(redpin,255);
      analogWrite(bluepin,255);
      analogWrite(greenpin,255);
   }
}

void led()
{
  redval=199;
  greenval=2;
  blueval=1;
  for(int i=200;i<300;i++)
  {
    redval-=2;//红灯变暗
    greenval=1;//绿灯不变
    blueval+=2;// 黄灯变亮 
    analogWrite(redpin,redval);//给LED接口付模拟值
    analogWrite(bluepin,greenval);
    analogWrite(greenpin,blueval);
    Serial.print(i,DEC);//显示出i的值
    Serial.print(   "     R:");//分别显示出各个LED的模拟值
    Serial.print(redval,DEC);
    Serial.print(    "    B:");
    Serial.print(blueval,DEC);
    Serial.print(    "    G:");
    Serial.println(greenval,DEC);
  }
}


//随机色
//void led()
//{
//  int r=random(0,256);
//  int g=random(0,256);
//  int b=random(0,256);
//  analogWrite(redpin,r);//给LED接口付模拟值
//  analogWrite(bluepin,g);
//  analogWrite(greenpin,b);
//  delay(2000);
//}
