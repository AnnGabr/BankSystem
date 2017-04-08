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


