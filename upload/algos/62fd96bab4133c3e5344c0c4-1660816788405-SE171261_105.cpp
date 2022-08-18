#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> inputNumbers() {
	vector<int> numbers;
	//your code here
  int n;cin>>n;
  int a;
  for(int i=1;i<=n;i++) {
    cin>>a;
    numbers.push_back(a);
  }
  
	return numbers;
}

vector<int> findBiggestAnd2ndBiggest(vector<int> numbers) {
	vector<int> result;
	//your code here
  int max1=0,max2=0;
  if(numbers[1]>numbers[0]) {
    max1=numbers[1];max2=numbers[0];
  }
  else if(numbers[0]>numbers[1]) {
    max1= numbers[0];max2=numbers[1];
  }
  else max1=numbers[0];
  for(int i=0;i<numbers.size();i++) {
    if(numbers[i]>max1) {
      max2=max1;
      max1=numbers[i];
    }
    else if(numbers[i]<max1) {
      if(numbers[i]>max2) max2=numbers[i];
    }
  }
  result.push_back(max1);
  result.push_back(max2);
	return result;
}

vector<int> sortBubble(vector<int> numbers) {
	vector<int> sortedNumbers;
	//your code here
  for(int i=0;i<numbers.size();i++) {
    for(int j=1;j<numbers.size()-i;j++) {
      if(numbers[j-1]<numbers[j]) {
        int temp=numbers[j-1];
        numbers[j-1]=numbers[j];
        numbers[j]=temp;
      }
    }
  }
  for(int i=0;i<numbers.size();i++) {
    sortedNumbers.push_back(numbers[i]);
  }
	return sortedNumbers;
}

vector<int> insertValues(vector<int> newValues, vector<int> numbers) {
	vector<int> insertedNumbers;
	//your code here
  for(int i=0;i<newValues.size();i++) {
    numbers.push_back(newValues[i]);
  }
  for(int i=0;i<numbers.size();i++) {
    for(int j=1;j<numbers.size()-i;j++) {
      if(numbers[j-1]<numbers[j]) {
        int temp=numbers[j-1];
        numbers[j-1]=numbers[j];
        numbers[j]=temp;
      }
    }
  }
  for(int i=0;i<numbers.size();i++) {
    insertedNumbers.push_back(numbers[i]);
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