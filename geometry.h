#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <ostream>

struct Cylinder {
  const double radius;
  const double thickness;
  const double length;
};

struct Sphere {
  const double radius;
  const double thickness;
};

struct Ellipse {
  const double radius;
  const double thickness;
  const double ratio;
};

struct RectangularPlate {
  const double length;
  const double width;
  const double thickness;
};

struct CircularPlate {
  double radius;
  double thickness;
};

#endif