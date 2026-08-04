#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool searchInLine(char *searchItem, char *line);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    FILE *fp;
    char *line = NULL;
    size_t line_len = 0;
    if (argc == 2)
    {
        bool check = false;
        while (getline(&line, &line_len, stdin) != -1)
        {
            // Get the line
            // We need to confirm that the file here contain (argv[1])
            // We can do our own seaching function called "searchInLine"
            check = searchInLine(argv[1], line);
            if (check)
                printf("%s", line);
        }
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            fp = fopen(argv[i], "r");

            if (fp == NULL)
            {
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            bool check = false;
            while (getline(&line, &line_len, fp) != -1)
            {
                // Get the line
                // We need to confirm that the file here contain (argv[1])
                // We can do our own seaching function called "searchInLine"
                check = searchInLine(argv[1], line);
                if (check)
                    printf("%s", line);
            }
        }
        free(line);
        fclose(fp);
    }
    return 0;
}

bool searchInLine(char *searchItem, char *line)
{
    int searchLen = strlen(searchItem);
    int lineLen = strlen(line);
    bool check_return;

    for (int i = 0; i != lineLen; i++)
    {
        check_return = true;
        for (int j = 0; j != searchLen; j++)
        {
            if (searchItem[j] != line[j + i])
            {
                check_return = false;
                break;
            }
        }
        if (check_return)
            return true;
    }
    return false;
}