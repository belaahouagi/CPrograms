#include <stdio.h>
#include <math.h> // Biblioteca para funções matemáticas, como sqrt

int main() {
    float a, b, c;
    float x1, x2;

    printf("Digite um número a: ");
    scanf("%f", &a);

    printf("Digite um número b: ");
    scanf("%f", &b);

    printf("Digite um número c: ");
    scanf("%f", &c);

    x1 = -b - sqrt(b*b - 4*a*c)/2*a;
    x2 = -b + sqrt(b*b - 4*a*c)/2*a;

    printf("x1 = %.2f\n", x1);
    printf("x2 = %.2f\n", x2);

    
    return 0;
}
