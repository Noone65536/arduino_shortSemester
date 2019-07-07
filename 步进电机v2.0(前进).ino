int Pin0 = 8;  
int Pin1 = 9;
int Pin2 = 10;
int Pin3 = 11;
int Pin4 = 4 ;
int Pin5 = 5 ;
int Pin6 = 6 ;
int Pin7 = 7 ;
int _step =0 ;//步进电动机的步模式
boolean dir; //= -1;正反转
int stepperSpeed = 3;//电机转速,1ms一步
void setup()
{
  pinMode(Pin0, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
}


void loop() {
  up2();
  
  //down();
  //delay(3000);

}

void down()
  {
   
    switch(_step){
    case 0:
    //stepperSpeed++;
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);//32A
    break;
    case 1:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);//10B
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
    break;
    case 2:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;
    case 3:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
    break;
    case 4:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
    break;
    case 5:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
    break;
      case 6:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;
    case 7:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
    break;
    default:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;
  }
   _step++;
 
  if(_step>7){    _step=0;  }

  delay(stepperSpeed);
  } 
    
     
    
  void up()
{ 
  
  switch(_step){
    case 0:
    //stepperSpeed++;
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);//32A
    break;
    case 1:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);//10B
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
    break;
    case 2:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
    break;
    case 3:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
    break;
    case 4:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;
    case 5:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
    break;
      case 6:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
    break;
    case 7:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
    break;
    default:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
    break;
  }
    _step++;
 
  if(_step>7){    _step=0;  }
 
  delay(stepperSpeed);

}

 void up2()
{ 
  
  switch(_step){
    case 0:
    //stepperSpeed++;
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin3, LOW);//32A
      digitalWrite(Pin7, HIGH);
    break;
    case 1:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin1, LOW);//10B
      digitalWrite(Pin5, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin7, HIGH);
    break;
    case 2:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin5, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin7, LOW);
    break;
    case 3:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin5, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin6, HIGH);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin7, LOW);
    break;
    case 4:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin6, HIGH);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin7, LOW);
    break;
    case 5:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin4, HIGH);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin6, HIGH);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin7, LOW);
    break;
      case 6:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin4, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin7, LOW);
    break;
    case 7:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin4, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin7, HIGH);
    break;
    default:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin4, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin5, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin6, LOW);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin7, LOW);
    break;
  }
    _step++;
 
  if(_step>7){    _step=0;  }
 
  delay(stepperSpeed);

}

