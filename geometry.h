#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <ostream>
#include <boost/typeof/std/complex.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/io.hpp>

using namespace boost::units::si;
using namespace boost::units;

struct Cylinder {
  quantity<length> radius;
  quantity<length> thickness;
  quantity<length> height;
};

struct Sphere {
  quantity<length> radius;
  quantity<length> thickness;
};

struct Ellipse {
  quantity<length> radius;
  double ratio;
  quantity<length> thickness;
};

struct RectangularPlate {
  quantity<length> base;
  quantity<length> height;
  quantity<length> thickness;
};

struct CircularPlate {
  quantity<length> radius;
  quantity<length> thickness;
};

using Geometry = std::variant<Cylinder, Sphere>;


#endif