/**
 * the main setup and loop running on the board
 */

void setup() {

  // set up the colour classifier
  set_colours();

  // start the colour sensor pins
  pinMode(C_S0, OUTPUT);
  pinMode(C_S1, OUTPUT);
  pinMode(C_S2, OUTPUT);
  pinMode(C_S3, OUTPUT);
  pinMode(C_IN, INPUT);
  pinMode(IR_IN, INPUT);

  // start the IR pins
  pinMode(IR_LIN, INPUT);
  pinMode(IR_RIN, INPUT);

  // start the motor pins
  pinMode(M_SA, OUTPUT);
  pinMode(M_SB, OUTPUT);
  pinMode(M_1, OUTPUT); // right reverse
  pinMode(M_2, OUTPUT); // right forward
  pinMode(M_3, OUTPUT); // left reverse
  pinMode(M_4, OUTPUT); // left forward
  
  // set frequency scaling to 20%
  digitalWrite(C_S0, HIGH);
  digitalWrite(C_S1, LOW);
  
  // turn on serial communication
  Serial.begin(9600);
}

void loop() {

  // motors forward
  // check black - if either are colour/white, adjust accordingly
  // read colour - if green drop seed by wiggling/vibrating
  //               if blue wait
  //               if red/white keep going
  
  /*// read a colour
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
  String result = classify_colour(reading.red, reading.green, reading.blue);
  Serial.print("detected colour was ");
  Serial.println(result);

  // wait a second
  delay(1000);*/

}