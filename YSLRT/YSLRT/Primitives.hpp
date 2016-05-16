#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include "Ray.hpp"

class Primitive {
public:
	Primitive(glm::vec3 color) : color(color){}		// TÄHÄN CLASSIIN VOIS SIT LISÄTÄ KAIKENLAISIA PINNAN OMINAISUUKSIA 
	virtual float intersect(Ray *ray) = 0;			// KUTEN VÄRIN JA MITEN VALO KÄYTTÄYTYY NIIDEN KANSSA
	virtual glm::vec3 getNormal(Ray *ray) = 0;
	glm::vec3 color;
};

class Sphere: public Primitive {
public:
	Sphere(glm::vec3 center, float radius, glm::vec3 color) : Primitive(color), c(center), r(radius){}
	float intersect(Ray *ray);
	glm::vec3 getNormal(Ray *ray); /* CALL ONLY AFTER FINDING AN INTERSECTION */
private:
	glm::vec3 c; /* Center point */
	float r; /* Radius */
};

class Triangle: public Primitive {
public:
	Triangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2, glm::vec3 color);
	Triangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2, 
			 glm::vec3 n0, glm::vec3 n1, glm::vec3 n2, glm::vec3 color): 
			 Primitive(color), v0(v0), v1(v1), v2(v2), 
							   n0(n0), n1(n1), n2(n2)	{}
	float intersect(Ray *ray);
	glm::vec3 getNormal(Ray *ray);
private:
	glm::vec3 v0, v1, v2; /* 3 vertices of the triangle */
	glm::vec3 n0, n1, n2; /* per vertex normals */
};

class Plane: public Primitive {
public:
	Plane(glm::vec3 n, glm::vec3 p0, glm::vec3 color) : Primitive(color), n(normalize(n)), p0(p0){}
	float intersect(Ray *ray);
	glm::vec3 getNormal(Ray *ray){ return n; }
private:
	glm::vec3 n; /* Plane normal */
	glm::vec3 p0; 
};

#endif
