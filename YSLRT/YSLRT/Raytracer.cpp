#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "Raytracer.hpp"

class Ray
{
public:
	Ray::Ray(glm::vec3 origin, glm::vec3 direction) : origin(origin), direction(direction){}
	glm::vec3 origin;
	glm::vec3 direction;
};