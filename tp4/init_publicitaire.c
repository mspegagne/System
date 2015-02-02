#include "simple_semaphore.h"

int main(int argc, char *argv[]){
 
	int i;
	int val;
	val = atoi(argv[1]);
	int semid;
	key_t cle = ftok("ab",1);
	semid = creer_semaphore(cle,val);

}
