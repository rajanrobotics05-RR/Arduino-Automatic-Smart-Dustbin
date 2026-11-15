
/*
  Project 04: Automatic Smart Dustbin
  Controller : Arduino Uno
  Sensor     : HC-SR04 Ultrasonic Sensor
  Actuator   : SG90 Servo Motor

  Developed by: Rajan Robotics
  Vision to Reality
*/

#include <Servo.h>

// Pin definitions
#define TRIG_PIN 9
#define ECHO_PIN 10
#define SERVO_PIN 6

// Settings
#define OPEN_DISTANCE 20
#define OPEN_ANGLE 90
#define CLOSE_ANGLE 0

#define LID_OPEN_TIME 3000

Servo dustbinServo;

float distance;
unsigned long duration;

bool lidOpen = false;
unsigned long lidOpenTime = 0;

// Measure distance using HC-SR04
float measureDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0)
  {
    return -1;
  }

  distance = (duration * 0.0343) / 2.0;

  return distance;
}

void openLid()
{
  dustbinServo.write(OPEN_ANGLE);
  lidOpen = true;
  lidOpenTime = millis();

  Serial.println("Dustbin Lid OPEN");
}

void closeLid()
{
  dustbinServo.write(CLOSE_ANGLE);
  lidOpen = false;

  Serial.println("Dustbin Lid CLOSED");
}

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dustbinServo.attach(SERVO_PIN);
  dustbinServo.write(CLOSE_ANGLE);

  digitalWrite(TRIG_PIN, LOW);

  Serial.println("RAJAN ROBOTICS");
  Serial.println("Automatic Smart Dustbin");
  Serial.println("------------------------");
}

void loop()
{
  float currentDistance = measureDistance();

  Serial.print("Distance: ");

  if (currentDistance < 0)
  {
    Serial.println("No measurement");
  }
  else
  {
    Serial.print(currentDistance);
    Serial.println(" cm");
  }

  // Detect hand near dustbin
  if (currentDistance > 0 && currentDistance <= OPEN_DISTANCE)
  {
    if (!lidOpen)
    {
      openLid();
    }

    // Keep lid open while hand remains detected
    lidOpenTime = millis();
  }

  // Close lid after hand moves away
  if (lidOpen && millis() - lidOpenTime >= LID_OPEN_TIME)
  {
    closeLid();
  }

  delay(100);
}
