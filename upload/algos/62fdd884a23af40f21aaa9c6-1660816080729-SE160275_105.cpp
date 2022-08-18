#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> inputNumbers() {
	vector<int> numbers;
	//your code here
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        numbers.push_back(x);
    }
	return numbers;
}

vector<int> findBiggestAnd2ndBiggest(vector<int> numbers) {
	vector<int> result;
	//your code here
    int max_index = -1;
    for (int i = 0; i < numbers.size(); ++i)
        if (max_index == -1 || numbers[i] > numbers[max_index]) 
            max_index = i;

    int second_max_index = -1;
    for (int i = 0; i < numbers.size(); ++i) 
        if (numbers[i] != numbers[max_index]) {
            if (second_max_index == -1 || numbers[i] > numbers[second_max_index])
                second_max_index = i;
        }

    result.push_back(numbers[max_index]);
    result.push_back(numbers[second_max_index]);
    result.push_back(max_index);
    result.push_back(second_max_index);

	return result;
}

vector<int> sortBubble(vector<int> numbers) {
	vector<int> sortedNumbers;
	//your code here
    int n = numbers.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (numbers[j] > numbers[i]) {
                swap(numbers[i], numbers[j]);
            }
    for (int i = 0; i < n; ++i)
        sortedNumbers.push_back(numbers[i]);
	return sortedNumbers;
}

vector<int> insertValues(vector<int> newValues, vector<int> numbers) {
	vector<int> insertedNumbers;
	//your code here
    for (int i : newValues) {
        numbers.push_back(i);
    }
    insertedNumbers = sortBubble(numbers);
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