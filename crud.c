#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sqlite3.h>

#include "tables.h"

void TITLE()
{
    printf("                                                         ----------------------------------\n");
    printf("                                                            DataBase  (+) Shot & Hit (+)  \n");
    printf("                                                         ----------------------------------\n");
}

void MAIN_MENU()
{
    TITLE();
    printf( " --------------------------\n");
    printf( "  <ID>    < MAIN MENU >\n");
    printf( " --------------------------\n\n");
    printf( "   1 --> Throwing  weapon\n") ;
    printf( "   2 --> Pneumatic weapon\n") ;
    printf( "   3 --> Traumatic weapon\n") ;
    printf( "   4 --> Hunting   weapon\n") ;
    printf( "   5 --> Military  weapon\n") ;
    printf( "   6 --> Arrows & Bullets\n");
    printf( "   7 --> Sights\n\n");
    printf( " --------------------------\n");
    printf( "   8 --> GO  to BASKET \n");
    printf( " --------------------------\n");

 }

void BASKET_MENU()
{
    TITLE();
    printf( " -------------------------------------\n");
    printf( "  <ID>        < BASKET MENU >\n");
    printf( " -------------------------------------\n\n");
    printf( "   1 --> VIEW / DELETE\n");
    printf( "   2 --> CLEAR BASKET\n");
    printf( "   3 --> TOTAL AMOUNT\n");
    printf( " -------------------------------------\n");
    printf( "   4 --> BACK\n");
    printf( " -------------------------------------\n");

}

int  CALLBACK(void* data, int argc, char **argv, char **azColName)
{
    //fprintf(stderr, "%s: ", (const char*)data);

    for(int i = 0; i<argc; i++)
      {
        printf("%s ", argv[i] );
        //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
      }

   printf("\n");

   return 0;
}

int  SUMM_BASKET (sqlite3 *db, int rc,  char* sql)
{
    char *zErrMsg;
    rc = sqlite3_open("Weapon.db", &db);
    printf("\n<ID>                  < BASKET >                  <PRICE>\n");
    printf("----------------------------------------------------------\n");
    printf("\n    T O T A L   A M O U N T   > > > > > > > > > >  ");
    printf("$ ");
    sql =  "SELECT sum(Price) FROM Basket";
    rc = sqlite3_exec(db, sql, CALLBACK, NULL, &zErrMsg);
    return  0;
}

int  INSERT(sqlite3 *db,int rc)
{
    char *zErrMsg = NULL;
    char table [7][255]  = { "Throwing_weapon", "Pneumatic_weapon", "Traumatic_weapon", "Hunting_weapon",
                             "Military_weapon", "Ammunition", "Sights" };
    int index;
    printf( "\n    <PRESS ANY LETTER TO RETURN>\n");
    printf("\n    ID table  for ADD --> ");
    scanf("%d",&index);

    char sql1[50];
    printf("    ID weapon for ADD --> ");
    int ID;
    scanf("%d",&ID);

    sprintf(sql1,"INSERT INTO Basket SELECT * FROM %s  WHERE ID='%d'", table[index-1], ID);

    fflush(stdin);
    rc = sqlite3_exec(db, sql1, NULL, CALLBACK, &zErrMsg);

    if( rc != SQLITE_OK )
    {
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    }

    return 0;

    //     sql ="INSERT INTO Basket SELECT * FROM Sights WHERE ID=%d"
}

int  DELETE(sqlite3 *db,int rc,  char* sql)
{
    char *zErrMsg = NULL;
    BASKET(db, sql, rc);
    printf( "\n    <PRESS ANY LETTER TO RETURN>\n");
    printf( "\n    ID weapon for DELETE --> ");
    char sql1[50];
    int ID;

    scanf("%d",&ID);
    fflush(stdin);
    sprintf(sql1,"DELETE FROM Basket where ID=%i;",ID);
    rc = sqlite3_exec(db, sql1, CALLBACK, NULL, &zErrMsg);

    if( rc != SQLITE_OK )
    {
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    }

    return 0;

    // sql = "DELETE FROM Basket where ID=%d";

}

