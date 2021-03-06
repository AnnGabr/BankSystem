//
//  main.c
//  TP_lab5
//
//  Created by Katsiaryna Zaitsava on 07.04.17.
//  Copyright © 2017 Katsiaryna Zaitsava. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include "Bank_Manager.h"

char *sql;
sqlite3 *db = NULL;
char *err_msg = NULL;
sqlite3_stmt *res;
int rc;
char* oper = "Operator";
char* admin = "Administrator";

void openDB(){
    rc = sqlite3_open("Bank_System.db", &db);
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n",
                sqlite3_errmsg(db));
        sqlite3_close(db);
        
        exit(1);
    }

}
int verification (char* login, char* password){

    sql = "SELECT Position FROM BANK_USERS WHERE Login = ? AND Password = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    
    if (rc == SQLITE_OK){
        sqlite3_bind_text(res, 1, login, (int)strlen(login), SQLITE_STATIC);
        sqlite3_bind_text(res, 2, password, (int)strlen(password), SQLITE_STATIC);
    }
    
    else {
        fprintf(stderr, "Failed to execute query: %s\n", sqlite3_errmsg(db));
    }
    
    if(sqlite3_step(res) == SQLITE_ROW){
        char* position = (char*) malloc(256);
        
        strcpy(position, sqlite3_column_text(res, 0));
        if (!strcmp(position, oper))
            return 1;
        else if (!strcmp(position, admin))
            return 2;
        else
            return 0;
    }
    return -1;
}
int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    NotUsed = 0;
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
void credit(int ID, int sum){
    
    sql = "UPDATE BANK_ACCOUNTS SET Balance = Balance + ? where ID = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    
    sqlite3_bind_int(res, 1, sum);
    sqlite3_bind_int(res, 2, ID);
    sqlite3_step(res) ;
    sqlite3_finalize(res);
}
void debit(int ID, int sum){
    sql = "UPDATE BANK_ACCOUNTS SET Balance = Balance - ? where ID = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    
    sqlite3_bind_int(res, 1, sum);
    sqlite3_bind_int(res, 2, ID);
    sqlite3_step(res) ;
    sqlite3_finalize(res);
}
void printAllAccounts(){
    sql = "SELECT * FROM BANK_ACCOUNTS";
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    if (rc != SQLITE_OK){
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        exit(0);
    }
}
void printAllClients(){
    sql = "SELECT * FROM BANK_CLIENTS";
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    if (rc != SQLITE_OK){
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        exit(0);
    }
}

void printAllUsers(){
    sql = "SELECT * FROM BANK_USERS";
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    if (rc != SQLITE_OK){
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        exit(0);
    }
}
void addNewClient(char* name, char* phone, char* address, char* email, int bank_user_id){
    printf("ADDING NEW CLIENT\n");
    sql = "INSERT INTO BANK_CLIENTS (Client_name, Phone_number, Address, Email, BANK_USERS_ID) VALUES (?, ?, ?, ?, ?)";
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    sqlite3_bind_text(res, 1, name, (int)strlen(name), SQLITE_STATIC);
    sqlite3_bind_text(res, 2, phone, (int)strlen(phone), SQLITE_STATIC);
    sqlite3_bind_text(res, 3, address, (int)strlen(address), SQLITE_STATIC);
    sqlite3_bind_text(res, 4, email, (int)strlen(email), SQLITE_STATIC);
    sqlite3_bind_int(res, 5, bank_user_id);
    sqlite3_step(res);
    sqlite3_finalize(res);
}
void printClientAndAccounts(int ID){
    printf("CLIENT AND ACCOUNT\n");
    sql = "SELECT BANK_CLIENTS.ID, Client_name, Account_number, Account_type, Balance FROM BANK_CLIENTS INNER JOIN BANK_ACCOUNTS ON BANK_CLIENTS.ID = BANK_ACCOUNTS.BANK_Clients_Client_id WHERE BANK_CLIENTS.ID = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    if (rc == SQLITE_OK)
        sqlite3_bind_int(res, 1, ID);
    else
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    
    while (sqlite3_step(res) == SQLITE_ROW){
        printf("%d ", sqlite3_column_int(res, 0));
        printf("%s ", sqlite3_column_text(res, 1));
        printf("%s ", sqlite3_column_text(res, 2));
        printf("%s ", sqlite3_column_text(res, 3));
        printf("%d ", sqlite3_column_int(res, 4));
        
        printf("\n");
    }
    
    sqlite3_finalize(res);
}
void clientAndAccounts(){
    printf("CLIENT AND ACCOUNT\n");
    sql = "SELECT BANK_CLIENTS.ID, Client_name, Account_number, Account_type, Balance FROM BANK_CLIENTS INNER JOIN BANK_ACCOUNTS ON BANK_CLIENTS.ID = BANK_ACCOUNTS.BANK_Clients_Client_id";
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    
}



