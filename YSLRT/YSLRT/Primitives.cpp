#include <glm/glm.hpp>
#include "Primitives.hpp"
#include "Raytracer.hpp"

using namespace glm;

float Sphere::intersect(Ray ray)
{
	return 0.0f;
}

float Triangle::intersect(Ray ray)
{
	vec3 n = normalize(cross(v1 - v0, v2 - v0));

	return 0.0f;
}