/*
----------------------------SYSTEME Janvier 2012----------------------------


Exercice I

a/
Execution du traitant d'interruption (handler)

b/
il tourne mais on a pas la main dessus et on le libre accès au prompt.

c/
Un tube anonyme peut être utilisable uniquement par la descendance d'un processus, il ne possède pas de nom

d/
La formule "accès aléatoire" fait référence à un accès direct. Elle fait référence à un type de périphérique à accès en mode bloc.

e/
Les déroutements sont des événements envoyés au systeme pour prendre la main pour gérer les erreurs

f/
Père connait fils grace à la valaur retour fork (=0)
fils connait valeur père grace à getppid()

h/
Permet de conserver la fluidité d'un systeme multitache en cas de transfert de données vers un périphérique
-> Prof :
Le dma (direct memeory access) prend en charge le transfert des peripheriques en particulier les lecteurs de disques.
Il gere les transfert, economise les coeurs, fluidifie le transfert.

g/
Le processus demandeur est bloqué. 
-> trouver une case libre en mémoire physique
-> mettre la page en mémoire, mettre à jour les informations de traduction
-> liberer le processus

i/
Les threads sont plus légers que les processus. (on appelle thread "processus léger") 

j/
Si tube encore ouvert en écriture l'opération read est bloquante. 
Sinon la lecture renvoie End of File si le tube est vide

Exercice II 

*/

for(i=1; i<6; i++)
{
	pid = fork();
	if(pid==0)
	{
		if(i==1)
		{
			for(j=1; j<3; j++)
			{
				pid2 = fork();
				if(pid2==0)
				{
					break; //fils
				}
			}
			break;
		}
		
	}
	else
	{
		//père
	}
}
if(i==6)
{
	i=0;
}
if(j==3)
{
	j=0;
}
printf("%d,%d\n" i,j);


/*
Exercice III 

FIFO ^défaut de page
	 *chargement d'une page présente en mémoire physique
*/

	 0  7  2  7  5  8  9  2  4  2

	 ^0 0  0  0  0  ^8 8  8  8  8
	 	^7 7  *7 7  7  ^9 9  9  9
	 	   ^2 2  2  2  2  *2 ^4 4
	 	         ^5 5  5  5  5  ^2

//7 défaut de page (algo optimal)
//->. -> défaut

O. 7. 2. 7 5. 8. 9. 2 4. 2

/*
LRU *rouge
*/

	 0  7  2  7  5  8  9  2  4  2

	 *0 0  0  0  0  *8 8  8  8  8
	 	*7 7  *7 7  7  7  *2 2  *2
	 	   *2 2  2  2  *9 9  9  9
	 	         *5 5  5  5  *4 4

/*
Exercice IV

1/
Taille espace virtuel = 2^32 = 4Go

2/
Gain de temps car traduction de page lente

3/
taille_table = 4 x 2^20
			 = 2^2 x 2^20
			 = 2^22 octets

4/ ?
2eef4
34ce
34fe
64a

5/

Taille 2^12

100 Ko . 100Ko/4 = 25 pages
				   1 Tlivre -
				   1 Tpages - 2 x 4 Ko

1Mo . 1Mo/4Ko = 256 pages
			    1 Tlivre  -
			    1 Tpages  - 2 x 4 Ko

10Mo . 10Mo/4Ko = 2560 pages
			      1 Tlivre  -
			      3 Tpages  - 4 Ko x 4 Ko


Exercice V

A:2 	B:6
A:6 	B:5
A:6 	B:6
A:2 	B:2
A:5 	B:5
A:2 	B:5

Exercice VI

1/
*/

init(A,1);
init(B,0);
init(C,0);

//p1

while(1){
	P(A);
	printf("A");
	V(B);
}

//p2

while(1){
	P(B);
	printf("B");
	V(C);
}

//p3

while(1){
	P(C);
	printf("C");
	V(A);
}

/*
2/
*/

P1=1 B_C=0

while(1){
	P(P1);
	printf("A");
	V(B_C);
}

//p2

while(1){
	P(B_C);
	printf("B");
	V(P1);
}

//p3

while(1){
	P(B_C);
	printf("C");
	V(P1);
}

/*
3/

...

Exercice VII

1/
*/

init(mutex,1);
init(boy, 1);

Nbboy = 0;

void boy_wants_to_use_br(){
	P(mutex);
	Nbboy++;
	if(Nbboy==1) P(boy);
	V(mutex);
}

void boy_leave_br(){
	P(mutex);
	Nbboy--;
	if(Nbboy==0) V(boy);
	V(mutex);
}

/*
Code lecteur rédacteur
idem que boy mais avec nbgirl pour les filles

2/
*/




