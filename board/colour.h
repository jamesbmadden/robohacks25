// pins for the colour sensor
#define C_S0 4
#define C_S1 3
#define C_S2 7
#define C_S3 6
#define C_IN 8

// defines a colour point that we can reference in our colour classifier algorithm
typedef struct Colour {
  String name;
  int red;
  int green;
  int blue;
};