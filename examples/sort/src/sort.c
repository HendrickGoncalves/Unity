
#include "sort.h"

int sort(int *v, int size) {
    int i, j, tmp;

    for (i = 1; i < size; i++) {
        for (j = 0; j < (size-1); j++) {
            if (v[j] > v[j + 1]) {
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }

    return 0;
}
