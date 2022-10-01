#include <shenk/shenk.h>

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
  