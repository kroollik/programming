﻿#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> combinate(string);
vector<string> combinate(int, string);
vector<string> makeOtherArray(int, string);
vector<string> removeAnalogStrings(vector<string>, string);

int main()
{
	int n;
	string dict;
	vector<string> array;

	cin >> n;
	cin >> dict;

	if (dict.length() == n) array = combinate(dict);
	else array = combinate(n, dict);

	for (string i : array) cout << i << " ";
	cout << '\n';
}

vector<string> combinate(string dict)
{
	vector<string> array;
	vector<string> miniArray;
	string letter;


	if (dict.length() > 2) {
		letter = dict[0];
		dict = dict.substr(1);
		miniArray = combinate(dict);

		for (int i = 0; i < miniArray.size(); i++) {
			string thisDict = letter + miniArray[i];
			array.push_back(thisDict);
			for (int j = 1; j < thisDict.size(); j++) {
				string word = thisDict[j] + thisDict.substr(1, j - 1) + thisDict[0] + thisDict.substr(j + 1);
				array.push_back(word);
			}
		}
	}
	else {
		array.push_back(dict);

		char i = dict[0];
		dict[0] = dict[1];
		dict[1] = i;
		array.push_back(dict);
	}
	return array;
}

vector<string> combinate(int n, string dict) {
	vector<string> array;
	vector<string> bigArray = removeAnalogStrings(makeOtherArray(n, dict), dict);

	for (int i = 0; i < bigArray.size(); i++) {
		vector <string> thisIteration = combinate(bigArray[i]);
		for (int j = 0; j < thisIteration.size(); j++) {
			array.push_back(thisIteration[j]);
		}
	}

	array = removeAnalogStrings(array, "");

	return array;
}


vector<string> makeOtherArray(int n, string dict)
{
	//последовательность в n свободных букв, всех комбинаций (повторы есть)
	vector<string> array;
	vector<string> miniArray;

	int plusLatters = n - dict.length();

	if (plusLatters > 2) {
		miniArray = makeOtherArray(n - 1, dict);
		for (int i = 0; i < dict.length(); i++) {
			for (int j = 0; j < miniArray.size(); j++) {
				string word = dict[i] + miniArray[j];
				sort(word.begin(), word.end());
				array.push_back(word);
			}
		}
	}
	else if (plusLatters == 2) {
		for (int i = 0; i < dict.length(); i++) {
			for (int j = 0; j < dict.length(); j++) {
				string smallDict = "";
				smallDict.push_back(dict[i]);
				smallDict.push_back(dict[j]);
				array.push_back(smallDict);
			}
		}
	}
	else {
		for (int i = 0; i < dict.length(); i++) {
			string smallDict = "";
			smallDict.push_back(dict[i]);
			array.push_back(smallDict);
		}
	}

	return array;
}

vector<string> removeAnalogStrings(vector<string> array, string dict) {
	vector<string> bigArray;

	//убрала повторы + добавление словаря
	for (int i = 0; i < array.size(); i++) {
		if (array[i] == "") continue;
		bigArray.push_back(array[i] + dict);

		for (int j = 0; j < array.size(); j++) {
			if (i != j && array[i] == array[j]) {
				array[j] = "";
			}
		}
	}

	return bigArray;

}