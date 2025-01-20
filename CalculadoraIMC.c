#include <stdio.h> // Biblioteca para entrada e saída (printf)

int main() {
    float peso, altura, IMC;

    altura = 1.8;
    peso = 70.0;

    IMC = peso / (altura * altura);

    // Corrigido o printf com o especificador de formato %f
    printf("Seu IMC é: %.2f\n", IMC); // %.2f limita o resultado a 2 casas decimais

    return 0; // Indica que o programa foi executado com sucesso
}
