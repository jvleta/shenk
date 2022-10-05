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
  constexpr auto radius = 1.0 * meter;
  constexpr auto length = 10.0 * meter;
  constexpr auto thickness = 0.01 * meter;
  std::vector<quantity<si::length>> radii{1.0 * meter, 2.0 * meter,
                                          3.0 * meter};
  std::vector<quantity<si::length>> heights{10.0 * meter, 20.0 * meter,
                                            30.0 * meter};
  std::vector<quantity<si::length>> thicknesses{.01 * meter, 0.02 * meter,
                                                0.03 * meter};

//   const auto cyl = shenk::geometry::Cylinder{radius, thickness, length};
//   auto volume = shenk::geometry::ComputeInternalVolume(cyl);
//   ApprovalTests::Approvals::verify(volume);
  ApprovalTests::CombinationApprovals::verifyAllCombinations(
      "INTERNAL VOLUMES",
      [&](auto r, auto t, auto h) {
        auto cylinder = shenk::geometry::Cylinder{r, t, h};
        return shenk::geometry::ComputeInternalVolume(cylinder);
      },
      radii, thicknesses, heights);
}