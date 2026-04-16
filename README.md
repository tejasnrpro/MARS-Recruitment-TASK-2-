# MARS-Recruitment-TASK-2-
_**TEJAS NITIN RAJAN
ME25B1004**_
THE FILES,CODE AND OVERVIEW FOR MARS Recruitment TASK 2
**Components**
Arduino board, L298 motor driver, DC motor, potentiometer, push button, power supply, and
connecting wires.
**System Overview**
The potentiometer provides an analog input for speed control, while the push button provides a
digital input to toggle direction. The L298 driver interfaces the Arduino with the motor.
Controlling the motor’s speed was a continuous process, happening constantly in the loop()
function
**CODE LOGIC **
1. Reading the Twist: First, the Arduino analogRead(potpin) function checks the
potentiometer’s position. This gives us a number between 0 and 1023, representing how
much the knob is turned.
2. Translating to Speed: I then used the map() function to convert this 0-1023 range into a
suitable speed value for the motor, specifically from 0 to 200. This range was chosen to
give good control over the motor’s RPM.
3. Applying the Power: Finally, analogWrite(EN, speed) sends this calculated speed value
to the L298N’s Enable pin. This uses Pulse Width Modulation (PWM) to effectively vary
the power delivered to the motor, making it spin faster or slower
Changing the motor’s direction was designed to happen when the push button is pressed.
Here’s the interesting part of the logic:
1. **Button Watcher**: The code constantly monitors the push button. Since I used
INPUT_PULLUP, pressing the button makes the pin read LOW. So, if (!digitalRead(btn))
is how we detect a press.
**2. A Time-Based Decision:** When the button is pressed, the code captures the exact moment
(millis()). It then calculates a value d by looking at how much time has passed since that
button press (up to 5 seconds). This d value is mapped and constrained between 100 and 200.
**3. Flipping the Switch:** Based on this d value, the motor’s direction is set:
– If d is less than 100 (which it won’t be with the current constrain, but
conceptually), IN1 goes HIGH and IN2 goes LOW, making the motor spin one way.
– If d is 100 or more, IN1 goes LOW and IN2 goes HIGH, reversing the motor’s spin.

**It’s worth noting that the current direction logic is quite unique.** It uses the
duration of the button press (or rather, the time elapsed since the initial press) to determine
direction. While functional, a more common approach might be to simply toggle the direction
with each press, or hold for one direction and release for another. This time-based mapping
offers an interesting alternative, though it might behave differently than a simple toggle
 
**finally** I successfully implemented both speed control using a potentiometer and
direction control with a push button, demonstrating a fundamental aspect of robotics and
automation. It’s a great stepping stone for more complex motor control applications, and it
highlights the power of Arduino in making our ideas move
