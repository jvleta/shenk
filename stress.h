#ifndef STRESS_H
#define STRESS_H

#include <tuple>
#include <variant>

#include "components.h"

#include <boost/typeof/std/complex.hpp>
#include <boost/units/pow.hpp>
#include <boost/units/systems/si/area.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/volume.hpp>

using namespace boost::units::si;
using namespace boost::units;

using stress = pressure;

struct StressTensor {
  quantity<stress> sigma11{};
  quantity<stress> sigma22{};
  quantity<stress> sigma33{};
  quantity<stress> sigma23{};
  quantity<stress> sigma13{};
  quantity<stress> sigma12{};
};

// struct PrincipalStresses {
//   quantity<stress> sigma1;
//   quantity<stress> sigma2;
//   quantity<stress> sigma3;
// };

using PrincipalStresses =
    std::tuple<quantity<stress>, quantity<stress>, quantity<stress>>;

// using StressTensor =
//     std::tuple<quantity<stress>, quantity<stress>, quantity<stress>,
//                quantity<stress>, quantity<stress>, quantity<stress>>;
class ComputeStressState {
private:
  auto compute_hoop_stress(quantity<stress> p, quantity<length> r,
                           quantity<length> t) -> quantity<stress> {
    return p * r / t;
  }

public:
  auto operator()(CylindricalComponent component) -> PrincipalStresses {
    auto sigma = compute_hoop_stress(component.condition.pressure,
                                component.geometry.radius,
                                component.geometry.thickness);
    return {sigma, sigma / 2.0, 0.0 * pascal};
  }

  auto operator()(SphericalComponent component) -> PrincipalStresses {
    auto sigma = compute_hoop_stress(component.condition.pressure,
                                     component.geometry.radius,
                                     component.geometry.thickness);
    return {sigma, sigma, 0.0 * pascals};
  }
};

using ComponentType = std::variant<CylindricalComponent, SphericalComponent>;
[[nodiscard]] PrincipalStresses
ComputePrincipalStresses(ComponentType component) {
  return std::visit(ComputeStressState(), component);
}

#endif