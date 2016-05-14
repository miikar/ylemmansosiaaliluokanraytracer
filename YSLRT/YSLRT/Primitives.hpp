#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

class Sphere {
public:
	Sphere(glm::vec3 center, glm::vec3 radius) : c(center), r(radius){}
	float intersect(Ray ray);
private:
	glm::vec3 c;
	glm::vec3 r;
};

class Triangle {
public:
	Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c) : a(a), b(b), c(c){}
	float intersect(Ray ray);
private:
	glm::vec3 a, b, c;
};

#endif
