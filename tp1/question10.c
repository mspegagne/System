#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


pid_t pidFils;  
int tab[4];

void hierarchie	(int r){
if (r == 0) return;
	int i;
  for(i=0;i<2;i++){
		tab[r] = getpid();	
  	pidFils = fork();
  	if (pidFils!=0){
    /* ------------ code du père ----------------- */
    		//printf("je suis le pere, mon numero est %d \n",getpid()); 
  	}
  	else{
    /* ------------ code du fils ----------------- */
    		printf("rang%d je suis le fils,  mon numero est %d",r,getpid()); 
				int j;				
				for(j=r ; j<4 ; j++){
					printf (" %d ", tab[j]);
				}
				printf("\n");
				hierarchie( r-1);
				break;
    }
	}
}



main(){
	 hierarchie(3);


}
