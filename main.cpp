#include <iostream>
#include <variant>
#include <vector>

#include "components.h"
#include "conditions.h"
#include "geometry.h"
#include "volume.h"

#include <boost/typeof/std/complex.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/length.hpp>

using namespace boost::units::si;
using namespace boost::units;

int main() {
  auto cylinder1 = Cylinder{};
  auto cylinder2 = Cylinder{30.0 * meter, 1.0 * meter, 5.0 * meter};

  auto v1 = volumes::ComputeInternalVolume(cylinder1);
  auto v2 = volumes::ComputeInternalVolume(cylinder2);

  std::cout << v1 << "\n";
  std::cout << v2 << "\n";

  return 0;
}
