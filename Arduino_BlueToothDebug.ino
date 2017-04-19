#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    lcd.init();
    lcd.backlight();
    Serial.begin(9600);

    lcd.setCursor(0,0);
    lcd.print("Message :");
}

void loop()
{
    getMessage();
}

void getMessage(){
    String message = "";

    while( Serial.available() > 0 ){
      clearALine(1);// clear the contents of the last transmission that on the screen
       message += (char)Serial.read();  
    }
    lcd.setCursor(0,1);
    lcd.print(message);

    Serial.flush();// clear the cache of bluetooth
}

void clearALine(int lineNumber){
 lcd.setCursor(0,lineNumber);
 lcd.print("                ");// sixteen blank
}
