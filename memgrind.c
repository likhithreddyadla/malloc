#include "mymalloc.h"
#include<sys/time.h>

void testA();
void testB();
void testC();
void testD();
void testE();
void testF();

int range(int l,int h)
{
  int g =(l+rand()%(h+1-l));
  	return g;
}
int main(int argc, char*argv[])
{
  // STARTING TEST A
  struct timeval tvalBefore, tvalAfter;

  gettimeofday(&tvalBefore,NULL);
  int k;
  for(k=0;k<100;++k)
    {
      testA();
    }
  gettimeofday(&tvalAfter,NULL);
  double avg1=((tvalAfter.tv_sec-tvalBefore.tv_sec)*1000000L +tvalAfter.tv_usec)-tvalBefore.tv_usec/100.0;
  //  printf("Test case A time in microseconds: %ld \n",((tvalAfter.tv_sec-tvalBefore.tv_sec)*1000000L +tvalAfter.tv_usec)-tvalBefore.tv_usec);
  // end of the test A
  struct timeval tvalBefore1, tvalAfter1;
	// starting the test B
  gettimeofday(&tvalBefore1,NULL);
	for(k=0;k<100;++k)
	{
		testB();
	}
	gettimeofday(&tvalAfter1,NULL);
	double avg2=((tvalAfter1.tv_sec-tvalBefore1.tv_sec)*1000000L +tvalAfter1.tv_usec)-tvalBefore1.tv_usec/100.0;
	//	printf("TEST CASE B time in microsecondsB: %ld\n",((tvalAfter1.tv_sec-tvalBefore1.tv_sec)*1000000L +tvalAfter1.tv_usec)-tvalBefore1.tv_usec);

	struct timeval tvalBefore2, tvalAfter2;
	// STARTING THE TEST CASE C
	gettimeofday(&tvalBefore2,NULL);
	for(k=0;k<100;++k)
	{
		testC();
	}	
	gettimeofday(&tvalAfter2,NULL);
	double avg3=((tvalAfter2.tv_sec-tvalBefore2.tv_sec)*1000000L+tvalAfter2.tv_usec)-tvalBefore2.tv_usec/100.0;
	//printf("TEST CASE C time in microseconds %ld\n",((tvalAfter2.tv_sec-tvalBefore2.tv_sec)*1000000L+tvalAfter2.tv_usec)-tvalBefore2.tv_usec);

	//STARTIng the test case D
	struct timeval tvalBefore3,tvalAfter3;
	gettimeofday(&tvalBefore3,NULL);
	for(k=0;k<100;++k)
	  {
	    testD();
	  }
	gettimeofday(&tvalAfter3,NULL);
	double avg4=((tvalAfter3.tv_sec-tvalBefore3.tv_sec)*1000000L+tvalAfter3.tv_usec)-tvalBefore3.tv_usec/100.0;
	//	printf("TEST CASE D time in microseconds %ld\n",((tvalAfter3.tv_sec-tvalBefore3.tv_sec)*1000000L+tvalAfter3.tv_usec)-tvalBefore3.tv_usec);
	
	// starting the testcase E
	struct timeval tvalBefore4,tvalAfter4;
	gettimeofday(&tvalBefore4,NULL);
	for(k=0;k<100;++k)
	  {
	    testE();
	  }
	gettimeofday(&tvalAfter4,NULL);
	double avg5=((tvalAfter4.tv_sec-tvalBefore4.tv_sec)*1000000L+tvalAfter4.tv_usec)-tvalBefore4.tv_usec/100.0;
	//	printf("TEST CASE E time in microseconds %ld\n",((tvalAfter4.tv_sec-tvalBefore4.tv_sec)*1000000L+tvalAfter4.tv_usec)-tvalBefore4.tv_usec);
	
	//STARTING THE TEST CASE F
	struct timeval tvalBefore5,tvalAfter5;
	gettimeofday(&tvalBefore5,NULL);
	for(k=0;k<100;++k)
	  {
	    testF();
	  }
	gettimeofday(&tvalAfter5,NULL);
	double avg6=((tvalAfter5.tv_sec-tvalBefore5.tv_sec)*1000000L+tvalAfter5.tv_usec)-tvalBefore5.tv_usec/100.0;
	//	printf("TEST CASE F time in microseconds %ld\n",((tvalAfter5.tv_sec-tvalBefore5.tv_sec)*1000000L+tvalAfter5.tv_usec)-tvalBefore5.tv_usec);
	
	printf("Test case A time in microseconds and Average time in microseconds: %ld , %lf\n",((tvalAfter.tv_sec-tvalBefore.tv_sec)*1000000L +tvalAfter.tv_usec)-tvalBefore.tv_usec,avg1);
	printf("TEST CASE B time in microsecondsB and AVERAGE time in microseconds: %ld, %lf \n",((tvalAfter1.tv_sec-tvalBefore1.tv_sec)*1000000L +tvalAfter1.tv_usec)-tvalBefore1.tv_usec,avg2);
	printf("TEST CASE C time in microseconds and AVERAGE time in microseconds %ld, %lf \n",((tvalAfter2.tv_sec-tvalBefore2.tv_sec)*1000000L+tvalAfter2.tv_usec)-tvalBefore2.tv_usec,avg3);
	printf("TEST CASE D time in microseconds %ld and AVERAGE time in microseconds, %lf \n",((tvalAfter3.tv_sec-tvalBefore3.tv_sec)*1000000L+tvalAfter3.tv_usec)-tvalBefore3.tv_usec,avg4);
	printf("TEST CASE E time in microseconds and AVERAGE time in microseconds %lf, %ld\n",((tvalAfter4.tv_sec-tvalBefore4.tv_sec)*1000000L+tvalAfter4.tv_usec)-tvalBefore4.tv_usec,avg5);
	printf("TEST CASE F time in microseconds and AVERAGE time in microseconds %lf,%ld\n",((tvalAfter5.tv_sec-tvalBefore5.tv_sec)*1000000L+tvalAfter5.tv_usec)-tvalBefore5.tv_usec,avg6);
	
return 0;
}

