#ifndef VOLUME_H
#define VOLUME_H

#include <boost/typeof/std/complex.hpp>
#include <boost/units/pow.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/area.hpp>
#include <boost/units/systems/si/volume.hpp>
#include <boost/units/systems/si/io.hpp>

#include "geometry.h"

using namespace boost::units::si;
using namespace boost::units;

namespace volumes {
constexpr double pi = M_PI;

struct InternalVolume {
  quantity<volume> operator()(Cylinder cylinder) {
    return pi * (pow<2>(cylinder.radius) * cylinder.height);
  }

  quantity<volume> operator()(Sphere sphere) {
    constexpr double factor = 4.0 / 3.0;
    return factor * pi * pow<3>(sphere.radius);
  }

  quantity<volume> operator()(Ellipse ellipse) {
    constexpr double factor = 4.0 / 3.0;
    return factor * pi * pow<3>(ellipse.radius) / ellipse.ratio;
  }
};

using Geometry = std::variant<Cylinder, Sphere, Ellipse>;
[[nodiscard]] quantity<volume> ComputeInternalVolume(Geometry geometry) {
  return std::visit(InternalVolume(), geometry);
}

} // namespace volumes

#endif