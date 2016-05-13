
#include "Raytracer.hpp"

int main(void)
{
	Raytracer rt;
	rt.calculatePixels(1980,1080);
	rt.dataToFile("yslrt");
	return 0;
}