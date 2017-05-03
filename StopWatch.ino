
int startResetBTN = 4;
int elapsedButton = 3;
int redLed = 2;
int greenLed = 8;
int buttonState = 0;
int lastButtonState = 10;
bool isRunning = false;
unsigned long start,finish,elapsed;
void setup() {
  // put your setup code here, to run once:
  pinMode(greenLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  pinMode(startResetBTN,INPUT);
  pinMode(elapsedButton,INPUT);
  digitalWrite(greenLed,HIGH);
  Serial.begin(9600);
  Serial.println("Press the first button once to start, a second time to reset. \nThe second button will display the elapsed time if the stopwatch is not running.");
}

void loop() {
  // put your main code here, to run repeatedly:
 buttonState = digitalRead(startResetBTN);
 if(buttonState != lastButtonState){
  lastButtonState = buttonState;
   if(buttonState == HIGH){
    if(isRunning == false){
      isRunning = true;
      switchLed(HIGH,LOW);
      start = millis();
      Serial.println("Started");
    }else{
      switchLed(LOW,HIGH);
      isRunning = false;
      finish=millis();
      displayTime();
    }
   }
 }

 if(digitalRead(3) == HIGH && isRunning == false){
  displayTime();
  delay(1000);
 }
}

void displayTime(){
  int h,m,s,ms;
  unsigned long over;
  elapsed = finish-start;

  h = int(elapsed/3600000);
  over = elapsed%3600000;
  m = int(over/60000);
  over = over%60000;
  s = int(over/1000);
  ms = over%1000;

  Serial.println(String(h)+":"+String(m)+":"+String(s)+":"+String(ms));
}
void switchLed(int red,int green){
    digitalWrite(redLed,red);
    digitalWrite(greenLed,green);
}

