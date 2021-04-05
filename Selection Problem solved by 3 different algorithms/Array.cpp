#include "Array.h"


void Array::get_n()//here we get N ,and check regularity
{
	Name2 temp;
	temp.readName();
	char* temp_n = temp.getName();
	int size = temp.getNamelen();
	for (int i = 0; i < size; i++)
	{
		if ( !( (temp_n[i]>='0') && (temp_n[i] <= '9') ))
		{
			cout << "wrong input" << endl;
			exit(-1);
		}
	}

	n = atoi(temp_n);

	get_i(); //now that we made sure that the input for n is valid we move on to check i
}

//here we get i ,and check regularity
void Array::get_i()
{
	Name2 temp;
	temp.readName();
	char* temp_i = temp.getName();
	int size = temp.getNamelen();
	for (int i = 0; i < size; i++)
	{
		if (!((temp_i[i] >= '0') && (temp_i[i] <= '9')))
		{
			cout << "wrong input" << endl;
			exit(-1);
		}
	}

	i = atoi(temp_i);
	if (i > n)
	{
		cout << "wrong input" << endl;
		exit(-1);
	}
	reciveNumbersInput();//now that we made sure that the input for i is valid we move on to check the numbers

}


// here we get n numbers ,and check regularity
void Array:: reciveNumbersInput()
{
	arr = new double[n];
	//Name2* nameArray = new Name2[n];
	Name2 temp;

	int count = 0;

	temp.readName();
	int size = temp.getNamelen();
	char* temp_num = temp.getName();
	int indexOfDotApperance = -1;
	


	while (size!=0)
	{
		count++;

		if (count > n) {
			cout << "wrong input" << endl;
			exit(-1);
		}
	
		if (temp_num[0] == '-')
		{
			bool dotAppeard = false;
			for (int i = 1; i < size; i++)
			{
				if (!((temp_num[i] >= '0') && (temp_num[i] <= '9')))
				{
					if ( (temp_num[i]=='.')&& (dotAppeard==false))
					{
						dotAppeard = true;
						indexOfDotApperance = i;
					}
					else
					{
						cout << "wrong input" << endl;
						exit(-1);
					}

				}
			}


			//now we check if there is at least one digit after the dot , and not more than 4 ditits 
			if (indexOfDotApperance != (-1)) //we check if a dot even appeared in the number 
			{
				if ((size - indexOfDotApperance - 1) > 4)
				{
					cout << "wrong input" << endl;
					exit(-1);
				}

				if ((size - indexOfDotApperance-1) == 0)
				{
					cout << "wrong input" << endl;
					exit(-1);
				}

			}

		}
		else //the number is positive , and we need to check the first digit as well
		{
			bool dotAppeard = false;

			for (int i = 0; i < size; i++)
			{
				if (!((temp_num[i] >= '0') && (temp_num[i] <= '9')))
				{
					if ((temp_num[i] == '.') && (dotAppeard == false))
					{
						dotAppeard = true;
						indexOfDotApperance = i;
					}
					else
					{
						cout << "wrong input" << endl;
						exit(-1);
					}

				}
			}

			//now we check if there is at least one digit after the dot , and not more than 4 ditits 
			if (indexOfDotApperance != (-1)) //we check if a dot even appeared in the number 
			{
				if ((size- indexOfDotApperance -1)>4)
				{
					cout << "wrong input" << endl;
					exit(-1);
				}

				if ((size - 1 - indexOfDotApperance)==0)
				{
					cout << "wrong input" << endl;
					exit(-1);
				}

			}

			
		}
		
		
		//cout << temp_num << endl; debug
		//if we got to here , we know that the string is a valid number , so we put it in arr
		arr[count - 1] = atof(temp_num);
		////////////////////////////////////////////////////////////////////////////////////
	//	cout << "\n the num is : " << arr[count - 1] << endl; //debug
		
		if ((temp.getEnter()) == true)
		{
			break;
		}


		indexOfDotApperance = -1; // we initalaize this variable for the next itiration

		temp.readName();

		temp_num = temp.getName();

		

	
		if ( (temp_num[0] == '\n') || (temp_num[0] == '\t') || (temp_num[0] == ' '))
		{
			size = 0;
		}
		else
		{
			size = temp.getNamelen();
		}

		
	
	}
	

	if (count < n) {
		cout << "wrong input" << endl;
		exit(-1);
	}


	
}


double* Array::getArrCpy()
{
	double* arr_cpy;
	arr_cpy = new double[n];
	checkMemoryAllocation(arr_cpy);
	for (int i = 0; i < n; i++)
	{
		arr_cpy[i]=arr[i];
	}
	return arr_cpy;
}

//double Array:: StringToDouble(char* str, int size, int indexOfDot, bool isNegetive)
//{
//	double num=0;
//	int counter=0;
//
//	if (isNegetive==false)
//	{
//		for (int i = (indexOfDot - 1); i >= 0; i--, counter++)
//		{
//			int digit = (str[i] - '0');
//
//			for (int j = 0; j < counter; j++)
//			{
//				digit = digit * 10;
//			}
//
//			num += digit;
//
//		}
//
//		counter = 1;
//
//		for (int i = (indexOfDot + 1); i <= (size - 1); i++, counter++)
//		{
//			float digit = (str[i] - '0');
//			for (int j = 0; j < counter; j++)
//			{
//				digit = digit * (1 / 10);
//			}
//
//			num += digit;
//		}
//
//		return (num);
//	}
//	else
//	{
//		for (int i = (indexOfDot - 1); i >= 1; i--, counter++)
//		{
//			int digit = (str[i] - '0');
//
//			for (int j = 0; j < counter; j++)
//			{
//				digit = digit * 10;
//			}
//
//			num += digit;
//
//		}
//
//		counter = 1;
//
//		for (int i = (indexOfDot + 1); i <= (size - 1); i++, counter++)
//		{
//			double digit = (str[i] - '0');
//			for (int j = 0; j < counter; j++)
//			{
//				digit = digit * (1 / 10);
//			}
//
//			num += digit;
//		}
//
//		return ((-1)*num);
//
//
//
//	}
//	
//	
//
//
//}