#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
//You can use one among Dev-C++ or visual studio or visual studio code for testing
using namespace std;
int inputNumber() {
	int number = -1;
	//your code here
  cin>>number;
	return number;
}
int checkPrime(int n) {
  if(n<=1) return 0;
  for(int i=2;i*i<=n;i++) {
    if(n%i==0) return 0;
  }
  return 1;
}
vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
	//your code here
  long long a=1;
  for(int i=1;i<=number;i++) {
    a*=10;
  }
  for(int i=0;i<a;i++) {
    if(checkPrime(i))listPrime.push_back(i);
  }
	return listPrime;
}
int checkReverse(int n) {
  char b[100];
  sprintf(b,"%d",n);
  int length=strlen(b);
  for(int i=0;i<length/2;i++) {
    if((int)b[i]!=(int)b[length-i-1])return 0;
  }
  return 1;
}
vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	//your code here
  long long a=1;
  for(int i=1;i<=number;i++) {
    a*=10;
  }

  for(int i=0;i<a;i++) {
    if(checkReverse(i))listReversible.push_back(i);
  }
	return listReversible;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	//your code here
  long long a=1;
  for(int i=1;i<=number;i++) {
    a*=10;
  }
  for(int i=0;i<a;i++) {
    char b[100];
    sprintf(b,"%d",i);
    int sum=0;
    for(int j=0;j<strlen(b);j++) {
      sum+=(int)b[j]-48;
    }
    if(checkReverse(sum))listReversible_Sum.push_back(i);
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