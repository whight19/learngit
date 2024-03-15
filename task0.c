#include<stdio.h>
int func(int m, int k, int* b) {
    static int c[999];
    int z, q, num=0;
    for (z = 0; z <= 999-m; z++) {
        for (q = 0; q < m; q++) {
            num = num + *(b + q);
        }
        c[z] = k * m - num;
    }
    int temp, e = 0;
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
    int n, m, k, i, e;
    char s =0;
    static int a[999];
    printf("请输入");
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    printf("请输入");
    for (i = 0; i <= 999&&s!='\n'; i++) {
        scanf("%d", &a[i]);
        s= getchar();
    }
    int* b;
    b = a;
    e = func(m, k, b);
    if (e == -1) {
        printf("0   0");
    }
    else {
        printf("%d   %d", e+1, e + m);
    }
}