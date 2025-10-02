/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial
  by Dejan Nedelkovski,
  www.HowToMechatronics.com
*/

// defines pins numbers
const int trigPin = 11;
const int echoPin = 12;
// defines variables
long duration;
int distance;
bool detect_flag=false;
int count_object = 0;
void setup() {
  // UltraSonic Pins
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("  Distance: ");
  Serial.println(distance);
 if (distance > 100) { 
  Serial.println("waiting to detect an object");
  }
  else
  {
  Serial.println("object detected and present");
  detect_flag = true;
  }
  
  if(detect_flag == true && distance > 101)
  {
  count_object++;
  detect_flag = false;
}
Serial.println(count_object);
}
