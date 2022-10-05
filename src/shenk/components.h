#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "conditions.h"
#include "geometry.h"

template <typename GeometryType> struct Component {
  GeometryType geometry;
  OperatingCondition condition;
};

using CylindricalComponent = Component<shenk::geometry::Cylinder>;
using SphericalComponent = Component<shenk::geometry::Sphere>;
using EllipsoidalComponent = Component<shenk::geometry::Ellipsoid>;
using CircularPlateComponent = Component<shenk::geometry::CircularPlate>;
using RectangularPlateComponent = Component<shenk::geometry::RectangularPlate>;

#endif