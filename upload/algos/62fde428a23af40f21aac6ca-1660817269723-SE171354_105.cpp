#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> inputNumbers()
{
	vector<int> numbers;
	// your code here
	int t;
	while (cin >> t)
		numbers.push_back(t);
	// numbers = {2, 1, 6, 5, 9};
	return numbers;
}

vector<int> findBiggestAnd2ndBiggest(vector<int> numbers)
{
	vector<int> result;
	// your code here
	int n = numbers.size();
	int a[n] = {};
	int j = 0;
	for (auto i : numbers)
	{
		a[j] = i;
		j++;
	}
	int meo = -1;
	int maxx = -1;
	int maxx2 = -1;
	int meomeo = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > maxx)
		{
			maxx = a[i];
			meo = i;
			continue;
		}
		if (a[i] > maxx2)
		{
			maxx2 = a[i];
			meomeo = i;
		}
	}
	result = {maxx, meo, maxx2, meomeo};
	return result;
}

vector<int> sortBubble(vector<int> numbers)
{
	vector<int> sortedNumbers;
	// your code here
	int n = numbers.size();
	int a[n] = {};
	int j = 0;
	for (auto i : numbers)
	{
		a[j] = i;
		j++;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j] < a[j + 1])
			{
				int k = a[j];
				a[j] = a[j + 1];
				a[j + 1] = k;
				// a[j], a[j + 1] = a[j + 1], a[j];
			}
		}
	}
	for (int i = 0; i < n; i++)
		sortedNumbers.push_back(a[i]);
	return sortedNumbers;
}

vector<int> insertValues(vector<int> newValues, vector<int> numbers)
{
	vector<int> insertedNumbers;
	// your code here
	for (auto i : newValues)
		numbers.push_back(i);

	return sortBubble(numbers);
}

int main(int argv, char **args)
{
	// 1.Input array
	cout << "Input arrays: ";
	vector<int> numbers = inputNumbers();
	cout << endl;

	// 2.Find 1st and 2nd biggest numbers
	cout << "1st and 2nd biggest numbers: ";
	auto result = findBiggestAnd2ndBiggest(numbers);
	for (auto data : result)
		cout << data << "\t";
	cout << endl;

	// 3. Sorted array
	cout << "Sorted array: ";
	auto sortedArray = sortBubble(numbers);
	for (auto data : sortedArray)
		cout << data << "\t";
	cout << endl;

	// 4. Insert values
	vector<int> newValues;
	cout << "Values to be inserted: ";
	newValues = inputNumbers();
	cout << endl
		 << "Inserted array: ";
	auto insertedArray = insertValues(newValues, numbers);
	for (auto data : insertedArray)
		cout << data << "\t";
	cout << endl;

	system("pause");
	return 0;
}