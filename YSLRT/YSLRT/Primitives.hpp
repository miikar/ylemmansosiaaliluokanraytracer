#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include "Ray.hpp"

class Primitive {
public:
	Primitive(){}									// TÄHÄN CLASSIIN VOIS SIT LISÄTÄ KAIKENLAISIA PINNAN OMINAISUUKSIA 
	virtual float intersect(Ray ray) = 0;			// KUTEN VÄRIN JA MITEN VALO KÄYTTÄYTYY NIIDEN KANSSA
};

class Sphere: public Primitive {
public:
	Sphere(glm::vec3 center, float radius) : c(center), r(radius){}
	float intersect(Ray ray);
private:
	glm::vec3 c; /* Center point */
	float r; /* Radius */
};

class Triangle: public Primitive {
public:
	Triangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2) : v0(v0), v1(v1), v2(v2){}
	float intersect(Ray ray);
private:
	glm::vec3 v0, v1, v2; /* 3 vertices of the triangle */
};

class Plane: public Primitive {
public:
	Plane(glm::vec3 n) : n(n){}
	float intersect(Ray ray);
private:
	glm::vec3 n; /* Plane normal */
};

#endif
