#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

class Sphere {
public:
	Sphere(glm::vec3 center, glm::vec3 radius);

	double intersect(Ray ray);
private:
	glm::vec3 c;
	glm::vec3 r;
};

#endif
