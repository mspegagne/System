#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "simple_semaphore.h"


int main(int argc, char *argv[]){

  int nbterm = 5;             
  key_t cle_mem;
  cle_mem = ftok("QWERTY", 'A');
  int length = sizeof(int)*nbterm;  

  int shmid = shmget(cle_mem,length,0);
  
  int * shm = shmat(shmid,NULL,0) ;
         
  key_t cle_sem;
  cle_sem = ftok("AZERTY", 'A');
  int semid = creer_semaphore(cle_sem, 0);

  int i;

  for(i=0;i<5;i++)
  {     
    printf("%d\n", shm[i]);
  }

}