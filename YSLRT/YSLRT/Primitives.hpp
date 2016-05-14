#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

class Primitive {
public:
	Primitive();									// T�H�N CLASSIIN VOIS SIT LIS�T� KAIKENLAISIA PINNAN OMINAISUUKSIA 
	virtual float intersect(Ray ray) = 0;			// KUTEN V�RIN JA MITEN VALO K�YTT�YTYY NIIDEN KANSSA
};

class Sphere: public Primitive {
public:
	Sphere(glm::vec3 center, glm::vec3 radius) : c(center), r(radius){}
	float intersect(Ray ray);
private:
	glm::vec3 c; /* Center point */
	glm::vec3 r; /* Radius */
};

class Triangle: public Primitive {
public:
	Triangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2) : v0(v0), v1(v1), v2(v2){}
	float intersect(Ray ray);
private:
	glm::vec3 v0, v1, v2; /* 3 vertices of the triangle */
};

#endif
