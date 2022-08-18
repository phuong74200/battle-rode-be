#include <cstring>
#include <stdio.h>
#include <iostream>
#include <vector>
//You can use one among Dev-C++ or visual studio or visual studio code for testing
using namespace std;

bool prime[1000001];

void siveve() {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= 1000; i++) {
		for (int j = i * i; j <= 1000001; j += i) {
			prime[j] = false;
		}
	}
}

bool reversible(int n) {
	long long ans  = n;
	long long res = 0;
	while (n) {
		res = res*10 + n%10;
		n/=10;
	}
	return res == ans;
}

bool Sum_of_Digits_check(int n) {
	long long s =0;
	while (n) {
		s += (n % 10);
		n /= 10;
	}
	if (reversible(s)) {
		return true;
	}
	else {
		return false;
	}
}

int inputNumber() {
	int number = -1;
	cin >> number;
	return number;
}

vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
	siveve();
	if (prime[number]) {
		listPrime.push_back(number);
	}
	return listPrime;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	if (reversible(number)) {
		listReversible.push_back(number);
	}
	return listReversible;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	if (Sum_of_Digits_check(number)) {
		listReversible_Sum.push_back(number);
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