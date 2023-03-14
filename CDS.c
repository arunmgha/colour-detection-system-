

#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows

int lcdColumns = 16;

int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows); // change your I2C ADDRESS HERE EXAMPLE 0x3F

const int s0 = D3;  

const int s1 = D4;  

const int s2 = D5;  

const int s3 = D6;  

const int out = D7;   

int red = 0;  

int green = 0;  

int blue = 0; 


int redcolor= 0;

int greencolor= 0;

int bluecolor= 0;

int yellowcolor= 0;


int color= 0;



void setup()   

{  

  Serial.begin(9600); 

  lcd.init();

  lcd.backlight();

  lcd.setCursor(0, 0);

    lcd.print("ESP Color Finder");

  pinMode(s0, OUTPUT);  

  pinMode(s1, OUTPUT);  

  pinMode(s2, OUTPUT);  

  pinMode(s3, OUTPUT);  

  pinMode(out, INPUT);  

  digitalWrite(s0, HIGH);  

  digitalWrite(s1, HIGH);  


}  

void loop() 

{  


  digitalWrite(s2, LOW);  

  digitalWrite(s3, LOW);  

  //count OUT, pRed, RED  

  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  

  digitalWrite(s3, HIGH);  

  //count OUT, pBLUE, BLUE  

  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  

  digitalWrite(s2, HIGH);  

  //count OUT, pGreen, GREEN  

  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 

  Serial.print("R Intensity:");  

  Serial.print(red, DEC);  

  Serial.print(" G Intensity: ");  

  Serial.print(green, DEC);  

  Serial.print(" B Intensity : ");  

  Serial.print(blue, DEC);  

  if(red<18 & red>6 & green<32 & green>26 & blue<29 & blue>20){

    delay(250);

    redcolor++;

    Serial.print("Red");

    lcd.setCursor(0, 1);

    lcd.print("     Red       ");

    delay(2000);

    lcd.clear();


  }

  if(red<30 & red>26 & green<40 & green>36 & blue<30 &blue>26){

    delay(250);

    bluecolor++;

    Serial.print("Blue");

    lcd.setCursor(0, 1);

    lcd.print("    Blue      ");

    delay(2000);

    lcd.clear();


  }

  if(red<24 & red>20 & green<24 & green>20 & blue<22 & blue>18){

    delay(250);

    greencolor++;

    Serial.print("Green");

    lcd.setCursor(0, 1);

    lcd.print("     Green      ");

    delay(2000);

    lcd.clear();


  }

  if(red<16 & red>12 & green<24 & green>20 & blue<26 & blue>22){

    delay(250);

    yellowcolor++;

    Serial.print("Yellow");

    lcd.setCursor(0, 1);

    lcd.print("     Yellow     ");

    delay(2000);

    lcd.clear();


  } 

   

   Serial.println();  

 // delay(1000); 

} 

