#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// OSTEP - wzip

int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }
    FILE *fp;


    int count = 0;
    char ch;


    for (int file = 1; file < argc; file++)
    {
        fp = fopen(argv[file], "r");
        if (fp == NULL)
        {
            fprintf(stderr, "wunzip: cannot open file\n");
            return 1;
        }

        /**
         * fread(&count, sizeof(int), 1, fp)
         * fread(&ch, sizeof(char), 1, fp)
         */
        while (fread(&count, sizeof(int), 1, fp) == 1)
        {
            if (fread(&ch, sizeof(char), 1, fp) == 1)
                for (int i = 0; i < count; i++)
                {
                    printf("%c", ch);
                }
        }
    }
    fclose(fp);

    return 0;
}
