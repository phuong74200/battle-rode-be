#include <stdio.h>
#include <iostream>
#include <vector>

// You can use one among Dev-C++ or visual studio or visual studio code for testing
using namespace std;
int inputNumber()
{
	int number = -1;
	// your code here
	cin >> number;
	return number;
}

vector<int> getPrimeNumberList(int number)
{
	vector<int> listPrime;
	// your code here
	if (number == 1)
	{
		listPrime = {2, 3, 5, 7};
		return listPrime;
	}
	long long k = 1;
	for (int i = 1; i < number; i++)
		k *= 10;
	k++;
	int m = k * 10 - 1;
	for (int i = k; i < m; i += 2)
	{
		int check = 0;
		int j = 3;
		while (j * j <= i)
		{
			if (i % j == 0)
			{
				check = 1;
				break;
			}
			j += 2;
		}
		if (check == 0)
			listPrime.push_back(i);
	}
	return listPrime;
}

vector<int> getReversibleList(int number)
{
	vector<int> listReversible;
	// your code here
	if (number == 1)
	{
		listReversible = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		return listReversible;
	}
	long long k = 1;
	for (int i = 1; i < number; i++)
		k *= 10;
	int m = k * 10 - 1;
	for (int i = k; i <= m; i++)
	{
		int re = 0;
		int t = i;
		while (t != 0)
		{
			re = re * 10 + t % 10;
			t /= 10;
		}
		if (re == i)
			listReversible.push_back(i);
	}

	return listReversible;
}

vector<int> getReversible_SumList(int number)
{
	vector<int> listReversible_Sum;
	// your code here
	if (number == 1)
	{
		listReversible_Sum = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		return listReversible_Sum;
	}
	long long k = 1;
	for (int i = 1; i < number; i++)
		k *= 10;
	int m = k * 10 - 1;
	for (int i = k; i <= m; i++)
	{
		int summ = 0;
		int t = i;
		while (t != 0)
		{
			summ += t % 10;
			t /= 10;
		}
		int re = 0;
		t = summ;
		while (t != 0)
		{
			re = re * 10 + t % 10;
			t /= 10;
		}
		if (re == summ)
			listReversible_Sum.push_back(i);
	}

	return listReversible_Sum;
}

// do not change anything in the main method
int main(int argc, char **args)
{
	// 1.Input number
	cout << "input number: ";
	int number = inputNumber();
	cout << endl;

	// 2.Prime list
	cout << "Prime List: ";
	auto listPrime = getPrimeNumberList(number);
	for (auto data : listPrime)
		cout << data << "\t";
	cout << endl;

	// 3.Reversible List
	cout << "Reversible List: ";
	auto listReversible = getReversibleList(number);
	for (auto data : listReversible)
		cout << data << "\t";
	cout << endl;

	// 4. Reversible_Sum List
	cout << "Reversible_Sum List: ";
	auto listReversible_Sum = getReversible_SumList(number);
	for (auto data : listReversible_Sum)
		cout << data << "\t";
	cout << endl;

	system("pause");
	return 0;
}