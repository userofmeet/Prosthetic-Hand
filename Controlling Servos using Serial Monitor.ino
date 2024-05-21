#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

Servo* servos[] = {&servo1, &servo2, &servo3, &servo4, &servo5};

const int servoPins[] = {2, 3, 4, 5, 6};

void setup() {
  for (int i = 0; i < 5; i++) 
  {
    servos[i]->attach(servoPins[i]);
  }
  Serial.begin(9600);
  Serial.println("Enter servo number (1-5) and angle (0-180):");
}

void loop() {
  if (Serial.available()) 
  {
    String input = Serial.readStringUntil('\n');
    int spaceIndex = input.indexOf(' ');
    if (spaceIndex != -1) {
      String servoNumberStr = input.substring(0, spaceIndex);
      String angleStr = input.substring(spaceIndex + 1);
  
      int servoNumber = servoNumberStr.toInt();
      int angle = angleStr.toInt();
      
      if (servoNumber >= 1 && servoNumber <= 5 && angle >= 0 && angle <= 180) {
        servos[servoNumber - 1]->write(angle);
        Serial.print("Servo ");
        Serial.print(servoNumber);
        Serial.print(" set to ");
        Serial.print(angle);
        Serial.println(" degrees");
      } else {
        Serial.println("Invalid input. Enter servo number (1-5) and angle (0-180).");
      }
    } else {
      Serial.println("Invalid format. Use: <servo number> <angle>");
    }
  }
}
