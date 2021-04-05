#include <iostream> 
#include <iomanip>      // std::setprecision
#include "functions.h"
#include "Array.h"
#include "Name2.h"

//for running time cacl
#include <chrono>
#include <fstream>

using namespace std;

int main()
{
	Array a;
	a.get_n();
	int n=a.getN();
	int i = a.getI();

	double* arr1 = a.getArrCpy();
	double* arr2 = a.getArrCpy();
	double* arr3 = a.getArrCpy();
	
	double temp=0;

	cout<<setprecision(4) << fixed;

	//first we need to clear the current content of Measure.txt file

	ofstream toDelete("Measure.txt"); // The name of the file
	toDelete.close();
	//////////////////////////////////////////////////////////////


	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	// Here you put the name of the function you wish to measure

	insertionSort(arr2, n);
	cout << "Insertion sort i'th element: " << arr2[i - 1] << endl;
	
	//////////////////////////////////////////////////////////////
	
	auto end = chrono::high_resolution_clock::now();

		// Calculating total time taken by the program.
	double time_taken =	chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt",ios::app); // The name of the file
	myfile << "Time taken by function Insertion sort  is : " << fixed << time_taken << setprecision(9);
	myfile << " sec" << endl;
	
	//////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////


	 start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	// Here you put the name of the function you wish to measure

	temp = Select(arr1, 0, n - 1, i);
	cout << "Selection i'th element: " << (temp) << endl;

	//////////////////////////////////////////////////////////////

	end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function Selection is : " << fixed << time_taken << setprecision(9);
	myfile << " sec" << endl;
	

	//////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////


	 start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	// Here you put the name of the function you wish to measure


	temp = TheQuintetAlgorithm(arr3, n, i);
	cout << "Quintuplet algorithm i'th element: " << temp << endl;

	//////////////////////////////////////////////////////////////

	 end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	 time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function Quintuplet algorithm is : " << fixed << time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	//////////////////////////////////////////////////////////////



	

	




	




















	 delete[]arr1 ;
	 delete[]arr2 ;
	 delete[]arr3 ;

	return 0;
}




