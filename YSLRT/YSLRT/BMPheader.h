#pragma pack(push)
#pragma pack(1) 

struct BMPFILEHEADER
{
	__int16 bfType = 19778;
	__int32 bfSize;
	__int16 bfReserved1 = 0;
	__int16 bfReserved2 = 0;
	__int32 bfOffBits = 54;
}bmfh;


struct BMPINFOHEADER
{
	__int32 biSize = 40;
	__int32 biWidth;
	__int32 biHeight;
	__int16 biPlanes = 1;
	__int16 biBitCount = 24;
	__int32 biCompression = 0;
	__int32 biSizeImage;
	__int32 biXPelsPerMeter;
	__int32 biYPelsPerMeter;
	__int32 biClrUsed = 0;
	__int32 biClrImportant = 0;
}bmih;

#pragma pack(pop) 