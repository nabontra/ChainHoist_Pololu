int dir = 9;
int pwmh = 10;
int speedmotor = 0;
int accel = 5;
int upperlimit = 13;
int lowerlimit = 12;
int upperState = 0;
int lowerState = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(dir,OUTPUT); //dir
pinMode(pwmh,OUTPUT); //pwmh
pinMode(upperlimit,INPUT);
pinMode(lowerlimit,INPUT);
delay(3000);
  lowerState = digitalRead(lowerlimit);
  upperState = digitalRead(upperlimit);
digitalWrite(dir,LOW);  //lower motor
analogWrite(pwmh,255);
}

void loop() {
lowerState = digitalRead(lowerlimit);
  while((lowerState)==LOW)
   {
     digitalWrite(dir,LOW);
     analogWrite(pwmh,255);
     lowerState = digitalRead(lowerlimit);
     }
   
   analogWrite(pwmh,0);
   for (int x = 0; x<120; x++){
    delay(1000);  //dwell for 120s
   }
   
     digitalWrite(dir,HIGH); //switch direction to raise
     analogWrite(pwmh,255);  //move motor
     delay(5000);
   
  upperState = digitalRead(upperlimit);
  while ((upperState)==LOW)
   {
    digitalWrite(dir,HIGH);
     analogWrite(pwmh,255);
     upperState = digitalRead(upperlimit);
     
   }
   analogWrite(pwmh,0);
   for (int x = 0; x<120; x++){
    delay(1000);  //dwell for 120s
   }  //dwell for 120s
     digitalWrite(dir,LOW); //switch direction to raise
     analogWrite(pwmh,255);  //move motor
}
