#include <shenk/conditions.h>

#include <boost/typeof/std/complex.hpp>
#include <boost/units/systems/si/io.hpp>

#include <boost/units/systems/si/pressure.hpp>
#include <boost/units/systems/temperature/celsius.hpp>

#include "ApprovalTests/Approvals.h"
#include <gtest/gtest.h>

using namespace boost::units::si;
using namespace boost::units;

TEST(Condition_tests, Condition_initialization) {
  auto condition = OperatingCondition{};
  ApprovalTests::Approvals::verify(condition);
}

