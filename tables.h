#ifndef TABLES_H
#define TABLES_H

#endif // TABLES_H

#include <sqlite3.h>

int  THROWING    (sqlite3 *db, char* sql, int rc);
int  PNEUMATIC   (sqlite3 *db, char* sql, int rc);
int  TRAUMATIC   (sqlite3 *db, char* sql, int rc);
int  HUNTING     (sqlite3 *db, char* sql, int rc);
int  MILITARY    (sqlite3 *db, char* sql, int rc);
int  AMMUNITION  (sqlite3 *db, char* sql, int rc);
int  SIGHTS      (sqlite3 *db, char* sql, int rc);
int  BASKET      (sqlite3 *db, char* sql, int rc);
