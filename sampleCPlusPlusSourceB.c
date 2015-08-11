/**
* @author : Yash M. Sawant
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXLENGTH 20
#define MINVALUE -999



int main() {
    int i;
    int a[MAXLENGTH];
    int c[MAXLENGTH]; c[0] = 0;
    int s[MAXLENGTH]; s[0] = MINVALUE;
    int p = -1, tp = -1, pv = 0;
    for(i = 0 ; i < MAXLENGTH ; i ++) {
        srand((time(NULL)) % (23 * (i + 1)));
        a[i] = rand() % 499;
        printf("%4d ", a[i]);

        /**
        *    Dynamic Programming Maximum Subarray Program
        *
        *   51   51  374  199   23  346  346  199  374  143
        *    0    0  323 -175 -176  323    0 -147  175 -231
        * -999    0  323  323  323  323  323  323  351  351
        *  Max Sub Array = 351 and Starts at 0
        */
    }
    printf("\n");
    for(i = 1 ; i < MAXLENGTH ; i ++) {
        c[i] = a[i] - a[i - 1];
    }
    printf("%4d ", c[0]);
    for(i = 1 ; i < MAXLENGTH ; i ++) {
        printf("%4d ", c[i]);
        if(s[i - 1] < pv + c[i]) {
            s[i] = pv + c[i];
            pv = pv + c[i];
			if(tp > p) {
                p = tp;
			}
        } else {
            s[i] = s[i - 1];
            pv = pv + c[i];
            if(pv < 0) {
                pv = 0; tp = i;
            }
        }
    }
    printf("\n");
    for(i = 0 ; i < MAXLENGTH ; i ++) {
        printf("%4d ", s[i]);
    }
    printf("\n");
    printf("Max Sub Array = %d and Starts at %d ", s[MAXLENGTH - 1], p);
    return 0;

}