int  MAIN_OPERATION(char* sql)
{
    sqlite3 *db;
    int rc;
    char    *zErrMsg;

    const char* data = "Callback function called";

    rc = sqlite3_open("Weapon.db", &db);

        if( rc )
        {
             fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        } else
              {
                // fprintf(stderr, "Opened database successfully\n\n");
              }

        int weapon, basket;
        int h ;
        system("cls");
        MAIN_MENU();

        do {
             weapon = getch();
           } while(weapon< '1' || weapon > '8');

            switch (weapon)
                   {

                      case '1': do{
                                   system("cls");
                                   TITLE();
                                   THROWING (db, sql, rc);
                                   INSERT(db, rc);
                                   printf("\n\n    C --> Continue\n    E --> Exit");

                                   do {
                                        h=getch();
                                      } while(h!='c' && h!='C' && h!='e' && h!='E');
                                        system("cls");
                                        TITLE();
                                        THROWING(db, rc, sql);
                                      } while(h == 'c' || h == 'C');
                                        break;
                     case '2': do{
                                   system("cls");
                                   TITLE();
                                   PNEUMATIC(db, sql,rc);
                                   INSERT(db, rc);
                                   printf("\n\n    C --> Continue\n    E --> Exit");
                                   do {
                                        h=getch();
                                      } while(h!='c' && h!='C' && h!='e' && h!='E');
                                        system("cls");
                                        TITLE();
                                        PNEUMATIC(db, rc, sql);
                                      } while(h == 'c' || h == 'C');
                               break;

                     case '3': do{
                                   system("cls");
                                   TITLE();
                                   TRAUMATIC (db, sql,rc);
                                   INSERT(db, rc);
                                   printf("\n\n    C --> Continue\n    E --> Exit");
                                   do {
                                        h=getch();
                                      } while(h!='c' && h!='C' && h!='e' && h!='E');
                                        system("cls");
                                        TITLE();
                                        TRAUMATIC(db, rc, sql);
                                      } while(h == 'c' || h == 'C');
                               break;

                     case '4':  do{
                                   system("cls");
                                   TITLE();
                                   HUNTING (db, sql,rc);
                                   INSERT(db, rc);
                                   printf("\n\n    C --> Continue\n    E --> Exit");
                                   do {
                                        h=getch();
                                      } while(h!='c' && h!='C' && h!='e' && h!='E');
                                        system("cls");
                                        TITLE();
                                        HUNTING(db, rc, sql);
                                       } while(h == 'c' || h == 'C');
                                        break;
                     case '5': do{
                                   system("cls");
                                   TITLE();
                                   MILITARY (db, sql,rc);
                                   INSERT(db, rc);
                                   printf("\n\n    C --> Continue\n    E --> Exit");
                                   do {
                                        h=getch();
                                      } while(h!='c' && h!='C' && h!='e' && h!='E');
                                        system("cls");
                                        TITLE();
                                        MILITARY(db, rc, sql);
                                      } while(h == 'c' || h == 'C');
                                        break;
                     case '6': do{
                                   system("cls");
                                   TITLE();
                                   AMMUNITION (db, sql,rc);
                                   INSERT(db, rc);
                                   printf("\n\n    C --> Continue\n    E --> Exit");
                                   do {
                                        h=getch();
                                      } while(h!='c' && h!='C' && h!='e' && h!='E');
                                        system("cls");
                                        TITLE();
                                        AMMUNITION(db, rc, sql);
                                      } while(h == 'c' || h == 'C');
                                        break;
                     case '7': do{
                                   system("cls");
                                   TITLE();
                                   SIGHTS(db, sql,rc);
                                   INSERT(db, rc);
                                   printf("\n\n    C --> Continue\n    E --> Exit");
                                   do {
                                        h=getch();
                                      } while(h!='c' && h!='C' && h!='e' && h!='E');
                                        system("cls");
                                        TITLE();
                                        SIGHTS(db, rc, sql);
                                      } while(h == 'c' || h == 'C');
                                        break;

                     case '8':  do{system("cls");
                                BASKET_MENU();

                                 do{
                                     basket = getch();
                                   } while('4' < basket || basket < '1');

                             switch (basket)
                                    {
                                        case '1': do{
                                                      system("cls");
                                                      TITLE();
                                                      SUMM_BASKET(db, rc, sql);
                                                      DELETE(db, rc, sql);
                                                      printf("\n\n   C --> Continue\n   E --> Exit");
                                                     do {
                                                          h=getch();
                                                        } while(h!='c' && h!='C' && h!='e' && h!='E');
                                                          system("cls");
                                                          TITLE();
                                                          SUMM_BASKET(db, rc, sql);
                                                          BASKET(db, rc, sql);
                                                          if (h=='e' || h=='E')  {break;}
                                                       } while(h == 'c' || h == 'C');

                                                      break;

                                       case '2':  system("cls");
                                                  TITLE();
                                                  sql = "DELETE from Basket";
                                                  printf("   --> Basket is cleared\n");
                                                  break;

                                      case '3':   system("cls");
                                                  TITLE();
                                                  SUMM_BASKET (db, rc, sql);
                                                  break;

                                       case '4':  system("cls");
                                                  BASKET_MENU();
                                                  break;
                                    }
                                    printf("\n\n   B --> Basket menu\n   E --> Exit");
                                     do {h=getch();
                                      } while(h!='b' && h!='B' && h!='e' && h!='E');
                                              system("cls");
                                              BASKET_MENU();
                                               if (h=='e' || h=='E')  {break;}
                                                   if (h=='b' || h=='B')  {system("cls");  BASKET_MENU();}
                                                      } while(h == 'b' || h == 'B');

                                                       break;

                       }

        rc = sqlite3_exec(db, sql, CALLBACK, NULL, &zErrMsg);

        if( rc != SQLITE_OK )
        {
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
        } else
              {
               //fprintf(stdout, "\nOperation done successfully\n");
              }

        sqlite3_close(db);
}

void REPEAT()
{
    int h;
    char*sql = NULL;

    do{ MAIN_OPERATION(sql);
         printf("\n\n   M --> Main menu\n   E --> Exit");
        do {h=getch();
          } while(h!='m' && h!='M' && h!='e' && h!='E');
                 if (h=='e' || h=='E')  {break;}
                       if (h=='m' || h=='M')  {system("cls"); MAIN_MENU();}
                          } while(h == 'm' || h == 'M');
}






































// sprintf(sql,"INSERT INTO CHOISE SELECT * FROM %s WHERE %s.ID= '%d'",table[Case-1],table[Case-1],ID);

// sql = "INSERT INTO nameTable SELECT * FROM nameTable WHERE nameTable.ID= '%d'";



//        sql = "DELETE from Pneumatic_weapon where ID=2" ;
//        sql = "SELECT * from Pneumatic_weapon";

//        sql = "INSERT INTO Basket SELECT * FROM Lights WHERE Lights.ID=5"

//        sql = "UPDATE Weapon set Price = 25000 where ID=1";
//        sql = "SELECT * from Pneumatic_weapon";

