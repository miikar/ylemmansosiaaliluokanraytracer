#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

class Raytracer
{
public:
	Raytracer(int w, int h) : pixelData(w * h), width(w), height(h){}
	void calculatePixels(void); 
	void dataToFile(std::string path); 
private:
	std::vector<glm::vec3> pixelData;	/* 1D ARRAY, W*H INDICES - Access [i][j] with [i+width*j] */
	int width;
	int height;
};

class Ray
{
public:
	Ray(glm::vec3 origin, glm::vec3 direction) : origin(origin), direction(direction){}
	glm::vec3 origin;    
	glm::vec3 direction; /* Unit vector */
};


#endif
