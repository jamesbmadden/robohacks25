// pins for the colour sensor
#define C_S0 20
#define C_S1 21
#define C_S2 18
#define C_S3 19
#define C_IN 17

// defines a colour point that we can reference in our colour classifier algorithm
typedef struct Colour {
  String name;
  int red;
  int green;
  int blue;
};