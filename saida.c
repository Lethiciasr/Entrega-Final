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
int T7;
int T8;
int T9;
int T10;
int T11;
int T12;

int main()
{
int T1;
int T2;
int T3;
int T4;
int T5;
int T6;
int T7;
int T8;
int T9;
int T10;
int T11;
int T12;
T3 = 0;
T2 = T3;
T4 = 0;
T1 = T4;
L1:
T5 = 10;
T6 = T1 < T5;
if (!T6) goto L2;
T7 = 3;
T8 = T1 == T7;
if (!T8) goto L4;
goto L3;
L4:
T9 = 7;
T10 = T1 == T9;
if (!T10) goto L5;
goto L2;
L5:
T11 = T2 + T1;
T2 = T11;
L3:
T1 = T1 + 1;
goto L1;
L2:
T12 = 0;
    return 0;
}
