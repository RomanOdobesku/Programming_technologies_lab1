// TriangleLibrary.cpp : Defines the exported functions for the DLL.
#include "stdafx.h"
#include "TriangleLibrary.h"
#include <cmath>
#include <algorithm>
#include <iostream>

bool is_sim(long sample[], long triangle[]) {
	if (sample[0] * triangle[1] != sample[1] * triangle[0]) {
		return false;
	}
	else if (sample[0] * triangle[2] != sample[2] * triangle[0]) {
		return false;
	}
	else if (sample[1] * triangle[2] != sample[2] * triangle[1]) {
		return false;
	}
	else {
		return true;
	}
}

bool similar_triangles(
	int a11, int a12,
	int a21, int a22,
	int a31, int a32,
	int b11, int b12,
	int b21, int b22,
	int b31, int b32)
{
	long first_triangle_length_square[3];
	long second_triangle_length_square[3];

	first_triangle_length_square[0] = (a21 - a11)*(a21 - a11) + (a22 - a12)*(a22 - a12);
	first_triangle_length_square[1] = (a31 - a11)*(a31 - a11) + (a32 - a12)*(a32 - a12);
	first_triangle_length_square[2] = (a31 - a21)*(a31 - a21) + (a32 - a22)*(a32 - a22);
	std::sort(first_triangle_length_square, first_triangle_length_square + 3);
	//std::sort(std::begin(first_triangle_length_square), std::end(first_triangle_length_square));

	second_triangle_length_square[0] = (b21 - b11)*(b21 - b11) + (b22 - b12)*(b22 - b12);
	second_triangle_length_square[1] = (b31 - b11)*(b31 - b11) + (b32 - b12)*(b32 - b12);
	second_triangle_length_square[2] = (b31 - b21)*(b31 - b21) + (b32 - b22)*(b32 - b22);
	std::sort(second_triangle_length_square, second_triangle_length_square + 3);
	//std::sort(std::begin(second_triangle_length_square), std::end(second_triangle_length_square));

	return is_sim(first_triangle_length_square, second_triangle_length_square);
}