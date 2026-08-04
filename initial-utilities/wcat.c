#include <stdio.h>
#include <stdlib.h>
/**
 * What I need: fopen, fgets, fprintf
 *
 */

int main(int argc, char *argv[])
{

	if (argc == 1)
		return 0;

	char str[80];
	FILE *p;
	// if argc = 2 ==> one file
	// if argc = 3 ==> two file
	for (int i = 1; i < argc; i++)
	{
		p = fopen(argv[i], "r"); // YOu need this to be str
		if (p == NULL)
		{
			printf("wcat: cannot open file\n");
			exit(1);
		}
		while (fgets(str, sizeof(str), p) != NULL)
		{
			printf("%i", i);
			printf("%s", str);
		}
		if (fclose(p) != 0)
		{
			perror("Error closing file");
			return 1;
		}
	}

	return 0;
}

