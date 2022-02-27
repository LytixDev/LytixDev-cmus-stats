#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Copyright 2022 Nicolai Brand
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, see <http://www.gnu.org/licenses/>.

import os
import sqlite3


def sqlite_init() -> tuple:
    home = os.environ["HOME"]
    postfix = "/.local/share/cmus-stats/cmus-stats.db"
    db_full_path = home + postfix

    con = sqlite3.connect(db_full_path)
    cur = con.cursor()
    return con, cur


# returns the data as a list with its elements being tuples of the value at the given field
# ex: fetch_x("title", "genre") will return [('song name x', 'genre y') ... ]
def fetch_x(*fields, con=None, cur=None) -> list:
    if len(fields) == 0:
        arg = "*"
    else:
        arg = "".join(field + "," for field in fields)[:-1]
    
    if con is None or cur is None:
        con, cur = sqlite_init();

    query = f"select {arg} from songs"
    cur.execute(query)
    data = cur.fetchall()

    cur.close()
    con.close()
    return data
