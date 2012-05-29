#ifndef LOADV3DFFMPEG_H
#define LOADV3DFFMPEG_H

#ifdef USE_FFMPEG

#include "../../v3d/v3d_core.h" // Image4DSimple
#include <iostream>

bool loadStackFFMpeg(const char* fileName, Image4DSimple& image);
bool loadStackFFMpegAsGray(const char* fileName, Image4DSimple& img);
bool saveStackFFMpeg(const char * fileName, const My4DImage& img);

#endif // USE_FFMPEG

#endif // LOADV3DFFMPEG_H
