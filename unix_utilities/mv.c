#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	char Buff[100];

        if (argc != 3){
                perror("Invalid - Number Of Arguments\n");
                exit(-3);
        }
        int fd_read = open(argv[1], O_RDONLY, 0644);

        if (fd_read < 0){
                perror("Error - Couldn't Open In The File\n");
                exit(-1);
        }
        int fd_write = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd_write < 0){
                perror("Error - Couldn't Open In The File\n");
                exit(-1);
        }
        int num_read;
        while((num_read = read(fd_read, Buff, 100)) > 0){
                if (write(fd_write, Buff, num_read) < 0){
                        perror("Error - Couldn't Write In The File\n");
                        exit(-1);
                }

        }
	if (remove(argv[1]) != 0) {
        	perror("Deletion failed");
    	}
	if (close(fd_read) == -1){
		perror("Couldn't Close File\n");
	}

	if (close(fd_write) == -1){
		perror("Couldn't Close File\n");
	}
        return 0;

}
