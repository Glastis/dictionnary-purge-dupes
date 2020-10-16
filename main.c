#include "headers/main.h"
#include "headers/const.h"
#include "headers/file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void             init_tab(char ***tab)
{
    unsigned int        i;

    i = 0;
    if (!(*tab = malloc(sizeof(char *) * MAX_LINE_PER_READ + 1)))
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    while (i < MAX_LINE_PER_READ)
    {
        if (!(tab[0][i] = malloc(sizeof(char) * LINE_MAX_LEN + 1)))
        {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        ++i;
    }
}

static void             purge(FILE *infile, const char *outpath)
{
    char                **lines;

    init_tab(&lines);
    fclose(fopen(outpath, "w+"));
    while (!get_line_tab(lines, MAX_LINE_PER_READ, infile))
    {
        add_tab_if_not_in_file(outpath, lines);
    }
    fclose(infile);
}

int                     main(int ac, char **av)
{
    FILE                *file;

    if (ac < 3)
    {
        fprintf(stderr, "./purge_dupe file_to_purge output_file\n");
        return -1;
    }
    if (!(file = fopen(av[1], "rb")))
    {
        fprintf(stderr, "Unable to open file: %s\n", av[1]);
        return 1;
    }
    purge(file, av[2]);
    return 0;
}
