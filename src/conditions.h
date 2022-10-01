#ifndef CONDITIONS_H
#define CONDITIONS_H

#include <boost/typeof/std/complex.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/pressure.hpp>
#include <boost/units/systems/temperature/celsius.hpp>

using namespace boost::units::si;
using namespace boost::units;
using namespace boost::units::temperature;
struct OperatingCondition {
  quantity<pressure> pressure;
  quantity<absolute<celsius::temperature>> temperature;
};

#endif