/**
* on button press, output the colour values to the console for use in the main code
*/
// pins for the colour sensor
#define S0 4
#define S1 3
#define S2 7
#define S3 6
#define sensor_out 8

// Stores frequency read by the photodiodes
int red = 0;
int green = 0;
int blue = 0;
int colour_captured = 0;

void setup() {
  
  // set the input/output pins
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensor_out, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // start serial so we can read values on the computer
  Serial.begin(9600);
}

void loop () {

  // wait for a serial input
  if (Serial.available() > 0 && !colour_captured) {
    String msg = Serial.readString();
    capture_colour(msg);
    
  } else if (Serial.available() == 0 && colour_captured) {
    // reset the colour captured so it can be pressed again
    colour_captured = 0;
  }

}

void capture_colour (String msg) {

  Serial.print("== COLOUR CAPTURE ");
  Serial.print(msg);

  // set RED read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  red = pulseIn(sensor_out, LOW);
  
  Serial.print("R = ");
  Serial.print(red);
  delay(100);
  
  // set GREEN read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  green = pulseIn(sensor_out, LOW);

  Serial.print(" G = ");
  Serial.print(green);
  delay(100);
 
  // set BLUE read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blue = pulseIn(sensor_out, LOW);

  Serial.print(" B = ");
  Serial.println(blue);
  delay(100);

  Serial.print("\n");

  // set that the colour's been captured
  colour_captured = 1;

}