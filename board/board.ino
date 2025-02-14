void setup() {

  // set up the colour classifier
  set_colours();

  // start the colour sensor pins
  pinMode(C_S0, OUTPUT);
  pinMode(C_S1, OUTPUT);
  pinMode(C_S2, OUTPUT);
  pinMode(C_S3, OUTPUT);
  
  // set the colour sensor output
  pinMode(C_OUT, INPUT);
  pinMode(IR_IN, INPUT);
  
  // set frequency scaling to 20%
  digitalWrite(C_S0, HIGH);
  digitalWrite(C_S1, LOW);
  
  // turn on serial communication
  Serial.begin(9600);
}
void loop() {
  
  // read a colour
  Colour reading = read_colour();

  // output the colour
  Serial.println("== READING ==");
  Serial.print("Red: ");
  Serial.print(reading.red);
  Serial.print(" Green: ");
  Serial.print(reading.green);
  Serial.print(" Blue: ");
  Serial.println(reading.blue);

  // check what the reading is
  String result = classify_colour(red, green, blue);
  Serial.print("detected colour was ");
  Serial.println(result);
}