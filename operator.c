#include <stdio.h>

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
		case 'b': {
			double balance = getBalance();
			printf("current balance: %f\n", balance);
			break;
		}
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
	printf("c - credit\nd - debit\nb - balance\ns - show accounts info\ne - exit\n");
}

void makeDebit(){
	printf("debit");
	//TODO
}

void makeCredit(){
	printf("credit");
	//TODO
}

double getBalance(){
	printf("balance");
	double balance = 0.0;
	//TODO
	return balance;
}

void showAccInfo() {
	//TODO
}