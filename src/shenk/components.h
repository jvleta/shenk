#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "conditions.h"
#include "geometry.h"

template <typename GeometryType> struct Component {
  GeometryType geometry;
  OperatingCondition condition;
};

using CylindricalComponent = Component<Cylinder>;
using SphericalComponent = Component<Sphere>;
using EllipsoidalComponent = Component<Ellipsoid>;
using CircularPlateComponent = Component<CircularPlate>;
using RectangularPlateComponent = Component<RectangularPlate>;

#endif