#pragma once

#include <iostream> 
#include "Name2.h"
using namespace std;


class Array
{
private:
	double* arr;
	int n;
	int i;

public:
	Array()
	{
		n = 0;
		arr = nullptr;
	}

	void get_n();//here we get N ,and check regularity
	void get_i();//here we get i ,and check regularity
	void reciveNumbersInput(); // here we get n numbers ,and check regularity
	



	//double StringToDouble(char* str, int size, int indexOfDot, bool isNegetive);

	void checkMemoryAllocation(void * ptr)
	{
		if (ptr == nullptr)
		{
			cout << "Error! memory not allocated." << endl;
			exit(-1);
		}
	}

	double* getArrCpy();

	int getN() { return n; }
	int getI() { return i; }

	~Array()
	{
		delete[] arr;
	}


};

