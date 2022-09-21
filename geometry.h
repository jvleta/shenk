#ifndef GEOMETRY_H
#define GEOMETRY_H

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
  const double ratio;
  const double thickness;
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