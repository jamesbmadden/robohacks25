/**
 * provides methods to manage the motors
 */

// motor pins
#define M_SA = 14
#define M_SB = 15
#define M_1 = 16
#define M_2 = 17
#define M_3 = 18
#define M_4 = 19

void stop () {

  // set all motor pins to low
  digitalWrite(M_1, LOW);
  digitalWrite(M_2, LOW);
  digitalWrite(M_3, LOW);
  digitalWrite(M_4, LOW);

}

void go_forward (int delay_time, float speed) {

  // set speed (from range 0 to 255)
  analogWrite(M_SA, int(speed * 255));
  analogWrite(M_SB, int(speed * 255));

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
  analogWrite(M_SA, int(speed * 255));
  analogWrite(M_SB, int(speed * 255));

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
  analogWrite(M_SA, int(speed * 255));
  analogWrite(M_SB, int(speed * 255));

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
  analogWrite(M_SA, int(speed * 255));
  analogWrite(M_SB, int(speed * 255));

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
    rotate_left(10, 255);
    rotate_right(10, 255);

  }

}