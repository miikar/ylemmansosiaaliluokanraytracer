
#include <vector>
#include "Primitives.hpp"
#include "Raytracer.hpp"

int main(void)
{
	std::vector<Primitive> map;
	Raytracer rt(1980, 1080);
	rt.setMap(&map);
	rt.calculatePixels();
	rt.dataToFile("yslrt");
	return 0;
}