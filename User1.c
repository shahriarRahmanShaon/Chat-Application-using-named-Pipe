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
        // reading from pipe one which already writtern on the other program
        
        fd1 = open("pipeOne",  O_RDONLY); // opeing in read mode
            read(fd1,buffer,sizeof(buffer)); // reading in buffer
            close(fd1);
            write(STDOUT_FILENO, buffer, strlen(buffer)); // printing to the console
			
        fd2 = open("pipeTwo", O_WRONLY);
            printf(" Type message...\n ");
            fgets(arr1, 80, stdin);
            write(fd2, arr1, strlen(arr1) + 1);
            close(fd2);
    
	} 
}
