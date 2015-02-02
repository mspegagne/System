/*
 * physical_memory.h
 *
 */
#ifndef PHYS_MEM_H
#define PHYS_MEM_H

#include "mmu.h"

page_phys pm_getFreePage();
void pm_freePage(page_phys pp);
int pm_isFull();
void pm_init(int size);

#endif
