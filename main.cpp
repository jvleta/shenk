#include <iostream>
#include <variant>
#include <vector>

#include "materials.h"
#include "stress.h"

int main() {
  auto material = Material();
  auto props = material.get_properties(70.0);
  // using Components = std::variant<Component<Cylinder>, Component<Sphere>>;

  // OperatingCondition condition1{300.0, 800.0};

  // std::vector<Components> components{
  //     Component<Cylinder>{{30.0, 1.0, 10.0}, condition1},
  //     Component<Sphere>{{30.0, 1.0}, condition1}};
  // for (auto &comp : components) {
  //   std::visit(ComputeStressState(), comp);
  // }
  return 0;
}
