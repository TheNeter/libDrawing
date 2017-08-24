#include "main.h"

#if defined(__cplusplus)
#endif

extern "C" void Init(void)
{
	FBFile  = open("/dev/fb0", O_RDWR);
	if (ioctl(FBFile, FBIOGET_VSCREENINFO, &info) == -1) {
		perror("Error reading variable information");
		exit(3);
	}
	info.bits_per_pixel = 32;
	info.xres = 800;
	info.yres = 480;
	info.xres_virtual = 800;
	info.yres_virtual = 480;
	info.grayscale = 0;
	if (ioctl(FBFile, FBIOPUT_VSCREENINFO, &info) == -1) {
		perror("Error reading variable information");
		exit(3);
	}
	if (ioctl(FBFile, FBIOGET_FSCREENINFO, &finfo) == -1) {
		perror("Error reading fixed information");
		exit(3);
	}
	ScreenSize = info.xres * info.yres * info.bits_per_pixel / 8;
	FBMap = (char*)mmap(0, ScreenSize, PROT_READ | PROT_WRITE, MAP_SHARED, FBFile, 0);
}

extern "C" int Width()
{
	return info.xres;
}
extern "C" int Height()
{
	return info.bits_per_pixel;
}

extern "C" void DrawPixel(int x, int y, char r, char g, char b)
{
	long location = (long)((x + info.xoffset) * (info.bits_per_pixel / 8) + (y + info.yoffset) * finfo.line_length);
	uint32_t cColor = r << 16 | g << 8 | b;
	*((uint32_t*)(FBMap + location)) = cColor;
}

