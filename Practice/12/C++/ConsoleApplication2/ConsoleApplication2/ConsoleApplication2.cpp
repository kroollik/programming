#include<iostream>;
#include<cmath>;
using namespace std;
int main(){
	setlocale(LC_ALL, "Russian");
	unsigned int n,f,i;
	cout << "Введите целое число от 0 до 10^9" << endl;
	cin >> n;
	f = 1;
	if (n >=0 && n <= 1000000000) {
		for (i = 1; i<=n; i++) {
			f = f * i;
		}
	}
	cout <<n<< "! = "<<f;
	return 0;

}