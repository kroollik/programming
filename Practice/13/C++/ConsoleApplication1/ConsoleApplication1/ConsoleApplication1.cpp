#include<iostream>;
#include<cmath>;
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите одно целое число от 2 до 10^9 ";
	int n;
	cin >> n;
	if ((n > 1) && (n <=(pow(10,9)))) {
		if ((n % 2 == 0) || (n % 3 == 0) || (n % 5 == 0) || (n % 7 == 0) && ((n != 2) && (n != 3) && (n != 5) && (n != 7))) {
			cout << "Составное";
		}
		else {
			cout << "Простое";
		}
	}
	return 0;
}

