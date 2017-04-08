//
//  user.c
//  lab5
//
//  Created by Katsiaryna Zaitsava on 08.04.17.
//  Copyright © 2017 Katsiaryna Zaitsava. All rights reserved.
//



#include <stdio.h>

#include "user.h"
#include "Client.h"
#include "Operator.h"
#include "Admin.h"
#include "Bank_Manager.h"

int openAccount() {
    int user_type = verification(person.login, person.password);
    if(user_type != -1){
        person.user_type = user_type;
        isActive = 1;
    }else
        isActive = 0;
    return isActive;
}

void closeAccount() {
    isActive = 0;
}

void readPersonInfo() {
    printf("Enter login:\n");
    scanf("%s", person.login);
    getchar();
    printf("Enter password:\n");
    scanf("%s", person.password);
    getchar();
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
