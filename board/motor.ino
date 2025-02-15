/**
 * provides methods to manage the motors
 */

void stop () {

  // set all motor pins to low
  digitalWrite(M_1, LOW);
  digitalWrite(M_2, LOW);
  digitalWrite(M_3, LOW);
  digitalWrite(M_4, LOW);

}

void go_forward (int delay_time, float speed) {

  // set speed (from range 0 to 255)
  // analogWrite(M_SA, int(speed * 255));
  // analogWrite(M_SB, int(speed * 255));

  // set pins to forward
  digitalWrite(M_1, LOW);
  digitalWrite(M_2, HIGH);
  digitalWrite(M_3, LOW);
  digitalWrite(M_4, HIGH);

  // wait the specified time
  delay(delay_time);

}

void go_backwards (int delay_time, float speed) {

  // set speed (from range 0 to 255)
  // analogWrite(M_SA, int(speed * 255));
  // analogWrite(M_SB, int(speed * 255));

  // set pins to forward
  digitalWrite(M_1, HIGH);
  digitalWrite(M_2, LOW);
  digitalWrite(M_3, HIGH);
  digitalWrite(M_4, LOW);
  
  // wait the specified time
  delay(delay_time);

}

void rotate_left (int delay_time, float speed) {

  // set speed (from range 0 to 255)
  // analogWrite(M_SA, int(speed * 255));
  // analogWrite(M_SB, int(speed * 255));

  // set pins to forward
  digitalWrite(M_1, LOW);
  digitalWrite(M_2, HIGH);
  digitalWrite(M_3, HIGH);
  digitalWrite(M_4, LOW);
  
  // wait the specified time
  delay(delay_time);

}

void rotate_right (int delay_time, float speed) {

  // set speed (from range 0 to 255)
  // analogWrite(M_SA, int(speed * 255));
  // analogWrite(M_SB, int(speed * 255));

  // set pins to forward
  digitalWrite(M_1, HIGH);
  digitalWrite(M_2, LOW);
  digitalWrite(M_3, LOW);
  digitalWrite(M_4, HIGH);
  
  // wait the specified time
  delay(delay_time);

}

/**
 * go side to side to eject seeds
 */
void wiggle (int wiggle_count) {

  for (int i = 0; i < wiggle_count; i++) {

    // quickly rotate
    rotate_left(10, 1);
    rotate_right(10, 1);

  }

}

/**
 * move to the centre of a circle
 */
void move_to_centre () {

  String colour;
  int n;

  while (colour != "white") {
    go_forward(100, 0.5);
    // colour reading
    Colour reading = read_colour();
    colour = classify_colour(reading.red, reading.green, reading.blue);
    n++;
  }

  stop();
  // now move backwards
  for (int i = n / 2; i > 0; i--) {
    go_backwards(100, 0.5);
  }
  stop();

}

/**
 * continue forwards until the black line on IR
 */
void forwards_until_black () {

  IRReading ir = read_ir();

  while (true) {
    go_forward(10, 1);
    if (ir.left || ir.right) {
      return;
    }
  }

}

/**
 * do a wide turn to avoid the red
 */
void wide_swerve () {

  rotate_right(100, 1);
  go_forward(200, 1);
  rotate_left(200, 1);
  forwards_until_black();

}