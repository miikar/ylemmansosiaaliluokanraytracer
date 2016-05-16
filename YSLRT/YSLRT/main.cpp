
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
	Triangle tri1(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.5, -0.5f, -0.5f), glm::vec3(0.7f, 0.3f, 0.4f));
	Triangle tri2(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.7f, 0.3f, 0.4f));
	Triangle tri3(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.7f, 0.3f, 0.4f));
	Triangle tri4(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.7f, 0.3f, 0.4f));
	Sphere sph(glm::vec3(0.0f, 0.75f, 0.0f), 0.25f, glm::vec3(0.8f,0.5f,0.3f));
	Sphere sph2(glm::vec3(-0.75f, -0.25f, 0.0f), 0.25f, glm::vec3(0.5f, 0.8f, 0.3f));
	Plane pln1(glm::vec3(0.0f,1.0f,0.0f), glm::vec3(0.0f,-0.5f,0.0f), glm::vec3(0.1f,0.2f,0.3f));
	Plane pln2(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.1f, 0.2f, 0.3f));

	map.push_back(&tri1);
	map.push_back(&tri2);
	map.push_back(&tri3);
	map.push_back(&tri4);
	map.push_back(&sph);
	map.push_back(&sph2);
	map.push_back(&pln1);
	map.push_back(&pln2);

	Raytracer rt(1980, 1080);
	rt.setMap(&map);
	rt.calculatePixels();
	rt.dataToFile("yslrt");

	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	ElapsedMicroseconds.QuadPart *= 1000000;
	ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
	time = (double) (ElapsedMicroseconds.QuadPart / 1000000ll);
	time += ((double)(ElapsedMicroseconds.QuadPart % 1000000ll)) / 1000000.0;
	
	std::cout << std::setprecision(7)<< "Image rendered in " << time << " seconds." << std::endl;
	return 0;
}