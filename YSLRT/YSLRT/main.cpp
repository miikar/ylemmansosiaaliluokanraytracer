
#include "Raytracer.hpp"

int main(void)
{
	Raytracer rt(1980, 1080);
	rt.calculatePixels();
	rt.dataToFile("yslrt");
	return 0;
}