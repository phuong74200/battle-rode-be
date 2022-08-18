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
	long long a = 1, b = 10;
	number--;
	while(number--)
    {
        a *= 10;
        b *= 10;
    }
    bool is_prime[b];
    for(long long i = 0; i < b; i++)
    {
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;
    for(long long i = 2; i < b; i++)
    {
        if(is_prime[i])
        {
            int j = 2;
            while(i * j < b)
            {
                is_prime[i * j] = false;
                j++;
            }
        }
    }
    for(int i = a; i < b; i++) if(is_prime[i]) listPrime.push_back(i);
	return listPrime;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	long long a = 1, b = 10;
	number--;
	while(number--)
    {
        a *= 10;
        b *= 10;
    }
    if(number == 1) a = 0;
    for(int i = a; i < b; i++)
    {
        string str = "", rev = "";
        int t = i;
        while(t != 0)
        {
            int q = t % 10;
            str = char(int('a' + q)) + str;
            rev = rev + char(int('a' + q));
            t /= 10;
        }
        if(str == rev) listReversible.push_back(i);
    }
	/*vector<string> d[number];
	for(int i = '0'; i <= '9'; i++) d[1].push_back(i);
	for(int i = '0'; i <= '9'; i++) d[1].push_back(i);
	if(number % 2 != 0)
    {
        for(int i = 3, i <= number; i+=2)
            for(int j = '0'; j <= '9'; j++)
            {
                for(auto data : )
            }
    }*/
	return listReversible;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	number--;
	long long a = 1, b = 10;
	while(number--)
    {
        a *= 10;
        b *= 10;
    }
    if(number == 1) a = 0;
    for(int i = a; i < b; i++)
    {
        int t = i, sum_digit = 0;
        while(t != 0)
        {
            int q = t % 10;
            sum_digit += q;
            t /= 10;
        }
        string str = "", rev = "";
        t = sum_digit;
        while(t != 0)
        {
            int q = t % 10;
            str = char(int('a' + q)) + str;
            rev = rev + char(int('a' + q));
            t /= 10;
        }
        if(str == rev) listReversible_Sum.push_back(i);
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
