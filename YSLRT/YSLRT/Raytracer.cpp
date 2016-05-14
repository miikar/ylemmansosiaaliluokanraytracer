#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "Raytracer.hpp"
#include "BMPheader.h"

void Raytracer::calculatePixels(void){
	for (int x = 0; x < width; x++){
		for (int y = 0; y < height; y++){
			using namespace glm;
			static vec2 resolution = vec2((float)width, (float)height);

			/* RAYTRACING STARTS HERE */

			vec2 pIndex = vec2((float)x, (float)y);							  /* Current pixel (x,y) */
			vec2 uv = vec2(pIndex.x / resolution.x, pIndex.x / resolution.y); /* Pixel coordinates uv [0.0,1.0] */
			vec2 p = uv*2.0f - 1.0f;										  /* Pixel coordinates p [-1.0,1.0] */
			p.x *= resolution.x / resolution.y;								  /* Adjust p to aspect ratio */

			vec3 color = vec3(1.0f*p.y);
			

			clamp(color, 0.0f, 1.0f);
			pixelData[x+width*y] = color;
		}
	}
}

void Raytracer::dataToFile(std::string path) {
	// BMPFILEHEADER
	// BMPINFOHEADER

	struct BMPFILEHEADER bmfh;
	struct BMPINFOHEADER bmih;

	// Set bmfh
	bmfh.bfSize = width * height * 3 + 68;

	// Set bmih
	bmih.biWidth = width;
	bmih.biHeight = height;
	bmih.biSizeImage = width * height * 3;

	bmih.biXPelsPerMeter = 0;
	bmih.biYPelsPerMeter = 0;

	// Image


	FILE *f;
	f = fopen("img.bmp", "w");
	fclose(f);
}