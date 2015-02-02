#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


pid_t pidFils;

void hierarchie(int i){
    if(i == 0) return;
    int j;
    printf("Rang : %d \n",i);
    for(j=0;j<2;j++){
        pidFils = fork();
        if (pidFils!=0){
            // printf("je suis le pere %d \n",getpid());
        }
        else{
            printf("je suis le fils %d \n",getpid());
            i--;
            hierarchie(i);
            break;
        }
    }
}


main(){
    
    hierarchie(3);
    
}
