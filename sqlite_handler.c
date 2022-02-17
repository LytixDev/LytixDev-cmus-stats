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
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#include "sqlite_handler.h"

sqlite3 *connect_to_db(char *db_name)
{
    sqlite3 *db;
    int rc;

    rc = sqlite3_open(db_name, &db);

    if(rc) {
        //fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        //fprintf(stdout, "Opened databse '%s' successfully\n", db_name);
    }
    return db;
}

/* insert query parameterized */
int insert_data(sqlite3 *db, char *query, int id, const char *title, const char *artist, int duration, int play_count)
{
    sqlite3_stmt *res;
    int rc = sqlite3_prepare_v2(db, query, -1, &res, 0);

    printf("%d\n", id);
    printf("%s\n", title);
    printf("%s\n", artist);
    printf("%d\n", duration);
    printf("%d\n", play_count);

    if (rc == SQLITE_OK) {
        sqlite3_bind_int(res, 1, id);
        sqlite3_bind_text(res, 2, title, strlen(title), NULL);
        sqlite3_bind_text(res, 3, artist, strlen(artist), NULL);
        sqlite3_bind_int(res, 4, duration);
        sqlite3_bind_int(res, 5, play_count);
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    sqlite3_step(res);
    sqlite3_finalize(res);
    return 0;
}
