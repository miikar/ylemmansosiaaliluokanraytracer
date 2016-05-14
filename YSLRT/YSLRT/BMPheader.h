struct BMPFILEHEADER
{
	__int16 bfType = 19778;
	__int32 bfSize;
	__int16 bfReserved1 = 0;
	__int16 bfReserved2 = 0;
	__int32 bfOffBits = 68;
}bmfh;


struct BMPINFOHEADER
{
	__int16 biSize = 40;
	__int16 biWidth;
	__int16 biHeight;
	__int16 biPlanes = 1;
	__int16 biBitCount = 24;
	__int16 biCompression = 0;
	__int16 biSizeImage;
	__int16 biXPelsPerMeter;
	__int16 biYPelsPerMeter;
	__int16 biClrUsed = 0;
	__int16 biClrImportant = 0;
}bmih;