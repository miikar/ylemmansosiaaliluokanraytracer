#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "Raytracer.hpp"

void Raytracer::dataToFile(std::string path) {
	// BMPFILEHEADER
	// BMPINFOHEADER

	unsigned char bmpfileheader[14];
	unsigned char bmpinfoheader[54];

	FILE *f;
	f = fopen("img.bmp", "w");
	fclose(f);
	Ray ray(glm::vec3(1.0f), glm::vec3(1.0f));
	ray.direction;
	ray.origin;
}