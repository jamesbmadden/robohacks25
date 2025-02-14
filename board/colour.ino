#include <limits.h>

// defines a colour point that we can reference in our colour classifier algorithm
typedef struct Colour {
  String name;
  int red;
  int green;
  int blue;
};


const int COLOUR_COUNT = 2;

String classify_colour(int r, int g, int b) {

  Colour colours[COLOUR_COUNT];

  colours[0].name = "white";
  colours[0].red = 0;
  colours[0].green = 0;
  colours[0].blue = 0;

  colours[1].name = "black";
  colours[1].red = 255;
  colours[1].green = 255;
  colours[1].blue = 255;

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