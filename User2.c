#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
    
    int fd1,fd2;
	char arr1[80];
	char buffer[80];

    while(1)
    {
		// pipe1 - writting to pipe1 which will be read on the other program
		fd2 = open("pipeOne", O_WRONLY); // opening pipe one to write
        
            printf(" Type message...\n ");
            fgets(arr1, 80, stdin);
            write(fd2, arr1, strlen(arr1) + 1); // writtting to the pipe
            close(fd2); // closing the pipe

		// pipe2 - reading to pipe2 which already writtern on another program
		fd1 = open("pipeTwo",  O_RDONLY); // reading from pipe two
        
            read(fd1,buffer,sizeof(buffer));
            close(fd1);
            write(STDOUT_FILENO, buffer, strlen(buffer)); // printing to the conseole

    
	} 
}
