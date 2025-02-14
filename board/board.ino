/**
 * the main setup and loop running on the board
 */

// set the colour that was last handled so we don't duplicate actions on blue or green
String handled_colour = "white";

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

  // STEP 1: course correction
  IRReading ir = read_ir();

  // check if rotation is needed
  if (ir.left && !ir.right) {
    // turn slightly left
    rotate_left(100, 200);
  } else if (ir.right && !ir.left) {
    // turn slightly right
    rotate_right(100, 200);
  }

  // STEP 2: colour action
  // take a colour reading
  Colour reading = read_colour();
  String colour = classify_colour(reading.red, reading.green, reading.blue);

  // take action based on the colour
  if (colour.compareTo("blue") == 0 && handled_colour.compareTo("blue") != 0) {
    // lake! pause here
    delay(7000);
    // then keep going
    go_forward(200, 200);
  } else if (colour.compareTo("green") == 0 && handled_colour.compareTo("green") != 0) {
    // activate wiggles to drop seeds
    wiggle(50);
  }

  // move forwards and set handled colour
  handled_colour = colour;
  go_forward(200, 200);



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