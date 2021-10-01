// TriangleLibrary.h - Contains declarations of math functions
#pragma once

#ifdef TRIANGLELIBRARY_EXPORTS
#define TRIANGLELIBRARY_API __declspec(dllexport)
#else
#define TRIANGLELIBRARY_API __declspec(dllimport)
#endif

extern "C" TRIANGLELIBRARY_API bool similar_triangles(
	int a11, int a12,
	int a21, int a22,
	int a31, int a32,
	int b11, int b12,
	int b21, int b22,
	int b31, int b32);