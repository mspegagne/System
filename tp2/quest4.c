#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>

 
static int i = 0;


struct sigaction action;
sigset_t mask_nv;
sigset_t mask_anc;

void handler(int sig){
  printf("\n%d\n", i);
}


int main (int argc, char * argv[])
{
  
  // bloque SIGUSR1
  sigemptyset(&mask_nv);
  sigaddset(&mask_nv, SIGTSTP); // A decommenter
  // sigprocmask(SIG_BLOCK, &mask_nv, &mask_anc);

  //Définition du handler
  action.sa_handler=handler;
  sigaction(SIGTSTP,&action,NULL);


   while(1)
      {
        sleep(1);
        i++;

      }

}
