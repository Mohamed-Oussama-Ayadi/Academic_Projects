#include <DHT.h>
# include <LiquidCrystal_I2C.h>
#include "pitches.h"
LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(2,DHT11);
float temp_dht=0, humidity=0;

char BYTE;
String BYTE2="";
int b=1;
int l=1;
int v=1;

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


void play_melody()
{
   // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(5, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(5);
  }
}

void setup() {
  delay(2000);
  pinMode(5, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(5, 0);
  digitalWrite(8, 0);


  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0); //lcd.setCursor(colonne,ligne); pour positionner le curseur

  lcd.print("WELCOME!");

//lcd.blink(); // turn on the blinking cursor
Serial.begin(9600);

}

void loop() {

 BYTE=Serial.read();
 if(BYTE>='.' && BYTE<='9')
 {
 BYTE2+=BYTE;
 }


 if(BYTE=='b')
 b=0;
 else
 if(BYTE=='e')
      b=1;
      else 
      if(BYTE=='o')
      l=0;
      else
      if(BYTE=='n')
      l=1;
      else
      if(BYTE=='v')
      v=0;
      else 
      if(BYTE=='a')
      v=1;
      else
      if(BYTE=='i')
      digitalWrite(10,HIGH);
      else 
      if(BYTE=='d')
      digitalWrite(10,LOW);
      if(BYTE=='w')
      {
        play_melody();
        b=0;
      }
      else 
      if(BYTE=='k')
      digitalWrite(5,LOW);
  
 
  temp_dht = dht.readTemperature();
  humidity = dht.readHumidity();
  lcd.setCursor(0,0); //lcd.setCursor(colonne,ligne); pour positionner le curseur
  lcd.print("T:"); //pour afficher une valeur ou une chaîne de caractère.
  lcd.setCursor(2,0);
  lcd.print(temp_dht);
  lcd.print(char(223));//°symbol
  lcd.print("C/");
  if(BYTE2.length()>=4)
  {
  lcd.setCursor(11,0);
  lcd.print(BYTE2);
  BYTE2="";
  }

  lcd.setCursor(0,1); //lcd.setCursor(colonne,ligne); pour positionner le curseur
  lcd.print("H:"); //pour afficher une valeur ou une chaîne de caractère.
  lcd.setCursor(2,1);
  lcd.print(humidity);
  lcd.print("%");

if(temp_dht >= 28)
  {
    digitalWrite(8, LOW); //GREEN LED
    if(l==1)
    {
      digitalWrite(10, HIGH); // Led oranger
      Serial.write('r');
      Serial.write('1');
      Serial.write(' ');
    }
    else 
      if(l==0)
      {
        digitalWrite(10, LOW);
        Serial.write('r');
        Serial.write('0');
        Serial.write(' ');
      }
    
    if(b==1)
    {
      play_melody();
      b=0;
      Serial.write('b');
      Serial.write('1');
      Serial.write(' ');
    }
    else 
      if(b==0)
      {
        digitalWrite(5, LOW);
        Serial.write('b');
        Serial.write('0');
        Serial.write(' ');
      }
    
    Serial.write('v');
    Serial.write('0');
    Serial.write(' ');
 }
  else 
  {
    digitalWrite(10, LOW); //Orange LEd
    if(v==1)
    {
    digitalWrite(8, HIGH); //GREEN LED
    Serial.write('v');
    Serial.write('1');
    Serial.write(' ');
    }
    else
    if(v==0)
    {
    digitalWrite(8, LOW);
    Serial.write('v');
    Serial.write('0');
    Serial.write(' ');
    }
    digitalWrite(5, LOW); //BUZZER
    Serial.write('r');
    Serial.write('0');
    Serial.write(' ');
    Serial.write('b');
    Serial.write('0');
    Serial.write(' ');
 }

  Serial.print('t');
  Serial.print(temp_dht);
  Serial.write(' ');
  Serial.print('h');
  Serial.print(humidity);

  Serial.write(' ');
  Serial.print('.');


  }
