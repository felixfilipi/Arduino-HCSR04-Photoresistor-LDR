const int pResistor = A0; // Photoresistor at pin A0
const int ledPin=9;       // Led at pin 9

int value;   

void setup(){
 pinMode(ledPin, OUTPUT);  // Set lepPin - 9 pin as an output
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
}

void loop(){
  value = analogRead(pResistor);
  
  if (value > 25){
    digitalWrite(ledPin, LOW); 
  }
  else{
    digitalWrite(ledPin, HIGH);
  }

  delay(500);
}
