#include<iostream>;
#include<cmath>;
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	float a, b;
	char c;
	cout << "Введите 'вещественное число','знак операции','вещественное число'" << endl;
	cin >> a >> c >> b;
	if (c == '+') {
		cout << a + b;
	}
	else {
		if (c == '-') {
			cout << a - b;
		}
		else {
			if (c == '*') {
				cout << a * b;
			}
			else {
				if (c == '/' && b !=0) {
					cout << a / b;
				}
				else {
					if (b == 0) {
						cout << "ОШИБКА деление на 0";
					}

				}
			}
		}
	}
	return 0;

}
