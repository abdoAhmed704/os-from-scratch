#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// OSTEP - wzip

int main(int argc, char *argv[])
{
    // FIX:
    // The assignment requires at least one input file.
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    FILE *fp;

    // FIX:
    // These variables keep the state of the current run.
    // They MUST survive across lines AND across files.

    int count = 0;
    char previous;
    int first_char = 1;

    // Read every file passed on the command line.
    for (int file = 1; file < argc; file++)
    {
        fp = fopen(argv[file], "r");

        if (fp == NULL)
        {
            fprintf(stderr, "wzip: cannot open file\n");
            return 1;
        }

        int current;

        // FIX:
        // Read one character at a time.
        // This makes the input behave like one continuous stream,
        // exactly as required by the assignment.
        while ((current = fgetc(fp)) != EOF)  // aaabb
        {
            if (first_char)
            {
                previous = (char)current;
                count = 1;
                first_char = 0;
            }
            else if (current == previous)
            {
                count++;
            }
            else
            {
                // FIX:
                // Write one run:
                // 4-byte binary integer + 1 ASCII character.
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&previous, sizeof(char), 1, stdout);

                previous = (char)current;
                count = 1;
            }
        }

        fclose(fp);
    }

    // FIX:
    // Write the final run after ALL files have been processed.
    if (!first_char)
    {
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&previous, sizeof(char), 1, stdout);
    }

    return 0;
}

// ===================================================  BAD VERSION ===========================================================
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <string.h>

// // Project time line:
// //  1- doing the conversion function (DONE)
// //  2- build the code stages as following:
// //      a- Input handling
// //      b- connect the conversion function
// //      c- pass it to the Binary write fwrite function.
// //  3- Creating append function
// void append_str(char *dest, const char *src)
// {
//     int dest_len = strlen(dest);
//     int src_len = strlen(src);
//     for (int i = 0; i < src_len; i++)
//     {
//         dest[dest_len + i] = src[i];
//     }
//     dest[dest_len + src_len] = '\0';
// }

// char *run_length_encoding(char *str)
// {
//     int str_len = strlen(str);
//     int icount = 0;
//     char temp[100];
//     char *return_str = malloc(1024);

//     if (return_str == NULL)
//     {
//         perror("malloc");
//         exit(1);
//     }
//     return_str[0] = '\0';

    
//     for (int i = 0; i < str_len; i = i + icount)
//     {
//         icount = 0;
//         for (int j = i; j < str_len; j++)
//         {

//             if (str[i] == str[j])
//             {
//                 icount++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         sprintf(temp, "%d%c", icount, str[i]);
//         append_str(return_str, temp);
//     }
//     return return_str;
// }

// int main(int argc, char *argv[])
// {
//     if (argc == 1)
//     {
//         printf("searchterm [file ...]\n");
//         exit(1);
//     }

//     FILE *fp_read;
//     FILE *fp_write;
//     char *line;
//     char *econded_line;
//     size_t line_len = 0;

//     fp_read = fopen(argv[1], "r");

//     fp_write = fopen(argv[2], "w");
    

//     if (fp_read == NULL || fp_write == NULL)
//     {
//         printf("sick\n");
//         exit(1);
//     }
//     while (getline(&line, &line_len, fp_read) != -1)
//     {
//         econded_line = run_length_encoding(line);
//         fwrite(econded_line, strlen(econded_line), 1, fp_write);
//     }

//     fclose(fp_read);
//     fclose(fp_write);
//     free(line);
//     free(econded_line);
//     return 0;

//     // char dest[100] = "Hello ";
//     // char *src = "World";
//     // printf("dest before: %s\n", dest);
//     // append_str(dest, src);
//     // printf("dest after: %s\n", dest);
// }