void testA()
{
  	int k;
  	do
  	{
  		char *OneByte=(char*)malloc(sizeof(char));
  		free(OneByte);
  		++k;
  	}while(k<150);
  
}

void testB()
{
  
// array of 50 bytes
  	char *Check2[50];

	int k, j;
	for (j = 0; j < 3; j++)
	{
		for (k = 0; k < 50; k++)
		{
		// mallocing one byte 
			Check2[k] = (char *)malloc(sizeof(char));
		}
		// free whaever you have malloced
		for (k = 0; k < 50; k++)
		{
			free(Check2[k]);
		}
	}
}


void testC()
{
 	char *check3[50];

	int writy = 0, last = -1, num = 0, create = 0;

	while (create < 50)
	{
		int ass = range(0, 1);

		// Allocate
		if (ass == 0)
		{
			char *a = (char *)malloc(sizeof(char));
			if (a != NULL)
			{
				check3[writy] = a;
				last = writy;
				++writy;
				++create;
			}

			else
			{
				// Could not malloc
			}
		}

		// Free
		if (ass == 1)
		{
			if (last< 0 && writy == 0)
				continue;

			free(check3[last]);
			--writy;
			--last;
		}

		++num;
	}

	// Free the rest of the heap
	int y;
	for (y = 0; y < writy; y++)
		free(check3[y]);
}
void testD()
{
	int num = 0, last = -1, create = 0, writy=0;

	char *check3[50];
	do
	{
		int ww = range(0, 1);
		int huge = range(1, 64);

		if (huge <= 0)
			continue;

		// Malloc
		if (ww == 0)
		{
			char *a = (char *)malloc(sizeof(char) * huge);
			if (a != NULL)
			{
				check3[writy] = a;
				last = writy;
				++writy;
				++create;
			}

			else
			{
				
			}
		}

		// Free
		if (ww == 1)
		{
			if (last< 0 && writy == 0)
				continue;

			free(check3[last]);
			--writy;
			--last;
		}

		++num;
	}while(create<50);

	// Free the rest of the heap
	int i;
	for (i = 0; i < writy; i++)
		free(check3[i]);
}
void testE()
{
  // checking for free variables for stack which cant be free (base testcase)
  int poo=7;
  free(&poo);
  // freeing a pointer which is alreay freed
  char *piint = (char*)malloc(sizeof(char) * 69);
	free(piint);
	free(piint);
	//mallocing 0 bytes which should be an error
	int *qw = (int*)malloc(0);
	free(qw);
	// mallocing somehting which is over the size of the heap
	short *out =(short*)malloc(sizeof(short)*2099);
	void* p=malloc(sizeof(int));
	char* sdf="MY name is khan";
	p=malloc(sizeof(char)*(strlen(sdf)+1));
	memcpy(p,sdf,strlen(sdf));
	free(p);
}
void testF()
{
  	int *kiki= (int*)malloc(sizeof(int)*789);
	free(kiki+4);
	void *pubg=malloc(45);
	free((int*)pubg);
	//	long pp =malloc(200);
        char*p ="a";

 int *ptr=malloc(4);
  free(ptr);
  int*ptr2=malloc(4);
  free(ptr);
	

}
