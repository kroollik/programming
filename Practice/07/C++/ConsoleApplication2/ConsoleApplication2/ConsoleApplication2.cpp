#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	float a, b, c, x1, x2, x3, y1, y2, y3, p, S;
	int count;
	cout << "1 - ввод параметров треугольника через длины сторон или 2 - ввод параметров через координаты вершин" << endl;
	cin >> count;
	if (count == 1) {
		cout << "Введите a = ";
		cin >> a;
		cout << "Введите b = ";
		cin >> b;
		cout << "Введите c = ";
		cin >> c;
		if (a > 1000 || b > 1000 || c > 1000 || a <= 0 || b<=0 || c<=0) {
			cout << "Ошибочный ввод";
		}
		p = (a + b + c) / 2;
		S = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "S = " << S;
	}
	else {
		if (count == 2) {
			cout << "Введите x1 y1 ";
			cin >> x1 >> y1;
			cout << "Введите x2 y2 ";
			cin >> x2 >> y2;
			cout << "Введите x3 y3 ";
			cin >> x3 >> y3;
			a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
			b = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
			c = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
			if (a > 1000 || b > 1000 || c > 1000 || a <= 0 || b <= 0 || c <= 0) {
				cout << "Ошибочный ввод";
			}
			p = (a + b + c) / 2;
			S = sqrt(p * (p - a) * (p - b) * (p - c));
			cout << "S = " << S;
		}
		else {
			if (!(count == 1) || !(count == 2)) {
				cout << "Ошибочный ввод" << endl;
				
			}
		}
	}
	
	return 0;
}