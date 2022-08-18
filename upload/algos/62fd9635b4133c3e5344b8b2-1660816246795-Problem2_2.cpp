#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> inputNumbers() {
	int n;cin>>n;
	vector<int> numbers;
	for(int i = 0; i < n; ++i){
		int x;cin>>x;
		numbers.push_back(x);
	}
	//your code here
	return numbers;
}

vector<int> findBiggestAnd2ndBiggest(vector<int> numbers) {
	vector<int>tmp;
	for(auto i : numbers)
		tmp.push_back(i);
	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());
	int num1=tmp[0], idx1 = 0, num2=-1, idx2= -1;
	for(int i = 1; i < tmp.size(); ++i){
		if(tmp[i] != num1){
			idx2 = i;
			num2 = tmp[i];
			break;
		}
	}
	vector<int> ans;
	for(int i = 0; i < numbers.size(); ++i)
		if(numbers[i] == num1){
			ans.push_back(i);
			break;
		}
	for(int i = 0; i < numbers.size(); ++i)
		if(numbers[i] == num2){
			ans.push_back(i);
			break;
		}
	return ans;
}

vector<int> sortBubble(vector<int> numbers) {
	vector<int> sortedNumbers;
	for(auto i: numbers)
		sortedNumbers.push_back(i);
	int n = numbers.size();
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			if(sortedNumbers[i] <= sortedNumbers[j])
				swap(sortedNumbers[i], sortedNumbers[j]);
		}
	}
	return sortedNumbers;
}

vector<int> insertValues(vector<int> newValues, vector<int> numbers) {
	vector<int> insertedNumbers;
	for(auto i: newValues)
		insertedNumbers.push_back(i);
	for(auto i: numbers)
		insertedNumbers.push_back(i);

	auto newValueSorted = sortBubble(insertedNumbers);


	return newValueSorted;
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