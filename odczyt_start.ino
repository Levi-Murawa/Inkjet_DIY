\\ A0 - Błękitny, wewnętrzny
\\ A1 - Zielony, zewnętrzny
\\ Błękitny do białego drukarki
\\ Fioletowy do czarnego drukarki

int in1 = 0;
int lastIn = 0;
int count = 0;
int stan = 0;
int stanMoj = 0;
char sensor[4] = {0, 1, 3, 2}; 

void setup() 
{
  Serial.begin(9600); 
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(10, LOW);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, OUTPUT);
}

void loop() 
{
  in1 = digitalRead(A0)|digitalRead(A1)<<1;

  if(in1 == 1 || in1 == 2)
  {
    stanMoj = in1;
    count = 0;
  }
  else
  {
    count++;
    if(count > 30)
    {
      stanMoj = in1;
    }
  }
  if(stanMoj == 2)
  {
    if(count > 150)
    {
      digitalWrite(2, HIGH); //stan na koniec
    }
    else
    {
      digitalWrite(2, LOW); //stan na poczatek
    }
    Serial.println("wysoko");
  }
  else
  {
    if(count > 150)
    {
      digitalWrite(2, LOW);
    }
    else
    {
      digitalWrite(2, HIGH);
    }
    
    Serial.println("nisko");
  }
  //Serial.print(stanMoj);
  Serial.print("\t");
  //Serial.println(in1);
  /*if(in1 != lastIn)
  {
    Serial.print(lastIn);
    Serial.print("---");
    Serial.println(count);
    count = 0;
    lastIn = in1;
  }
  else
  {
    count++;
  }
  if(in1 == 1 || in1 == 2)
  {
    stanMoj = in1;
  }
  if(count > 200)
  {
    stanMoj = in1;
  }
  Serial.println(stanMoj); */
  //{
  //  stan++;
  //}
  //else if(in1 == 1)
  //{
  //  stan--;
  //}
  //stan = stan & 3;
  //digitalWrite(1, sensor[stan] & 1);
  //digitalWrite(2, sensor[stan] & 2);
  //Serial.println(in1);
  //in2 = digitalRead(A1);
  //Serial.print(im1);
  //Serial.print("\t");
  //Serial.print(in2);
  //Serial.println("");
  delay(1);
}
