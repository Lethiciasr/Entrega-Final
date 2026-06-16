#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int T1;
int T2;
int T3;
int T4;
int T5;
int T6;

int main()
{
int T1;
int T2;
int T3;
int T4;
int T5;
int T6;
T1 = 15;
T2 = T1;
T3 = 18;
T4 = T2 >= T3;
if (!T4) goto L1;
T5 = 1;
printf("%d\n", T5);
goto L2;
L1:
T6 = 0;
printf("%d\n", T6);
L2:
    return 0;
}
