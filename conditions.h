#ifndef CONDITIONS_H
#define CONDITIONS_H

struct OperatingCondition {
  const double pressure;
  const double temperature;
  OperatingCondition(double pressure, double temperature) : pressure(pressure), temperature(temperature){}
};

#endif