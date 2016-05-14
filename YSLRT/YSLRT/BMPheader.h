#include <stdint.h>

#pragma pack(push)
#pragma pack(1)

struct BMPFILEHEADER
{
	uint16_t bfType = 19778;
	uint32_t bfSize;
	uint16_t bfReserved1 = 0;
	uint16_t bfReserved2 = 0;
	uint32_t bfOffBits = 54;
}bmfh;


struct BMPINFOHEADER
{
	uint32_t biSize = 40;
	uint32_t biWidth;
	uint32_t biHeight;
	uint16_t biPlanes = 1;
	uint16_t biBitCount = 24;
	uint32_t biCompression = 0;
	uint32_t biSizeImage;
	uint32_t biXPelsPerMeter;
	uint32_t biYPelsPerMeter;
	uint32_t biClrUsed = 0;
	uint32_t biClrImportant = 0;
}bmih;

#pragma pack(pop) 