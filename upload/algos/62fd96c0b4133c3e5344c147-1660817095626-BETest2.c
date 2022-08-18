#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000

void inputNumbers(int numbers[],int* pn) {
	int n;
	scanf("%d", &n);
	numbers[n];
	
	
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &numbers[i]);
	}
	
	
}

void findBiggestAnd2ndBiggest(int numbers[],int n, int result[2]) {
	
	int max = numbers[0];
    for (int i = 1; i < n; i++)
        if (max < numbers[i])
            max = numbers[i];
   	result[0] = max;
}

void sortBubble(int numbers[],int n) {
	
	int temp;
	
	
	for(int i = 0; i < n - 1; i++) {       
        for(int j = i + 1; j < n; j++) {   
		       
            if(numbers[j] > numbers[i]) {               

                temp = numbers[i];

                numbers[i] = numbers[j];

                numbers[j] = temp;

            }

        }
    }
    
    
}

void insertValues(int newValues[],int nNew,int numbers[],int* pn) {
	//your code here
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

