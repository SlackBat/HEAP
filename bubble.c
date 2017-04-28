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
	t=wtime();

	int const N=50000;
	int mas[N], X;
	
	for(int i=0; i<N; i++)
		mas[i]=getrand(1, 100000);
		
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(mas[i]<mas[j])
				{
				X=mas[j];
				mas[j]=mas[i];
				mas[i]=X;
				}
				
	//for(int i=0; i<N; i++)
	//	printf("%7d", mas[i]);

	t=wtime()-t;
	printf("Elapsed time: %.6f sec.\n", t); 
	return 0;
}	