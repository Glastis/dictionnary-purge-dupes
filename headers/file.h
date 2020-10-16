/*
** Created by glastis
** Date: 15-Oct-20
** Contact: developers@glastis.com
*/

#ifndef PURGE_DUPES_FILE_H
#define PURGE_DUPES_FILE_H

#include <stdio.h>

int                     get_line(char *ret, FILE *infile);
int                     get_line_tab(char **tab, unsigned int max, FILE *infile);
void                    write_tab_to_file(const char *outpath, char **tab);
void                    add_tab_if_not_in_file(const char *outpath, char **tab);

#endif //PURGE_DUPES_FILE_H
