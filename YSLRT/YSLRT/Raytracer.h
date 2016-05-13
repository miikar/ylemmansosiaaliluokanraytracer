#ifndef RAYTRACER_H
#define RAYTRACER_H

class Raytracer
{
public:
	void calculatePixels(int w, int h); // w*h resolution
	void dataToFile(std::string path);
private:
	std::vector<std::vector<int>> pixelData;
};

#endif RAYTRACER_H
