// TriangleClient.cpp : Client app for TriangleLibrary DLL.
#include "pch.h"
#include <iostream>
#include <string>
#include "TriangleLibrary.h"

using namespace std;


bool check2(string s) { //проверка на int
	int minuses = 0;
	bool ans = true;
	for (int j = 0; j < s.length(); ++j) {
		if (s[j] == '-') minuses++;
		if (!((s[j] >= '0' && s[j] <= '9') || s[j] == '-') || minuses > 1) {
			ans = false;
		}
	}
	if (minuses == 1 && s[0] != '-') {
		ans = false;
	}
	return ans;
}
string s1;
long in(string message) {
	cout << message;
	long ans;
	cin >> s1;
	if (check2(s1)) {
		return atoll(s1.c_str());
	}
	else {
		cout << "Error, try again" << endl;
		in(message);
	}
}

int main()
{
	int a11, a12, a21, a22, a31, a32, b11, b12, b21, b22, b31, b32;

	a11 = in("Enter a11 >> ");
	a12 = in("Enter a12 >> ");
	a21 = in("Enter a21 >> ");
	a22 = in("Enter a22 >> ");
	a31 = in("Enter a31 >> ");
	a32 = in("Enter a32 >> ");

	b11 = in("Enter b11 >> ");
	b12 = in("Enter b12 >> ");
	b21 = in("Enter b21 >> ");
	b22 = in("Enter b22 >> ");
	b31 = in("Enter b31 >> ");
	b32 = in("Enter b32 >> ");
	

	if (similar_triangles(
		a11, a12,
		a21, a22,
		a31, a32,
		b11, b12,
		b21, b22,
		b31, b32 )) {
		std::cout << "YES" << std::endl;
	} else std::cout << "NO" << std::endl;
}