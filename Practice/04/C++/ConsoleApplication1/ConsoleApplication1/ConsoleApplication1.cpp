#include<iostream>;
using namespace std;
int main(){
	// первый способ
	int a, b, c, a1, b1;
	cin >> a;
	cin >> b;
	c = b;
	b = a;
	a = c;
	cout << "a = " << a << ' ';
	cout << "b = " << b << endl;
	// второй способ
	cin >> a1;
	cin >> b1;
	a1 = a1 + b1;
	b1 = a1 - b1;
	a1 = a1 - b1;
	cout << "a1 = " << a1 <<' ';
	cout << "b1 = " << b1 << endl;

	return 0;

}
