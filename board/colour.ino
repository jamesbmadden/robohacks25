/**
* utility functions for reading and classifying colours
*/
#include <limits.h>


// Stores frequency read by the photodiodes
int red = 0;
int green = 0;
int blue = 0;

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

  colours[4].name = "white";
  colours[4].red = 19;
  colours[4].green = 20;
  colours[4].blue = 18;

}

/**
 * takes in an r, g, and b value and returns the name of the closest match in the preset colours list
 */
String classify_colour (int r, int g, int b) {

  /*Serial.print("classifying colour r = ");
  Serial.print(r);
  Serial.print(", g = ");
  Serial.print(g);
  Serial.print(", b = ");
  Serial.println(b);*/

  // compute the distances from each colour
  double minDistance = INT_MAX;
  String minDistanceLabel = "";

  for (int i = 0; i < COLOUR_COUNT; i++) {
    
    // calculate the distance in 3d space
    double dist_r = r - colours[i].red;
    double dist_g = g - colours[i].green;
    double dist_b = b - colours[i].blue;
    double dist = sqrt( dist_r * dist_r + dist_g * dist_g + dist_b * dist_b );

    /*Serial.print(colours[i].name);
    Serial.print(" has distance ");
    Serial.println(dist);*/

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

  delay(10);

  // read green
  digitalWrite(C_S2,HIGH);
  digitalWrite(C_S3,HIGH);
  
  reading.green = pulseIn(C_IN, LOW);
  
  delay(10);

  // read blue
  digitalWrite(C_S2,LOW);
  digitalWrite(C_S3,HIGH);
  
  reading.blue = pulseIn(C_IN, LOW);
  
  delay(10);

  return reading;

}