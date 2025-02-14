/**
* utility functions for using the infrared sensor
*/
#define IR_LIN 2
#define IR_RIN 1

// results for both the left and the right IR sensor
typedef struct IRReading {
  int left;
  int right;
};

/**
 * read from the sensor and return 1 for black, 0 for lighter colour.
 * in order for this to work, the sensor has to be calibrated properly. use the calibration script under the ir_calibration folder for that
 */
int is_black (int pin) {

  // value is HIGH when the measure is black
  int val = digitalRead(pin);

  return val == HIGH;

}

/**
 * read from both sensors and return both results
 */
IRReading read_ir () {

  IRReading results;

  results.left = is_black(IR_LIN);
  results.right = is_black(IR_RIN);

  return results;

}