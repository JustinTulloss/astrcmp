Description
===========
This is a simple library for getting the `Levenshtein Distance <http://en.wikipedia.org/wiki/Levenshtein_distance>`_ 
in C.

It was adapted from the Picard project, where it was implemented using
Python unicode objects.

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

Look at test.c to see an example of how the function behaves.

License
=======
This is licensed under the GPL version 2 since it was stolen from a GPL project. I may at some point rewrite the code from scratch and re-license it as BSD so that it is more generally useful. Please let me know if this is something you want and I'll be more likely to get around to it.
