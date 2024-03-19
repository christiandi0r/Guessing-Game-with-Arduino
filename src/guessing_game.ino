const int RLED = 13; //Red LED on Pin 13
const int BLED = 12; //Blue LED on Pin 12
const int GLED = 11; //Green LED on Pin 11
const int BUTTON1 = 4; //The Button is connected to pin 4
const int BUTTON2 = 3; //The Button is connected to pin 3
const int BUTTON3 = 2; //The Button is connected to pin 2

int randomChoice()
{
  int computerChoice;
 
  randomSeed(analogRead(0));
  computerChoice = random(1, 4);

  return computerChoice;
}

void setup()
{
  Serial.begin(9600);
  
  pinMode (GLED, OUTPUT); //Set Green LED as Output
  pinMode (RLED, OUTPUT); //Set Red LED as Output
  pinMode (BUTTON1, INPUT); //Set button as input
  pinMode (BUTTON2, INPUT); //Set button as input
  pinMode (BUTTON3, INPUT); //Set button as input
}

void setMode(int trueNum)
{
  //Button 1
  if (digitalRead(BUTTON1) == HIGH && digitalRead(BUTTON1) == trueNum)
  {
    digitalWrite(GLED, HIGH);
    digitalWrite(RLED, LOW);
  }
  
  else if (digitalRead(BUTTON1) == HIGH && digitalRead(BUTTON1) != trueNum)
  {
    digitalWrite(GLED, LOW);
    digitalWrite(RLED, HIGH);
  }

  //Button 2
  else if (digitalRead(BUTTON2) == HIGH && digitalRead(BUTTON2) == trueNum)
  {
    digitalWrite(GLED, HIGH);
    digitalWrite(RLED, LOW);
  }
  
  else if (digitalRead(BUTTON2) == HIGH && digitalRead(BUTTON2) != trueNum)
  {
    digitalWrite(GLED, LOW);
    digitalWrite(RLED, HIGH);
  }
  
  //Button 3
  else if (digitalRead(BUTTON3) == HIGH && digitalRead(BUTTON3) == trueNum)
  {
    digitalWrite(GLED, HIGH);
    digitalWrite(RLED, LOW);
  }
  
  else if (digitalRead(BUTTON3) == HIGH && digitalRead(BUTTON3) != trueNum)
  {
    digitalWrite(GLED, LOW);
    digitalWrite(RLED, HIGH);
  }

  //OFF (mode = 0)
  else  
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
}

void loop()
{
  delay(200);
  randomChoice();
  setMode(randomChoice());
  Serial.println(randomChoice());
}




