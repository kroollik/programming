#include<iostream>;
#include<cmath>;
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	float a,k;
	int b, i;
	cout << "Введите число возводимое в степень ";
	cin >> a;
	cout << "Введите степень числа ";
	cin >> b;
	if (b == 0) {
		cout << "Результат работы программы " << 1;
		return 0;
	}
	else {
		if (b == 1) {
			cout << "Результат работы программы " << a;
			return 0;
		}
		else {
			if (a == 1) {
				cout << "Результат работы программы " << a;
				return 0;
			}
		}
	}
	k = 1;
	if (b > 0) {
		for (i = 1; i <= b; i++)
			k = k * a;

		cout << k;
	}
	else {
		if (b < 0) {
			for (i = 1; i <= abs(b); i++)
				k = k * (1 / a);
			cout << k;
		}
	}
	return 0;
}
