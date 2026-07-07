# Arduino-based-Smart-Password-Look-System

An Arduino-based smart door lock that uses a 4×3 keypad and a 16×2 LCD to authenticate users using a five-digit password.

## Features

- 5-digit password authentication
- Password hidden with '*'
- LCD user interface
- Servo motor door lock
- Green LED for successful access
- Red LED for incorrect password
- Backspace function using '*'
- Automatic door relocking
- Audible feedback using speaker

## Components Used

- Arduino Uno
- 4×3 Keypad
- 16×2 LCD
- SG90 Servo Motor
- Red LED
- Green LED
- Active Speaker
- Jumper Wires

## Software Used

- Arduino IDE
- Proteus 8 Professional

## How It Works

1. User enters a five-digit PIN.
2. Characters are displayed as '*'.
3. If the password is correct:
   - Green LED turns on.
   - Servo unlocks the door.
   - LCD displays "Access Granted".
4. If the password is incorrect:
   - Red LED turns on.
   - LCD displays "Incorrect PIN".
5. The system automatically returns to the PIN entry screen.

## Future Improvements

- RFID authentication
- Fingerprint sensor
- Facerecognition feature
- EEPROM password storage
- Three-attempt lockout
- Mobile application control

## Author

**Amba Etta**
Computer Engineering Student
| Embedded Systems Engineer
