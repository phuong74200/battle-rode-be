#include <stdio.h>
#include <iostream>
#include <vector>
//You can use one among Dev-C++ or visual studio or visual studio code for testing
using namespace std;
int inputNumber() {
	int number = -1;
	//your code here
   cin >> number;
	return number;
}

bool isPrime(int number) {
   if (number <= 1) {
      return false;
   } else if (number <= 3) {
      return true;
   } else {
      for (int i = 2; i * i <= number; i++) {
         if (number % i == 0) {
            return false;
         }
      }
      return true;
   }
}

string revString(string num) {
   string revNum = "";
   for (int i = num.size() - 1; i >= 0; i--) {
      revNum += num[i];
   }
   return revNum;
}

bool isReversible(int nDigits, int number) {
   if (number < 0) {
      return false;
   }
   string num = "";
   int temp = number;
   while (temp > 0) {
      int r = temp % 10;
      num = (char)(r + '0') + num;
      temp /= 10;
   }
   while (num.size() < nDigits) num = "0" + num;
   return num == revString(num);
}

vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
	//your code here
   if (number != 0) {
      int start = 1;
      for (int i = 1; i < number; i++) start *= 10;
      int end = start * 10 - 1;

      for (int i = 1; i <= end; i++) {
         if (isPrime(i)) {
            listPrime.push_back(i);
         }
      }
   }
	return listPrime;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	//your code here
   if (number != 0) {
      int start = 1;
      for (int i = 1; i < number; i++) start *= 10;
      int end = start * 10 - 1;

      for (int i = 0; i <= end; i++) {
         if (isReversible(number, i)) {
            listReversible.push_back(i);
         }
      }
   }
	return listReversible;
}

int sumDigit(int number) {
   int sum = 0;
   while (number > 0) {
      sum += number % 10;
      number /= 10;
   }
   return sum;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	//your code here
   if (number != 0) {
      int start = 1;
      for (int i = 1; i < number; i++) start *= 10;
      int end = start * 10 - 1;

      for (int i = 0; i <= end; i++) {
         if (isReversible(number, sumDigit(i))) {
            listReversible_Sum.push_back(i);
         }
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