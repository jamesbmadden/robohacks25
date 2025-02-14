/**
* utility functions for reading and classifying colours
*/
#include <limits.h>

// pins for the colour sensor
#define C_S0 4
#define C_S1 3
#define C_S2 7
#define C_S3 6
#define C_IN 8

// Stores frequency read by the photodiodes
int red = 0;
int green = 0;
int blue = 0;

// defines a colour point that we can reference in our colour classifier algorithm
typedef struct Colour {
  String name;
  int red;
  int green;
  int blue;
};


const int COLOUR_COUNT = 5;
Colour colours[COLOUR_COUNT];

/**
 * fills in the colours array. must run before the classifier
 */
void set_colours () {

  colours[0].name = "black";
  colours[0].red = 136;
  colours[0].green = 138;
  colours[0].blue = 118;

  colours[1].name = "blue";
  colours[1].red = 91;
  colours[1].green = 48;
  colours[1].blue = 30;

  colours[2].name = "red";
  colours[2].red = 34;
  colours[2].green = 115;
  colours[2].blue = 90;

  colours[3].name = "green";
  colours[3].red = 95;
  colours[3].green = 48;
  colours[3].blue = 73;

  colours[3].name = "white";
  colours[3].red = 19;
  colours[3].green = 20;
  colours[3].blue = 18;

}

/**
 * takes in an r, g, and b value and returns the name of the closest match in the preset colours list
 */
String classify_colour (int r, int g, int b) {

  // compute the distances from each colour
  int minDistance = INT_MAX;
  String minDistanceLabel = "";

  for (int i = 0; i < COLOUR_COUNT; i++) {
    
    // calculate the distance in 3d space
    int dist = sqrt( sq(r - colours[i].red) + sq(g - colours[i].green) + sq(b - colours[i].blue) );

    // check if this is the new min distance
    if (dist < minDistance) {
      minDistance = dist;
      minDistanceLabel = colours[i].name;
    }

  }

  return minDistanceLabel;

}

/**
 * read a colour from the sensor
 */
Colour read_colour () {

  Colour reading;
  reading.name = "reading";

  // read red
  digitalWrite(C_S2,LOW);
  digitalWrite(C_S3,LOW);
  
  reading.red = pulseIn(C_IN, LOW);

  // read green
  digitalWrite(C_S2,HIGH);
  digitalWrite(C_S3,HIGH);
  
  reading.green = pulseIn(C_IN, LOW);

  // read blue
  digitalWrite(C_S2,LOW);
  digitalWrite(C_S3,HIGH);
  
  blue = pulseIn(C_IN, LOW);

  return reading;

}