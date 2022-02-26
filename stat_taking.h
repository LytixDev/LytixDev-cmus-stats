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

#include "sqlite_handler.h"
#include "track_info.h"

#include <string.h>
#include <stdlib.h>

/* context for the database that is passed around functions
 * usually named dbc.
 */
struct db_ctx
{
        sqlite3 *db;
        char db_full_path[512];
        bool db_connected;
}; 

/*
 * sets the database path using the $HOME env and creates a connection
 * db_connected field = 1 -> db is connected
 * db_connected field = 0 -> db is NOT connected
 */
void cmus_stats_init(void);

/* closes the connection to the db */
void cmus_stats_exit(void);

/* returns true if there is a database connection and vice versa */
bool db_connected(void);

/* saves the current track info to .local/share/cmus-stats/cmus-stats.db */
void save_track_info_to_db(struct track_info *ti);
