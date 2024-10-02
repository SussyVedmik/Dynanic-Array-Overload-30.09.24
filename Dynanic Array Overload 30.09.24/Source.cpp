#include "DynamicArray.h"
#include <iostream>


int main()
{
	DynamicArray a(5);
	a.Input();
	a.Output(); // constructor 1 param
	/*a.Input();
	a.Output();*/
	//DynamicArray b = a; // copy constructor
	//b.Output();

	/*DynamicArray rezult = GetObj();*/

	DynamicArray rez = a + 10;
	rez.Output();

	DynamicArray rez1 = a - 2;
	rez1.Output();

	DynamicArray rez2 = a * 2;
	rez2.Output();

	DynamicArray b(5);
	DynamicArray rez3 = a - b;
	rez3.Output();

	DynamicArray rez4 = a + 0;
	rez4.Output();

	++a;
	a.Output();

	--a;
	a.Output();

	system("pause");
}