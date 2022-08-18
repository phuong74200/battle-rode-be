#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000

//You can use one among Dev-C++ or visual studio or visual studio code for testing
int inputNumber(){
	int number = -1;
	scanf("%d", &number);
	return number;
}

void getReversibleList(int number,int listPrime[MAX_NUM], int* pn){
	
}

void getReversible_SumList(int number,int listReversible_Sum[MAX_NUM], int* pn){
	//your code here
}

int checkPrime(int num) {
	int i;
	for (i = 2; i < num/2; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int power(int base, int pow) {
	int i, result = 1;
	for (i = 0; i < pow; i++)
	result *= base;
	return result;
}

void getPrimeNumberList(int number,int listPrime[MAX_NUM], int* pn){
	int i, j = 0;
	for (i = 1; i < power(10, number); i++) {
		if (checkPrime(i) == 1) {
			listPrime[j] = i;
			++j;
		};
	};
}

int main(int argc,char** args) {
	//1.Input number
	printf("input number: ");
	int number = inputNumber();
	printf("\n");

	//2.Prime list
	int listPrime[MAX_NUM],nPrime,i;
	printf("Prime List: ");
	getPrimeNumberList(number,listPrime,&nPrime);
	for(i=0;i<nPrime;i++){
		printf("%d\t",listPrime[i]);
	}
	printf("\n");

	//3.Reversible List
	int listReversible[MAX_NUM],nReversible;
	printf("Reversible List: ");
	getReversibleList(number,listReversible,&nReversible);
	for(i=0;i<nReversible;i++){
		printf("%d\t",listReversible[i]);
	}
	printf("\n");

	//4. Reversible_Sum List
	printf("Reversible_Sum List: ");
	int listReversible_Sum[MAX_NUM],nReversible_Sum;
	getReversible_SumList(number,listReversible_Sum,&nReversible_Sum);
	for(i=0;i<nReversible_Sum;i++){
		printf("%d\t",listReversible_Sum[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
