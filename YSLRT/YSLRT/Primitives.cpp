#include <glm/glm.hpp>
#include "Primitives.hpp"
#include "Raytracer.hpp"

using namespace glm;

float Sphere::intersect(Ray * ray)
{
	float x0, x1;
	vec3 dist = ray->origin - c;

	// Quadratic equation
	float a = dot(ray->direction, ray->direction);
	float b = 2.0f * dot(ray->direction, dist);
	float c = dot(dist, dist) - (r * r);
	float discr = b * b - 4.0f * a * c;

	if (discr < 0.0f) return -1.0f;
	else if (discr == 0.0f) x0 = x1 = -0.5f * b / a;
	else {
		float q = (b > 0) ?
			-0.5f * (b + sqrt(discr)) :
			-0.5f * (b - sqrt(discr));
		x0 = q / a;
		x1 = c / q;
	}

	if (!(x0 < 0.0f) && x0 < x1)
	{
		ray->ip.xyz = ray->origin + ray->direction*x0;
		return x0;
	}
	ray->ip.xyz = ray->origin + ray->direction*x1;
	return x1;
}

vec3 Sphere::getNormal(Ray * ray)
{
	return normalize(ray->ip.xyz-c);
}

Triangle::Triangle(vec3 v0, vec3 v1, vec3 v2, vec3 color) : Primitive(color), v0(v0), v1(v1), v2(v2){
	vec3 n = cross((v1 - v0), (v2 - v0));
	n0 = n;
	n1 = n;
	n2 = n;
}

/* Copypaste on paras
* https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
*/
float Triangle::intersect(Ray * ray)  
{	
	static float epsilon = 0.000001f;

	vec3 e1, e2;	//Edge1, Edge2
	vec3 P, Q, T;
	float det, inv_det, u, v;
	float t;

	//Find vectors for two edges sharing V0
	e1 = v1 - v0;
	e2 = v2 - v0;
	//Begin calculating determinant - also used to calculate u parameter
	P = cross(ray->direction, e2);
	//if determinant is near zero, ray lies in plane of triangle
	det = dot(e1, P);
	
	//NOT CULLING
	if (det > -epsilon && det < epsilon)
		return -1.0f;
	inv_det = 1.0f / det;

	//calculate distance from V0 to ray origin
	T = ray->origin - v0;

	//Calculate u parameter and test bound
	u = dot(T, P) * inv_det;

	//The intersection lies outside of the triangle
	if (u < 0.0f || u > 1.0f) 
		return -1.0f;

	//Prepare to test v parameter
	Q = cross(T, e1);

	//Calculate V parameter and test bound
	v = dot(ray->direction, Q) * inv_det;
	//The intersection lies outside of the triangle
	if (v < 0.0f || u + v  > 1.0f) 
		return -1.0f;

	t = dot(e2, Q) * inv_det;

	if (t > epsilon) { //ray intersection
		ray->ip.uvw = vec3(u, v, 1.0f - u - v);
		return t;
	}

	return 0.0f;
}

vec3 Triangle::getNormal(Ray * ray)
{
	return ray->ip.uvw.z*n0 + ray->ip.uvw.x*n1 + ray->ip.uvw.y*n2;
}

float Plane::intersect(Ray * ray)
{
	return 0.0f;
}