#include <glm/glm.hpp>
#include "Primitives.hpp"
#include "Raytracer.hpp"

using namespace glm;

float Sphere::intersect(Ray ray)
{
	return 0.0f;
}

/* Copypaste on paras
* https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
*/
float Triangle::intersect(Ray ray)  
{	
	static float epsilon = 0.000001f;

	vec3 e1, e2;	//Edge1, Edge2
	vec3 P, Q, T;
	float det, inv_det, u, v;
	float t;

	//Find vectors for two edges sharing V1
	e1 = v1 - v0;
	e2 = v2 - v0;
	//Begin calculating determinant - also used to calculate u parameter
	P = cross(ray.direction, e2);
	//if determinant is near zero, ray lies in plane of triangle
	det = dot(e1, P);
	
	//NOT CULLING
	if (det > -epsilon && det < epsilon)
		return -1.0f;
	inv_det = 1.0f / det;

	//calculate distance from V1 to ray origin
	T = ray.origin - v0;

	//Calculate u parameter and test bound
	u = dot(T, P) * inv_det;

	//The intersection lies outside of the triangle
	if (u < 0.0f || u > 1.0f) 
		return -1.0f;

	//Prepare to test v parameter
	Q = cross(T, e1);

	//Calculate V parameter and test bound
	v = dot(ray.direction, Q) * inv_det;
	//The intersection lies outside of the triangle
	if (v < 0.0f || u + v  > 1.0f) 
		return -1.0f;

	t = dot(e2, Q) * inv_det;

	if (t > epsilon) { //ray intersection
		return t;
	}

	return 0.0f;
}

float Plane::intersect(Ray ray)
{
	return 0.0f;
}