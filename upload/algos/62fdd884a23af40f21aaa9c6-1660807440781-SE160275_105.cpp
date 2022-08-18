#include <stdio.h>
#include <iostream>
#include <vector>
//You can use one among Dev-C++ or visual studio or visual studio code for testing
using namespace std;

int inputNumber() {
	int number = -1;
	cin >> number;
	return number;
}

long long power(int number) {
	if (number == 0) return 0;
	long long res = 1;
	for (int i = 0; i < number; ++i)
		res *= 10;
	return res;
}

bool checkPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
	//your code here

	int r = power(number);
	int l = power(number - 1);

	for (int i = l; i < r; ++i)
		if (checkPrime(i)) listPrime.push_back(i);

	return listPrime;
}

bool checkReversible(int n) {
	vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	for (int i = 0; i < digits.size(); ++i)
		if (digits[i] != digits[digits.size() - i - 1]) return false;
	return true;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	//your code here
	int l = power(number - 1);
	int r = power(number);

	for (int i = l; i < r; ++i) {
		if (checkReversible(i)) listReversible.push_back(i);
	}

	return listReversible;
}

int get_sum_digit(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	//your code here

	int l = power(number - 1);
	int r = power(number);

	for (int i = l; i < r; ++i)
		if (checkReversible(get_sum_digit(i))) listReversible_Sum.push_back(i);

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