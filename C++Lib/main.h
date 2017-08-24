#pragma once
#include <cstdio>
#include <linux/fb.h>
#include <linux/input.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <pthread.h>
#include <iostream>
#include <algorithm>
#include <linux/kd.h>
#include <cstring>

fb_var_screeninfo info;
fb_fix_screeninfo finfo;
char* FBMap;
char* FBSwapMap;
int FBFile;
long ScreenSize;
extern "C" void Init(void);
extern "C" int Width(void);
extern "C" int Height(void);
extern "C" void DrawPixel(int x, int y, char r, char g, char b);