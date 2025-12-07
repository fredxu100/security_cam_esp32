const int pirSensorPin = 41;   // Input pin for the PIR sensor (connect PIR OUT here)
const int ledPin = 1;        // Output pin for the LED (onboard LED or external LED w/resistor)

// Variable to store the state of the PIR sensor
int motionState = LOW;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Initialize the PIR sensor pin as an input
  // Note: Most modern PIR modules (like HC-SR501) have 
  // an internal pull-up/down, but INPUT is sufficient.
  pinMode(pirSensorPin, INPUT);

  // Start serial communication for debugging
  Serial.begin(9600);
  Serial.println("PIR Motion Detector Ready.");
}

void loop() {

  // Read the state of the PIR sensor pin
  motionState = digitalRead(pirSensorPin);

  // Check if the sensor has detected motion (signal is HIGH)
  if (motionState == HIGH) {
    // If motion is detected, turn the LED on
    digitalWrite(ledPin, HIGH);

    // Print a message to the serial monitor
    Serial.println("--- Motion Detected! ---");

    // Optional: Add a small delay to avoid rapid state changes, 
    // although the PIR module has its own internal delay.
    delay(500);
  } else {
    // If no motion is detected (or the PIR timeout expired), turn the LED off
    digitalWrite(ledPin, LOW);
    
    // Print a message to the serial monitor
    Serial.println("--- No Motion ---");
  }
}