#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include <vector>
#include "Ray.hpp"
#include "Primitives.hpp"

class Raytracer
{
public:
	Raytracer(int w, int h) : pixelData(w * h), width(w), height(h){}
	void setMap(std::vector<Primitive*> *inMap){ map = inMap; }
	void calculatePixels(void); 
	void dataToFile(std::string path); 
private:
	std::vector<glm::vec3> pixelData;	/* 1D ARRAY, W*H INDICES - Access [i][j] with [i+width*j] */
	std::vector<Primitive*> *map;
	int width;
	int height;
};

#endif
