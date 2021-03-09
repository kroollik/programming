#include <iostream>
#include <vector>
#include <ctime>
std::vector <int>& write(std::vector <int>& arr, int n) {
    for (int i = 0; i < arr.size(); i++) {
        std::cin >> arr[i];
    }
    return arr;
}
void print(std::vector <int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << "[" << i << "] = " << arr[i] << std::endl;
    }
}
std::vector <std::vector<int>>& writematrix(std::vector<std::vector<int>>& matrix, int sqrtn) {
		for (int i = 0; i < sqrtn; i++)
		{
			for (int j = 0; j < sqrtn; j++)
			{
				std::cin >> matrix[i][j];
			}
		}
	return matrix;
}
void printmatrix(std::vector<std::vector<int>>& matrix, int sqrtn) {
		for (int i = 0; i < sqrtn; i++)
		{
			for (int j = 0; j < sqrtn; j++)
			{
				std::cout << matrix[i][j] << "  ";
			}
			std::cout<<std::endl;
		}
	}
enum Sortirovka
{
    UP,    
    DOWN    
};
void swapElements(int& element1, int& element2)
{
    int s = element1;
    element1 = element2;
    element2 = s;
}
bool raspologenie(int a, int b, Sortirovka napravlenie)
{
    if (napravlenie == UP)
    {
        return a <= b;
    }
    else
    {
        return a >= b;
    }
}
bool proverka(std::vector<int>& arr, int n, Sortirovka napravlenie)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (!raspologenie(arr[i], arr[i + 1], napravlenie))
        {
            return false;
        }
    }

    return true;
}
std::vector<int>& shuffleElements(std::vector<int>& arr, int n)
{
        int r = rand() % n;
        int k = rand() % n;
        swapElements(arr[r], arr[k]);
        return arr;
}
std::vector<int>& BozoSort(std::vector<int>& arr, int n, Sortirovka napravlenie)
{
    while (!proverka(arr, n, napravlenie))
    {
        arr = shuffleElements(arr, n);
    }

    return arr;
}
std::vector<int> BozoSort(int a, int b, int c, Sortirovka napravlenie)
{
    std::vector<int> arr{ a, b, c };
    return BozoSort(arr, arr.size(), napravlenie);
}
int main(){
    setlocale(LC_ALL,"Russian");
    srand(time(NULL));
    int n,a,b,c,sqrtn;
	/*a = rand();
	b = rand();
    std::cout << a << "  " << b;*/
    std::cout << "Введите количество элементов массива вещественных чисел\n";
    std::cin >> n;
	sqrtn = sqrt(n);
    std::vector<int> arr(n);
    std::vector<std::vector<int>> matrix(sqrtn, std::vector<int>(sqrtn));
    write(arr, n);
    arr = BozoSort(arr, n, UP);
    print(arr);
    std::cout << std::endl;
    arr = BozoSort(arr, n, DOWN);
    print(arr);
    std::cout << std::endl;
    arr = BozoSort(arr[0], arr[1], arr[2], UP);
    print(arr);
	/*writematrix(matrix, sqrtn);
    matrix = BozoSort(matrix, sqrtn, UP);
	printmatrix(matrix, sqrtn);*/
    return 0;}



