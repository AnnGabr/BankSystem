#pragma once

#include <stdio.h>

#include "Client.h"
#include "Operator.h"
#include "Admin.h"

typedef enum  user_t
{
	CLIENT = 0,
	OPERATOR,
	ADMIN
}User_type;

typedef struct pers {
	int id;
	int accountNumb;
	char login[15];
	char password[15];
	User_type user_type;
} Person;

int isActive = false;
Person person;

int openAccount() {
	//TODO 
	return isActive;
}

void closeAccount() {
	isActive = false;
}

void readPersonInfo() {
	printf("Enter login:\n");
	scanf("%s", &person.login);
	getchar();
	printf("Enter password:\n");
	scanf("%s", &person.password);
	getchar();

	person.user_type = OPERATOR;/////////
	isActive = true;/////////////
}

void startQuery() {
	if (!isActive) {
		printf("No account was opened\n");
		return;
	}

	switch (person.user_type) {
	case(CLIENT):
		startClientQuery();
		break;
	case(ADMIN):
		startAdminQuery();
		break;
	case(OPERATOR):
		startOperatorQuery();
		break;
	default:
		printf("Wrong user type!\n");
	}
}