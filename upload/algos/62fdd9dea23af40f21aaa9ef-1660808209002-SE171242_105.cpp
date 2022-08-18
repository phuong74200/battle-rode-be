#include <stdio.h>
#include <iostream>
#include <vector>
//You can use one among Dev-C++ or visual studio or visual studio code for testing
using namespace std;
int inputNumber() {
	int number = -1;
	int n;
	cin >> n;
	number = n;
	return number;
}

vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
	//your code here
	int n = number;
	if (n == 0){
		return listPrime;
	}
	string mxS = "";
	for (int i = 0; i < n; i++){
		mxS = mxS + "9";
	}
	string mnS = "1";
	for (int i = 0; i < n - 1; i++){
		mnS = mnS + "0";
	}
	
	int mn = stoi(mnS), mx = stoi(mxS);
	for (int i = max(mn, 2); i <= mx; i++){
		bool check = 1;
		for (int j = 2; j * j <= i; j++){
			if (i % j == 0){
				check = 0;
				break;
			}
		}
		if (check) listPrime.push_back(i);
	}
	return listPrime;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	int n = number;
	
	if (n == 0){
		return listReversible;
	}
	string mxS = "";
	for (int i = 0; i < n; i++){
		mxS = mxS + "9";
	}
	string mnS = "1";
	for (int i = 0; i < n - 1; i++){
		mnS = mnS + "0";
	}
	
	int mn = stoi(mnS), mx = stoi(mxS);
	for (int curNum = mn; curNum <= mx; curNum++){
		string curString = to_string(curNum);
		
		int p1 = 0, p2 = curString.size() - 1;
		while(p1 < p2){
			if (curString[p1] == curString[p2]){
				p1++;
				p2--;
			}
			else break;
		}
		if (p1 >= p2){
			listReversible.push_back(curNum);
		}
	}
	return listReversible;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	
	int n = number;
	
	if (n == 0){
		return listReversible_Sum;
	}
	string mxS = "";
	for (int i = 0; i < n; i++){
		mxS = mxS + "9";
	}
	string mnS = "1";
	for (int i = 0; i < n - 1; i++){
		mnS = mnS + "0";
	}
	
	int mn = stoi(mnS), mx = stoi(mxS);
	
	for (int curNum = mn; curNum <= mx; curNum++){
		string curString = to_string(curNum);
		int tmp = 0;
		for (int i = 0; i < curString.size(); i++){
			tmp += (curString[i] - '0');
		}
		
		string s = to_string(tmp);
		int p1 = 0, p2 = s.size() - 1;
		while(p1 < p2){
			if (s[p1] == s[p2]){
				p1++;
				p2--;
			}
			else break;
		}
		if (p1 >= p2){
			listReversible_Sum.push_back(curNum);
		}
	}
	
	return listReversible_Sum;
}

//do not change anything in the main method
int main(int argc,char** args) {
	//1.Input number
	cout<<"input number: ";
	int number = inputNumber();
	cout << endl;

	//2.Prime list
	cout << "Prime List: ";
	auto listPrime = getPrimeNumberList(number);
	for (auto data : listPrime) cout << data << "\t";
	cout << endl;

	//3.Reversible List
	cout << "Reversible List: ";
	auto listReversible = getReversibleList(number);
	for (auto data : listReversible) cout << data << "\t";
	cout << endl;

	//4. Reversible_Sum List
	cout << "Reversible_Sum List: ";
	auto listReversible_Sum = getReversible_SumList(number);
	for (auto data : listReversible_Sum) cout << data << "\t";
	cout << endl;

	system("pause");
	return 0;
}
