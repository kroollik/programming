#include <iostream>
#include <cmath>
#include <iomanip>
#include "факториал.h"
#include "Тейлор.h"
#include "сочетания.h"
	using namespace std;
	int main() {
		const double PI = 3.141592653589793;
		const int K = 5; // количество членов разложения 
		const int K1 = 10; // крайнее значение диапозона для расчета количесвта сочетаний
		setlocale(LC_ALL, "Russian");
		cout << "Введите число, факториал которого хотите посчитать: ";
		int n, n1;
		double x;
		cin >> n;
		cout << 'n' << "	" << "n!" << endl;
		for (int i = 1; i <= n; i++)
			cout << i << "	" << f(i) << endl;
		cout << " " << endl;
		cout << "Введите число синус которого хотите узнать: ";
		cin >> x;
		cout << 'x' << "	" << "sin(x)" << endl;
		for (double i = 0; i < 46 * (PI / 180); i += (PI / 180)) {
			cout << setprecision(4) << i << "	" << sinx(i, K) << endl;
		}
		cout << "Введите число, чтобы узнать количество сочетаний: ";
		cin >> n1;
		cout << 'k' << "	" << "C(k,10)" << endl;
		for (int i = 1; i <= n1; i++)
			cout << i << "	" << C(K1, i ) << endl;




	return 0;
}


