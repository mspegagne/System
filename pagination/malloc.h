/*
 * malloc.h
 *
 */

void* my_malloc(int s);
void malloc_init(void* pointer, int size);
// This method free (and merge)
void my_free(void * a);
