#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


main(){

  pid_t pidFils= fork();
  if (pidFils!=0){
    /* ------------ code du père ----------------- */
    printf("je tourne en boucle\n"); 
    while(1){ printf("je tourne en boucle\n");}
  }
  else{
    /* ------------ code du fils ----------------- */
    while(1){ printf("Moi aussi je tourne en boucle\n");}
    printf("fils\n");
    }
}
  
