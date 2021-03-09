#include <iostream>;
#include <cmath>;
using namespace std;
int main() {
	setlocale (LC_ALL, "Russian");
	float a, b, c, x, D, x1, x2;
	cout << "Введите a, b, c" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	D = b*b - 4 * a * c;
	if (a == 0 && b == 0 && c == 0){
		cout << "Корнем уравнения является любое число" << endl;
	}
	else {
		if (b == 0 && a == 0) {
			cout << "Нет корней" << endl;
		}
		else {
			if (a == 0) {
				x = ((-c) / b);
				cout << "x = " << x;
			}
			else {
				if (D > 0) {
					x1 = (-b + sqrt(D)) / (2 * a);
					x2 = (-b - sqrt(D)) / (2 * a);
					cout << "x1 = " << x1 << endl;
					cout << "x2 = " << x2 << endl;
				}
				else {
					if (D == 0) {
						x = (-b) / (2 * a);
						cout << "x = " << x;
					}
					else {
						if (D < 0) {
							cout << "Нет действительных корней";
						}
					}

				}
			}
		}
	}
		return 0;
   }