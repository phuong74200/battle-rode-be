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

bool f[100000001];

vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
    int st = 1, en = 10;
    for (int i = 1; i < number; i++){
        st *= 10;
        en *= 10;
    }
    en--;
    fill(f, f+10000000, 0);
    f[1] = 1;
    for (long long i = 2; i <= 40000; i++)
        if (!f[i]){
            for (long long j = i*i; j <= 10000000; j+=i)
                f[j] = 1;
        }
    for (int i = st; i <= en; i++)
    {
        if (!f[i]) listPrime.push_back(i);
    }
	return listPrime;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	int st = 1, en = 10;
    for (int i = 1; i < number; i++){
        st *= 10;
        en *= 10;
    }
    en--;
    for (int i = st; i <= en; i++){
        int tmp = i, i2 = 0;
        while(tmp){
            i2 = i2*10 + tmp%10;
            tmp /= 10;
        }
        if (i2 == i) listReversible.push_back(i);
    }
	return listReversible;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	int st = 1, en = 10;
    for (int i = 1; i < number; i++){
        st *= 10;
        en *= 10;
    }
    en--;
    for (int i = st; i <= en; i++){
        int tmp = i, i2 = 0, s = 0;
        while(tmp){
            s += tmp%10;
            tmp /= 10;
        }
        tmp = s;
        while(tmp){
            i2 = i2*10 + tmp%10;
            tmp /= 10;
        }
        if (i2 == s) listReversible_Sum.push_back(i);
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
