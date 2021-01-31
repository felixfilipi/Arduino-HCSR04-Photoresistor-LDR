#define echoPin 2 //  pin D2 as Echo HC-SR04
#define trigPin 3 // pin D3 as Trig HC-SR04
#define ledPin 4 // pin D4 as LED's Positive

long duration;
int distance; 

void setup() {
  pinMode(trigPin, OUTPUT); // Sets trig as OUTPUT
  pinMode(echoPin, INPUT); // Set echo as INPUT
  Serial.begin(9600);
}

void loop() {
  // clear trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  // Set trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin(returns the sound wave travel time)
  duration = pulseIn(echoPin, HIGH);
  // Calculate distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // When distance less than 10 cm the LED HIGH
  if(distance<=10){
    digitalWrite(ledPin,HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
  // Print distance in Serial Monitor (Shortcut: Ctrl+Shift+M)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
