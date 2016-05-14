#include <glm/glm.hpp>
#include "Primitives.hpp"
#include "Raytracer.hpp"

using namespace glm;

float Sphere::intersect(Ray ray)
{
	return 0.0f;
}

/*
* https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
*/
float Triangle::intersect(Ray ray)  
{
	/*
	static float epsilon = 0.000001;
	vec3 e1, e2;
	vec3 P, Q, T;
	float det, inv_det, u, v;
	float t;

	e1 = v1 - v0;
	e2 = v2 - v0;

	P = cross(ray.direction, e2);
	det = dot(e1, P);
	*/

	return 0.0f;
}

float Plane::intersect(Ray ray)
{
	return 0.0f;
}