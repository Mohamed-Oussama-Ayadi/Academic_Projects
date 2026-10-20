#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h> // pour télécharger la librairie: croquis - include library - manage libraries - LiquidCrystal_I2C.h de Frank de Brabander
LiquidCrystal_I2C lcd(0x27,16,2);
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
  const int REDLED= 2;
 int GREENLED = 3;
 int BUZZER = 7;
 


 
void setup() //fonction d'initialisation de la carte
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
 
 


  //LCD
lcd.init(); //initialisation de l'écran LCD
lcd.backlight();
lcd.setCursor(4,0);
lcd.print("Projet");
lcd.setCursor(2,1);
lcd.print("SMART RDI ");
delay(3000);
lcd.setCursor(1,0);
lcd.print("Projet SMARTRDI");
lcd.setCursor(1,1);
lcd.print("scan your card");


}
void loop()
{//inpout

       String x =Serial.readString();
    if(x == "x")
    {
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("WELCOME");
        
        //digitalWrite(GREENLED,HIGH);
         // digitalWrite(BUZZER,LOW);
           
    delay(3000);
      lcd.clear();
      lcd.setCursor(4,0);
lcd.print("Projet");
lcd.setCursor(2,1);
lcd.print("SMART RDI ");
delay(3000);
lcd.setCursor(1,0);
lcd.print("Projet SMARTRDI");
lcd.setCursor(1,1);
lcd.print("scan your card");
    delay(3000);
    }
    if(x == "y")
    {
      lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("GOODBYE");
       
        //digitalWrite(GREENLED,HIGH);
         // digitalWrite(BUZZER,LOW);
                  delay(4000);
         lcd.clear();
    }
     if(x == "a")
    {
      lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("GREEN LED ON");
        digitalWrite(REDLED,LOW);
        digitalWrite(GREENLED,HIGH);
         // digitalWrite(BUZZER,LOW);
         delay(4000);
         digitalWrite(REDLED,LOW);
        digitalWrite(GREENLED,LOW);

    }
     if(x == "b")
    {
      lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("RED LED ON");
                digitalWrite(GREENLED,LOW);

        digitalWrite(REDLED,HIGH);
         // digitalWrite(BUZZER,LOW);
                  delay(4000);
         digitalWrite(REDLED,LOW);
        digitalWrite(GREENLED,LOW);
    }
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
 
  String content= "";
  byte letter;
  //Creation UID
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));

  }
  content.toUpperCase();//
  //output
  if (content.substring(1) == "03 98 7E 92")
  {
    lcd.clear();
     String message=Serial.readString();
    lcd.setCursor(0,0);
    //lcd.print("acces");
     //lcd.setCursor(0,1);
    //lcd.print("Authorise");
    digitalWrite(GREENLED,HIGH);
              digitalWrite(BUZZER,LOW);

    delay(3000);
    digitalWrite(GREENLED,LOW);
    digitalWrite(REDLED,LOW);

    //delay(3000);
     
    //lcd.clear();
    //lcd.setCursor(0,0);
    lcd.print(message);
    delay(3000);
      lcd.clear();
      lcd.setCursor(4,0);
lcd.print("Projet");
lcd.setCursor(2,1);
lcd.print("SMART RDI ");
delay(3000);
lcd.setCursor(1,0);
lcd.print("Projet SMARTRDI");
lcd.setCursor(1,1);
lcd.print("scan your card");


     
  
  }
 
  else if (content.substring(1) == "A3 3A 9F A7")
  {
    
     String message=Serial.readString();
     lcd.clear();
    lcd.setCursor(0,0);
    //lcd.print("acces");
     //lcd.setCursor(0,1);
    //lcd.print("Authorise");
    digitalWrite(GREENLED,HIGH);
          digitalWrite(BUZZER,LOW);

    delay(3000);
    digitalWrite(GREENLED,LOW);
    digitalWrite(REDLED,LOW);

     //delay(3000);
    //lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(message);
     delay(3000);
      lcd.clear();
      lcd.setCursor(4,0);
lcd.print("Projet");
lcd.setCursor(2,1);
lcd.print("SMART RDI ");
delay(3000);
lcd.setCursor(1,0);
lcd.print("Projet SMARTRDI");
lcd.setCursor(1,1);
lcd.print("scan your card");

    
  }
 
 else   {
   String message=Serial.readString();
   digitalWrite(REDLED,HIGH);
      digitalWrite(BUZZER,HIGH);

    delay(3000);
    digitalWrite(GREENLED,LOW);
    digitalWrite(REDLED,LOW);

    
    
    lcd.clear();
    lcd.setCursor(0,0);  
    //lcd.print("access denied");
    //delay(3000);
    //lcd.clear();
   
    lcd.print(message);
    delay(4000);
      lcd.clear();
      lcd.setCursor(4,0);
lcd.print("Projet");
lcd.setCursor(2,1);
lcd.print("SMART RDI ");
delay(3000);
lcd.setCursor(1,0);
lcd.print("Projet SMARTRDI");
lcd.setCursor(1,1);
lcd.print("scan your card");

  }

  delay(4000);
}
