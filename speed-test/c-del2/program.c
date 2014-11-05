#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include "thingmodule.h"

#define max(a,b) (((a) (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

/* Subtract the ‘struct timeval’ values X and Y,
 *    storing the result in RESULT.
 *       Return 1 if the difference is negative, otherwise 0. */

int timeval_subtract (struct timeval *result, struct timeval*x, struct timeval *y) {
      /* Perform the carry for the later subtraction by updating y. */
      if (x->tv_usec < y->tv_usec) {
              int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
                  y->tv_usec -= 1000000 * nsec;
                      y->tv_sec += nsec;
                        }
        if (x->tv_usec - y->tv_usec > 1000000) {
                int nsec = (x->tv_usec - y->tv_usec) / 1000000;
                    y->tv_usec += 1000000 * nsec;
                        y->tv_sec -= nsec;
                          }

          /* Compute the time remaining to wait.
           *      tv_usec is certainly positive. */
          result->tv_sec = x->tv_sec - y->tv_sec;
            result->tv_usec = x->tv_usec - y->tv_usec;

              /* Return 1 if result is negative. */
              return x->tv_sec < y->tv_sec;
}

int main(int argc, char *argv[]){
    int m = 5000;
    int n = 5000;

    double **data, **fuzzed;

    struct timeval data_start, data_end,
                   calc_start, calc_end, 
                   data_diff, calc_diff;

    gettimeofday(&data_start, NULL);
    data =  malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++){
        data[i] = malloc(n * sizeof(double));
    }

    fuzzed = malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++){
        fuzzed[i] = malloc(n * sizeof(double));
    }

    printf("Generating sample data (%dx%d array), in C...\n", m, n);

    for (int j = 0; j < m; j++){
        for (int k = 0; k < n; k++) {
            data[j][k] = pow(((float)j/10.0), 4) + pow(((float)k/20.0), 4);
        }
    }
    gettimeofday(&data_end, NULL);

    printf("Performing gradient calculation on data (%dx%d array), with results:\n", m, n);
    gettimeofday(&calc_start, NULL);
    del2(data, fuzzed, m, n);
    gettimeofday(&calc_end, NULL);

    for (int i = 0; i< min(m, n); i+=1000){
        printf("%f\n", fuzzed[i][i]);
    }

    timeval_subtract(&data_diff, &data_end, &data_start);
    timeval_subtract(&calc_diff, &calc_end, &calc_start);

    printf("Summary:\n");
    printf("   Data generation code segment (C) took %f seconds\n", data_diff.tv_sec + data_diff.tv_usec/1e6);
    printf("   Gradient calculation code segment (C) took %f seconds\n", calc_diff.tv_sec + calc_diff.tv_usec/1e6);
    printf("   Total time: %.3f seconds\n", (data_diff.tv_sec + data_diff.tv_usec/1e6) + (calc_diff.tv_sec + calc_diff.tv_usec/1e6));

    // We should free() data, and fuzzed here. I'm lazy though.
    return 0;
}
