#include "DynamicArray.h"
#include<Windows.h>

DynamicArray::DynamicArray() : ptr(nullptr), size(0) {}

DynamicArray::DynamicArray(int S)
{
    cout << "Construct by 1 param\n";
    size = S;
    ptr = new int[size];
    for (int i = 0; i < size; ++i) {
        ptr[i] = rand() % 100;  // случайные числа для примера
    }
}

DynamicArray::DynamicArray(const DynamicArray& a)  // конструктор копирования
{
    cout << "Copy construct\n";
    size = a.size;
    ptr = new int[size];
    for (int i = 0; i < size; ++i) {
        ptr[i] = a.ptr[i];
    }
}

DynamicArray::~DynamicArray()
{
    cout << "Destruct\n";
    delete[] ptr;
    delete[] ptr2;
    delete[] ptr3;
}

void DynamicArray::Input()
{
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; i++) {
        ptr[i] = rand();
    }
}

void DynamicArray::Output()
{
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << "\t";
    }
    size = 5;
    cout << "\n---------------------------------\n";
}

int* DynamicArray::GetPointer() const
{
    return ptr;
}

int DynamicArray::GetSize() const
{
    return size;
}

DynamicArray DynamicArray::operator+(int x)
{
	srand(static_cast<unsigned int>(time(0)));
	DynamicArray temp(size + x);
	for (int i = 0; i < size; i++) {
		temp.ptr[i] = ptr[i];
	}
	for (int i = size; i < temp.size; i++) {
		temp.ptr[i] = rand();
	}
	return temp;
}

DynamicArray DynamicArray::operator-(int x)
{
    if (size > x) {
        DynamicArray temp(size - x);
        for (int i = 0; i < temp.size; i++) {
            temp.ptr[i] = ptr[i];
        }
        return temp;
    }
    return *this; 
}

DynamicArray DynamicArray::operator*(int x)
{
    DynamicArray temp(size);
    for (int i = 0; i < size; i++) {
        temp.ptr[i] = ptr[i] * x;
    }
    return temp;
}

DynamicArray DynamicArray::operator-(const DynamicArray& other)
{
    int newSize = (size > other.size) ? size : other.size;
    DynamicArray temp(newSize);
    for (int i = 0; i < newSize; i++) {
        if (i < size && i < other.size) {
            temp.ptr[i] = ptr[i] - other.ptr[i];
        }
        else if (i < size) {
            temp.ptr[i] = ptr[i];
        }
        else {
            temp.ptr[i] = 0;
        }
    }
    return temp;
}

DynamicArray DynamicArray::operator+(long x)
{
    cout << "konkatenacia" << "\t";
    ptr2 = new int[size];
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; i++) {
        ptr2[i] = rand();
    }
    size = size * 2;

    ptr3 = new int[size];
    for (int i = 0; i < size/2; i++) {
        ptr3[i] = ptr[i];
    }
    for (int i = size-4; i < size; i++) {
        ptr3[i] = ptr2[i];
    }
    for (int i = 0; i < size; i++) {
        cout << ptr3[i] << "\t";
    }
    size = 5;
    cout << "\n---------------------------------\n";
    return size;
}

//// Перегрузка оператора + для конкатенации массивов
//DynamicArray DynamicArray::operator+(const DynamicArray& other)
//{
//    DynamicArray temp(size + other.size);
//    for (int i = 0; i < size; i++) {
//        temp.ptr[i] = ptr[i];
//    }
//    for (int i = 0; i < other.size; i++) {
//        temp.ptr[size + i] = other.ptr[i];
//    }
//    return temp;
//}



DynamicArray& DynamicArray::operator++()
{
    this->size = this->size++;
    srand(static_cast<unsigned int>(time(0)));
    for (int i = size-1; i < size; i++) {
        ptr[i] = rand();
    }
    return *this;
}

DynamicArray& DynamicArray::operator--()
{
    this->size = this->size--;
    return *this;
}