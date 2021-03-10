#include <iostream>
using namespace std;

int* create(int LengthArray, int FirstElementArray = 0, int Step = 0)
{
    int* Array = new int [LengthArray];

    Array[0]=FirstElementArray;

    for(int i = 1; i < LengthArray; i++)
    {
        Array[i] = Array[0] + Step*i;
    }
    return Array;
}

void sort(int* Array, int LengthArray)
{
    int Temp;
    int PreviousIndex;
    for (int i = 1; i < LengthArray; i++)
    {
        Temp = Array[i];
        PreviousIndex = i - 1;
        while (PreviousIndex >= 0 && Array[PreviousIndex] > Temp)
        {
            Array[PreviousIndex + 1] = Array[PreviousIndex];
            Array[PreviousIndex] = Temp;
            PreviousIndex--;
        }
    }
}

int* print(int* Array, int LengthArray)
{
    for (int i = 0; i < LengthArray; i++)
    {
        cout << Array[i] << endl;
    }
    return Array;
}
int main()
{
    int LengthArray, FirstElementArray, Step;

    std::cin >> LengthArray >> FirstElementArray >> Step;
    
    int* Array = create(LengthArray, FirstElementArray, Step);
    sort(Array, LengthArray);
    print(Array, LengthArray);

    delete[] Array;
    return 0;
}
