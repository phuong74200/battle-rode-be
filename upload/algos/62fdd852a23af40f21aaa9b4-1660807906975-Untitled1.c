#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int choice;
char code[101][101];
char title[101][101];
int pos=-1;
float quantity[101];
float price[101];
float value[101];
int n;
float total=0;
void addbook(){
	int check;
	printf ("Enter number of books: "); scanf ("%d", &n);
	if (pos+n>=100) printf ("The list is full!!!\n");
	else {
		int i;
		for (i=0;i<n;i++){
			do{
				pos++;
				printf("\tEnter %dth Code Book: ", pos+1);
        		fflush(stdin);
        		gets(code[pos]);
        		check=0;
        		for (i=0;i<pos;i++){
        			if (strcmp(code[i], code[pos])==0) check++;
				}
				if (check!=0) {
					printf ("Code has existed, please reenter!\n");
					pos--;
				}
			}while (check!=0);
			printf ("Enter title: ");
			gets(title[pos]);
			do{
				printf ("Enter quantity: "); scanf("%f", &quantity[pos]);
				if (quantity[pos]<0) printf ("Invalid\n");
			}while(quantity[pos]<0);
			do{
				printf ("Enter price: "); scanf ("%f", &price[pos]);
				if(price[pos]<0) printf ("Invalid\n");
			}while(price[pos]<0);
			value[pos]=price[pos]*quantity[pos];
			total+=price[pos]*quantity[pos];
		}
	}
}
void display(){
	int i;
	printf ("CODE               Title       Quantity       Price       Value\n");
	for (i=0;i<=pos;i++){
		printf ("%4s%20s%15.1f%12.1f%12.1f\n", code[i], title[i], quantity[i], price[i], value[i]);
	}
	printf ("                                                        Total Value: %.1f\n", total);
}
void sortbook(){
	int i, j;
	char str[100];
	int p;
	for (i=0;i<=pos-1;i++){
		for (j=i+1;j<=pos;j++){
			if (strcmp(code[i], code[j])>0){
				strcpy(str, code[i]);
				strcpy(code[i], code[j]);
				strcpy(code[j], str);
				strcpy(str, title[i]);
				strcpy(title[i], title[j]);
				strcpy(title[j], str);
				p=quantity[i];
				quantity[i]=quantity[j];
				quantity[j]=p;
				p=price[i];
				price[i]=price[j];
				price[j]=p;
				p=value[i];
				value[i]=value[j];
				value[j]=p;
			}
		}
	}
	printf ("CODE               Title       Quantity       Price       Value\n");
	for (i=0;i<=pos;i++){
		printf ("%4s%20s%15.1f%12.1f%12.1f\n", code[i], title[i], quantity[i], price[i], value[i]);
	}
	printf ("                                                        Total Value: %.1f\n", total);
}
void maxprice(){
	if (pos<0) printf ("No existed book in list!!!\n");
	else {
		int i;
		float max=price[0];
		for (i=1;i<=pos;i++){
			if (price[i]>max) max =price[i];
		}
		printf ("CODE               Title       Quantity       Price       Value\n");
		for (i=0;i<=pos;i++){
			if (price[i]==max){
				printf ("%4s%20s%15.1f%12.1f%12.1f\n", code[i], title[i], quantity[i], price[i], value[i]);
				break;
			}
		}
	}
}
void edit(){
	if (pos<0) printf ("No existed book in list!!!\n");
	else {
		char str[100];
		printf ("Enter code: "); 
		fflush(stdin);
		gets(str);
		int check=0;
		int flag;
		int i;
		for (i=0;i<=pos;i++){
			if (strcmp(str, code[i])==0){
				check=1;
				flag=i;
			}
		}
		if (check==0) printf ("Code not existed!!\n");
		else {
			printf ("Enter title: ");
			gets(title[flag]);
			total-=price[flag]*quantity[flag];
			do{
				printf ("Enter quantity: "); scanf("%f", &quantity[flag]);
				if (quantity[flag]<0) printf ("Invalid\n");
			}while(quantity[flag]<0);
			do{
				printf ("Enter price: "); scanf ("%f", &price[flag]);
				if(price[flag]<0) printf ("Invalid\n");
			}while(price[flag]<0);
			value[flag]=price[flag]*quantity[flag];
			total+=price[flag]*quantity[flag];
		}
	}
}
void delet(){
	if (pos<0) printf ("No existed book in list!!!\n");
	else {
		char str[100];
		printf ("Enter code: ");
		fflush(stdin); gets(str);
		int check=0;
		int flag;
		int i;
		for (i=0;i<=pos;i++){
			if (strcmp(str, code[i])==0){
				check=1;
				flag=i;
			}
		}
		if (check==0) printf ("Code not existed!!\n");
		else {
			total-=price[flag]*quantity[flag];
			for (i=flag;i<pos;i++){
				strcpy(code[i], code[i+1]);
				strcpy(title[i], title[i+1]);
				quantity[i]=quantity[i+1];
				price[i]=price[i+1];
				value[i]=value[i+1];
			}
			pos--;
		}
	}	
}
void docFile() {
	FILE* fOut = fopen("input.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
			fscanf(fOut, "%4[^\n]%20[^\n]%10.1f%10.1f%10.1f\n", &code, &title,&quantity, &price, &value);
			i++;
			if(feof(fOut)) { 
				break;
			}
		}
	}
	
	fclose(fOut);
	pos = i-1;
}

int main(){
	do {
		printf ("===============Menu================\n");
		printf ("1.Enter of list of book\n");
		printf ("2.Display the list of books\n ");
		printf ("3. Sort the list of books by code\n");
		printf ("4. Load data from file \n");
		printf ("5. Find the <first> max price\n ");
		printf ("6. Find by code and edit the book\n");
		printf ("7. Find by code and delete the book\n");
		printf ("0. Exit!\n");
		printf ("Your selection <0-7>: ");scanf ("%d", &choice);
		switch(choice){
			case 1:	addbook();
				break;
			case 2:display();
				break;
			case 3:sortbook();
				break;
			case 4:docFile();
		       break;
			case 5:maxprice();
				break;
			case 6:edit();
				break;
			case 7:delet();
				break;
			default: printf ("BYE");
		}
	}while (choice >=1&&choice<=7);
}
