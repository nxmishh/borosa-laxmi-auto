#define BUZZER_PIN 8

unsigned long previousMillis = 0; // Stores the last time the buzzer sounded
unsigned long interval = 1000; // Initial interval for buzzer sound (1 second)
int buzzerState = 0; // Tracks the state of the buzzer (0 = off, 1 = on)
unsigned long totalDuration = 10000; // Total duration of the program (10 seconds)

void setup() {
  pinMode(BUZZER_PIN, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  unsigned long currentMillis = millis(); // Get the current time
  
  // Check if the total duration of the program has elapsed
  if (currentMillis < totalDuration) {
    // Check if enough time has passed to change the buzzer interval
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis; // Update the previousMillis variable
      
      // Toggle the buzzer state
      buzzerState = !buzzerState;
      
      // Set the buzzer according to the state
      digitalWrite(BUZZER_PIN, buzzerState);
      
      // Adjust the interval for the next beep
      if (interval == 1000) {
        interval = 500; // Change interval to 0.5 seconds
      }
    }
  } else {
    // If total duration elapsed, turn off the buzzer
    digitalWrite(BUZZER_PIN, LOW);
  }
}
