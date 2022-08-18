#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
//You can use one among Dev-C++ or visual studio or visual studio code for testing
using namespace std;


int inputNumber() {
	int number = -1;
	cin >> number;
	//your code here
	return number;
}
const int mxx = 1e6;
bool isPrime[mxx + 10];
void init_prime(){
	memset(isPrime, 1, sizeof isPrime);
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2; i*i <= mxx; ++i){
		if(isPrime[i])
			for(int j = i+i; j*j <= mxx; j += i)
				isPrime[j] = 0;
	}
}
bool is_padlindrome(int number){
	vector<int>digit;
	while(number){
		digit.push_back(number%10);
		number /= 10;
	}
	int n = digit.size();
	for(int i = 0 ; i <= n/2 - 1; ++i){
		if(digit[i] != digit[n-i-1])
			return 0;
	}
	return 1;
}
vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
	for(int i = 2; i <= number; ++i)
		if(isPrime[i])
			listPrime.push_back(i);
	//your code here
	return listPrime;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	vector<int>digit(number);
	int lim = number/2 - 1;
	for(int i = 0; i <= lim; ++i){
		for(int j  = 1; j <= 9; ++j){
			digit[i] = digit[number-i-1] = j;
			int getNum = 0;
			for(auto z: digit)
				getNum = getNum * 10 + z;
			listReversible.push_back(getNum);
		}
	}
	//your code here
	return listReversible;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	vector<int>digit(number);
	int lim = number/2 - 1;
	for(int i = 0; i <= lim; ++i){
		for(int j  = 1; j <= 9; ++j){
			digit[i] = digit[number-i-1] = j;
			int getNum = 0;
			for(auto z: digit)
				getNum = getNum * 10 + z;
			if(is_padlindrome(getNum))
				listReversible_Sum.push_back(getNum);
		}
	}
	//your code here
	return listReversible_Sum;
}

//do not change anything in the main method
int main(int argc,char** args) {
	init_prime();
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