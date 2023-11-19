#pragma once
#include "../box.h"
#include <cmath>

class Rock : public Cube
{
public:
  Rock(const glm::vec3 &minBound, const glm::vec3 &maxBound, const Material &mat)
      : Cube(minBound, maxBound, mat) {}

  Intersect rayIntersect(const glm::vec3 &rayOrigin, const glm::vec3 &rayDirection) const override
  {
    Intersect intersect = Cube::rayIntersect(rayOrigin, rayDirection);

    const float epsilon = 0.0001;
    if (glm::abs(intersect.point.y - maxBound.y) < epsilon || glm::abs(intersect.point.y - minBound.y) < epsilon)
    {
    // Madera y
      Color c = loadTexture(std::abs(intersect.point.x - minBound.x), std::abs(intersect.point.z - minBound.z), "rock");

      intersect.color = c;
      intersect.hasColor = true;
    }
    else if (glm::abs(intersect.point.z - maxBound.z) < epsilon || glm::abs(intersect.point.z - minBound.z) < epsilon){
      // Madera z
      Color c = loadTexture(std::abs(intersect.point.x - minBound.x), std::abs(intersect.point.y - minBound.y), "rock");

      intersect.color = c;
      intersect.hasColor = true;
    }
    else if (glm::abs(intersect.point.x - minBound.x) < epsilon || glm::abs(intersect.point.x - maxBound.x) < epsilon){
      // Madera x
      Color c = loadTexture(std::abs(intersect.point.z - minBound.z), std::abs(intersect.point.y - minBound.y), "rock");

      intersect.color = c;
      intersect.hasColor = true;
    }

    return intersect;
  };
};
