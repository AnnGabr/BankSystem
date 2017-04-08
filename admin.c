#include <stdio.h>

#include "Admin.h"

void startAdminQuery() {
	int quit = 0;
	while (!quit)
	{
		char option;
		printAdminOptions();
		scanf("%c", &option);
		getchar();

		switch (option) {
		case 'a':
			printAccInfo();
			break;
		case 'c':
			printClientsInfo();
			break;
		case 'f':
			printCommInfo();
			break;
		case 'n':
			addClient();
			break;
		case 'e':
			quit = 1;
			break;
		default:
			printf("Invalid option\n");
		}
	}
}

void printAdminOptions() {
	printf("Choose options:\n");
	printf("a - get accounts info\nc - get clients info\nf - get common info\nn - add client\ne - exit\n");
}

void printCommInfo() {
	printf("Common info\n");
	//TODO
}

void printAccInfo() {
	printf("Accounts info\n");
	//TODO
}

void printClientsInfo() {
	printf("Clients info\n");
	//TODO
}

void addClient() {
	printf("add client\n");
}