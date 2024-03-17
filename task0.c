#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int func(long n ,long  m, long k, long* b) {
    static long  c[999];
    long  z, q, num=0;
    for (z = 0; z <= 999-m; z++) {
        for (q = 0; q < m; q++) {
            num = num + *(b +z+q);
        }
        c[z] = k * m - num;
        num = 0;
    }
    for (z = n-m+1; z < 1000; z++) {
        c[z] = c[z]-k*(z-n+m-1);
    }
    long temp, e = 0;
    temp = c[0];
    for (z = 1; z <= 999-m; z++) {
        if (temp < c[z]) {
            temp = c[z];
            e = z;
        }
    }
    if (temp <= 0) {
        return -1;
    }
    else {
        return e;
    }
}
int main() {
    long  n, m, k, i, e;
    char s =0;
    static long a[999];
    printf("ÇëÊäÈë");
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    printf("ÇëÊäÈë");
    for (i = 0; i <= 999&&s!='\n'; i++) {
        scanf("%d", &a[i]);
        s= getchar();
    }
    long* b;
    b = a;
    e = func(n,m, k, b);
    if (e == -1) {
        printf("0   0");
    }
    else {
        printf("%d   %d", e+1, e + m);
    }
}