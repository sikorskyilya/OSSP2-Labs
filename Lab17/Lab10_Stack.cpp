#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
bool Task1(char *word);
bool Task2(char *word);
bool Task3(char *word);
bool Task4(char *word);


template< class T >
class Stack {

private:
	int MAX;
	int top;
	T* items;

public:
	Stack(int size) {
		MAX = size;
		top = -1;
		items = new T[MAX];
	}

	~Stack() { delete[] items; }

	void push(T c) {
		if (full()) {
			cout << "Stack Full!" << endl;
			exit(1);
		}

		items[++top] = c;
	}

	T pop() {
		if (empty()) {
			cout << "Stack Empty!" << endl;
			return NULL;
			exit(1);
		}


		return items[top--];
	}

	T free() {
		top = -1;
		return true;
	}

	int empty() { return top == -1; }

	int full() { return top + 1 == MAX; }
};

int what;
char word[200] = { " " };

int main()
{
	setlocale(0, "");
	while (true)
	{
		char p[2] = { " " };
		cout << "Введите выражение:\n";
		gets_s(word);
		strcat_s(word, p);
		cout << "\nЧисло с фикс. точков: " << Task1(word);//2.1
		cout << "\nЧисло с плав. точков: " << Task2(word);//-2.1e-2
		cout << "\nКомплексное число: " << Task3(word);//5+2j 
		cout << "\nПростейшее алгебраическое выражение без скобок: " << Task4(word);//a+b
		cout << endl;
	}

	system("pause");
	return 0;
}


bool Task1(char *word)
{
	Stack<int> s(5);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (isdigit(word[i]) || word[i] == '-')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 1)
		{
			if (isdigit(word[i]))
				s.push(1);
			else if (word[i] == '.')
			{
				s.push(2);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 2)
		{
			if (isdigit(word[i]))
				s.push(3);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 3)
		{
			if (isdigit(word[i]))
				s.push(3);
			else if (word[i] == ' ')
			{
				return true;
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		return false;
	}


	return true;
}
bool Task2(char *word) {
	/////////////////////////
	Stack<int> s(8);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (isdigit(word[i]) || word[i] == '-' || word[i] == '+')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 1)
		{
			if (isdigit(word[i]))
				s.push(1);
			else if (word[i] == '.')
			{
				s.push(2);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 2)
		{
			if (isdigit(word[i]))
				s.push(3);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 3)
		{
			if (isdigit(word[i]))
				s.push(3);
			else if (word[i] == 'e')
			{
				s.push(4);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 4)
		{
			if (word[i] == '+' || word[i] == '-')
				s.push(5);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 5)
		{
			if (isdigit(word[i]))
				s.push(6);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 6)
		{
			if (isdigit(word[i]))
				s.push(6);
			else if (word[i] == ' ')
			{
				return true;
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		return false;
	}


	return true;
}
bool Task3(char *word)
{
	Stack<int> s(5);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (isdigit(word[i]) || word[i] == '-' || word[i] == '+')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 1)
		{
			if (isdigit(word[i]))
				s.push(1);
			else if (word[i] == '-' || word[i] == '+')
			{
				s.push(2);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 2)
		{
			if (isdigit(word[i]))
				s.push(2);
			else if (word[i] = 'j')
			{
				s.push(3);
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 3)
		{
			if (word[i] == ' ')
			{
				return true;
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		return false;
	}


	return true;
}
bool Task4(char *word)
{
	Stack<int> s(3);
	s.free();
	s.push(0);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		int sost = s.pop();
		if (sost == 0)
		{
			if (word[i] == 'b' || word[i] == 'a')
				s.push(1);
			else
			{
				s.push(-1);
			}
		}
		else if (sost == 1)
		{
			if (word[i] == '+' || word[i] == '-' || word[i] == '*' || word[i] == ':')
				s.push(0);
			else if (word[i] == ' ')
			{
				return true;
			}
			else
			{
				s.push(-1);
			}
		}
		else if (sost == -1)
		{
			return false;
		}
		else
		{
			s.push(-1);
		}
	}

	if (s.pop() == -1)
	{
		return false;
	}


	return true;
}
