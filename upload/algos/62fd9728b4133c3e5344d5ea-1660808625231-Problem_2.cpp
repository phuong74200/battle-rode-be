#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
//You can use one among Dev-C++ or visual studio or visual studio code for testing
using namespace std;
int inputNumber() {
	int number = -1;
	//your code here
	cin >> number;
	return number;
}

int checkPrime(int n) {
	if(n < 2) return 0;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int checkReverse(int n) {
	vector<int> a;
	int x = n;
	while(x) {
		a.push_back(x % 10);
		x /= 10;
	}
	for(int i = 0; i < a.size() / 2; i++) {
		if(a[i] != a[a.size() - 1 - i]) {
			return 0;
		}
	}
	return 1;
}

int sumOfDig(int n) {
	int x = n;
	int sum = 0;
	while(x) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
	//your code here
	unsigned long long n = pow(10, number);
	for(unsigned long long i = 0; i < n; i++) {
		if(checkPrime(i)) {
 			listPrime.push_back(i);
		}
	}
	return listPrime;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	//your code here
	if(number == 0) {
		listReversible.push_back(0);
		return listReversible;
	}
	unsigned long long n = pow(10, number);
	for(unsigned long long i = 0; i <= n; i++) {
		if(checkReverse(i)) {
 			listReversible.push_back(i);
		}
	}
	return listReversible;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	//your code here
	if(number == 0) {
		listReversible_Sum.push_back(0);
		return listReversible_Sum;
	}
	unsigned long long n = pow(10, number);
	for(unsigned long long i = 0; i < n; i++) {
		if(checkReverse(sumOfDig(i))) {
			listReversible_Sum.push_back(i);
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