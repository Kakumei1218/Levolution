#include <stdio.h>
#include <math.h>
int main() {
double A = pow(2.0, 32.0) + 0.2; // A = 2^32 + 0.2
double B = pow(2.0, 32.0) + 0.1; // B = 2^32 + 0.1
double C = A - B; // A - B (計算上の0.1)
double N = 0.0;
double M = 0.0;
for (int i = 1; i <= 10; i++) {
N = N + 0.1; // 純粋な0.1を10回足す
M = M + C; // 誤差を含んだCを10回足す
}
printf("A = %.5f ¥n", A);
printf("B = %.5f ¥n", B);
printf("N = %.20f ¥n", N);
printf("M = %.20f ¥n", M);
return 0;
}