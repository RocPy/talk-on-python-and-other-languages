#include "thingmodule.h"

void del2(double **data, double **fuzz, int m, int n){
    int j, k;

    for (j = 0; j < m; j++) {
        fuzz[j][0] = 0.0;
        fuzz[j][n-1] = 0.0;
    }

    for (k = 0; k < n; k++) {
        fuzz[0][k] = 0.0;
        fuzz[m-1][k] = 0.0;
    }

    for (j = 1; j < m -1; j++){
        for (k = 1; k < n - 1; k++) {
            fuzz[j][k] = 0.5*(
                    data[j-1][k] +
                    data[j+1][k] +
                    data[j][k-1] +
                    data[j][k+1] -
                    4.0*data[j][k]);
        }
    }

    return;
}
