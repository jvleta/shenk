#ifndef VOLUME_H
#define VOLUME_H

#include <cmath>

#include "geometry.h"

namespace volumes {
constexpr double pi = M_PI;

struct InternalVolume {
  double operator()(Cylinder cylinder) {
    return pi * std::pow(cylinder.radius, 2.0) * cylinder.length;
  }

  double operator()(Sphere sphere) {
    constexpr double factor = 4.0 / 3.0;
    return factor * pi * std::pow(sphere.radius, 3.0);
  }

  double operator()(Ellipse ellipse) {
    constexpr double factor = 4.0 / 3.0;
    return factor * pi * std::pow(ellipse.radius, 3.0) / ellipse.ratio;
  }
};

using Geometry = std::variant<Cylinder, Sphere, Ellipse>;
[[nodiscard]] double ComputeInternalVolume(Geometry geometry) {
  return std::visit(InternalVolume(), geometry);
}

} // namespace volumes

#endif