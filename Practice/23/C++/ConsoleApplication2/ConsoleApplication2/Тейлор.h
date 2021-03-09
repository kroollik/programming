#include "факториал.h"
#ifndef Ряд_Тейлора
#define Ряд_Тейлора

double sinx(double x, int k) {
	for (int i = 1; i <= k; i++) 
		x = x + pow((-1), i) * pow(x, ((2 * i) + 1)) / f((2 * i) + 1);
		return x;
	}
#endif;
