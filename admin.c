#include <stdio.h>
#include "Bank_Manager.h"
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
    clientAndAccounts();
}

void printAccInfo() {
    printAllAccounts();
}

void printClientsInfo() {
    printAllClients();
}

void addClient() {
    char* name, *phone, *address, *email;
    int bank_user;
    printf("Enter name: ");
    scanf("%s", name);
    getchar();
    printf("Enter phone: ");
    scanf("%s", phone);
    getchar();
    printf("Enter address: ");
    scanf("%s", address);
    getchar();
    printf("Enter email: ");
    scanf("%s", email);
    getchar();
    printf("Enter bank user id: ");
    scanf("%d", &bank_user);
    getchar();
    addNewClient(name, phone, address, email, bank_user);
}
