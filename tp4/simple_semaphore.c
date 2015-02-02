/* TP4 
http://www.commentcamarche.net/faq/11267-utilisation-des-semaphores-systeme-v#au-commencement-la-creation-d-une-cl
*/
#include "simple_semaphore.h"

/*	semget pour la création d'un sémaphore : int semget (key_t key, int nsems, int semflg)
			Les arguments de cet appel sont :
        key: La clé que nous venons de créer (nom numérique de l'ensemble de sémaphore)
    		nsems: Le nombre de sémaphores que nous voulons créer
    		semflg: Les permissions et les paramètres lors de la création de notre sémaphore (droits d'accès de cet ensemble)


  	semctl pour son contrôle et sa destruction : int semctl ( int semid, int semno, int cmd, union semun arg ) 
		    semid est l'identifiant de notre sémaphore que nous venons de créer
    		semno est le énième sémaphore créé qui nous intéresse. Attention, ça commence à zéro, et comme on en a créé qu'un seul, celui qui nous intéresse est le zéro.
    		cmd est la commande à appliquer à notre sémaphore ; ici, celle qui nous intéresse est SET_VAL pour donner une valeur à notre sémaphore.
    		arg est un paramètre dont le type a une interprétation différente selon la commande envoyée. Comme nous avons choisi SET_VAL, ici arg sera de type int et représentera la valeur que l'on veut affecter à notre sémaphore. ;


   	 semop pour sa gestion : int semop ( int semid, struct sembuf *sops, unsigned nsops ) 
    		semid: l'identifiant de votre sémaphore, comme d'habitude. Celui qui vous a été donné par semget.
    		sops: l'adresse de votre structure sembuf
    		nsops: le nombre d'opérations à effectuer. Ici nous n'avons qu'une seule opération à effectuer, donc on mettra 1. Si vous en avez plusieurs, il vous faudra passer un tableau de structures sembuf dans le paramètre sops. */

int creer_semaphore(key_t cle, int val){
	int semid = semget (IPC_PRIVATE, 1 , IPC_CREAT | 0666); //IPC_CREAT : indique que l'on veut créer un droit de lecture et d'écriture
	semctl(semid, 0, SETVAL, val);

	return semid;
}

int ouvrir_semaphore(key_t cle, int val){
	int semid = semget (cle, 1 , 0); //0 : ouvrir
	semctl(semid, 0, SETVAL, val);

	return semid;
}

void p(int semid){
	struct sembuf op;
	op.sem_num = 0; //Numéro de notre sémaphore: le premier et le seul
	op.sem_op = -1; //Pour un P() on décrémente (-1 pour décrémenter et 1 pour incrémenter)
	op.sem_flg = 0; //On ne s'en occupe pas

	semop(semid, &op, 1);	
}

void v(int semid){
	struct sembuf op;
	op.sem_num = 0; //Numéro de notre sémaphore: le premier et le seul
	op.sem_op = 1; //Pour un V() on incrémente (-1 pour décrémenter et 1 pour incrémenter)
	op.sem_flg = 0; //On ne s'en occupe pas

	semop(semid, &op, 1);	
}

void main(){

	int idsem1;
	int idsem2;

	idsem1 = creer_semaphore(1);
	printf(idsem1);

	/*v(idsem2);

	sleep(10);


	exit(0);*/
	}


