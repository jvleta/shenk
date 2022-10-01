#ifndef MATERIALS_H
#define MATERIALS_H

#include <functional>

struct MaterialProperties {
  double yield_stress;
  double elastic_modulus;
  double poisson_ratio;
};

enum class MaterialType { Steel };

struct Material {
  std::function<MaterialProperties(double)> get_properties;
  Material(MaterialType type) {
    switch (type) {
    case MaterialType::Steel:
      get_properties = [](double temperature) {
        return MaterialProperties{30.0e3, 28.3e6, 0.3};
      };
    };
  }

  Material() { *this = std::move(Material(MaterialType::Steel)); };
  
};

#endif