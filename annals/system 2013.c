/*
----------------------------SYSTEME 2013----------------------------


Exercice I

a/
Car l'algo LRU nécessite de parcourir toute la table des pages. Perte de temps en cas de grande table.

b/
en attente ou execution

c/
SIGKILL et SIGSTOP ne peuvent être bloqués ou ignorés, le traitement ne peut être modifié. 
C'est une grantie pour s'assurer de toujours pouvoir reprendre la main sur un programme rétif.

d/
Un programme est un ensemble d'instructions
Un processus est un programme en cours d'execution

e/
Le processus a été interrompu ou attend un événement (la fin d'une opération d'entrée/sortie, un signal, ...).

f/
Un segment de mémoire partagée peut être identifié à deux niveaux :
niveau utilisateur -> une clé numérique par segment
niveau système -> un entier

g/
La communication se fait par numéro de port ou adresse mémoire régulière 

h/
Pour qu'en cas de suppression de la mémoire vive elle existe toujours sur le disque (cf tp)

i/
Avec un cache de traduction

j/
comme des processus ?



Exercice II 

1/ Affichage

Début application
Avant exec
monprog true machin
Fin application

2/
	   _fork1----fork1
	  /	
	 /__fork1
	/    		_fork1---fork1
main----fork0__/_fork1
	\ 		   \_fork0---fork1--fork1
	 \				  \__fork1
      \			_fork1---fork1
	   -fork0__/_fork1


Exercice III
*/

init(servir, 0);
init(pain, 0);
init(beurre, 0);
init(confiture, 0);

//Mangeur 
P(pain);
//mange()
V(servir);

//Serveur
if(confiture && beurre)
	V(pain);
if(...)
if(...)

P(servir);

/*
Exercice IV 
*/

tete = 0;
queue = 0;
libre = n;

public synchronized produire(msg){
	if(libre==0) this.wait();
	buffer[tete]=msg;
	tete = (tete + 1)%n;
	libre--;
	this.notifyAll();
}

public synchronized String consomme(){
	if(libre==n) this.wait();
	String msg = buffer[queue];
	queue = (queue + 1)%n;
	synchronized(this){
		libre++;
		this.notifyAll();
	}
}



/*
Exercice V 

1/
11 bits : numéro segment
10 bits : numéro page
11 bits : déplacement

2/
5 bit : numéro page
11 bits : déplacement
64-16-1=47

3/
A)  1 table des segments
	3 segments => 3 tables des pages
	1 entrée = 64 bits = 8 octets
	=> 1 table des segments = 1024*8 = 8ko
	11 bits de segment => 1 table = 2048 segments =2048 * 8 = 16ko
	=> Table des tables = 1*16 + 3*8 ko = 40ko

B)  1 table des segments +  2 tables des pages = 1*16 + 2*8 = 32ko

4/
cf photo

5/

Ad Virt -- A1
0	1	2	Seg page depl	

Ad Physique 
-> 00101|00000000010

Ad Virt -- A2
1	1	-	Seg page depl	

Ad Physique 
-> 01010|00101001001

Ad Virt -- B1
0	1	-	Seg page depl	

Ad Physique 
-> Défaut de page

Ad Virt -- B2
0	1	-	Seg page depl	

Ad Physique 
-> 00010|00000100010


*/



