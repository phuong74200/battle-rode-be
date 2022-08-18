#include <algorithm>
#include <functional>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> inputNumbers() {
	vector<int> numbers;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		numbers.push_back(x);
	}
	return numbers;
}

vector<int> findBiggestAnd2ndBiggest(vector<int> numbers) {
	vector<int> result;
	int max1 = -1, max2 = -1;
	for (auto items : numbers) {
		if (items >= max1) {
			max2 = max1;
			max1 = items;
		}
		else if (items >= max2) {
			max2 = items;
		}
	}
	cout << max1 << " " << max2 << endl;
	result.push_back(max1);
	result.push_back(max2);
	return result;
}

vector<int> sortBubble(vector<int> numbers) {
	vector<int> sortedNumbers;
	for (auto items : numbers) {
		sortedNumbers.push_back(items);
	}
	sort(sortedNumbers.begin(), sortedNumbers.end(), greater<int> ());
	return sortedNumbers;
}

vector<int> insertValues(vector<int> newValues, vector<int> numbers) {
	vector<int> insertedNumbers;
	for (int items : numbers) {
		insertedNumbers.push_back(items);
	}
	for (int items : newValues) {
		insertedNumbers.push_back(items);
	}
	sort(insertedNumbers.begin(), insertedNumbers.end(), greater<int> ());
	return insertedNumbers;
}

int main(int argv, char** args) {
	//1.Input array
	cout << "Input arrays: ";
	vector<int> numbers = inputNumbers();
	cout << endl;
	
	//2.Find 1st and 2nd biggest numbers
	cout << "1st and 2nd biggest numbers: ";
	auto result = findBiggestAnd2ndBiggest(numbers);
	for (auto data : result) cout << data << "\t";
	cout << endl;

	//3. Sorted array
	cout << "Sorted array: ";
	auto sortedArray = sortBubble(numbers);
	for (auto data : sortedArray) cout << data << "\t";
	cout << endl;

	//4. Insert values
	vector<int> newValues;
	cout << "Values to be inserted: ";
	newValues = inputNumbers();
	cout<< endl << "Inserted array: ";
	auto insertedArray = insertValues(newValues, numbers);
	for (auto data : insertedArray) cout << data << "\t";
	cout << endl;

	system("pause");
	return 0;
}