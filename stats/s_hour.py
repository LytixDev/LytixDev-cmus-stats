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

from matplotlib import pyplot as plt
from get_stats import fetch_x
import numpy as np


def listening_clock():
    # stores the data in a dict where the key is the hour and the value is \
    # total songs played during that hour
    hours = {k+1:0 for k in range(0, 24)}
    for data in fetch_x("hour"):
        hours[data[0]] += 1

    names = [f"{k-1:02}-{k:02}" for k in hours.keys()]
    plt.style.use("fivethirtyeight")
    plt.bar(names, hours.values())
    plt.show()


if __name__ == "__main__":
    listening_clock()
