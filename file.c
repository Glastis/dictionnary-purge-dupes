/*
** Created by glastis
** Date: 15-Oct-20
** Contact: developers@glastis.com
*/

#include "headers/const.h"
#include "headers/file.h"
#include "stdlib.h"
#include "string.h"

static int              tablen(char **tab)
{
    int                 i;

    i = 0;
    while (tab[i])
    {
        ++i;
    }
    return i;
}

static void             remove_line_from_tab(char **tab, const char *line)
{
    unsigned int        i;
    int                 max;

    max = -1;
    i = 0;
    while (tab[i])
    {
        if (!strcmp(tab[i], line))
        {
            if (max == -1)
            {
                max = tablen(tab);
            }
            tab[i] = tab[max - 1];
            tab[max - 1] = NULL;
            --max;
        }
        else
        {
            ++i;
        }
    }
}

static void             remove_tab_if_in_file(const char *outpath, char **tab)
{
    char                compline[LINE_MAX_LEN];
    FILE                *outfile;

    if (!(outfile = fopen(outpath, "rb")))
    {
        fprintf(stderr, "Unable to open file: %s\n", outpath);
        exit(1);
    }
    while (!get_line(compline, outfile))
    {
        remove_line_from_tab(tab, compline);
    }
    fclose(outfile);
}

void                    add_tab_if_not_in_file(const char *outpath, char **tab)
{
    unsigned int        i;

    i = 0;
    while (tab[i] && tab[i + 1])
    {
        remove_line_from_tab(&tab[i + 1], tab[i]);
        ++i;
    }
    remove_tab_if_in_file(outpath, tab);
    write_tab_to_file(outpath, tab);
}

void                    write_tab_to_file(const char *outpath, char **tab)
{
    unsigned int        i;
    FILE                *outfile;

    if (!(outfile = fopen(outpath, "a")))
    {
        fprintf(stderr, "Unable to open file: %s\n", outpath);
        exit(1);
    }
    i = 0;
    while (tab[i])
    {
        fwrite(tab[i], 1, strlen(tab[i]), outfile);
        ++i;
    }
    fclose(outfile);
}

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

int                     get_line_tab(char **tab, unsigned int max, FILE *infile)
{
    unsigned int        i;

    i = 0;
    while (i < max && !get_line(tab[i], infile))
    {
        ++i;
    }
    tab[i] = NULL;
    return i == 0;
}
