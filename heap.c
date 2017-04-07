heap.c             [----] 18 L:[  1+ 0   1/ 28] *(18  / 414b) 0010 0x00A [*][X]
#include <stdio.h>

int main() {
    int const N = 9;
    int A[N], i, swap;

    for (i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < N; ++i) {
        if (A[N] < A[N * 2 + 1]) {
            swap = A[N];
            A[N] = A[N * 2 + 1];
            A[N * 2 + 1] = swap;
        }

        if (A[N] < A[N * 2 + 2]) {
            swap = A[N];
            A[N] = A[N * 2 + 2];
            A[N * 2 + 2] = swap;
        }
    }

    for (i = 0; i < N; ++i) {
        printf ("\n%d", A[N]);
    }
}
