#pragma once
int f(int k) {
	int h = 1;
	for (int i = 1; i <= k; i++) {
		h = h * i;
	}
	k = h;

	return k;
}
