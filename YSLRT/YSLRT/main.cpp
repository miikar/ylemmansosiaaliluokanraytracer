
#include <vector>
#include <glm/glm.hpp>
#include "Primitives.hpp"
#include "Raytracer.hpp"

int main(void)
{
	std::vector<Primitive> map;
	Sphere sp(glm::vec3(0.0f), 0.5f);
	map.push_back(sp);

	Raytracer rt(1980, 1080);
	rt.setMap(&map);
	rt.calculatePixels();
	rt.dataToFile("yslrt");
	return 0;
}