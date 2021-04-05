#pragma once
#include <iostream> 
using namespace std;

//Functions:
void insertionSort(double arr[], int n);
void printArray(double arr[], int n); // debug

double Select(double A[],int left,int right,int i);
int Partition(double A[],int left,int right);

void bubbleSort(int arr[], int n);


void PrintInFormat(double num);



double TheQuintetAlgorithm(double* a, int n, int i);

void swapAdress(double* xp, double* yp);

int Partition2(double A[], int left, int right, double p);
