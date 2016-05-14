
#include <vector>
#include <glm/glm.hpp>
#include "Primitives.hpp"
#include "Raytracer.hpp"

int main(void)
{
	std::vector<Primitive*> map;
	Triangle tri(glm::vec3(0.0f,0.5f,1.0f), glm::vec3(0.5f,0.0f,1.0f), glm::vec3(-0.5,0.0f,1.0f));
	map.push_back(&tri);

	Raytracer rt(1980, 1080);
	rt.setMap(&map);
	rt.calculatePixels();
	rt.dataToFile("yslrt");
	return 0;
}