// Arduino Car Parking System

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //Change the HEX address
#include <Servo.h> 

Servo myservo1;
int greenLedPin = 5; //Définir le numéro de la broche pour la LED verte
int IR1 = 2;
int IR2 = 4;

int Slot = 4;           //Enter Total number of parking Slots

int flag1 = 0;
int flag2 = 0;
char data;

void setup() {
   Serial.begin(9600); 
   pinMode(greenLedPin, OUTPUT); //Configurer la broche de la LED verte en tant que sortie
   lcd.begin(2,16);
  lcd.backlight();
   
 
 
pinMode(IR1, INPUT);
pinMode(IR2, INPUT);
  
myservo1.attach(3);
myservo1.write(100);

lcd.setCursor (0,0);
lcd.print("     ARDUINO    ");
lcd.setCursor (0,1);
lcd.print(" PARKING SYSTEM ");
delay (2000);
lcd.clear(); 
 
}

void loop(){
 
   if(Serial.available())
{
   /* lcd.clear();
    lcd.setCursor (15,1);
    lcd.print(data);
    lcd.setCursor (15,15);
     //data=Serial.read();
    lcd.print("Nombre  invites est");
    Serial.print(data);
    delay (3000);
    data=Serial.read();*/
    lcd.clear();
lcd.setCursor(0,0);
lcd.print("Nombre d'invites est");
while(!Serial.available()); // Attendre que des données soient reçues
char data = Serial.read();
if(data != '\0') { // Vérifier que la donnée est lisible
  lcd.setCursor(0,1);
  lcd.print(data);
}
delay(3000);

    if(data=='1') //si le caractère lu est égale à 1
    {
        lcd.clear();
        lcd.setCursor(15, 15);
        lcd.print(" ARDUINO  ");
    }
}

if(digitalRead (IR1) == LOW && flag1==0){
if(Slot>0){
  flag1=1;
if(flag2==0){myservo1.write(0);
digitalWrite(greenLedPin, HIGH); //Allumer la LED verte lorsque la voiture entre dans le parking
Slot = Slot-1;
Serial.write("w");}
}else{
lcd.setCursor (0,0);
lcd.print("    SORRY :(    ");  
lcd.setCursor (0,1);
lcd.print("  Parking Full  "); 
delay (3000);
lcd.clear(); 
}
}

if(digitalRead (IR2) == LOW && flag2==0){
  
  flag2=1;
if(flag1==0){myservo1.write(0); Slot = Slot+1;}
}

if(flag1==1 && flag2==1){
delay (1000);
myservo1.write(100);
flag1=0, flag2=0;
digitalWrite(greenLedPin, LOW); // Éteint la LED verte
}

lcd.setCursor (0,0);
lcd.print("    WELCOME!    ");
lcd.setCursor (0,1);
lcd.print("Slot Left: ");
lcd.print(Slot);
Serial.print("w");
    }
