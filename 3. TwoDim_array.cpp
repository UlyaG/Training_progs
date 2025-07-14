#include <iostream>
#include <windows.h>
using namespace std;

void showarr(int arr[][6], int size)
{
	int* ptr = *arr;
	system("CLS");
	for (int i = 0; i <= size - 1; i++)
	{
		for (int j = 0; j <= size - 1; j++)
		{
			if (*(ptr+j+i*size) != 0)
			{
				cout << *(ptr + j + i * size) << "\t";
			}
			else { cout << ' ' << "\t"; }
		}
		cout << endl;
	}
	Sleep(100);
}

void showArrBlocks(int arr[][6], int size)
{
	int* ptr = *arr;
	system("CLS");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i <= size - 1; i++)
	{
		for (int j = 0; j <= size - 1; j++)
		{
			if ((i < (size / 2)) && (j < (size / 2))) 
			{
				SetConsoleTextAttribute(hConsole, 4);
			}
			if ((i < (size / 2)) && (j >= (size / 2)))
			{
				SetConsoleTextAttribute(hConsole, 2);
			}
			if ((i  >= (size / 2)) && (j < (size / 2)))
			{
				SetConsoleTextAttribute(hConsole, 1);
			}
			if ((i >= (size / 2)) && (j >= (size / 2)))
			{
				SetConsoleTextAttribute(hConsole, 6); 
			}
			cout << *(ptr + j + i * size) << "\t";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 15);
}

void point1(int array[][6])
{
	const int size = 6;
	int* ptr1 = *array;
	int start = 0, end = size - 1, direction = 0;
	while (direction <= ((size/2*3+(size/2-1)-1)))
	{
		if (direction % 4 == 0)
		{
			start = direction / 4;
			int k = start;
			end = size - 1 - (direction / 4);
			while (k <= end)
			{
				*(ptr1 + k + size * start) = rand() % (size * size) + 1;
				k++;
				showarr(array, size);
			}
		}
		if (direction % 4 == 1)
		{
			start = direction / 4 + 1;
			int k = start;
			end = size - 1 - (direction / 4);
			while (k <= end)
			{
				*(ptr1 + end + size * k) = rand() % (size * size) + 1;
				k++;
				showarr(array, size);
			}
		}
		if (direction % 4 == 2)
		{
			start = size - 2 - (direction / 4);
			int k = start;
			end = direction / 4;
			while (k >= end)
			{
				*(ptr1 + k + size * (start + 1)) = rand() % (size * size) + 1;
				k--;
				showarr(array, size);
			}
		}
		if (direction % 4 == 3)
		{
			start = size - 2 - (direction / 4);
			int k = start;
			end = direction / 4 + 1;
			while (k >= end)
			{
				*(ptr1 + (end - 1) + size * k) = rand() % (size * size) + 1;
				k--;
				showarr(array, size);
			}
		}
		direction++;
	}
}

void point2(int array[][6])
{
	const int size = 6;
	int* ptr = *array;
	int start = 0, end = size - 1, direction = 0;
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0) 
		{
			for (int j = 0; j < size; j++)
			{
				*(ptr+i+j*size) = rand() % (size * size) + 1;
				showarr(array, size);
			}
		}
		else
		{
			for (int j = size-1; j >= 0; j--)
			{
				*(ptr + i + j * size) = rand() % (size * size) + 1;
				showarr(array, size);
			}
		}
	}
}

void point3(int array[][6])
{
	const int size = 6;
	int* ptr = *array;
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			int c;
			c = *(ptr + j + i * size);
			*(ptr + j + i * size) = *(ptr + j + (i + size / 2) * size);
			*(ptr + j + (i + size / 2) * size) = *(ptr + (j + size / 2) + (i + size / 2) * size);
			*(ptr + (j + size / 2) + (i + size / 2) * size) = *(ptr + (j + size / 2) + i * size);
			*(ptr + (j + size / 2) + i * size) = c;
		}
	}
	showArrBlocks(array, size);
}

void point4(int array[][6])
{
	const int size = 6;
	int* ptr = *array;
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			int c;
			c = *(ptr + j + i * size);
			*(ptr + j + i * size) = *(ptr + (j + size / 2) + (i + size / 2) * size);
			*(ptr + (j + size / 2) + (i + size / 2) * size) = c;
			c = *(ptr + j + (i + size / 2) * size);
			*(ptr + j + (i + size / 2) * size) = *(ptr + (j + size / 2) + i * size);
			*(ptr + (j + size / 2) + i * size) = c;
		}
	}
	showArrBlocks(array, size);
}

void point5(int array[][6])
{
	const int size = 6;
	int* ptr = *array;
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			int c;
			c = *(ptr + j + i * size);
			*(ptr + j + i * size) = *(ptr + j + (i + size / 2) * size);
			*(ptr + j + (i + size / 2) * size) = c;
			c = *(ptr + (j + size / 2) + i * size);
			*(ptr + (j + size / 2) + i * size) = *(ptr + (j + size / 2) + (i + size / 2) * size);
			*(ptr + (j + size / 2) + (i + size / 2) * size) = c;
		}
	}
	showArrBlocks(array, size);
}

void point6(int array[][6])
{
	const int size = 6;
	int* ptr = *array;
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			int c;
			c = *(ptr + j + i * size);
			*(ptr + j + i * size) = *(ptr + (j + size / 2) + i * size);
			*(ptr + (j + size / 2) + i * size) = c;
			c = *(ptr + j + (i + size / 2) * size);
			*(ptr + j + (i + size / 2) * size) = *(ptr + (j + size / 2) + (i + size / 2) * size);
			*(ptr + (j + size / 2) + (i + size / 2) * size) = c;
		}
	}
	showArrBlocks(array, size);
}

