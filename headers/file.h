/*
** Created by glastis
** Date: 15-Oct-20
** Contact: developers@glastis.com
*/

#ifndef PURGE_DUPES_FILE_H
#define PURGE_DUPES_FILE_H

#include <stdio.h>

int                     get_line(char *ret, FILE *infile);
void                    put_in_file(const char *filepath, const char *str);
int                     is_in_file(const char *filepath, const char *str);

#endif //PURGE_DUPES_FILE_H
