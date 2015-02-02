/* TP4 */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int creer_semaphore(key_t cle, int val);

int ouvrir_semaphore(key_t cle, int val);

void p(int semid);

void v(int semid);
