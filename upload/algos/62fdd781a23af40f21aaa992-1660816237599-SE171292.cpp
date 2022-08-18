#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> inputNumbers() {
	vector<int> numbers;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        numbers.push_back(x);
	}
	return numbers;
}

vector<int> findBiggestAnd2ndBiggest(vector<int> numbers) {
	vector<int> result;
    int maxx = 0;
    for(int u:numbers){
        if(u > maxx){
            maxx = u;
        }
    }
    result.push_back(maxx);
    int tmp_maxx = maxx;
    maxx = 0;
    for(int u: numbers){
        if(u > maxx && u != tmp_maxx){
            maxx = u;
        }
    }
    result.push_back(maxx);
	return result;
}

vector<int> sortBubble(vector<int> numbers) {
	vector<int> sortedNumbers;
	int n = (int)(numbers.size());
	for(int i=0;i<n;i++){
        int minn = numbers[i], id = i;
        for(int j=i+1;j<n;j++){
            if(numbers[j] < minn){
                minn = numbers[j];
                id = j;
            }
        }
        swap(numbers[i],numbers[id]);
	}
	for(int u: numbers) sortedNumbers.push_back(u);
	return sortedNumbers;
}

vector<int> insertValues(vector<int> newValues, vector<int> numbers) {
	vector<int> insertedNumbers;
	numbers = sortBubble(numbers);
	reverse(numbers.begin(),numbers.end());
	auto inserting = [&](int val, vector<int> G){
        vector<int> T;
        int len = (int)(G.size());
        for(int i=0;i<len;i++){
            if(val >= G[i]){
                T.push_back(val);
                for(int j=i;j<len;j++){
                    T.push_back(G[j]);
                }
                return T;
            }
            else{
                T.push_back(G[i]);
            }
        }
        T.push_back(val);
        return T;
	};
	for(int u: newValues){
        numbers = inserting(u, numbers);
	}
	for(int u: numbers) insertedNumbers.push_back(u);
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
