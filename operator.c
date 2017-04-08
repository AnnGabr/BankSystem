#include <stdio.h>
#include "Bank_Manager.h"
#include "Operator.h"

void startOperatorQuery() {
	int quit = 0;
	while (!quit)
	{
		char option;
		printOperatorOptions();
		scanf("%c", &option);
		getchar();

		switch (option) {
		case 'c':
			makeCredit();
			break;
		case 'd':
			makeDebit();
			break;
		case 's':
			showAccInfo();
			break;
		case 'e':
			quit = 1;
			break;
		default:
			printf("Invalid option\n");
		}
	}
}

void printOperatorOptions() {
	printf("Choose option:\n");
	printf("c - credit\nd - debit\ns - show accounts info\ne - exit\n");
}

void makeDebit(){
    int id, sum;
    printf("Enter client id:\n");
    scanf("%d", &id);
    getchar();
    printf("Enter debit sum:\n");
    scanf("%d", &sum);
    getchar();
    debit(id, sum);
}

void makeCredit(){
    int id, sum;
    printf("Enter client id:\n");
    scanf("%d", &id);
    getchar();
    printf("Enter credit sum:\n");
    scanf("%d", &sum);
    getchar();
    credit(id, sum);
}

void getBalance(){
	
}

void showAccInfo() {
    int id;
    printf("Enter client id:\n");
    scanf("%d", &id);
    printClientAndAccounts(id);
}





