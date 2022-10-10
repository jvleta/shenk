#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <ostream>

#include <boost/typeof/std/complex.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/length.hpp>

using namespace boost::units::si;
using namespace boost::units;

namespace shenk::geometry {
struct Cylinder {
  quantity<length> radius;
  quantity<length> thickness;
  quantity<length> height;
  friend std::ostream &operator<<(std::ostream &os, const Cylinder &cylinder) {
    os << "radius   : " << cylinder.radius << "\n"
       << "thickness: " << cylinder.thickness << "\n"
       << "height   : " << cylinder.height << "\n";
    return os;
  }
};

struct Sphere {
  quantity<length> radius;
  quantity<length> thickness;
  friend std::ostream &operator<<(std::ostream &os, const Sphere &sphere) {
    os << "radius   : " << sphere.radius << "\n"
       << "thickness: " << sphere.thickness << "\n";
    return os;
  }
};

struct Ellipsoid {
  quantity<length> radius;
  quantity<length> height;
  quantity<length> thickness;
  friend std::ostream &operator<<(std::ostream &os,
                                  const Ellipsoid &ellipsoid) {
    os << "radius   : " << ellipsoid.radius << "\n"
       << "height   : " << ellipsoid.height << "\n"
       << "thickness: " << ellipsoid.thickness << "\n";
    return os;
  }
};

struct RectangularPlate {
  quantity<length> base;
  quantity<length> height;
  quantity<length> thickness;
  friend std::ostream &operator<<(std::ostream &os,
                                  const RectangularPlate &plate) {
    os << "base     : " << plate.base << "\n"
       << "height   : " << plate.height << "\n"
       << "thickness: " << plate.thickness << "\n";
    return os;
  }
};

struct CircularPlate {
  quantity<length> radius;
  quantity<length> thickness;
  friend std::ostream &operator<<(std::ostream &os,
                                  const CircularPlate &plate) {
    os << "radius   : " << plate.radius << "\n"
       << "thickness: " << plate.thickness << "\n";
    return os;
  }
};

} // namespace shenk::geometry

#endif