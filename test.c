/*
 * Copyright (C) 2009 Justin Tulloss
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

#include "astrcmp.h"
#include <stdio.h>
#include <string.h>

char *strings[] = {
    "Hello",
    "World",
    "hi",
    "Hell",
    "OR",
    "Damn Kids",
    "Kids"
};


void compare_and_print(int index1, int index2, float correct) {
    float result = LevenshteinDistance(strings[index1], strlen(strings[index1]),
                                     strings[index2], strlen(strings[index2]));
    printf("Similarity between \"%s\" and \"%s\" is %f\n", 
        strings[index1], strings[index2], result);
    if (correct != result) {
        fprintf(stderr, "FAILURE: Result %f should have been %f\n", 
            result, correct);
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    compare_and_print(0, 0, 1.0);
    compare_and_print(1, 1, 1.0);
    compare_and_print(0, 2, 0.0);
    compare_and_print(0, 4, 0.0);
    compare_and_print(0, 5, 0.0);
    compare_and_print(0, 1, .199999988);
    compare_and_print(0, 3, .800000011);
    compare_and_print(5, 6, .444444417);
    compare_and_print(6, 5, .444444417);
}