void combSort(int array[][6], const int size)
{
	int dif = size - 1;
	int *ptr = *array;
	while (dif >= 1)
	{
		for (int i = 0; i + dif < size; i++)
		{
			if (*(ptr + i) > *(ptr + i + dif))
			{
				int c = *(ptr + i);
				*(ptr + i) = *(ptr + i + dif);
				*(ptr + i + dif) = c;
			}
		}
		dif/=1.247;
	}
	while (true)
	{
		int k = 0;
		for (int i = 0; i < size-1; i++)
		{
			if (*(ptr + i) > *(ptr + i + 1))
			{
				int c = *(ptr + i);
				*(ptr + i) = *(ptr + i + 1);
				*(ptr + i + 1) = c;
			}
			else { k++; }
		}
		if (k == size - 1) { break; }
		else k = 0;
	}
}

void decrease(int array[][6], int numb)
{
	int* ptr = *array;
	for (int i = 0; i < 6 * 6; i++)
	{
		*(ptr + i) = *(ptr + i) - numb;
	}
}

void increase(int array[][6], int numb)
{
	int* ptr = *array;
	for (int i = 0; i < 6 * 6; i++)
	{
		*(ptr + i) = *(ptr + i) + numb;
	}
}

void multiply(int array[][6], int numb)
{
	int* ptr = *array;
	for (int i = 0; i < 6 * 6; i++)
	{
		*(ptr + i) = *(ptr + i) * numb;
	}
}

void divide(int array[][6], int numb)
{
	int* ptr = *array;
	for (int i = 0; i < 6 * 6; i++)
	{
		*(ptr + i) = *(ptr + i) / numb;
	}
}

void newArr(int arr[][6], int size)
{
	int* ptr = *arr;
	for (int i = 0; i < size * size; i++)
	{
		*(ptr+i) = rand() % (size * size) + 1;
	}
}

void arraySum(int arr1[][6], int arr2[][6], int arr3[][6], int size)
{
	int* ptr1 = *arr1;
	int* ptr2 = *arr2;
	int* ptr3 = *arr3;
	for (int i = 0; i < size * size; i++)
	{
		*(ptr3 + i) = *(ptr1 + i) + *(ptr2 + i);
	}
}

int main()
{
	int item = 1;
	const int size = 6;
	int array1a[size][size] = {};
	int array1b[size][size] = {};
	int arrayIhw1[size][size] = {};
	int arrayIhw2[size][size] = {};
	int arrayIhwSum[size][size] = {};
	int op = 0, numb = 0;
	bool rep;
	while (item != 0)
	{
		cout << "Choose an item: " << endl <<
			"1. Show the filling of the array (type a). " << endl <<
			"2. Show the filling of the array (type b). " << endl <<
			"3. Show moving blocks (type a). " << endl <<
			"4. Show moving blocks (type b). " << endl <<
			"5. Show moving blocks (type c). " << endl <<
			"6. Show moving blocks (type d). " << endl <<
			"7. Sort the array. " << endl <<
			"8. Decrease/increase/multiply/divide the array by your number." << endl <<
			"9. Individual Homework (#1)." << endl <<
			"0. Stop working with code. " << endl;
		cin >> item;
		switch (item) {
		case 1:
			point1(array1a);
			break;
		case 2:
			point2(array1b);
			break;
		case 3:
			showArrBlocks(array1a, size);
			Sleep(1000);
			point3(array1a);
			Sleep(1000);
			break;
		case 4:
			showArrBlocks(array1a, size);
			Sleep(1000);
			point4(array1a);
			Sleep(1000);
			break;
		case 5:
			showArrBlocks(array1a, size);
			Sleep(1000);
			point5(array1a);
			Sleep(1000);
			break;
		case 6:
			showArrBlocks(array1a, size);
			Sleep(1000);
			point6(array1a);
			Sleep(1000);
			break;
		case 7:
			combSort(array1a, size*size);
			showarr(array1a, size);
			break;
		case 8:
			cout << "Choose an operation: " << endl <<
				"1) Decrease;" << endl <<
				"2) Increase;" << endl <<
				"3) Multiply;" << endl <<
				"4) Divide;" << endl;
			rep = 1;
			while (rep) 
			{
				cin >> op;
				switch (op) {
				case 1:
					cout << "Enter the number: ";
					cin >> numb;
					showarr(array1a, size);
					Sleep(1000);
					decrease(array1a, numb);
					showarr(array1a, size);
					rep = 0;
					break;
				case 2:
					cout << "Enter the number: ";
					cin >> numb;
					showarr(array1a, size);
					Sleep(1000);
					increase(array1a, numb);
					showarr(array1a, size);
					rep = 0;
					break;
				case 3:
					cout << "Enter the number: ";
					cin >> numb;
					showarr(array1a, size);
					Sleep(1000);
					multiply(array1a, numb);
					showarr(array1a, size);
					rep = 0;
					break;
				case 4:
					cout << "Enter the number: ";
					cin >> numb;
					showarr(array1a, size);
					Sleep(1000);
					divide(array1a, numb);
					showarr(array1a, size);
					rep = 0;
					break;
				default:
					cout << "Try again." << endl;
				}
			}
			break;
		case 9:
			newArr(arrayIhw1, size);
			showarr(arrayIhw1, size);
			cout << "First array. " << endl;
			Sleep(3000);
			newArr(arrayIhw2, size);
			showarr(arrayIhw2, size);
			cout << "Second array. " << endl;
			Sleep(3000);
			arraySum(arrayIhw1, arrayIhw2, arrayIhwSum, size);
			showarr(arrayIhwSum, size);
			cout << "Their summary. " << endl;
			Sleep(3000);
			break;
		case 0:
			break;
		default:
			cout << "Error! Try again.";
		}
	}
	return 0;
}