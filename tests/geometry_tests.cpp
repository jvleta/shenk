#include <iostream>
#include <variant>
#include <vector>

#include "components.h"
#include "conditions.h"
#include "geometry.h"
#include "stress.h"
#include "volume.h"

#include <boost/typeof/std/complex.hpp>
#include <boost/units/systems/si/io.hpp>

#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/pressure.hpp>
#include <boost/units/systems/temperature/celsius.hpp>

#include "ApprovalTests/Approvals.h"
#include <gtest/gtest.h>

using namespace boost::units::si;
using namespace boost::units;

constexpr auto zero_length = quantity<length>{};

TEST(Cylinder_tests, Cylinder_initialization) {
  auto cylinder = Cylinder{};
  ApprovalTests::Approvals::verify(cylinder);
}

TEST(Sphere_tests, Sphere_initialization) {
  auto sphere = Sphere{};
  ApprovalTests::Approvals::verify(sphere);
}

TEST(Ellipspoid_tests, Ellipspoid_initialization) {
  auto ellipsoid = Ellipsoid{};
  ApprovalTests::Approvals::verify(ellipsoid);
}

TEST(RectangularPlate_tests, RectangularPlate_initialization) {
  auto plate = RectangularPlate{};
  ApprovalTests::Approvals::verify(plate);
}

TEST(CircularPlate_tests, CircularPlate_initialization) {
  auto plate = CircularPlate{};
  ApprovalTests::Approvals::verify(plate);
}

// int main() {
//   double *x;
//   auto cylinder = Cylinder{3.0 * meter, 0.0254 * meter, 10.0 * meter};
//   auto condition = OperatingCondition{1.38e6 * pascals,
//                                       250.0 *
//                                       absolute<celsius::temperature>()};
//   auto volume = volumes::ComputeInternalVolume(cylinder);
//   std::cout << volume << "\n";

//   auto component = CylindricalComponent{cylinder, condition};
//   std::cout << component.condition.pressure << "\n";
//   // auto stresses = ComputePrincipalStresses(component);
//   // std::cout << "sigma1 = " << std::get<0>(stresses) << "\n";
//   // std::cout << "sigma2 = " << std::get<1>(stresses) << "\n";
//   // std::cout << "sigma3 = " << std::get<2>(stresses) << "\n";
//   return 0;
// }
