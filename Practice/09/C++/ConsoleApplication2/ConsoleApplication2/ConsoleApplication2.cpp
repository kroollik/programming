#include<iostream>;
#include<cmath>;
#include<stdlib.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int h1, m1, h2, m2;
	char c;
	cin >> h1 >> c >> m1;
	if (h1 < 0 || h1 > 24 || m1 < 0 || m1 > 60) {
		cout << "Ошибка ввода" << endl;
		return 0;
	}
	cin >> h2 >> c >> m2;
	if (h2 < 0 || h2 > 24 || m2 < 0 || m2 > 60) {
		cout << "Ошибка ввода" << endl;
		return 0;
	}
	if (((h2 - h1 == 0) && (m2 - m1 <= 15)) || ((h2 - h1 == 1) && (m2 - m1 == -45)) || ((h2 - h1 == -23) && (m2 - m1 == -45))) {
		cout << "Встреча состоится" << endl;
	}
	else {
		cout << "Встреча не состоится" << endl;
	}

	return 0;
	}
