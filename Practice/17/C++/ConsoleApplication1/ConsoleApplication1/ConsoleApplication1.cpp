#include <iostream>
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	setlocale(LC_ALL, "ru");
	int number = 0, max = 0, k = 0;
	int colornumber[37]{2,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1};
	int red = 0;
	int black = 0;
	int NumberNotDroppedOutElements[37];
	const int size = sizeof(NumberNotDroppedOutElements) / sizeof(int);
	for (int i = 0; i < size; i++)
	{
		NumberNotDroppedOutElements[i] = i;
	}
	int OftenDropedOutElements[37]{};
	int NumberDroppedOutElements[37]{};
	

	while (k < 12)
	{	
	cin >> number;
	if (number < 0) 
	{
		return 0;
	}
	OftenDropedOutElements[number] += 1;
	for (int i = 0; i < size; i++)
	{
		if (OftenDropedOutElements[i] >= max)
		{
			max = OftenDropedOutElements[i];
			NumberDroppedOutElements[i] = i;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (OftenDropedOutElements[i] == max)
		{
			cout << NumberDroppedOutElements[i] << ' ';
		}
	}
	cout << endl;
	NumberNotDroppedOutElements[number] = -1;
	for (int i = 0; i < size; i++)
	{
		if (NumberNotDroppedOutElements[i] != -1)
		{
			cout << NumberNotDroppedOutElements[i] << ' ';
		}
	}
		k += 1;
		cout << endl;
		if (colornumber[number] == 1)
		{
			red += 1;
		}
		else if(colornumber[number] == 0)
		{
			black += 1;
		}
		cout << red << " " << black << endl;
		cout << endl;
	}
		
}
	

	

	




