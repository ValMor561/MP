#pragma once

#include <iostream>
#include <list>
struct TPare
{
	int v1, v2;
	TPare(int _v1 = 0, int _v2 = 0) : v1(_v1), v2(_v2) { }
	void operator = (int* val) {
		v1 = val[0];
		v2 = val[1];
	}
	bool operator == (TPare& pare) {
		return v1 == pare.v1 && v2 == pare.v2;
	}
	friend std::ostream& operator<<(std::ostream& r, TPare& pare) {
		r << "(" << pare.v1 << "," << pare.v2 << ")";
		return r;
	}
};

int RoundDFS(std::list<int>* L, std::list<TPare>* T, int n);