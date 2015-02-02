/*
----------------------------SYSTEME Janvier 2011----------------------------


Exercice I

a/
le systeme d'ordonnancement a pour role de repartir la main entre les processus. Il a donc le pouvoir d'interrompre un processus pour donner la main à un autre.

b/
oui

c/
Un gain de mémoire (toutes les pages seront pleines)

d/
Gestion de mémoire plus complexe. Les pages sont moins alignées et décharger une page ne permet pas forcément de charger la nouvelle

e/
Protéger la mémoire des autres processus. 
Gerer la mémoire, cad que les infos soient chargées quand on en a besoin. 
Page libre/occupée, traduction, capable de vider.

f/
Un interblocage intervient quand plusieurs processus se bloquent mutuellement. C'est souvent la conséquence d'une mauvaise utilisation des sémaphores.
ex :
sem_init(s1, 1);
sem_init(s2, 1);

g/
L'attente active consiste en la vérification continuelle de la condition d'attente et donc utilise du tps processus.
L'attente passive se base sur la mise en attente du processus suivant un certain evt, et évite donc toute consomation de ressources.
Il faut donc utiliser l'attente passive en général.

h/
COW utile lorsqu'un processus crée une copie de lui même (fork) 

i/
Utiliser les ressources dans le même ordre 

j/
Interruption


Exercice II 

*/

//Utilisation de kill() pour envoyer un message

void alarm_handler(){
	//masquage de sigusr1
	printf("trop tard");
}

void sigusr1_handler(){
	alarm(0);
	printf("message recu");
}

void main(){
	// definir handler alarm
	struct sigaction handler_alarm;
	handler_alarm.sa_handler = alarm_handler;
	sigaction(SIGALARM, &handler_alarm, NULL);

	//definir handler sigusr1
	struct sigaction handler_sigusr1
	handler_sigusr1.sa_handler = sigusr1_handler;
	sigaction(SIGUSR1, &handler_sigusr1, NULL);

	//envoyer un message
	kill(pidP2, SIGUSR1);
	alarm(10);
	wait(); //sigsuspend (...)
}

Exercice III


FCFS/
                    TT 
P1 ----             4
P2     -----        8
P3          -       7		7,2
P4           ---    8
P5              --  9


Round Robin/
                      TT 
P1 --  --             6
P2   --    --     -   13
P3        -           4			8
P4           --    -  10
P5              --    7


PCTER/
                       TT 
P1 ----                4
P2              -----  14
P3     --              2		5,4
P4       -----         3
P5            --       4


Exercice IV 

1/
25 + (5/100)*200 = 35ns

2/
25 + ((100-x)/100)*200 < 200
x > 12,5%


Exercice V 

1/

init(SA, 2);
init(SB, 2);
init(SC, 2);

//P1
while(1){
	P(A);
	P(A);
	printf("A\n");
	V(B);
	V(C);
}

//P2
while(1){
	P(B);
	P(B);
	printf("B\n");
	V(A);
	V(C);
}

//P3
while(1){
	P(C);
	P(c);
	printf("C\n");
	V(A);
	V(B);
}

2/

init(SA, 4);
init(SB, 4);
init(SC, 4);

//ne peut pas etre 6
//idem ensuite

//Avec des compteurs :

P(mutex);
if(abs(a-b) < 3 && abs(b-c) < 3 && abs(a-c) < 3){
	printf("A");
	a++;
}
V(mutex);

3/

//idem en changeant les valeurs

4/

init(inter, 3)

//Porte interne
V(inter);

//Porte externe
P(inter);



