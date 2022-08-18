#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> inputNumbers() {
	vector<int> numbers;
	//your code here
	int n;
	cout<<"\nEnter the number of elements, n = ";
	cin>>n;

	for(int i=0,x;i<n;i++) {
        cout<<"Enter a["<<i<<"] = ";
        cin>>x,numbers.push_back(x);
	}

	return numbers;

}

vector<int> findBiggestAnd2ndBiggest(vector<int> numbers) {
	vector<int> result;
	//your code here

    int mx=0;

	for(int i=1;i<numbers.size();i++)
        if(numbers[i]>numbers[mx]) mx=i;

    int mx2= mx == 0 ? 1 : 0;

    for(int i=1;i<numbers.size();i++)
        if(i!=mx && numbers[i]>numbers[mx2]) mx2=i;

    result.push_back(numbers[mx]);
    result.push_back(numbers[mx2]);

	return result;
}

vector<int> sortBubble(vector<int> numbers) {
	vector<int> sortedNumbers;
	//your code here
	int n = numbers.size();

    for(int i=n-2;i>=0;i--)
        for(int j=0;j<=i;j++)
            if(numbers[j] < numbers[j+1])
                swap(numbers[j], numbers[j+1]);

    for(int x : numbers) sortedNumbers.push_back(x);

	return sortedNumbers;
}

vector<int> insertValues(vector<int> newValues, vector<int> numbers) {
	vector<int> insertedNumbers;
	//your code here

    vector<int> cnt(1007,0);

    for(int x : newValues) cnt[x]++;
    for(int x : numbers) cnt[x]++;

    for(int i=1000;i>=0;i--) for(int j=1;j<=cnt[i];j++) insertedNumbers.push_back(i);

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
