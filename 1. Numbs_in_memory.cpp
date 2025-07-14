#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int item = 1;
	int value1;
	unsigned int order = 32, mask = 1 << order - 1;
	union {
		int tool1;
		float value2;
	};
	int value3;
	while (item) {
		cout << "Choose the item: " << endl <<
			"1. Show the size of the allocated memory for data types." << endl <<
			"2. Show how the number is stored in memory (integer)." << endl <<
			"3. Show how the number is stored in memory (float)." << endl <<
			"4. Show individual homework." << endl <<
			"0. Stop working with code." << endl;
		cin >> item;
		switch (item) {
		case 1:
			cout << "\t1) \n" << sizeof(int) << " bytes are allocated in memory to store data of the int type.\n";
			cout << sizeof(short int) << " bytes are allocated in memory to store data of the short int type.\n";
			cout << sizeof(long int) << " bytes are allocated in memory to store data of the long int type.\n";
			cout << sizeof(float) << " bytes are allocated in memory to store data of the float type.\n";
			cout << sizeof(double) << " bytes are allocated in memory to store data of the double type.\n";
			cout << sizeof(long double) << " bytes are allocated in memory to store data of the long double type.\n";
			cout << sizeof(char) << " bytes are allocated in memory to store data of the char type.\n";
			cout << sizeof(bool) << " bytes are allocated in memory to store data of the bool type.\n\n";
			break;
		case 2:
			cout << "\t2) \nEnter an integer: ";
			cin >> value1;
			for (int i = 1; i <= order; i++)
			{
				cout << (value1 & mask ? '1' : '0');
				mask >>= 1;
				if (i % 8 == 0)
					cout << ' ';
				if (i % order - 1 == 0)
					cout << ' ';
			}
			break;
		case 3:
			cout << "\n\n\t3) \nEnter a real number: ";
			cin >> value2;
			mask = 1 << order - 1;
			for (int i = 1; i <= order; i++)
			{
				cout << (tool1 & mask ? '1' : '0');
				mask >>= 1;
				if (i == 1)
					cout << ' ';
				if (i == 9)
					cout << ' ';
			}
			break;
		case 4:
			cout << "\n\n Individual homework: \n Enter an integer: ";
			cin >> value3;
			mask = 1 << order - 1;
			if (value3 < 0)
			{
				for (int i = 1; i <= order; i++)
				{
					if (i % 2 == 0)
						cout << '0';
					else
						cout << (value1 & mask ? '1' : '0');
					mask >>= 1;
					if (i % 8 == 0)
						cout << ' ';
					if (i % order - 1 == 0)
						cout << ' ';
				}
			}
			if (value3 > 0)
			{
				for (int i = 1; i <= order; i++)
				{
					if (i % 2 == 1)
						cout << '1';
					else
						cout << (value1 & mask ? '1' : '0');
					mask >>= 1;
					if (i % 8 == 0)
						cout << ' ';
					if (i % order - 1 == 0)
						cout << ' ';
				}
			}
			break;
		}
	}	
	return 0;
}