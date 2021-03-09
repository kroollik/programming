#include <iostream>;
#include <cmath>;
#include <ctime>;
using namespace std;
int main()
{	setlocale(LC_ALL,"Russian");
	int n,f,i,l;
	srand(time(0));
	n = rand() % 101;
	cout << "Добро пожаловать! Попробуй угадать число от 0 до 100 за 5 попыток." << endl;
	i = 1;
	for (i == 1; i <= 5; i++) {
		cin >> f;
		if (f < n) {
			cout << "Загаданное число больше" << endl;
		}
		else {
			if (f > n) {
				cout << "Загаданное число меньше" << endl;
			}
			else {
				if (f == n) {
					cout << "Поздравляю! Вы угадали" << endl;
					break;
				}
			}
		}
	}
	if (f != n) {
	cout << "Вы проиграли. Было загадано: " << n<<endl;	
	cout << "Хотите начать сначала? (1 - ДА )" << endl;
	cin >> l;
	if (l == 1) {
		return (main());
	}

	}
			
	

	return 0;

 
}

