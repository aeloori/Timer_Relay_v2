#define setPin 13
#define modePin 12

byte prestate=0;
byte set=0;
byte mode=0;
byte timer=0;
byte relayNo=0;

void setup()
{
  pinMode(4,OUTPUT);//define relay pin numbers ranging from 1-4 (1)
  pinMode(3,OUTPUT);//define relay pin numbers ranging from 1-4 (2)
  pinMode(2,OUTPUT);//define relay pin numbers ranging from 1-4 (3)
  pinMode(1,OUTPUT);//define relay pin numbers ranging from 1-4 (4)
  
  pinMode(setPin,INPUT);
  pinMode(modePin,INPUT);
  Serial.begin(9600);
}
void loop()
{
  ResetVal();
  RelaySetter();
  TimeSetter();
  RelayWorker();
  ResetVal();
}

//reset varaibles to initial position
void ResetVal()
{
  // reset prestate to '0'
  prestate =0;
  Serial.print("prestate is reseted to : ");
  Serial.println(prestate);
  Serial.println();

  // reset set to '0'
  set=0;
  Serial.print("set is reseted to : ");
  Serial.println(set);
  Serial.println();

  // reset mode to '0'
  mode =0;
  Serial.print("mode is reseted to : ");
  Serial.println(mode);
  Serial.println();

  // reset timer to '0'
  timer=0;
  Serial.print("timer is reseted to : ");
  Serial.println(timer);
  Serial.println();

  // reset relayNo to '0'
  relayNo=0;
  Serial.print("relayNo is reseted to : ");
  Serial.println(relayNo);
  Serial.println();
}

//operates relay for specific interval
void RelayWorker()
{
  switch(timer)
  {

    // Perform relay operation for 10sec interval
    case 1:
    {
      digitalWrite(relayNo,HIGH);
      for(int t=1;t<=1800;t++)
      {
        delay(1000);
      }
      digitalWrite(relayNo,LOW);
      break;
    }

    //perform relay operation of 30sec interval
    case 2:
    {
      digitalWrite(relayNo,HIGH);
      for(int t=1;t<=3600;t++)
      {
        Serial.println();
        Serial.print("current second is ");
        Serial.print(t);
        delay(1000);
      }
      digitalWrite(relayNo,LOW);
      break;
    }

    //perform relay operation of 30sec interval
    case 3:
    {
      digitalWrite(relayNo,HIGH);
      for(int t=1;t<=5400;t++)
      {
        Serial.println();
        Serial.print("current second is ");
        Serial.print(t);
        delay(1000);
      }
      digitalWrite(relayNo,LOW);
      break;
    }

    //perform relay operation of 30sec interval
     case 4:
    {
      digitalWrite(relayNo,HIGH);
      for(int t=1;t<=7200;t++)
      {
        Serial.println();
        Serial.print("current second is ");
        Serial.print(t);
        delay(1000);
      }
      digitalWrite(relayNo,LOW);
      break;
    }
    default:
    {
      Serial.println("select time duration of the relay operation ");
      Serial.println();
    }
  }
  Serial.println();
}


//set timer index number using set button and pressing mode button it continues to next stage
void TimeSetter()
{
  while(mode!=HIGH)
  {
    mode=digitalRead(modePin);
    set=digitalRead(setPin);
    if(set==HIGH && prestate==0)
    {
      timer++;
      prestate++;
      Serial.print("Current time index no is : ");
      Serial.println(timer);
      Serial.println();
      delay(100);
      if(timer>4)
      {
        timer=1;
      }
    }
    else if(set==LOW)
    {
      prestate=0;
    }
  }
  Serial.print("final timer index no is : ");
  Serial.println(timer);
  Serial.println();
}


//selecting relay number by using mode button for relay no and set button for finalizing the relay no
void RelaySetter()
{
  while(set!=HIGH)
  {
    set=digitalRead(setPin);
    mode=digitalRead(modePin);
    if(mode==HIGH && prestate==0)
    {
      relayNo++;
      prestate++;
      Serial.print("current relay number is :");
      Serial.println(relayNo);
      Serial.println();
      delay(100);
      if(relayNo>4)
      {
        relayNo=1;
      }
    }
    else if(mode==LOW)
    {
      prestate=0;
    }
  }
  prestate=0;
  Serial.print("Final realy number is : ");
  Serial.println(relayNo);
  Serial.println();
}
