#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "Primitives.hpp"
#include "Raytracer.hpp"
#include "BMPheader.h"

void Raytracer::calculatePixels(void){
	using namespace glm;
	vec2 resolution = vec2((float)width, (float)height)-1.0f;

	vec3 ang = vec3(3.14f*0.25f, 3.14f*0.5f, 0.0f);
	mat3 x = mat3(1.0, 0.0, 0.0, 0.0, cos(ang.x), -sin(ang.x), 0.0, sin(ang.x), cos(ang.x));
	mat3 y = mat3(cos(ang.y), 0.0, sin(ang.y), 0.0, 1.0, 0.0, -sin(ang.y), 0.0, cos(ang.y));
	mat3 z = mat3(cos(ang.z), -sin(ang.z), 0.0, sin(ang.z), cos(ang.z), 0.0, 0.0, 0.0, 1.0);
	mat3 rot = x*y*z;

	#pragma omp parallel for
	for (int x = 0; x < width; x++){
		for (int y = 0; y < height; y++){		

			/* RAYTRACING STARTS HERE */
			vec2 pIndex = vec2((float)x, (float)y);							 /* Current pixel (x,y) */
			vec2 uv = pIndex/resolution;									/* Pixel coordinates uv [0.0,1.0] */
			vec2 p = uv*2.0f - 1.0f;										 /* Pixel coordinates p [-1.0,1.0] */
			p.x *= resolution.x / resolution.y;								 /* Adjust p to aspect ratio */

			float z = -2.0f;
			vec3 c = vec3(0.0f, 0.0f, z-2.0f);								/* camera position*/
			Ray ray(c*rot, normalize(vec3(p, z) - c)*rot);				/* ray origin and direction */

			vec3 color = vec3(1.0f);
			float t;
			float tMin = 1000.0f;
			Primitive * closest = nullptr;
			for (auto i : *map)
			{
				t = i->intersect(&ray);
				if (t > 0.0f && t < tMin)
				{
					tMin = t;
					closest = i;
				}
			}
			if (closest != nullptr)
			{
				ray.ip.xyz = ray.origin + tMin*ray.direction;
				color = closest->color;
				vec3 ld = normalize(vec3(-1.0f, 0.75f, 1.0f)-ray.ip.xyz);
				color *= dot(ld, closest->getNormal(&ray));
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

	errno_t erno;
	erno = fopen_s(&f, path.append(".bmp").c_str(), "wb");
	if (erno != 0)
		fprintf(stderr, "erno %d apuva!\n", erno);
	fwrite(&bmfh, 1, 14, f);
	fwrite(&bmih, 1, 40, f);
	// Write pixelData
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			r = (unsigned char)(pixelData[x + width*y].r * 255.0f);
			g = (unsigned char)(pixelData[x + width*y].g * 255.0f);
			b = (unsigned char)(pixelData[x + width*y].b * 255.0f);
			fwrite(&b, 1, 1, f);
			fwrite(&g, 1, 1, f);
			fwrite(&r, 1, 1, f);
		}
		fwrite(pad, 1, padSize, f);
	}

	fclose(f);
}