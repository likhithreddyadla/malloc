#ifndef _MY_MALLOC_H

#define _MY_MALLOC_H

#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<time.h>

#define malloc( x ) mymalloc( x, __FILE__, __LINE__ )

#define free( x ) myfree( x, __FILE__, __LINE__ )


static char myblock[4096];

typedef struct metadata_tag 
{
	unsigned char status;
	unsigned short memorySize;

} meta_tag;

int heapStat(void);
void *mymalloc(int bytesNeeded,char *file, int line);
char *find(char *start, int bytes_needed);
char *divide(char *start, int bytes_needed);
void myfree(void *memory, char *file, int line);

#endif
