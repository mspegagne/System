#include "simple_semaphore.h"

void main(){

	int idsem1;
	int idsem2;

	idsem1 = init_semaphore(2);
	idsem2 = init_semaphore(0);

	v(idsem2);

	sleep(10);


	exit(0);
	}

