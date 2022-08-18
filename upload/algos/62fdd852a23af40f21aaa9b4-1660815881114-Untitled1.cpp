#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000

void inputNumbers(int numbers[],int* pn) {
	//your code here
	int n;
	scanf ("%d", &n);
	for (int i=0;i<n;i++){
		scanf ("%d", &numbers[i]);
	}
	*pn=n;
}

void findBiggestAnd2ndBiggest(int numbers[],int n, int result[2]) {
	//your code here
	int maxx=-1;
	for (int i=0;i<n;i++){
		if (maxx<numbers[i]) maxx=numbers[i];
	}
	result[0]=maxx;
	maxx=-1;
	for (int i=0;i<n;i++){
		if (maxx<numbers[i]&&numbers[i]<result[0]) maxx=numbers[i];
	}
	result[1]=maxx;
}

void sortBubble(int numbers[],int n) {
	//your code here
	int swap;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (numbers[i]<numbers[j]){
				swap=numbers[i];
				numbers[i]=numbers[j];
				numbers[j]=swap;
			}
		}
	}
}

void insertValues(int newValues[],int nNew,int numbers[],int* pn) {
	//your code here
	int n=*pn+nNew;
	int j=0;
	for (int i=*pn;i<n;i++){	
		numbers[i]=newValues[j];
		j++;
	}
	int swap;
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (numbers[i]<numbers[j]){
				swap=numbers[i];
				numbers[i]=numbers[j];
				numbers[j]=swap;
			}
		}
	}
	*pn=n;
	
}

int main(int argv, char** args) {
	int numbers[MAX_NUM],n=0,i;
	//1.Input array
	printf("Input arrays: ");
	inputNumbers(numbers,&n);
	printf("\n");
	
	//2.Find 1st and 2nd biggest numbers
	int maxElements[2];
	findBiggestAnd2ndBiggest(numbers,n,maxElements);
	printf("1st and 2nd biggest numbers:%d\t%d\n",
	maxElements[0],
	maxElements[1]);
	

	//3. Sorted array
	printf("Sorted array: ");
	sortBubble(numbers,n);
	for(i=0;i<n;i++)
		printf("%d\t",numbers[i]);
	printf("\n");
	
	//4. Insert values
	int newValues[MAX_NUM],nNew=0;
	printf("Values to be inserted: ");
	fflush(stdin);
	inputNumbers(newValues,&nNew);
	fflush(stdin);
	printf("\nInserted array: ");
	insertValues(newValues,nNew, numbers,&n);
	for(i=0;i<n;i++)
		printf("%d\t",numbers[i]);
	printf("\n");

	system("pause");
	return 0;
}
