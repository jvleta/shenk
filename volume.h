#ifndef VOLUME_H
#define VOLUME_H

#include <cmath>

#include "geometry.h"

constexpr double pi = M_PI;

struct InternalVolume {
  double operator()(Cylinder cylinder) {
    return pi * std::pow(cylinder.radius, 2.0) * cylinder.length;
  }

  double operator()(Sphere sphere) {
    constexpr double factor = 4.0 / 3.0;
    return factor * pi * std::pow(sphere.radius, 3.0);
  }
};

[[nodiscard]] double ComputeInternalVolume(Geometry geometry) {
  return std::visit(InternalVolume(), geometry);
}

#endif