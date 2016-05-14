#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "Primitives.hpp"
#include "Raytracer.hpp"
#include "BMPheader.h"

void Raytracer::calculatePixels(void){
	using namespace glm;
	vec2 resolution = vec2((float)width, (float)height);

	for (int x = 0; x < width; x++){
		for (int y = 0; y < height; y++){		

			/* RAYTRACING STARTS HERE */
			vec2 pIndex = vec2((float)x, (float)y);							 /* Current pixel (x,y) */
			vec2 uv = pIndex/resolution;									/* Pixel coordinates uv [0.0,1.0] */
			vec2 p = uv*2.0f - 1.0f;										 /* Pixel coordinates p [-1.0,1.0] */
			p.x *= resolution.x / resolution.y;								 /* Adjust p to aspect ratio */
			vec3 c = vec3(0.0f, 0.0f, -1.0f);
			Ray ray(c, vec3(p,0.0f)-c);

			vec3 color = vec3(1.0f);

			for (auto &i : *map)
			{
				if (i->intersect(ray) > 0.0f)
				{
					color = vec3(0.4f, 0.6f, 0.7f);
				}
			}
			
			color = clamp(color, 0.0f, 1.0f);
			pixelData[x+width*y] = color;
		}
	}
}

void Raytracer::dataToFile(std::string path) {
	FILE *f;
	unsigned char r, g, b;
	unsigned char pad[3] = { 0, 0, 0};
	int padSize = (4 - (width * 3) % 4) % 4;

	// Set bmfh
	bmfh.bfSize = width * height * 3 + 54;

	// Set bmih
	bmih.biWidth = width;
	bmih.biHeight = height;
	bmih.biSizeImage = width * height * 3;
	bmih.biXPelsPerMeter = 0;
	bmih.biYPelsPerMeter = 0;

	unsigned char fileheader[14];
	unsigned char infoheader[40];

	memcpy(fileheader, &bmfh, 14);
	memcpy(infoheader, &bmih, 40);
	errno_t erno;
	erno = fopen_s(&f,"img.bmp", "wb");
	if (erno != 0)
		fprintf(stderr, "erno %d apuva!\n", erno);
	fwrite(fileheader, 1, 14, f);
	fwrite(infoheader, 1, 40, f);
	// Write pixelData
	for (int y = height-1; y >= 0; y--) {
		for (int x = 0; x < width; x++) {
			r = (unsigned char)(pixelData[x + width*y].r * 255.0f);
			g = (unsigned char)(pixelData[x + width*y].g * 255.0f);
			b = (unsigned char)(pixelData[x + width*y].b * 255.0f);
			fwrite(&r, 1, 1, f);
			fwrite(&g, 1, 1, f);
			fwrite(&b, 1, 1, f);
		}
		fwrite(pad, 1, padSize, f);
	}

	fclose(f);
}