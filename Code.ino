#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
Servo doorServo;

const int servoPin = 9;
const int redLed = 10;
const int greenLed = 11;
const int buzzer = 12;

const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] =
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};     
byte colPins[COLS] = {6, 7, 8};        

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "12345";
String input = "";

void showEnterPIN(){ //display
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Enter PIN");
    lcd.setCursor(5, 1);
    };
    
void accessGranted(){
              digitalWrite(greenLed, HIGH);
              tone(buzzer, 1000);
              delay(100);
              tone(buzzer, 1500);
              delay(100);
              noTone(buzzer);
              

              lcd.clear();
              lcd.setCursor(5,0);
              lcd.print("Access");
              lcd.setCursor(5,1);
              lcd.print("Granted");//door opens
              doorServo.write(90);      
              delay(5000);

              doorServo.write(0);     

              digitalWrite(greenLed, LOW);
              digitalWrite(buzzer, LOW);
              input = "";
      };

void accessDenied(){
      digitalWrite(redLed, HIGH);
      digitalWrite(buzzer, HIGH);
    
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("Incorrect");
      lcd.setCursor(6,1);
      lcd.print("Pin");//door opens
      doorServo.write(90);      
      delay(5000);

      digitalWrite(redLed, LOW);
      digitalWrite(buzzer, LOW);
      input = "";
        };
        



void setup(){ 
    pinMode(greenLed, OUTPUT);
    pinMode(redLed, OUTPUT);
    pinMode(buzzer, OUTPUT);
  
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);

    doorServo.attach(servoPin);
    doorServo.write(0);     

    lcd.begin(16,2);

    showEnterPIN();

    Serial.begin(9600);
}

void loop(){
    char key = keypad.getKey();
    if(key == '*') {
          if(input.length() > 0){
            input.remove(input.length() - 1);

            showEnterPIN();
          for(int i = 0; i < input.length(); i++){
            lcd.print("*");
            }
          }
        }

     else if (key){
          input += key;
          lcd.print("*");
          }

          if(input.length() == 5){
              if (input == password){
                
              accessGranted();
              showEnterPIN();
              }
      else{
          accessDenied();
          showEnterPIN();
    }
}

}
