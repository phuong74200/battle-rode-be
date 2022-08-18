#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> inputNumbers() {
	vector<int> numbers;
	//your code here
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		numbers.push_back(x);
	}
	return numbers;
}

vector<int> sortBubble(vector<int> numbers) {
	vector<int> sortedNumbers;
	//your code here
	sortedNumbers = numbers;
	int length = numbers.size();
	for(int i = 0; i < length; i++) { 
		for(int j = length - 1; j >= i; j--) {
			if(sortedNumbers[j] >= sortedNumbers[j - 1]) {
				swap(sortedNumbers[j], sortedNumbers[j - 1]);
			}
		}
	}
	return sortedNumbers;
}

vector<int> findBiggestAnd2ndBiggest(vector<int> numbers) {
	vector<int> result;
	//your code here
	vector<int> x = sortBubble(numbers);
	int length = numbers.size();
	result.push_back(numbers[length - 1]);
	result.push_back(numbers[length - 2]);
	return result;
}



vector<int> insertValues(vector<int> newValues, vector<int> numbers) {
	vector<int> insertedNumbers;
	//your code here
	int length = newValues.size();
	insertedNumbers = numbers;
	for(int i = 0; i < length; i++) {
		insertedNumbers.push_back(newValues[i]);
	}
	insertedNumbers = sortBubble(insertedNumbers);
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