#include <stdio.h>

#include "Client.h"

void startClientQuery() {
	int quit = 0;
	while (!quit)
	{
		char option;
		printClientOptions();
		scanf("%c", &option);
		getchar();

		//switch (option) {
		/*case 'e':
			quit = 1;*/
		//default:
		//	printf("Invalid option\n");
			
		//}
	}
}

void printClientOptions() {

}