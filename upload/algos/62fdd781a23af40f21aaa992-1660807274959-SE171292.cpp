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

vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
	auto check_prime = [&](int x) -> int{
        if(x < 2) return false;
        if(x == 2 || x == 3) return true;
        for(int i=2;i*i<=x;i++){
            if(x % i == 0) return false;
        }
        return true;
	};
    int L = 1;
    for(int i=1;i<=number;i++) L*=10;
	for(int i=L/10;i<=L-1;i++){
        if(check_prime(i)){
            listPrime.push_back(i);
        }
	}
	return listPrime;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	auto check_reversible = [&](int x) -> int{
        int tmp = x;
        int res = 0;
        while(tmp > 0){
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        return (res == x);
	};
	int L = 1;
    for(int i=1;i<=number;i++) L*=10;
    for(int i=L/10;i<=L-1;i++){
        if(check_reversible(i)){
            listReversible.push_back(i);
        }
    }
	return listReversible;
}

vector<int> getReversible_SumList(int number){
	vector<int>listReversible_Sum;
	auto sum_of_digit = [&](int x) -> int{
        int res = 0;
        while(x){
            res += x % 10;
            x /= 10;
        }
        return res;
	};
	auto check_reversible = [&](int x) -> int{
        int tmp = x;
        int res = 0;
        while(tmp > 0){
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        return (res == x);
	};
	int L = 1;
    for(int i=1;i<=number;i++) L*=10;
    for(int i=L/10;i<=L-1;i++){
        if(check_reversible(sum_of_digit(i))){
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

