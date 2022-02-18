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

#include <sqlite3.h>

sqlite3 *connect_to_db(char *db_name);
int insert_data(sqlite3 *db, char *query, int id, char *title, char *artist, int duration);
/* will create table, if it already exists it does not excecute */
int create_table(sqlite3 *db);

