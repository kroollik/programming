#include "факториал.h"
#ifndef сочетания
#define сочетания

double C( int n, int k) {
	double c;
	for (int i = 1; i <= k; i++)
		c = f(n) / (f(k) * f(n - k));
	return c;
}
#endif;