#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main()
{
double t;
int const N = 50000, K=100000;
t=wtime();

	int A[N], C[K];
	int i, b=0;
	
	for(i=0;i<N;i++)
		A[i]=getrand(1, K);
	
	for(i=0;i<N;i++)
		C[i]=0;
		
	for(i=0;i<N;i++)
		C[A[i]]=C[A[i]]+1;
		
	for(int j=0;j<K;j++)
		for(i=0;i<C[j];i++){
			A[b]=j;
			b+=1;
		}
		
	//for(i=0;i<N;i++)
	//	printf("%8d", A[i]);

t=wtime()-t;
printf("Elapsed time: %.6f sec.\n", t); 
	return 0;
}	