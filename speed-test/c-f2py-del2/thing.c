#include <stdio.h>

void del2(double *stuff, double *fuzz, int m, int n) {
    int j, k, index;

    for (j = 0; j < m; j++) {
        index = (int)(j*m)+k;
        fuzz[j*m] = 0.0;
        fuzz[j*m+n] = 0.0;
    }

    for (k = 0; k < n; k++) {
        fuzz[k] = 0.0;
        fuzz[m+k] = 0.0;
    }

    for (j = 1; j < m -1; j++){
        //printf("row: %d\n", (int)(j));
        for (k = 1; k < n - 1; k++) {
            //printf("col: %d\n", (int)(k));
            index = (int)(j*m)+k;
            //printf("array access index: %d val: %f\n", index, stuff[index]);
            
            fuzz[index] = 0.5*(
                    stuff[(int)((j-1)*m)+k] +
                    stuff[(int)((j+1)*m)+k] +
                    stuff[(int)(j*m)+(k-1)] +
                    stuff[(int)(j*m)+(k+1)] -
                    4.0*stuff[index]);
        }
    }
}
