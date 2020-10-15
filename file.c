/*
** Created by glastis
** Date: 15-Oct-20
** Contact: developers@glastis.com
*/

#include "headers/const.h"
#include "headers/file.h"
#include "stdlib.h"
#include "string.h"

int                     get_line(char *ret, FILE *infile)
{
    int                 i;

    i = 0;
    while (fread(&ret[i], 1, 1, infile))
    {
        if (ret[i] == '\n' && i > 0)
        {
            ret[i] = '\0';
            return 0;
        }
        if (ret[i] != '\n')
        {
            ++i;
        }
    }
    if (ret[0] == '\n')
    {
        return get_line(ret, infile);
    }
    ret[i + 1] = '\0';
    return i == 0;
}

void                    put_in_file(const char *filepath, const char *str)
{
    FILE                *file;

    if (!(file = fopen(filepath, "ab")))
    {
        fprintf(stderr, "Failed to open: %s\n", filepath);
        exit(1);
    }
    fwrite(str, 1, strlen(str), file);
    fwrite("\n", 1, 1, file);
    fclose(file);
}

int                     is_in_file(const char *filepath, const char *str)
{
    FILE                *file;
    char                buff[LINE_MAX_LEN];

    if (!(file = fopen(filepath, "rb")))
    {
        fprintf(stderr, "Failed to open: %s\n", filepath);
        exit(1);
    }
    while (!get_line(buff, file))
    {
        if (!strcmp(buff, str))
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}