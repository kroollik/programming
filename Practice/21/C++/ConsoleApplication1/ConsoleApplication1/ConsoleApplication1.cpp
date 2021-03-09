#include <iostream>

using std::cout;
using std::endl;
using std::cin;

double BMI(double weight, double height)
{
	double bmi = weight / (pow(height, 2));
	return bmi;
}

void printBMI(double BMI)
{
	
	if (BMI < 18.5)
	{
		cout << "Underweight";
	} 
	else if (18.5 <= BMI && BMI < 25.0)
	{
		cout << "Normal";
	}
	else if (25.0 <= BMI && BMI < 30.0)
	{
		cout << "Overweight";
	}
	else if (30.0 <= BMI)
	{
		cout << "Obesity";
	}

}



int main() 
{
	setlocale(LC_ALL, "ru");
	double weight, height;
	cin >> weight >> height;
	height /= 100;
	double index = BMI(weight, height);
	printBMI(index);



	return 0;
}