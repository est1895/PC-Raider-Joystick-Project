// Pin A2 = X Axis
// Pin A3 = Y Axis
// Pin 16 = Button 1
// Pin 10 = Button 2
//
//--------------------------------------------------------------

#include "C:\Users\Owner\Documents\Arduino\libraries\PC_Raider\Joystick\Joystick.h"

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_JOYSTICK, 2, 0, true, true, false, false, false, false, false, false, false, false, false);

void setup() {    

    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(16, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);

    Joystick.begin();
}

void loop() {

    // X-Axis
    int xAxis = analogRead(A2);
    Joystick.setXAxis(xAxis);

    // Y-Axis
    int yAxis = analogRead(A3);
    Joystick.setYAxis(yAxis);

// Button 1
    int button1State = !digitalRead(16);
    if (button1State == 1)
    {         
       Joystick.pressButton(0);
    }
    else
    {  
      Joystick.releaseButton(0);
    }

    // Button 2
    int button2State = !digitalRead(10);
    if (button2State == 1)
    {         
       Joystick.pressButton(1);
    }
    else
    {  
      Joystick.releaseButton(1);
    }

    delay(50);
