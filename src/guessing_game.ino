const int RLED = 6; //Red LED on Pin 6
const int BLED = 11; //Blue LED on Pin 11
const int GLED = 5; //Green LED on Pin 5
const int speakerPin = 7;
const int BUTTON1 = 4; //The Button is connected to pin 4
const int BUTTON2 = 3; //The Button is connected to pin 3
const int BUTTON3 = 2; //The Button is connected to pin 2
const int MIN_LIGHT = 40; //Minimum expected light value
const int MAX_LIGHT = 200; //Maximum Expected Light value
const int LIGHT = 0; //Lght Sensor on analog pin A0
int val = 0; //variable to hold the analog reading
int numOfRights = 0;
int numOfWrongs = 0;
bool end = false;

void setup()
{
  Serial.begin(9600);
  pinMode(GLED, OUTPUT); //Set Green LED as Output
  pinMode(RLED, OUTPUT); //Set Red LED as Output
  pinMode(BLED, OUTPUT); //Set Blue LED as Output
  pinMode(speakerPin, OUTPUT); //Set speaker as Output
  pinMode(BUTTON1, INPUT); //Set button as input
  pinMode(BUTTON2, INPUT); //Set button as input
  pinMode(BUTTON3, INPUT); //Set button as input
  
}

int brightness()
{
  val = analogRead(LIGHT); //Read the light sensor
  val = map(val, MIN_LIGHT, MAX_LIGHT, 0, 255); //Map the light reading
  val = constrain(val, 0, 255); //Constrain light value

  return val;
}

int randomChoice()
{
  int computerChoice;

  randomSeed(analogRead(0));
  computerChoice = random(1, 4);

  return computerChoice;
}

void playSound(int button, int trueNum)
{
  if (digitalRead(button) == trueNum)
  {
    tone(speakerPin, 1000, 500);
  }

  else
  {
    tone (speakerPin, 200, 500);
  }
}

void setMode(int trueNum)
{
  //Button 1
  if (digitalRead(BUTTON1) == HIGH && digitalRead(BUTTON1) == trueNum)
  {
    analogWrite(GLED, brightness());
    playSound(BUTTON1, trueNum);
    numOfRights++;
  }

  else if (digitalRead(BUTTON1) == HIGH && digitalRead(BUTTON1) != trueNum)
  {
    analogWrite(RLED, brightness());
    playSound(BUTTON1, trueNum);
    numOfWrongs++;
  }

  //Button 2
  else if (digitalRead(BUTTON2) == HIGH && digitalRead(BUTTON2) == trueNum)
  {
    analogWrite(GLED, brightness());
    playSound(BUTTON2, trueNum);
    numOfRights++;
  }

  else if (digitalRead(BUTTON2) == HIGH && digitalRead(BUTTON2) != trueNum)
  {
    analogWrite(RLED, brightness());
    playSound(BUTTON2,trueNum);
    numOfWrongs++;
  }

  //Button 3
  else if (digitalRead(BUTTON3) == HIGH && digitalRead(BUTTON3) == trueNum)
  {
    analogWrite(GLED, brightness());
    playSound(BUTTON3, trueNum);
    numOfRights++;
  }
  
  else if (digitalRead(BUTTON3) == HIGH && digitalRead(BUTTON3) != trueNum)
  {
    analogWrite(RLED, brightness());
    playSound(BUTTON3,trueNum);
    numOfWrongs++;
  }
  
  //OFF (mode = 0)
  else
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }

    if (numOfWrongs >= 5)
    {
      tone(speakerPin, 1000, 500);
      delay(500);
      tone(speakerPin, 500, 500);
      delay(500);
      tone(speakerPin, 1000, 500);
      delay(500);
      tone(speakerPin, 500, 500);

      end = true;
    }

    else if (numOfRights >= 5)
    {
      tone(speakerPin, 2000, 500);
      delay(500);
      tone(speakerPin, 1000, 500);
      delay(500);
      tone(speakerPin, 2000, 500);
      delay(500);
      tone(speakerPin, 1000, 500);

      end = true;
    }
}

void loop()
{
  delay(140);
  randomChoice();
  setMode(randomChoice());

  if (end == true)
  {
    numOfWrongs = 0;
    numOfRights = 0;

    end = false;
  }

  //Serial.println(val);
  //Serial.println(numOfWrongs);
  //Serial.println(numOfRights);
  //Serial.println(randomChoice());
}
