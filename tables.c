#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sqlite3.h>

#include "crud.h"

int  THROWING    (sqlite3 *db, char* sql, int rc)
{
    char *zErrMsg;
    rc = sqlite3_open("Weapon.db", &db);
    printf("\n<ID.1>         < THROWING weapon >                <PRICE>\n");
    printf("---------------------------------------------------------\n");
    sql = "SELECT * from Throwing_weapon";
    rc = sqlite3_exec(db, sql, CALLBACK, NULL, &zErrMsg);
    return  0;
}

int  PNEUMATIC   (sqlite3 *db, char* sql, int rc)
{
    char *zErrMsg;
    rc = sqlite3_open("Weapon.db", &db);
    printf("\n<ID.2>          < PNEUMATIC weapon >              <PRICE>\n");
    printf("---------------------------------------------------------\n");
    sql = "SELECT * from Pneumatic_weapon";
    rc = sqlite3_exec(db, sql, CALLBACK, NULL, &zErrMsg);
    return  0;
}

int  TRAUMATIC   (sqlite3 *db, char* sql, int rc)
{
    char *zErrMsg;
    rc = sqlite3_open("Weapon.db", &db);
    printf("\n<ID.3>     < TRAUMATIC weapon >                   <PRICE>\n");
    printf("---------------------------------------------------------\n");
    sql = "SELECT * from Traumatic_weapon";
    rc = sqlite3_exec(db, sql, CALLBACK, NULL, &zErrMsg);
    return  0;
}

int  HUNTING     (sqlite3 *db, char* sql, int rc)
{
    char *zErrMsg;
    rc = sqlite3_open("Weapon.db", &db);
    printf("\n<ID.4>        < HUNTING weapon >                  <PRICE>\n");
    printf("---------------------------------------------------------\n");
    sql = "SELECT * from Hunting_weapon";
    rc = sqlite3_exec(db, sql, CALLBACK, NULL, &zErrMsg);
    return  0;
}

int  MILITARY    (sqlite3 *db, char* sql, int rc)
{
    char *zErrMsg;
    rc = sqlite3_open("Weapon.db", &db);
    printf("\n<ID.5>            < MILITARY weapon >             <PRICE>\n");
    printf("---------------------------------------------------------\n");
    sql = "SELECT * from Military_weapon";
    rc = sqlite3_exec(db, sql, CALLBACK, NULL, &zErrMsg);
    return  0;
}

int  AMMUNITION  (sqlite3 *db, char* sql, int rc)
{
    char *zErrMsg;
    rc = sqlite3_open("Weapon.db", &db);
    printf("\n<ID.6>           < AMMUNITION >                   <PRICE>\n");
    printf("---------------------------------------------------------\n");

    sql = "SELECT * from Ammunition";
    rc = sqlite3_exec(db, sql, CALLBACK, NULL, &zErrMsg);
    return  0;
}

int  SIGHTS      (sqlite3 *db, char* sql, int rc)
{
    char *zErrMsg;
    rc = sqlite3_open("Weapon.db", &db);
    printf("\n<ID.7>                 < SIGHTS >                 <PRICE>\n");
    printf("---------------------------------------------------------\n");
    sql = "SELECT * from Sights";
    rc = sqlite3_exec(db, sql, CALLBACK, NULL, &zErrMsg);
    return  0;
}

int  BASKET      (sqlite3 *db, char* sql, int rc)
{
    char *zErrMsg;
    rc = sqlite3_open("Weapon.db", &db);
    sql = "SELECT * FROM Basket";
    rc = sqlite3_exec(db, sql, CALLBACK, NULL, &zErrMsg);
    return  0;
}
