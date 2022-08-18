#include <stdio.h>
#include <iostream>
#include <vector>
//You can use one among Dev-C++ or visual studio or visual studio code for testing
using namespace std;
int inputNumber() {
	int number = -1;
	int res = 1;
	cin >> number;
	for(int i = 0; i < number; i++){
		res *= 10;
	}
	return res;
}

vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
	bool check;
	vector <int> v;
	for(int i = 0; i < number; i++) v.push_back(i);
	for(auto x : v){
		check = true;
		if(x % 2 == 0) check = false;
		for(int i = 3; i * i <= x; i += 2) if(x % i == 0){
			check = false;
			break;
		}
		if(check) listPrime.push_back(x);
	}
	return listPrime;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	int n, temp;
	vector <int> v;
	for(int i = 0; i < number; i++) v.push_back(i);
	for(auto x : v){
		n = x;
		temp = 0;
		while(x > 0){
			temp += x % 10;
			x /= 10;
			temp *= 10;
		}
		temp /= 10;
		if(temp == n) listReversible.push_back(n);
	}
	return listReversible;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	int sum, temp, n;
	vector <int> v;
	for(int i = 0; i < number; i++) v.push_back(i);
	for(auto x : v){
		sum = 0, n = x;
		while(x > 0){
			temp = x % 10;
			x /= 10;
			sum += temp;
		}
		temp = 0;
		x = sum;
		while(x > 0){
			temp += x % 10;
			x /= 10;
			temp *= 10;
		}
		temp /= 10;
		if(temp == sum) listReversible_Sum.push_back(n);
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
