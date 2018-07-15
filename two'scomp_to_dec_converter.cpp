#include <iostream>
#include "math.h"
using namespace std;


void convertDectoTwosComp(int dec_val, int* bin_arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		bin_arr[i] = 0;		//Filling array with 0's
	}

	if (dec_val >= 0)		//Postive case
	{
		for (int i=1 ; dec_val > 0 ; i++)
		{
			bin_arr[size-i] = dec_val % 2;
			dec_val = dec_val/2;
		}
	}
	else						//Negative case
	{
		dec_val = dec_val * -1;
		for (int i=1 ; dec_val > 0 ; i++)
		{
			bin_arr[size-i] = dec_val % 2;
			dec_val = dec_val/2;
		}

		// Inverting beacuse it is negative
		for (int i=0 ; i < size ; i++)
		{
			if (bin_arr[i] == 0)
			{
				bin_arr[i] = 1;
			}
			else if(bin_arr[i] == 1) 
			{
				bin_arr[i] = 0;
			}
		}

		// Adding 1
		int carry = 0;
		int* temp = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = 0;		//Filling array with 0's
		}
		temp[size-1] = 1;

		for (int i=0 ; i < size ; i++)	//Addition logic
		{
			if ( carry == 0 )
			{
				if (bin_arr[size-i-1] == 0 && temp[size-i-1] == 0)
				{
					bin_arr[size-i-1] = 0;
				}
				else if (bin_arr[size-i-1] == 1 && temp[size-i-1] == 0 || bin_arr[size-i-1] == 0 && temp[size-i-1] == 1)
				{
					bin_arr[size-i-1] = 1;
				}
				else if (bin_arr[size-i-1] == 1 && temp[size-i-1] == 1)
				{
					bin_arr[size-i-1] = 0;
					carry = 1;
				}
			}
			else if( carry == 1)
			{
				if (bin_arr[size-i-1] == 0 && temp[size-i-1] == 0)
				{
					bin_arr[size-i-1] = 1;
					carry = 0;
				}
				else if (bin_arr[size-i-1] == 1 && temp[size-i-1] == 0 || bin_arr[size-i-1] == 0 && temp[size-i-1] == 1)
				{
					bin_arr[size-i-1] = 0;
					carry = 1;
				}
				else if (bin_arr[size-i-1] == 1 && temp[size-i-1] == 1 || bin_arr[size-i-1] == 1 && temp[size-i-1] == 1)
				{
					bin_arr[size-i-1] = 1;
					carry = 1;
				}
			}
		}
		delete[] temp;
	}
}



void TwosCompAdd(const int* num1, const int* num2, int* bin_result, const int size)
{
	int carry = 0;
	for (int i=0 ; i < size ; i++) 	//Addition logic
	{
		if ( carry == 0 )
		{
			if (num1[size-i-1] == 0 && num2[size-i-1] == 0)
			{
				bin_result[size-i-1] = 0;
			}
			else if (num1[size-i-1] == 1 && num2[size-i-1] == 0 || num1[size-i-1] == 0 && num2[size-i-1] == 1)
			{
				bin_result[size-i-1] = 1;
			}
			else if (num1[size-i-1] == 1 && num2[size-i-1] == 1)
			{
				bin_result[size-i-1] = 0;
				carry = 1;
			}
		}
		else if( carry == 1)
		{
			if (num1[size-i-1] == 0 && num2[size-i-1] == 0)
			{
				bin_result[size-i-1] = 1;
				carry = 0;
			}
			else if (num1[size-i-1] == 1 && num2[size-i-1] == 0 || num1[size-i-1] == 0 && num2[size-i-1] == 1)
			{
				bin_result[size-i-1] = 0;
				carry = 1;
			}
			else if (num1[size-i-1] == 1 && num2[size-i-1] == 1 || num1[size-i-1] == 1 && num2[size-i-1] == 1)
			{
				bin_result[size-i-1] = 1;
				carry = 1;
			}
		}
	}

}



