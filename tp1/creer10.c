#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


pid_t pidFils;

main(){
    int j;
    for (j=0;j<10;j++){
        pidFils = fork();
        if (pidFils!=0){
           printf("je suis le pere %d \n",getpid());
        }
        else{
            printf("je suis le fils %d \n",getpid());
            break;
        }
    }
    
}
