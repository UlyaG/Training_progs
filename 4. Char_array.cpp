#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int length(char s[])
{
	unsigned int length = 0;
	while (s[length])   
		length++;
	return length;
}

void offset(char s[], int length, int i)
{
	for (int j = i; j < length; j++)
	{
		s[j] = s[j + 1];
	}
}

void backspace(char s[], int length, char symbol)
{
	bool k=1;
	for (int i = 0; i < length; i++)
	{
		while (k) {
			if ((s[i] == s[i + 1]) && (s[i] == symbol))
			{
				offset(s, length, i);
			}
			else k = 0;
		}
		k = 1;
	}
}

void backspace1(char s[], int length, char symbol)
{
	bool k = 1;
	for (int i = 0; i < length; i++)
	{
		while (k) {
			if ((s[i] == symbol))
			{
				offset(s, length, i);
			}
			else k = 0;
		}
		k = 1;
	}
}


void regist(char s[], int length)
{
	for (int i = 1; i < length; i++)
	{
		if ((s[i] >= 'A') && (s[i] <= 'Z'))
		{
			s[i] = s[i] + 32;
		}
	}
}

void editText(char s[], int n)
{
	backspace(s, n, ' ');
	backspace1(s, n, ',');
	backspace1(s, n, '!');
	backspace1(s, n, '(');
	backspace1(s, n, ')');
	backspace1(s, n, '-');
	backspace1(s, n, '"');
	backspace1(s, n, '?');
	backspace1(s, n, ';');
	backspace1(s, n, ':');
	backspace1(s, n, '/');
	backspace1(s, n, '0');
	backspace1(s, n, '1');
	backspace1(s, n, '2');
	backspace1(s, n, '3');
	backspace1(s, n, '4');
	backspace1(s, n, '5');
	backspace1(s, n, '6');
	backspace1(s, n, '7');
	backspace1(s, n, '8');
	backspace1(s, n, '9');
	regist(s, n);
}

int theBiggestWord(char s[], int length)
{
	int k = 0, max=0;
	for (int i = 0; i < length; i++)
	{
		if (s[i] != ' ')
		{
			k++;
			if (k > max)
				max = k;
		}
		else k = 0;
	}
	return max;
}

int howManyWords(char s[], int length)
{ 
	int k = 0;
	for (int i = 0; i < length; i++)
	{
		if ((s[i]==' ') && (s[i+1] >= 'a') && (s[i+1] <= 'z'))
		{
			k++;
		}
	}
	return k + 1;
}

int searchSubstring(char text[], char pattern[])
{
	int n = length(text);
	int m = length(pattern); 

	for (int i = 0; i <= n - m; i++) {
		int j;
		for (j = 0; j < m-1; j++) {
			if (text[i + j] != pattern[j + 1])
				break;
		}


		if (j == m-1) 
			return i; 
	}

	return -1;
}

void swapStrings(char** arr, int i, int j) {
	char* temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main() {
	const int n = 50 * 30;
	char text[n];
	int leng;

	//Ввод и форматирование текста
	cout << "Enter your text (use only latin letters): " << endl;
	cin.getline(text, n, '.');
	leng = length(text);
	editText(text, leng);
	cout << endl << "You formatted text: " << endl << text << endl;
	system("Pause");
	leng = length(text);
	
	//Создание словаря текста
	int letters = 30, words = howManyWords(text, leng);
	char** allWords;
	allWords = new char* [words];
	for (int i = 0; i < words; i++)
		allWords[i] = new char[letters];
		
	//Заполнение словаря
	int k = 0, l = 0;
	for (int i = 0; i < leng; i++)
	{
		if (((text[i] >= 'A') && (text[i] <= 'Z')) || ((text[i] >= 'a') && (text[i] <= 'z')))
		{
			allWords[k][l] = text[i];
			allWords[k][l+1] = '\0';
			l++;
		}
		else
		{
			k++;
			l = 0;
		}
	}

	//Сортировка словаря
	k = 1;
	while (k > 0)
	{
		k = 0;
		for (int i = 0; i < words - 1; i++)
		{
			if (strcmp(allWords[i], allWords[i + 1]) > 0)
			{
				char B[50];
				strcpy(B, allWords[i]);
				strcpy(allWords[i], allWords[i + 1]);
				strcpy(allWords[i + 1], B);
				k++;
			}
		}
	}
	cout << endl << "Dictionary of text alphabetically: " << endl;
	for (int i = 0; i < words; i++)
			cout << allWords[i] << endl;
	system("Pause");

	//Замена на прописную букву
	for (int i = 0; i < words; i++)
	{
		if ((allWords[i][0] >= 'a') && (allWords[i][0] <= 'z'))
		{
			allWords[i][0] = allWords[i][0] - 32;
		}
	}
	cout << endl << "Dictionary of text alphabetically (first letter are capital): " << endl;
	for (int i = 0; i < words; i++)
		cout << allWords[i] << endl;
	system("Pause");

	//Поиск 
	char word[50];
	cout << endl<< "Enter your word (with point in end): " << endl;
	cin.getline(word, 50, '.');
	int result = searchSubstring(text, word);
	if (result == -1)
		cout << "Your word didn't found" << endl;
	else
		cout << "Your word was founded with index: " << result << endl;

	
	return 0;
}