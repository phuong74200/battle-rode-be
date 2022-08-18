#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

bool isValid(int num) {
    return num > 0 && num < 100;
}

vector<int> inputNumbers() {
	vector<int> numbers;
	//your code here

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int num = -1;
        do {
            cin >> num;
        } while (!isValid(num));
        numbers.push_back(num);
    }

	return numbers;
}

vector<int> findBiggestAnd2ndBiggest(vector<int> numbers) {
	vector<int> result;
	//your code here
    int maxNum = -1;
    int posMaxNum = -1;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > maxNum) {
            maxNum = numbers[i];
            posMaxNum = i;
        }
    }
    int secondMaxNum = -1;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > secondMaxNum && i != posMaxNum) {
            secondMaxNum = numbers[i];
        }
    }
    result.push_back(maxNum);
    result.push_back(secondMaxNum);
	return result;
}

vector<int> sortBubble(vector<int> numbers) {
	vector<int> sortedNumbers;
	//your code here
    for (int num: numbers) sortedNumbers.push_back(num);

    for (int i = 0; i < sortedNumbers.size(); i++) {
        for (int j = i + 1; j < sortedNumbers.size(); j++) {
            if (sortedNumbers[i] < sortedNumbers[j]) {
                swap(sortedNumbers[i], sortedNumbers[j]);
            }
        }
    }
	return sortedNumbers;
}

vector<int> insertValues(vector<int> newValues, vector<int> numbers) {
	vector<int> insertedNumbers;
	//your code here
    for (int i = 0; i < numbers.size(); i++) {
        insertedNumbers.push_back(numbers[i]);
    }
    for (int i = 0; i < newValues.size(); i++) {
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