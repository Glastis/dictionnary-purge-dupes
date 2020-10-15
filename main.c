#include "headers/main.h"
#include "headers/const.h"
#include "headers/file.h"
#include <stdio.h>

int                     purge(FILE *infile, const char *outpath)
{
    char                line[LINE_MAX_LEN];

    fclose(fopen(outpath, "w+"));
    while (TRUE)
    {
        if (get_line(line, infile))
        {
            fclose(infile);
            return 0;
        }
        if (!is_in_file(outpath, line))
        {
            put_in_file(outpath, line);
        }
    }
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
        return -1;
    }
    return purge(file, av[2]);
}
