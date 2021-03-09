#include<iostream>;
#include<cmath>;
using namespace std;
int main (){
	setlocale(LC_ALL, "Russian");
	int n, i;
	cout << "Введите целое число от 0 до 10^15 ";
	cin>> n;
	i = 0;
	if ((n > 0) && (n < pow(10, 15))) {
		while (n > 0) {
			n = n / 2;
			i = i + 1;
		}
	}
	cout << i;
	






	return 0;
}