#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> inputNumbers() {
	vector<int> numbers;
	int n;
	int m;
	cin>>n;
	for(int i=1;i<=n;i++)
		{
			cin>>m;	
			numbers.push_back(m);
		}
	return numbers;
}

vector<int> findBiggestAnd2ndBiggest(vector<int> numbers) {
	vector<int> result;
	int tmp=0;
	int max=0;
	for(int i=0;i<numbers.size() ;i++)
	for(int j=i+1;i<numbers.size()-1;j++)
	{
		if(numbers[i]>numbers[j])
		{
			tmp=numbers[i];
			numbers[i]=numbers[j];
			numbers[j]=tmp;
		}
	}
	max=numbers[0];
	result.push_back(max);
	result.push_back(0);
	for(int i=0;i<numbers.size();i++)
	{
		if(numbers[i]!=max)
		{
			result.push_back(numbers[i]);
			result.push_back(i+1);
			break;
		}
	}
	return result;
}

vector<int> sortBubble(vector<int> numbers) {
	vector<int> sortedNumbers;
	int tmp=0;
	for(int i=0;i<numbers.size() ;i++)
	for(int j=i+1;i<numbers.size()-1;j++)
	{
		if(numbers[i]<numbers[j])
		{
			tmp=numbers[i];
			numbers[i]=numbers[j];
			numbers[j]=tmp;
		}
	}
	for(int i=0;i<numbers.size();i++)
	{
		sortedNumbers.push_back(numbers[i]);
	}
	return sortedNumbers;
}

vector<int> insertValues(vector<int> newValues, vector<int> numbers) {
	vector<int> insertedNumbers;
	//your code here
	return insertedNumbers;
}

int main(int argv, char** args) {
//1.Input array
	cout << "Input arrays: ";
	vector<int> numbers = inputNumbers();
	cout << endl;
//	for(int i=0;i<numbers.size();i++)
//	{
//		cout<<numbers[i]<<endl;
//		}	
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