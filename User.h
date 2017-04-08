//
//  user.h
//  lab5
//
//  Created by Katsiaryna Zaitsava on 08.04.17.
//  Copyright © 2017 Katsiaryna Zaitsava. All rights reserved.
//

#pragma once

typedef enum  user_t
{
    CLIENT,
    OPERATOR,
    ADMIN
}User_type;

typedef struct pers {
    int id;
    int accountNumb;
    char login[20];
    char password[20];
    User_type user_type;
} Person;

int isActive;
Person person;

int openAccount();

void closeAccount();

void readPersonInfo();

void startQuery();
