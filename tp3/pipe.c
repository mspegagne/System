#include <unistd.h>

int main(int argc, char *argv[]){

	int fd[2];
	pipe (fd);
	int test = fork();
	char buffer[20];

	if (test != 0)
	{
		close(fd[1]);
		close(STDOUT_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execlp("who", "who", NULL); 
	}
	else
	{
		close(fd[1]);		
		close(STDIN_FILENO);
		dup2(fd[0], STDIN_FILENO);
		execlp("grep", "grep", argv[1], NULL); 
	}
}