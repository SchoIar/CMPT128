// USE ARDUINO SOFTWARE TO RUN THIS FILE

#include <Adafruit_Keypad.h>
#include <Adafruit_Keypad_Ringbuffer.h>

#include <LiquidCrystal.h> //include LCD library (standard library)
#include <Keypad.h> //include keypad library - first you must install library (https://playground.arduino.cc/Code/Keypad/)

#define redLED 10 //define the LED pins
#define greenLED 11

/* const */ char* password = "1234"; //create a password - harcoded for now, warning will appear in compiler, to fix this remove the comment and make char a const
int pozisyon = 0; //keypad position

const byte rows = 4; //number of the keypad's rows and columns
const byte cols = 4;

char keyMap [rows] [cols] = { //define the symbols on the buttons of the keypad

  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins [rows] = {1, 2, 3, 4}; //pins of the keypad
byte colPins [cols] = {5, 6, 7, 8};

Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, rows, cols);

LiquidCrystal lcd (A0, A1, A2, A3, A4, A5); // pins of the LCD. (RS, E, D4, D5, D6, D7)

void setup(){

  lcd.begin(16, 2);
  pinMode(redLED, OUTPUT);  //set the LED as an output
  pinMode(greenLED, OUTPUT);
  setLocked (true); //state of the password
}

void loop(){

  char whichKey = myKeypad.getKey(); //define which key is pressed with getKey

  lcd.setCursor(0, 0);
  lcd.print("    Welcome");
  lcd.setCursor(0, 1);
  lcd.print(" Enter Password");

  if(whichKey == '*' || whichKey == '#'){

    pozisyon=0;
    setLocked (true);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Invalid Key!");
    delay(1000);
    lcd.clear();
  }
  if(whichKey == password [pozisyon]){

    pozisyon ++;
  }
  if(pozisyon == 4){
    setLocked (false);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*** Verified ***");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Arduino");
    lcd.setCursor(0, 1);
    lcd.print("Testing 1");
    delay(7000);
    lcd.clear();
  }
  delay(100);
}

void setLocked(int locked){
  if(locked){
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    }
    else{
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
    }
  }



/* =============================== IR SENSOR ===============================

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

int irPin = 2;  // IR pin
int LED = 3; // LED pin
int buzzerPin = 4;  //Buzzer pin

int sensorOut = LOW;  // Initialize

void setup () {

// set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);

  pinMode(irPin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

sensorOut = digitalRead(irPin);

  if (sensorOut == LOW)

  {

    Serial.println("No Obstacle!");
  lcd.clear();
  lcd.print("No Obstacle!");

    digitalWrite(LED, LOW);
    digitalWrite(buzzerPin, LOW);

  }

  else

  {

    Serial.println("Somebody there!");
  lcd.clear();
  lcd.print("Warning!");
  lcd.setCursor(0,1);
  lcd.print("Somebody there!");
  
    digitalWrite(LED, HIGH);
    digitalWrite(buzzerPin, HIGH);

  }

  delay(200);
}
*/
