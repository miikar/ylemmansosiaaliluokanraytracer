#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

class Raytracer
{
public:
	void calculatePixels(int w, int h); // w*h resolution
	void dataToFile(std::string path); 
private:
	std::vector<std::vector<glm::vec3>> pixelData;
};

#endif
