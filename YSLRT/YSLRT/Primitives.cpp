#include <glm/glm.hpp>
#include "Primitives.hpp"

Sphere::Sphere(glm::vec3 center, glm::vec3 radius){
	c = center;
	r = radius;
}

double Sphere::intersect(Ray ray)
{
	return 0.0;
}