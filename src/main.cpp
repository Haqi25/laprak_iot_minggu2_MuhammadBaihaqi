#include <Arduino.h>

// Pin definitions
#define LED_MERAH 18
#define LED_KUNING 19
#define LED_HIJAU 21
#define BUTTON_MERAH 12
#define BUTTON_KUNING 14
#define BUTTON_HIJAU 27

// Constants
#define BLINK_DELAY 200 // Delay between blinks in milliseconds

// For ESP32, LOW turns the LED on and HIGH turns it off when connected to GND
// Let's define macros to make the code more readable
#define LED_ON LOW
#define LED_OFF HIGH

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("ESP32 LED and Button Control");
  
  // Configure LED pins as outputs
  pinMode(LED_MERAH, OUTPUT);
  pinMode(LED_KUNING, OUTPUT);
  pinMode(LED_HIJAU, OUTPUT);
  
  // Configure button pins as inputs with internal pull-up resistors
  pinMode(BUTTON_MERAH, INPUT_PULLUP);
  pinMode(BUTTON_KUNING, INPUT_PULLUP);
  pinMode(BUTTON_HIJAU, INPUT_PULLUP);

  
  
  Serial.println("All LEDs are initially OFF. Press buttons to activate different modes.");
}



// Function for Mode 1: Red LED blinks 5 times
void mode1() {
  Serial.println("Mode 1: Red LED blinks 5 times");
  
  for (int i = 0; i < 5; i++) {
    digitalWrite(LED_MERAH, LED_ON);  // Turn on Red LED
    delay(BLINK_DELAY);
    digitalWrite(LED_MERAH, LED_OFF); // Turn off Red LED
    delay(BLINK_DELAY);
    digitalWrite(LED_MERAH, LOW);
  }
}

// Function for Mode 2: Red and Green LEDs alternate
void mode2() {
  Serial.println("Mode 2: Red and Green LEDs alternate");
  
  for (int i = 0; i < 5; i++) {
    // Red ON, Green OFF
    digitalWrite(LED_MERAH, LED_ON);
    digitalWrite(LED_HIJAU, LED_OFF);
    delay(BLINK_DELAY);
    
    // Red OFF, Green ON
    digitalWrite(LED_MERAH, LED_OFF);
    digitalWrite(LED_HIJAU, LED_ON);
    delay(BLINK_DELAY);
    digitalWrite(LED_MERAH, LOW);
  }
  
  // Turn all LEDs off at the end

}

// Function for Mode 3: Red, Yellow, Green LEDs in sequence
void mode3() {
  Serial.println("Mode 3: Red, Yellow, Green LEDs in sequence");
  
  for (int i = 0; i < 2; i++) {
    // Red ON, others OFF
    digitalWrite(LED_MERAH, LED_ON);
    digitalWrite(LED_KUNING, LED_OFF);
    digitalWrite(LED_HIJAU, LED_OFF);
    delay(BLINK_DELAY);
    
    // Yellow ON, others OFF
    digitalWrite(LED_MERAH, LED_OFF);
    digitalWrite(LED_KUNING, LED_ON);
    digitalWrite(LED_HIJAU, LED_OFF);
    delay(BLINK_DELAY);
    
    // Green ON, others OFF
    digitalWrite(LED_MERAH, LED_OFF);
    digitalWrite(LED_KUNING, LED_OFF);
    digitalWrite(LED_HIJAU, LED_ON);
    delay(BLINK_DELAY);
    digitalWrite(LED_MERAH, LOW);
    digitalWrite(LED_KUNING, LOW);
  }
  
 
}

void loop() {
  // Check if Button 1 (Red) is pressed
  if (digitalRead(BUTTON_MERAH) == LOW) {
    mode1();
    // Wait for button release to prevent multiple activations
    while (digitalRead(BUTTON_MERAH) == LOW) {
      delay(10);
    }
  }
  
  // Check if Button 2 (Yellow) is pressed
  if (digitalRead(BUTTON_KUNING) == LOW) {
    mode2();
    // Wait for button release to prevent multiple activations
    while (digitalRead(BUTTON_KUNING) == LOW) {
      delay(10);
    }
  }
  
  // Check if Button 3 (Green) is pressed
  if (digitalRead(BUTTON_HIJAU) == LOW) {
    mode3();
    // Wait for button release to prevent multiple activations
    while (digitalRead(BUTTON_HIJAU) == LOW) {
      delay(10);
    }
  }
  
  // Small delay for stability
  delay(10);
}