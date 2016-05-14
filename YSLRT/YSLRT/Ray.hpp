#ifndef RAY_HPP
#define RAY_HPP

#include <glm/glm.hpp>

class Ray
{
public:
	Ray(glm::vec3 origin, glm::vec3 direction) : origin(origin), direction(direction){}
	glm::vec3 origin;
	glm::vec3 direction; /* Unit vector */
};


#endif