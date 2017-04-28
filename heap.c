#include <stdio.h>

int main() {
	int const N = 9;
	int A[N], i, swap; 
	
	for (i = 0; i < N; ++i) {
		scanf("\n%d", &A[i]);
    }
	
	for (i = N/2-1; i >= 0; --i) {
		if (A[i] < A[i * 2 + 1]) {
			swap = A[i];
			A[i] = A[i * 2 + 1];
			A[i * 2 + 1] = swap;
		}	 
	
		if (A[i] < A[i * 2 + 2]) {
			swap = A[i];
			A[i] = A[i * 2 + 2];
			A[i * 2 + 2] = swap;
		}
	}
	
	printf("\n");
	
	for (i = 0; i < N; ++i) {
		printf ("%d ", A[i]);
	}
}