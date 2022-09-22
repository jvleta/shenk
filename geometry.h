#ifndef GEOMETRY_H
#define GEOMETRY_H

struct Cylinder {
  const double radius;
  const double thickness;
  const double length;
  Cylinder(double radius, double thickness, double length)
      : radius(radius), thickness(thickness), length(length) {}
};

struct Sphere {
  const double radius;
  const double thickness;
  Sphere(double radius, double thickness)
      : radius(radius), thickness(thickness) {}
};

struct Ellipse {
  const double radius;
  const double thickness;
  const double ratio;
  Ellipse(double radius, double thickness, double ratio)
      : radius(radius), thickness(thickness), ratio(ratio) {}
};

struct RectangularPlate {
  const double length;
  const double width;
  const double thickness;
  RectangularPlate(double length, double width, double thickness)
      : length(length), width(width), thickness(thickness) {}
};

struct CircularPlate {
  double radius;
  double thickness;
  CircularPlate(double radius, double thickness)
      : radius(radius), thickness(thickness) {}
};

#endif