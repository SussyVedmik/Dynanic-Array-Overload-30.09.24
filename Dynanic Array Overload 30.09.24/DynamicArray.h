#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
	int* ptr;
	int* ptr2;
	int* ptr3;// указатель на динам. массив
	int size;  // размер массива 
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&); // copy constructor
	~DynamicArray();

	void Input();// rand
	void Output();// вывод на консоль
	int* GetPointer() const;
	int GetSize() const;

	DynamicArray operator+(int x);
	DynamicArray operator-(int x);
	DynamicArray operator*(int x);
	DynamicArray operator-(const DynamicArray& other);
	/*DynamicArray operator+(const DynamicArray& other);*/
	DynamicArray operator+(long x);

	DynamicArray& operator++();
	DynamicArray& operator--();


};


