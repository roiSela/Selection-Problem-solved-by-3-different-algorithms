#include "functions.h"

/* Function to sort an array using insertion sort*/
void insertionSort(double arr[], int n)
{
    int i;
    int j;
    double k; // k stands for key

    for (i = 1; i < n; i++)
    {
        //we start from i=1 because an array with 1 element is alredy sorted.

        k = arr[i];

        j = i - 1; //j will mark the end of the sub-left array on which we compare key to.

        while ((j >= 0) && (arr[j] > k))
        {
            //in this loop , we go over the elements of the sub-array left to key , till we find arr[j] smaller than key , or until we reached the end.
           
            arr[j + 1] = arr[j]; //its fine to do this because on the first itiration we have key saved. 

            j = j - 1; //we go deeper to the left. 

        }
        arr[j + 1] = k; //if we didnt go into the arr[i] will not change its place, however, if we did infact went into this loop, now we put key in its righful place.
    }
}

// A utility function to print an array of size n 
void printArray(double arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


double Select(double A[], int left, int right, int i)
{
    int pivot; //location of pivot
    int leftPart;//size of part left to pivot (including pivot)
    
    pivot = Partition(A, left, right);
    leftPart = pivot - left + 1;
    if (i == leftPart)
    {
        return A[pivot];
    }
    if (i<leftPart)
    {
        return Select(A,left,pivot-1,i);
    }
    else
    {
        return Select(A,pivot+1,right,i-leftPart);
    }
}

int Partition(double A[], int left, int right)
{
    double pivot = A[left];  // as we learned , the pivot is initalazied to be the first element of the array

    while (left != right)
    {
        if (A[left] > A[right]) //
        {
            // implemation of std::swap(A[left], A[right]) because we are not allowed to use std;
            double temp;
            temp = A[left];
            A[left] = A[right];
            A[right] = temp;

        }
        //now we move on from an element that we already compared to the pivot

        if (pivot == A[left]) // we did not switch , and A[right] is fine where it is
        {
            right--;
        }        
        else
        {//we did infact switch , and now A[right] is in his rightfull place as the smaller number
            left++;
        }
    }
    //now left == right 
    return left;


}


// A function to implement bubble sort  
void bubbleSort(double arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place  
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapAdress(&arr[j], &arr[j + 1]);
}

void PrintInFormat(double num)
{
    int tmp;
    tmp = (int)num;
    num = num - tmp;
    
    cout << tmp << ".";

    for (int i = 0; i < 4; i++)
    {
        num = num * 10;
        int t;
        t = int(num);
        cout << t;
        num = num - t;
    }
}

//new :


double TheQuintetAlgorithm(double* a, int n, int i)
{
    if (n <= 5)
    {
        bubbleSort(a, n);
        return a[i - 1];
    }

    int m = (n + 4) / 5;
    double* mid;
    mid = new double[m];

    for (int i = 0; i < m; i++)
    {
        int f = i * 5;
        if (n - f > 4) //five elements , as needed 
        {
            bubbleSort(a + f, 5);
            mid[i] = a[f + 2];
        }
        else
        {      // less than 5 left
            bubbleSort(a + f, n - f);
            int temp = f + (n - f - 1) / 2;
            mid[i] = a[temp];
        }
    }
  

    double pivot = TheQuintetAlgorithm(mid, m, (m + 1) / 2);
   
    int k = Partition2(a, 0, n - 1, pivot);
  

    if (i == k)
    {
        return pivot;
    }
    else
    {
        if (i < k)
        {
            return TheQuintetAlgorithm(a, k - 1, i);
        }
        else//i > k
        {
            return TheQuintetAlgorithm(a + k, n - k, i - k);
        }

    }


    //stage v
}

void swapAdress(double* xp, double* yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}



int Partition2(double A[], int left, int right, double p)
{

    //first we need to make sure p is at the most left position
    int counter = 0;
    while (A[counter] != p)
    {
        counter++;
    }

    double temp;
    temp = A[left];
    A[left] = A[counter];
    A[counter] = temp;
    ///////////


    double pivot = A[left];

    while (left != right)
    {
        if (A[left] > A[right]) //
        {
            // implemation of std::swap(A[left], A[right]) because we are not allowed to use std;
            double temp;
            temp = A[left];
            A[left] = A[right];
            A[right] = temp;

        }
        //now we move on from an element that we already compared to the pivot

        if (pivot == A[left]) // we did not switch , and A[right] is fine where it is
        {
            right--;
        }
        else
        {//we did infact switch , and now A[right] is in his rightfull place as the smaller number
            left++;
        }
    }

  
     //now left == right 
    return (left + 1);


}

