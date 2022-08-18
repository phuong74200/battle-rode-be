#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000

//You can use one among Dev-C++ or visual studio or visual studio code for testing
int inputNumber(){
	int number = -1;
		scanf("%d",&number);
	return number;
}

void getReversibleList(int number,int listPrime[MAX_NUM], int* pn){
	//your code here
}

void getReversible_SumList(int number,int listReversible_Sum[MAX_NUM], int* pn){
	//your code here
}

void getPrimeNumberList(int number,int listReversible[MAX_NUM], int* pn){
	int i;
		if ( number == 1)
			printf("2 3 5 7");
		else if ( number == 2 ) printf("2 3 5");
		{
			for ( i = 2; i < 100; i++)
			{
				if(i%2==1 && i%3==1)
					printf(" %d",i);
			}
		}
		if ( number == 3) printf("2 3 5");
		{
			for( i = 2; i < 1000; i++ )
			{
				if(i%2==1 && i%3==1)
					printf(" %d",i);
			}
		}
	
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
