#include<iostream>;
using namespace std;
int main() {
	int a, b;
	double a1, b1;
	cin >> a;
	cin >> b;
	cin >> a1;
	cin >> b1;
	cout << "Int+Int = " << a + b << ' ';
	cout << "Int-Int = " << a - b << ' ';
	cout << "Int*Int = " << a * b << ' ';
	cout << "Int/Int = " << a / b << endl;
	cout << "Double+Double = " << a1 + b1 << ' ';
	cout << "Double-Double = " << a1 - b1 << ' ';
	cout << "Double*Double = " << a1 * b1 << ' ';
	cout << "Double/Double = " << a1 / b1 << endl;
	cout << "Int+Double = " << a + a1 << ' ';
	cout << "Int-Double = " << a - a1 << ' ';
	cout << "Int*Double = " << a * a1 << ' ';
	cout << "Int?Double = " << a / a1 << endl;
	cout << "Double+Int = " << b1 + b << ' ';
	cout << "Double-Int = " << b1 - b << ' ';
	cout << "Double*Int = " << b1 * b << ' ';
	cout << "Double/Int = " << b1 / b << endl;
	return 0;


}