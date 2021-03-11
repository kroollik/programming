#include <iostream>

using namespace std;

struct IntArray
{
    int* data;
    int size;
};


void create(IntArray* arr, int size)
{
    if (size <= 0)
    {
        return;
    }
    int* Array = new int[size];
    arr->data = Array;
    arr->size = size;
}
void create(IntArray& arr, int size)
{
    int* Array = new int[size];
    arr.data = Array;
    arr.size = size;
}


int get(IntArray* arr, int index)
{
    if (index > arr->size || index <= 0)
    {
        cout << "Выход за границы массива!";
        return -1;
    }
    return arr->data[index];
}
int get(IntArray& arr, int index)
{
    if (index > arr.size || index <= 0)
    {
        cout << "Выход за границы массива!";
        return -1;
    }
    return arr.data[index];
}


void set(IntArray* arr, int index, int value)
{
    if (index > arr->size || index <= 0)
    {
        cout << "Выход за границы массива!";
        return;
    }
    arr->data[index] = value;
}
void set(IntArray& arr, int index, int value)
{
    if (index > arr.size || index <= 0)
    {
        cout << "Выход за границы массива!";
        return;
    }
    arr.data[index] = value;
}


void print(IntArray* arr)
{
    cout << '[';
    for (int i = 0; i < arr->size; i++)
    {
        cout << arr->data[i];
        if (i < arr->size - 1)
        {
            std::cout << ", ";
        }
    }
    cout << ']' << endl;
}
void print(IntArray& arr)
{
    cout << '[';
    for (int i = 0; i < arr.size; i++)
    {
        cout << arr.data[i];
        if (i < arr.size - 1)
        {
            std::cout << ", ";
        }
    }
    cout << ']' << endl;
}


void resize(IntArray* arr, int newSize)
{
    if (newSize < 0)
    {
        return;
    }

    if (newSize == arr->size)
    {
        return;
    }
    if (newSize < arr->size)
    {
        int* NewArray = new int[newSize];
        for (int i = 0; i < newSize; i++)
        {
            NewArray[i] = arr->data[i];
        }
        delete[]arr->data;
        arr->data = NewArray;
        arr->size = newSize;
    }

    if (newSize > arr->size)
    {
        int* NewArray = new int[newSize];
        for (int i = 0; i < arr->size; i++)
        {
            NewArray[i] = arr->data[i];
        }
        for (int j = arr->size; j < newSize; j++)
        {
            NewArray[j] = 0;
        }
        delete[]arr->data;
        arr->data = NewArray;
        arr->size = newSize;
    }

}
void resize(IntArray& arr, int newSize)
{
    if (newSize < 0)
    {
        return;
    }

    if (newSize == arr.size)
    {
        return;
    }
    if (newSize < arr.size)
    {
        int* NewArray = new int[newSize];
        for (int i = 0; i < newSize; i++)
        {
            NewArray[i] = arr.data[i];
        }
        delete[]arr.data;
        arr.data = NewArray;
        arr.size = newSize;
    }

    if (newSize > arr.size)
    {
        int* NewArray = new int[newSize];
        for (int i = 0; i < arr.size; i++)
        {
            NewArray[i] = arr.data[i];
        }
        for (int j = arr.size; j < newSize; j++)
        {
            NewArray[j] = 0;
        }
        delete[]arr.data;
        arr.data = NewArray;
        arr.size = newSize;
    }

}



void destroy(IntArray* arr)
{
    if (!arr->data)
    {
        return;
    }

    delete[] arr->data;
    arr->data = nullptr;
    arr->size = 0;
}
void destroy(IntArray& arr)
{
    if (!arr.data)
    {
        return;
    }

    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
}

int main()
{
    IntArray a;
    create(a, 30);
    for (int i = 0; i < a.size; i++)
    {
        a.data[i] = 1+i;
    }
    print(a);
    resize(a, 50);
    print(a);
    resize(a, 10);
    print(a);
    destroy(a);
    return 0;
}
