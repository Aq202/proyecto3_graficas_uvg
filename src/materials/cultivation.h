#pragma once
#include "../box.h"
#include <cmath>

class Cultivation : public Cube
{
public:
  Cultivation(const glm::vec3 &minBound, const glm::vec3 &maxBound, const Material &mat)
      : Cube(minBound, maxBound, mat) {}

  Intersect rayIntersect(const glm::vec3 &rayOrigin, const glm::vec3 &rayDirection) const override
  {
    Intersect intersect = Cube::rayIntersect(rayOrigin, rayDirection);

    const float epsilon = 0.0001;
    if (glm::abs(intersect.point.y - maxBound.y) < epsilon)
    {
    // Añadir textura arriba grama
      Color c = loadTexture(std::abs(intersect.point.x - minBound.x), std::abs(intersect.point.z - minBound.z), "cultivation");

      intersect.color = c;
      intersect.hasColor = true;
    }

    return intersect;
  };
};
