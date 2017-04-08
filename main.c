#include <stdio.h>

#include "User.h"

int isExit() {
	char answer;
	int exit = -1;
	while (exit == -1) {
		printf("Do you want to continue?(y/n)\n");
		scanf("%c", &answer);
		getchar();
		if (answer == 'y')
			exit = 0;
		if (answer == 'n')
			exit = 1;
	}
	return exit;
}

int main() {
	printf("----BANK----\n");

	while (!isExit()) {
		readPersonInfo();
		openAccount();
		startQuery();
		closeAccount();
	}

	return 0;
}