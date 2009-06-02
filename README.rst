Description
===========
This is a simple library for getting the `Levenshtein Distance`_ in C.

It was adapted from the Picard project, where it was implemented using
Python unicode objects.

_`Levenshtein Distance`: http://en.wikipedia.org/wiki/Levenshtein_distance 

Usage
=====

To test:
 * run ``./run-test`` from the source directory.

To use in your program:
 * Compile:
   ``# scons``
 * Copy astrcmp.so and/or astcmp.a somewhere within your path.
 * Copy the astrcmp.h file somewhere where you can include it.
 * Include astrcmp.h in your source.
 * Remember to link to astrcmp if you are using the dynamic library.

License
=======
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
