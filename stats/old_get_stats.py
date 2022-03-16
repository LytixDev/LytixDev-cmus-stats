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
from collections import defaultdict

UID = 0
TITLE = 1
ARTIST = 2
DURATION = 4


def sqlite_init() -> tuple:
    home = os.environ["HOME"]
    postfix = "/.local/share/cmus-stats/cmus-stats.db"
    db_full_path = home + postfix

    con = sqlite3.connect(db_full_path)
    cur = con.cursor()
    return con, cur


def fetchall_data(cur):
    cmd = "select * from songs"
    cur.execute(cmd)
    return cur.fetchall()


def find_top_artist(data: str) -> list:
    artists = defaultdict(int)
    for row in data:
        if row[ARTIST] != "None":
            artists[row[ARTIST]] += 1

    return sorted(artists.items(), key=lambda x: x[1], reverse=True)


def find_top_songs(data: str) -> list:
    songs = defaultdict(int)
    for row in data:
        if "None" not in (row[ARTIST], row[TITLE]):
            songs[row[ARTIST] + " - " + row[TITLE]] += 1

    return sorted(songs.items(), key=lambda x: x[1], reverse=True)


def find_total_duration(data: str) -> float:
    total = 0
    for i in data:
        total += i[DURATION]

    return round(total / 3600, 2)


def main():
    MAX = 5
    con, cur = sqlite_init()
    data = fetchall_data(cur)

    print("Top artists:")
    for i in find_top_artist(data)[:MAX]:
        print(i[0] + " : " + str(i[1]))

    print("\n")

    print("Top songs:")
    for i in find_top_songs(data)[:MAX]:
        print(i[0] + " : " + str(i[1]))

    print("\n")
    print(f"Total listening time : {find_total_duration(data)} hours.")


if __name__ == "__main__":
    main()
