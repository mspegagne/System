#include "tri_fusion.h"
#include "simple_semaphore.h"
#include <stdio.h>
#include <unistd.h>

void fusion(int tableau[],int deb1,int fin1,int fin2)
        {
        int *table1;
        int deb2=fin1+1;
        int compt1=deb1;
        int compt2=deb2;
        int i;
        
        table1=malloc((fin1-deb1+1)*sizeof(int));

        //on recopie les éléments du début du tableau
        for(i=deb1;i<=fin1;i++)
            {
            table1[i-deb1]=tableau[i];
            }
                        
        for(i=deb1;i<=fin2;i++)
            {        
            if (compt1==deb2) //c'est que tous les éléments du premier tableau ont été utilisés
                {
                break; //tous les éléments ont donc été classés
                }
            else if (compt2==(fin2+1)) //c'est que tous les éléments du second tableau ont été utilisés
                {
                tableau[i]=table1[compt1-deb1]; //on ajoute les éléments restants du premier tableau
                compt1++;
                }
            else if (table1[compt1-deb1]<tableau[compt2])
                {
                tableau[i]=table1[compt1-deb1]; //on ajoute un élément du premier tableau
                compt1++;
                }
            else
                {
                tableau[i]=tableau[compt2]; //on ajoute un élément du second tableau
                compt2++;
                }
            }
        free(table1);
        }
        

void tri_fusion_bis(int tableau[],int deb,int fin)
        {
        if (deb!=fin)
            {

            int semid;            
            key_t cle;
            int id;
            cle = ftok("AZERTY");
            semid = creer_semaphore(cle, 0);

            int milieu=(fin+deb)/2;
            if(fork() == 0) 
            {
                tri_fusion_bis(tableau,deb,milieu);
                v(semid);
            }
            if(fork() == 0) 
            {
                tri_fusion_bis(tableau,milieu+1,fin);
                v(semid);
            }
            else
                p(semid);
                p(semid);
                fusion(tableau,deb,milieu,fin);
            }
        }

void tri_fusion(int tableau[],int longueur)
     {
     if (longueur>0)
            {
            tri_fusion_bis(tableau,0,longueur-1);
            }
     }

int main(int argc, char *argv[]){

    int creerSegmentMemoire(int nbterm){
        key_t cle;
        int id;
        cle = ftok("/tmp",'A');
         
        id = shmget(cle,sizeof(int)*5,IPC_CREAT);
        return id;
    }
 
    int N = 5;

    int shmid = creerSegmentMemoire(N);
    int * mem = shmat(shmid,NULL,0) ;

    int i;

    for(i=0;i<N;i++)
    { 
        mem[i]= rand()%100;
    }

    tri_fusion(mem, N);
    for(i=0;i<N;i++)
    { 
        printf("%d\n", mem[i]);
    }

    return 0;

}
