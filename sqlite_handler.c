/*
 * Copyright 2022 Nicolai Brand
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include <time.h>

#include "sqlite_handler.h"


sqlite3 *connect_to_db(char *db_name)
{
        sqlite3 *db;
        int rc;

        rc = sqlite3_open(db_name, &db);

        if(rc) {
                //fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
                return NULL;
        } else {
                //fprintf(stdout, "Opened databse '%s' successfully\n", db_name);
        }

        return db;
}

/* insert query parameterized */
int insert_data(sqlite3 *db, int id, char *title, char *artist, char *genre, int duration)
{

        const char *query = "INSERT INTO SONGS (ID, TITLE, ARTIST, GENRE, DURATION, YEAR, MONTH, DAY, WDAY, HOUR) " \
                            "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

        time_t t = time(NULL);
        struct tm time = *localtime(&t);

        sqlite3_stmt *res;
        int rc = sqlite3_prepare_v2(db, query, -1, &res, 0);

        if (rc == SQLITE_OK) {
                sqlite3_bind_int(res, 1, id);
                sqlite3_bind_text(res, 2, title, strlen(title), NULL);
                sqlite3_bind_text(res, 3, artist, strlen(artist), NULL);
                sqlite3_bind_text(res, 4, genre, strlen(genre), NULL);
                sqlite3_bind_int(res, 5, duration);
                sqlite3_bind_int(res, 6, time.tm_year + 1900);
                sqlite3_bind_int(res, 7, time.tm_mon + 1);
                sqlite3_bind_int(res, 8, time.tm_mday);
                sqlite3_bind_int(res, 9, time.tm_wday);
                sqlite3_bind_int(res, 10, time.tm_hour + 1);
        } else {
                fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
                return 1;
        }

        sqlite3_step(res);
        sqlite3_finalize(res);

        return 0;
}

int create_table(sqlite3 *db)
{
        const char *query = "CREATE TABLE SONGS("  \
                            "ID INT NOT NULL," \
                            "TITLE VARCHAR," \
                            "ARTIST VARCHAR," \
                            "GENRE VARCHAR," \
                            "DURATION INT," \
                            "YEAR INT," \
                            "MONTH INT," \
                            "DAY INT," \
                            "WDAY INT," \
                            "HOUR INT);";
        char *err_msg = 0;
        int rc = sqlite3_exec(db, query, NULL, 0, &err_msg);

        if (rc != SQLITE_OK) {
                //fprintf(stderr, "SQL error: %s\n", err_msg);
                sqlite3_free(err_msg);
                return 0;
        } else 
                return 1;
}
