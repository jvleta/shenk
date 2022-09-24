#include <iostream>
#include <variant>
#include <vector>

#include "stress.h"
#include "geometry.h"
#include "conditions.h"
#include "components.h"
#include "volume.h"

int main() {
  auto cylinder1 = Cylinder{};
  auto cylinder2 = Cylinder{30.0, 1.0, 5.0};

  auto v1 = volumes::ComputeInternalVolume(cylinder1);
  auto v2 = volumes::ComputeInternalVolume(cylinder2);
  
  double rho = 0.283;

  double w1 = rho * v1;

  return 0;
}
