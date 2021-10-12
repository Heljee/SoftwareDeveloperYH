#include <stdio.h>
#include <stdint.h>

#define EXPRESSION (3 * j / k - 2)
#define SET_VARIABLES \
    {                 \
        i = 3;        \
        j = 2;        \
        k = 0;        \
    }

int main(void)
{
    int i = 0, j = 7, k = 6;
    char a = 'A', b = '3';
    int32_t x, y = 3;
    uint32_t z = 32;
    double d;

    x = EXPRESSION;
    // 1 by using local variables inside this block
    printf("A: %d\n", x);

    // 0 0 1 1
    // 1 1 1 0
    // -------
    // 0 0 1 0
    y -= ((j << 1) & (k >> 1));
    printf("B: %d\n", y);

    // 57
    x = (!(i && k) || !k) ? k + b : j + b;
    printf("C: %d\n", x);

    // (51 + 6) % 10 = 6 + 66 = 72
    a += (b + k--) % 10;
    printf("D: %d\n", a);

    // 700 / 4 / 3 = 58,33
    d = (double)j * 100 / --k / 3;
    printf("E: %f\n", d);

    // x<z false, ":" false (0)
    x = -1;
    y = (x < z) ? (k < j < 0) : (b >= a < i);
    printf("F: %d\n", y);

    // 4294967295 / 32 = 134217727
    d = x / z;
    printf("G: %f\n", d);

    // 0 and 1, Logical AND is calc before OR
    i = 4;
    j = -1;
    k = 0;
    x = i && j && k;
    y = i || j && k;
    printf("H: %d, %d\n", x, y);

    // x = 1, y = 1
    x = i && j || k;
    y = i || j || k;
    printf("I: %d, %d\n", x, y);

    // i = 4, j=3, k=0, y = 1
    SET_VARIABLES;
    y = ++i || ++j && k++;
    printf("J: %d, %d, %d, %d\n", i, j, k, y);

    // i = 2, j = 2, k = 1, y = 0
    SET_VARIABLES;
    y = (123 && --i) ? k++ : ++k;
    printf("K: %d, %d, %d, %d\n", i, j, k, y);

    // i=4, j=3, k=1, y = 0,
    SET_VARIABLES;
    y = ++i && ++j && k++;
    printf("L: %d, %d, %d, %d\n", i, j, k, y);

    // i=2, j=3, k=3
    i = 4;
    j = --i;
    k = i--;
    printf("M: %d, %d, %d\n", i, j, k);

    i = -1;
    j = 1;

    // i is true, therefore we print Hello World
    i && printf("N: Hello World!\n") && --j;

    /*     
    int i = 0, j = 7, k = 6, r1, r2 = 3;
    char r3, r4 = 'A', ch = '3';
    uint32_t b = 32;
    int32_t a = -1;
    float r5;

    r1 = EXPRESSION;
    printf("A: %d\n", r1); // 1 Taking the local variables
    r2 -= ((j << 1) & (k >> 1));
    // 0 0 1 1
    // 1 1 1 0
    // -------
    // 0 0 1 0
    printf("B: %d\n", r2); // 1,

    r3 = (!(i && k) || !k) ? k + ch : j + ch; // 57
    printf("C: %d\n", r3);

    r4 += (ch + k--) % 10;  // (51 + 6) % 10 = 6 + 66 = 72
    printf("D: %d\n", r4);

    r5 = (float)j * 100 / --k / 3;  // 700 / 4 / 3 = 58,33
    printf("E: %f\n", r5);

    r1 = (a < b) ? (k < j < 0) : (ch >= r4 < i);    // a<b false, k<j<0 0, ch>=r4<i 0
    printf("F: %d\n", r1);
 */
    return 0;
}
