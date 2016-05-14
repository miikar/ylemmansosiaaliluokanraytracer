#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "Raytracer.hpp"

Raytracer::Raytracer(int w, int h){
	width = w;
	height = h;
}

void Raytracer::calculatePixels(){
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			pixelData[x][y] = glm::vec3(0.5f, 0.5f, 0.5f);
		}
	}
}

void Raytracer::dataToFile(std::string path){

}
