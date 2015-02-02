#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>


int main(int argc, char *argv[]){

  //Création et initialisation du segment memoire

  int nbterm = 5;             
  key_t cle_mem;
  cle_mem = ftok("QWERTY", 'A');
  int length = sizeof(int)*nbterm;  

  int shmid = shmget(cle_mem,length,0666 | IPC_CREAT);
  
  int * shm = shmat(shmid,NULL,0) ;
  memset(shm, 0, length);


}
