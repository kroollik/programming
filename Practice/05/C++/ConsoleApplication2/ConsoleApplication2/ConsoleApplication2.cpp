#include<iostream>;
using namespace std;
int main() {
	double x, x0, v0, t, a;
	cin >> x0 >> v0 >> t;
	a = 9.8;
	//неправильный вариант записи
	x = x0 + v0 * t + 1 / 2 * a * t * t;
	cout << x << endl;
	// правильный вариант записи
	x = x0 + v0 * t + a * t * t / 2;
	cout << x;
	return 0;
}