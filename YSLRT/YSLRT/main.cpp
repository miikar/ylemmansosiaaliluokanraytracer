
#include <vector>
#include <iostream>
#include <iomanip>
#include <glm/glm.hpp>
#include <Windows.h>
#include "Primitives.hpp"
#include "Raytracer.hpp"

int main(void)
{
	double time;
	LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
	LARGE_INTEGER Frequency;

	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&StartingTime);


	std::vector<Primitive*> map;
	Triangle tri(glm::vec3(0.0f,0.5f,1.0f), glm::vec3(0.5f,0.0f,1.0f), glm::vec3(-0.5,0.0f,1.0f));
	map.push_back(&tri);
	Raytracer rt(1980, 1080);
	rt.setMap(&map);
	rt.calculatePixels();
	rt.dataToFile("yslrt");

	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	ElapsedMicroseconds.QuadPart *= 1000000;
	ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
	time = ElapsedMicroseconds.QuadPart / 1000000;
	time += ((double)(ElapsedMicroseconds.QuadPart % 1000000)) / 1000000.0;
	
	std::cout << std::setprecision(7)<< "Image rendered in " << time << " seconds." << std::endl;
	return 0;
}