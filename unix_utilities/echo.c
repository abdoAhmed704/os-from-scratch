#include <stdio.h>

int main(int argc, int *argv[]){
	for(int i = 0; i < argc; i++){
		printf(argv[i + 1]);	
	}
	printf("\n");
	return 0;
}
