int ir1,ir2,ir3,ir4;

void setup() {
  pinMode(5,INPUT);//IR sensor 1
  pinMode(6,INPUT);//IR sensor 1
  pinMode(7,INPUT);//IR sensor 1
  pinMode(8,INPUT);//IR sensor 1
  pinMode(9,OUTPUT);//clokwise motor 1
  pinMode(10,OUTPUT);//anti-clokwise motor 1
  pinMode(11,OUTPUT);//clokwise motor 2
  pinMode(12,OUTPUT);//anti-clokwise motor 2
}

void hleft()
{
   while(ir1==0&&ir2==1&&ir3==1&&ir4==0)
  {
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}
}

void hright()
{
   while(ir1==0&&ir2==1&&ir3==1&&ir4==0)
  {
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
}
}

void sleft()
{
  
   while(ir1==0&&ir2==1&&ir3==1&&ir4==0)
  {
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  }
}

void sright()
{
  
   while(ir1==0&&ir2==1&&ir3==1&&ir4==0)
  {
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  }
}

void fwd()
{
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}

void rev()
{
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
}

void uturn()
{
  while(ir1==0&&ir2==1&&ir3==1&&ir4==0)
  {
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
}
}

void loop() {
  ir1=digitalRead(5);
  ir2=digitalRead(6);
  ir3=digitalRead(7);
  ir4=digitalRead(9);
  
  if((ir1==0&&ir2==1&&ir3==1&&ir4==0)||(ir1==1&&ir2==1&&ir3==0&&ir4==0)||(ir1==0&&ir2==0&&ir3==1&&ir4==1))  //NORMAL PATH
  {
    fwd();
  }

  if(ir1==0&&ir2==0&&ir3==0&&ir4==0) //DEAD END
  {
    uturn();
  }

  if(ir1==1&&ir2==1&&ir3==1&&ir4==1)
  {
    hright();
  }

  if(ir1==0&&ir2==0&&ir3==0&&ir4==1)
  {
    sright();
  }

  if(ir1==1&&ir2==0&&ir3==0&&ir4==0)
  {
    sleft();
  }

  if(ir1==0&&ir2==1&&ir3==1&&ir4==1)
  {
    fwd();
    delay(500);
    if((ir1==0&&ir2==1&&ir3==1&&ir4==0)||(ir1==1&&ir2==1&&ir3==0&&ir4==0)||(ir1==0&&ir2==0&&ir3==1&&ir4==1))  //NORMAL PATH
  {
    fwd();
  }
  else
  {
    rev();
    delay(600);
    hright();
  }
  }
  if(ir1==1&&ir2==1&&ir3==1&&ir4==0)
  {
    fwd();
    delay(500);
    if((ir1==0&&ir2==1&&ir3==1&&ir4==0)||(ir1==1&&ir2==1&&ir3==0&&ir4==0)||(ir1==0&&ir2==0&&ir3==1&&ir4==1)) //straight T
  {
    fwd();
  }
  else
  {
    rev();
    delay(600);
    hleft();
  }
  }
}



