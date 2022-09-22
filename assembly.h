#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include <variant>
#include <vector>

#include "components.h"

using Component =
    std::variant<CylindricalComponent, SphericalComponent, EllipticalComponent,
                 RectangularPlateComponent, CircularPlateComponent>;
class Assembly {
private:
  std::vector<Component> components_;

public:
  void add_component(Component component) { components_.push_back(component); }
};

#endif