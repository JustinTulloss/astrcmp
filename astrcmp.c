/*
 * Copyright (C) 2009 Justin Tulloss
 *
 * Adapted from:
 * Picard, the next-generation MusicBrainz tagger
 * Copyright (C) 2006 Lukáš Lalinský
 * Copyright (C) 2003 Benbuck Nason
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/***
 *
 * Approximate string comparison
 *
 * This work is based on the Levenshtein Metric or "edit distance", which is 
 * well known, simple, and seems to be unencumbered by any usage restrictions. 
 * For more information on the Levenshtein Distance you can refer to the web,
 * e.g. http://www.merriampark.com/ld.htm
 *
 * Accuracy and speed enhancements could probably be made to this algorithm by
 * implementing the improvements suggested by such people as Esko Ukkonen, Hal
 * Berghel & David Roach, and Sun Wu and Udi Manber.
 *
 * This has been succesfully compiled using:
 *    Microsoft Visual C++ 6 SP 5
 *    GNU gcc 3.2 & Cygwin
 *    GNU gcc 3.2 & MINGW
 *
 * Benbuck Nason, February 28th, 2003
 *
 ***/

 /* Adapted away from Python in 2009 by Justin Tulloss */

#include "astrcmp.h"

#include <stdlib.h>
#include <stdio.h>

#define MIN(a, b) a < b ? a : b;
#define MAX(a, b) a > b ? a : b;

/***
 * Compute Levenshtein distance
 ***/

#define MATRIX(a, b) matrix[(b) * (len1 + 1) + (a)]

float LevenshteinDistance(char *s1, char *s2)
{
    /* Step 1 */
    /* Check string lengths */
    int len1 = s1.length();
    int len2 = s2.length();

    if (s1.empty() || s2.empty()) {
        return 0.0f;
    }

    /* Step 2 */
    /* Allocate matrix for algorithm and fill it with default values */

    int *matrix = new int[(len1 + 1) * (len2 + 1)];

    for (int index1 = 0; index1 <= len1; index1++)
        MATRIX(index1, 0) = index1;

    for (int index2 = 0; index2 <= len2; index2++)
        MATRIX(0, index2) = index2;

    /* Step 3 */
    /* Loop through first string */

    for (int index1 = 1; index1 <= len1; index1++)
    {
        string *s1_current = s1[index1 - 1];

        /* Step 4 */
        /* Loop through second string */

        for (int index2 = 1; index2 <= len2; index2++)
        {
            string *s2_current = s2[index2 - 1];

            /* Step 5 */
            /* Calculate cost of this iteration
               (handles deletion, insertion, and substitution) */

            int cost = (s1_current == s2_current) ? 0 : 1;

            /* Step 6 */
            /* Calculate the total cost up to this point */

            int above = MATRIX(index1 - 1, index2);
            int left = MATRIX(index1, index2 - 1);
            int diagonal = MATRIX(index1 - 1, index2 - 1);
            int cell = MIN(MIN(above + 1, left + 1), diagonal + cost);

            /* Step 6a */
            /* Also cover transposition. This step is taken from:
               Berghel, Hal ; Roach, David : "An Extension of Ukkonen's 
               Enhanced Dynamic ProgramMINg ASM Algorithm"
               (http://berghel.net/publications/asm/asm.php) */

            if (index1 > 2 && index2 > 2)
            {
                int trans = MATRIX(index1 - 2, index2 - 2) + 1;
                if (s1[index1 - 2] != s2_current)
                    trans++;
                if (s1_current != s2[index2 - 2])
                    trans++;
                if (cell > trans)
                    cell = trans;
            }

            MATRIX(index1, index2) = cell;
        }
    }


    /* Step 7 */
    /* Return result */

    float result = ((float)1 - 
        ((float)MATRIX(len1, len2) / (float)MAX(len1, len2)));

    delete [] matrix;

    return result;
}
