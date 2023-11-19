#pragma once
#include <glm/glm.hpp>

class Camera
{
public:
  Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up, float rotationSpeed)
      : position(position), target(target), up(up), rotationSpeed(rotationSpeed)
  {
  }

  void rotate(float deltaX, float deltaY)
  {
    glm::quat quatRotY = glm::angleAxis(glm::radians(deltaX * rotationSpeed), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::quat quatRotX = glm::angleAxis(glm::radians(deltaY * rotationSpeed), glm::vec3(1.0f, 0.0f, 0.0f));

    position = target + quatRotY * (position - target);
    position = target + quatRotX * (position - target);
    printCamera();

  }

  void move(float deltaZ)
  {
    glm::vec3 dir = glm::normalize(target - position);
    position += dir * deltaZ;
    printCamera();
    target += dir * deltaZ;
  }

  void moveX(float deltaX)
  {
    position.x +=  deltaX;
    printCamera();
    target.x += deltaX;
  }

  void moveY(float deltaY)
  {
    // Desplazar la posición y el objetivo en el eje y
    position.y += deltaY;
    target.y += deltaY;
    printCamera();
  }

  void reset()
  {
    position = glm::vec3(3.0, 3.0, 5.0f);
    target = glm::vec3(3.0f, 3.0f, 0.0f);
  }

  void printCamera()
  {
    SDL_Log("position: %f, %f, %f", position.x, position.y, position.z);
    SDL_Log("target: %f, %f, %f", target.x, target.y, target.z);
  }

  glm::vec3 position;
  glm::vec3 target;
  glm::vec3 up;
  float rotationSpeed;
};
