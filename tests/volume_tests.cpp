#include <shenk/volume.h>

#include <boost/typeof/std/complex.hpp>
#include <boost/units/systems/si/io.hpp>

#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/volume.hpp>

#include <vector>

#include "ApprovalTests/Approvals.h"
#include "ApprovalTests/CombinationApprovals.h"

#include <gtest/gtest.h>

using namespace boost::units::si;
using namespace boost::units;

TEST(Cylinder_Volume_Tests, InternalVolume) {
  std::vector<quantity<si::length>> radii{1.0 * meter, 2.0 * meter,
                                          3.0 * meter};
  std::vector<quantity<si::length>> heights{10.0 * meter, 20.0 * meter,
                                            30.0 * meter};
  constexpr auto thickness = 0.01 * meter;
  ApprovalTests::CombinationApprovals::verifyAllCombinations(
      "CYLINDER INTERNAL VOLUME:",
      [&](auto r, auto h) {
        auto cylinder = shenk::geometry::Cylinder{r, thickness, h};
        return shenk::geometry::ComputeInternalVolume(cylinder);
      },
      radii, heights);
}

TEST(Sphere_Volume_Tests, InternalVolume) {
  std::vector<quantity<si::length>> radii{1.0 * meter, 2.0 * meter,
                                          3.0 * meter};
  constexpr auto thickness = 0.01 * meter;
  std::vector<quantity<si::volume>> volumes{};
  std::for_each(radii.begin(), radii.end(), [&](const auto r) {
    const auto sphere = shenk::geometry::Sphere{r, thickness};
    auto v = shenk::geometry::ComputeInternalVolume(sphere);
    volumes.push_back(v);
  });
  ApprovalTests::Approvals::verifyAll("SPHERE INTERNAL VOLUME", volumes);
}

TEST(Ellipsoid_Volume_Tests, InternalVolume) {
  std::vector<quantity<si::length>> radii{1.0 * meter, 2.0 * meter,
                                          3.0 * meter};
  std::vector<quantity<si::length>> heights{10.0 * meter, 20.0 * meter,
                                            30.0 * meter};
  constexpr auto thickness = 0.01 * meter;

  ApprovalTests::CombinationApprovals::verifyAllCombinations(
      "ELLIPSOID INTERNAL VOLUME:",
      [&](auto r, auto h) {
        auto ellipsoid = shenk::geometry::Ellipsoid{r, h, thickness};
        return shenk::geometry::ComputeInternalVolume(ellipsoid);
      },
      radii, heights);
}