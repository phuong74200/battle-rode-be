#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> inputNumbers() {
	vector<int> numbers;
	int n, x;
	cin >> n;
	while(n--)
    {
        cin >> x;
        numbers.push_back(x);
    }
	return numbers;
}

vector<int> findBiggestAnd2ndBiggest(vector<int> numbers) {
	vector<int> result;
    int largest = 0;
    int largest2 = 0;
    int idx;
    int idx2;
    int i = 0;
    for(auto data : numbers)
    {
        if(data > largest)
        {
            largest = data;
            idx = i;
        }
        i++;
    }
    i = 0;
    for(auto data : numbers)
    {
        if(data > largest2 && i != idx)
        {
            largest2 = data;
            idx2 = i;
        }
        i++;
    }
    result.push_back(largest);
    result.push_back(largest2);
    result.push_back(idx);
    result.push_back(idx2);
	return result;
}

vector<int> sortBubble(vector<int> numbers) {
	vector<int> sortedNumbers;
	for(int i = 0; i < numbers.size(); i++)
        for(int j = 0; j <= i; j++)
        {
            if(numbers[j] < numbers[j + 1])
            {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    for(auto data : numbers) sortedNumbers.push_back(data);
	return sortedNumbers;
}

vector<int> insertValues(vector<int> newValues, vector<int> numbers) {
	vector<int> insertedNumbers;
	int i = 0, j = 0;
	while(i < newValues.size()  && j < numbers.size())
    {
        if(newValues[i] > numbers[j])
        {
            insertedNumbers.push_back(newValues[i]);
            i++;
        }
        else
        {
            insertedNumbers.push_back(numbers[j]);
            j++;
        }
    }
    while(i < newValues.size())
    {
        insertedNumbers.push_back(newValues[i]);
    }
    while(j < numbers.size())
    {
        insertedNumbers.push_back(numbers[j]);
    }
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
