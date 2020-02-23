int red = 2; 
int pb = 4;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(red, OUTPUT);
  pinMode (pb, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(pb) == LOW)                 // wait for a second
  {
    digitalWrite(red, HIGH);
    delay(3000};
  }
  digitalWrite(red, LOW);
  }
  
