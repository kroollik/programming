﻿#include<iostream>;
#include<vector>;
int main() {
	using namespace std;
	int  c,h;
	h = 0;
	const int p = 9;
	char a[p];
	cin >> c; // введите количество билетов
	for (int i = 0; i < c; i++){
		for (int j = 0; j < p; j++){
			cin >> a[j]; // введите номера билетов
		}
		if ( (a[0] == 'a') && (a[4] == '5') && (a[5] == '5') && (a[6] == '6') && (a[7] == '6') && (a[8] == '1') ){
			for (int j = 0; j < p; j++){
				cout << a[j]; // билеты принадлежащие начальнику управления экономической безопасности и противодействия коррупции, полковнику полиции Суслику.
			}
			cout << " ";
			h = 1;
		}
	}
	if (h == 0){
		cout << -1;
	}
}