#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF 100

int main(){
	char Buff[BUFF];
	if (getcwd(Buff, 100) == NULL){
		printf("Error");
		exit(-1);
	}
	printf("%s\n", Buff);
	return 0;
}
