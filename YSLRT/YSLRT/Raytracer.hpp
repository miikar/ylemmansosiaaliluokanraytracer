#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

class Raytracer
{
public:
	Raytracer::Raytracer();
	void calculatePixels(int w, int h); // w*h resolution
	void dataToFile(std::string path); 
private:
	std::vector<std::vector<glm::vec3>> pixelData;
};

class Ray
{
public:
	Ray::Ray(glm::vec3 origin, glm::vec3 direction) : origin(origin), direction(direction){}
	glm::vec3 origin;
	glm::vec3 direction;
};


#endif
