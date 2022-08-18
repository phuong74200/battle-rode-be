#include <stdio.h>
#include <iostream>
#include <vector>
//You can use one among Dev-C++ or visual studio or visual studio code for testing
using namespace std;
int inputNumber() {
	int number = -1;
	//your code here
	cin>>number;
	return number;
}

vector<int> getPrimeNumberList(int number) {
	vector<int> listPrime;
	//your code here
	if(number<1) return listPrime;

    int l=0;
    int r=9;

    for(int i=1;i<number;i++) r=r*10 + 9;

    vector<bool> prime(r+10,true);

    prime[0]=false;
    prime[1]=false;

    for(int i=2;i<=r;i++)
        if(prime[i])
            for(int j=i+i;j<=r;j+=i)
                prime[j]=false;

    for(int i=l;i<=r;i++) if(prime[i]) listPrime.push_back(i);

	return listPrime;
}

vector<int> getReversibleList(int number) {
	vector<int> listReversible;
	//your code here
	if(number<1) return listReversible;

    int l=0;
    int r=9;

    for(int i=1;i<number;i++) r=r*10 + 9;

    for(int i=l;i<=r;i++) {
       int o=i,x=0;
       while(o>0) {
            x=x*10+o%10;
            o/=10;
       }
       if(i==x) listReversible.push_back(i);
    }
	return listReversible;
}

vector<int> getReversible_SumList(int number) {
	vector<int>listReversible_Sum;
	//your code here
	if(number<1) return listReversible_Sum;

    int l=0;
    int r=9;

    for(int i=1;i<number;i++) r=r*10 + 9;

    for(int i=l;i<=r;i++) {
        int x=i;
        int sum=0; while(x>0) sum+=x%10,x/=10;

       int rev_sum = 0;

       int tmp = sum;
       while(tmp>0) {
            rev_sum*=10;
            rev_sum+=tmp%10;
            tmp/=10;
       }

       if(sum==rev_sum) listReversible_Sum.push_back(i);
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
