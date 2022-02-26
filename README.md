cmus-stats 
=======================

You like cmus? You like graphs? You'll love cmus-stats!

(work in progress)

cmus-stats is a fork of the FOSS music player <a href="https://github.com/cmus/cmus">cmus</a> that adds stat taking and spotify wrapped-like graphs. On playing a song, cmus-stats stores track data locally in a SQlite3 type database. cmus-stats comes with scripts that will generate graphs and diagrams based on the local data.

Copyright © 2022 Nicolai Brand <nicolaibrand2002@gmail.com>

Copyright © 2008-2017 Various Authors

Copyright © 2004-2008 Timo Hirvonen <tihirvon@gmail.com>


Configuration (temporary)
-------------

Due to the fact it's still in developement, the temporary way to build and configure cmus-stats is all done by running

    $ ./test_build.sh

After running configure you can see from the generated `config.mk` file
what features have been configured in (see the `CONFIG_*` options).

*Note*: For some distributions you need to install development versions
of the dependencies.  For example if you want to use 'mad' input plugin
(mp3) you need to install `libmad0-dev` (Debian) or `libmad-devel` (RPM)
package. After installing dependencies you need to run `./configure`
again, of course.

If you want to use the Tremor library as alternative for decoding
Ogg/Vorbis files you have to pass `CONFIG_TREMOR=y` to the configure
script:

    $ ./configure CONFIG_VORBIS=y CONFIG_TREMOR=y

The Tremor library is supposed to be used on hardware that has no FPU.


Manuals
-------

    $ man cmus-tutorial

And

    $ man cmus


Git Repository
--------------

https://github.com/LytixDev/cmus-stats

    $ git clone https://github.com/LytixDev/cmus-stats.git
    

Git Repository of cmus
--------------

https://github.com/cmus/cmus

    $ git clone https://github.com/cmus/cmus.git


Hacking
-------

cmus uses the [Linux kernel coding style](https://www.kernel.org/doc/html/latest/process/coding-style.html).
Use hard tabs.  Tabs are _always_ 8 characters wide.  Keep the style consistent with rest of the
code.


Contribute
-------

Please feel free to contribute to the project by reporting bugs, requeting features or creating pull requests.
