#ifndef STRESS_H
#define STRESS_H

#include <tuple>

#include "components.h"

class ComputeStressState {
private:
  auto compute_hoop_stress(double p, double r, double t) -> double {
    return p * r / t;
  }

public:
  using PrincipalStresses = std::tuple<double, double, double>;

  auto operator()(CylindricalComponent component) -> PrincipalStresses {

    double sigma = compute_hoop_stress(component.condition.pressure,
                                       component.geometry.radius,
                                       component.geometry.thickness);
    return {sigma, sigma / 2.0, 0.0};
  }

  auto operator()(SphericalComponent component) -> PrincipalStresses {
    double sigma = compute_hoop_stress(component.condition.pressure,
                                       component.geometry.radius,
                                       component.geometry.thickness);
    return {sigma, sigma, 0.0};
  }
};

#endif