// include liberaries;
#include <LiquidCrystal.h> #include <Keypad.h> #include <Servo.h>
// Keypad
const
byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
// define the servo
Servo myServo;
//define the cymbols on the buttons of the keypads
char keymap[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'}, {'7','8', '9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {4, 5, 6, 7}; //connect to the row pinouts of the keypad byte colPins[COLS] = {0, 1, 2, 3};
//connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad myKeypad = Keypad( makeKeymap(keymap), rowPins, colPins, ROWS, COLS);
// create and initialize the LCD object LiquidCrystal lcd(8, 9, 10, 11, 12, 13); char password[] = {'4', '5', 'B'}; boolean flag;
int pos=0;
boolean reedPin = 7; //for the servo void setup()
{ myServo.attach(A0);
lcd.begin(16, 2);
lcd.cursor(); pinMode(reedPin,INPUT); // switch
}
void loop()
{flag = true; lcd.clear();
lcd.print("Password:");
for(int i = 0; i < sizeof(password); i++)
{ char key = myKeypad.waitForKey(); if(key != password[i])
{
flag = true; }
lcd.print("*");
}
lcd.setCursor(0 ,1);
if (digitalRead(7) == LOW) { int count=0;
lcd.print("Safe is Unlocked");
myServo.write(270) ; delay(10000);
myServo.write(90); 
} 
delay(3000);
}
