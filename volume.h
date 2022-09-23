#ifndef VOLUME_H
#define VOLUME_H

#include <cmath>

#include "geometry.h"

constexpr double pi = M_PI;

struct InternalVolume {
  static double compute(Cylinder cylinder) {
    return pi * std::pow(cylinder.radius, 2.0) * cylinder.length;
  }

  static double compute(Sphere sphere) {
    constexpr double factor = 4.0 / 3.0;
    return factor * pi * std::pow(sphere.radius, 3.0);
  }
};

#endif