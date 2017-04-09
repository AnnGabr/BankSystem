//
//  Bank_Manager.h
//  lab5
//
//  Created by Katsiaryna Zaitsava on 08.04.17.
//  Copyright © 2017 Katsiaryna Zaitsava. All rights reserved.
//

#pragma once

void openDB();
int verification (char*, char*);
int callback (void*, int, char**, char**);
void credit (int , int);
void debit (int, int);
void printAllAccounts();
void printAllClients();
void printAllUsers();
void addNewClient( char*, char*, char*, char*, int);
void printClientAndAccounts(int);
void clientAndAccounts();


