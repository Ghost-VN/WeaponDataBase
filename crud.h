#ifndef WEAPON_H
#define WEAPON_H

#endif // WEAPON_H

#include <sqlite3.h>

void TITLE(void);
void MAIN_MENU(void);
void BASKET_MENU(void);
int  CALLBACK(void *data, int argc, char **argv, char **azColName);
int  SUMM_BASKET (sqlite3 *db, int rc,  char* sql);
int  INSERT(sqlite3 *db,int rc,char* sql);
int  DELETE(sqlite3 *db,int rc,char* sql);
int  MAIN_OPERATION(char*sql);
void REPEAT(void);
