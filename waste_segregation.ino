#include <Servo.h>

Servo servo1;
const int trigPin = 12;
const int echoPin = 11;
const int potPin = A0;

long duration;
int distance = 0;
int soil = 0;
int fsoil = 0;

int maxDryValue = 1;     // Humidity threshold (%) to classify as wet waste
int Ultra_Distance = 15; // Trigger distance threshold in cm

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.attach(8);
  servo1.write(90); // Start in neutral position
  Serial.println("Soil Sensor + Ultrasonic + Servo System Ready");
}

void loop() {
  distance = 0; // Reset accumulator before reading

  // Take 2 ultrasonic readings and average them
  for (int i = 0; i < 2; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    distance += (duration * 0.034 / 2);
    delay(10);
  }
  distance = distance / 2;

  // Check if an object is within detection distance
  if (distance < Ultra_Distance && distance > 1) {
    delay(1000);
    fsoil = 0; // Reset moisture accumulator before reading

    // Take 3 soil moisture readings and average them
    for (int i = 0; i < 3; i++) {
      soil = analogRead(potPin);
      soil = constrain(soil, 485, 1023);
      fsoil += map(soil, 485, 1023, 100, 0);
      delay(75);
    }
    fsoil = fsoil / 3;

    Serial.print("Humidity: ");
    Serial.print(fsoil);
    Serial.print("% | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Servo actuation based on waste type
    if (fsoil > maxDryValue) {
      delay(1000);
      Serial.println("==> WET Waste");
      servo1.write(170);
      delay(3000);
    } else {
      delay(1000);
      Serial.println("==> DRY Waste");
      servo1.write(10);
      delay(3000);
    }

    // Return servo to center position
    servo1.write(90);
  }

  delay(1000);
}
