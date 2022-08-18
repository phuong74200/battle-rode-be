#include <stdio.h>
#include <iostream>
#include <vector>
//You can use one among Dev-C++ or visual studio or visual studio code for testing
using namespace std;
int inputNumber() {
	int number = -1;
	cin>>number;
	return number;
}

vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
	bool tmp=true;
        int flag=0,begin=1,end=1;
        for (int i=1;i<number;i++) {
            begin=begin*10;
            end=end*10;
        }
        end=end*10-1;
        for(int i=begin;i<=end;i++)
        {
            for(int j=2;j<=i/2;j++)
                if(i%j==0) tmp=false;
            if(tmp==true) {
                listPrime.push_back(i);
            }
            tmp=true;
        }
	return listPrime;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	//your code here
	return listReversible;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	//your code here
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