int twosCompToDec(int* bin_arr, const int size)
{
	int number = 0;
	int conversion;
	if ( bin_arr[0] == 0)
	{
		// Calculating value
		for (int i=0 ; i<size ; i++)
		{
			conversion = pow(2.0,i);
			number = number + bin_arr[size-i-1] * conversion;
		}
		return number;
	}
	else
	{
		// Inverting beacuse it is negative
		for (int i=0 ; i < size ; i++)
		{
			if (bin_arr[i] == 0)
			{
				bin_arr[i] = 1;
			}
			else if(bin_arr[i] == 1) 
			{
				bin_arr[i] = 0;
			}
		}

		// Adding 1
		int carry = 0;
		int* temp = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = 0;		//Filling array with 0's
		}
		temp[size-1] = 1;

		for (int i=0 ; i < size ; i++) 	//Addition logic
		{
			if ( carry == 0 )
			{
				if (bin_arr[size-i-1] == 0 && temp[size-i-1] == 0)
				{
					bin_arr[size-i-1] = 0;
				}
				else if (bin_arr[size-i-1] == 1 && temp[size-i-1] == 0 || bin_arr[size-i-1] == 0 && temp[size-i-1] == 1)
				{
					bin_arr[size-i-1] = 1;
				}
				else if (bin_arr[size-i-1] == 1 && temp[size-i-1] == 1)
				{
					bin_arr[size-i-1] = 0;
					carry = 1;
				}
			}
			else if( carry == 1)
			{
				if (bin_arr[size-i-1] == 0 && temp[size-i-1] == 0)
				{
					bin_arr[size-i-1] = 1;
					carry = 0;
				}
				else if (bin_arr[size-i-1] == 1 && temp[size-i-1] == 0 || bin_arr[size-i-1] == 0 && temp[size-i-1] == 1)
				{
					bin_arr[size-i-1] = 0;
					carry = 1;
				}
				else if (bin_arr[size-i-1] == 1 && temp[size-i-1] == 1 || bin_arr[size-i-1] == 1 && temp[size-i-1] == 1)
				{
					bin_arr[size-i-1] = 1;
					carry = 1;
				}
			}
		}
		delete[] temp;

		// Calculating value
		for (int i=0 ; i<size ; i++)
		{
			conversion = pow(2.0,i);
			number = number + bin_arr[size-i-1] * conversion;
		}

		// Making number negative
		number = number * -1;
		return number;

	}

}



void prntBinArr(const int* bin_arr, const int size)
{
	for (int i = 0; i < size; i++) 
	{ 
		cout << bin_arr[i]; 
		if ((i+1) % 4 == 0) 
			cout << " "; 
	} 
}



int main()
{

	//Declaring three arrays of integers A, B and C of inputted length 
	int size; 
	cout << "Enter the size of the bits: "; 
	cin >> size; 
	int *A = new int[size]; 
	int *B = new int[size];
	int *C = new int[size];

	//Reading the values of the two integers from the user 
	int a, b; 
	cout << "Enter first integer number: "; 
	cin >> a; 
	cout << "Enter second integer number "; 
	cin >> b;

	//Adding the integers in decimal and putting the result in dec_result variable.
	int dec_result = a + b;

	//Converting a and b to the inputted length of bits as binary in two's complement. Putting the results in arrays A and B.
	convertDectoTwosComp(a, A, size); 
	cout << a << " in two's complement binary is "; prntBinArr(A, size); cout << endl; 
	convertDectoTwosComp(b, B, size); 
	cout << b << " in two's complement binary is "; prntBinArr(B, size); cout << endl;

	//Adding the two arrays A and B in two's complement binary arithmetic and put the result in array C.
	TwosCompAdd(A, B, C, size); 
	cout << "The sum in binary is "; prntBinArr(C, size); cout << endl;

	//Converting the two's complement binary to a decimal and putting the result in bin_result.
	int bin_result = twosCompToDec(C, size);

	cout << endl << endl; 
	cout << "The sum of " << a << " and " << b << " in decimal arithmetic is " << dec_result << endl; 
	cout << "The sum in two's complement arithmetic is " << dec_result<< endl;

	//If the values of bin_result and dec_result are equal else the result must be out of range for the given bit-pattern.
	if (bin_result == dec_result) 
	{ 
		cout << "Thank you. Bye =)" << endl; 
	}
	else 
	{ 
		cout << "Incorrect bit-pattern range :(" << endl; 
	}

	delete[] A; 
	delete[] B; 
	delete[] C; 

	return 0; 
} 