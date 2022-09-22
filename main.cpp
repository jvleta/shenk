#include <iostream>
#include <variant>
#include <vector>

// #include "materials.h"
// #include "stress.h"
#include "geometry.h"
#include "conditions.h"

int main() {
  auto cylinder = Cylinder(30.0, 1.0, 5.0);
  auto condition1 = OperatingCondition(250.0, 600.0);

  // using Components = std::variant<Component<Cylinder>, Component<Sphere>>;
  // std::vector<Components> components{
  //     Component<Cylinder>{{30.0, 1.0, 10.0}, condition1},
  //     Component<Sphere>{{30.0, 1.0}, condition1}};
  // for (auto &comp : components) {
  //   std::visit(ComputeStressState(), comp);
  // }
  return 0;
}
