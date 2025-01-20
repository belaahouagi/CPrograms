#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Bem-vindo ao jogo de adivinhação!\n");
    printf("Eu escolhi um número entre 1 e 100. Tente adivinhar!\n");

    srand(time(NULL));
    int numerosecreto = rand() % 100 + 1;

    int chute, tentativas = 0;
    int limite_tentativas_dicas = 5;

    while (1) {
        printf("\nQual é o seu chute? ");
        scanf("%d", &chute);

        tentativas++;
        printf("O seu chute foi: %d\n", chute);

        if (chute == numerosecreto) {
            printf("Parabéns, você acertou em %d tentativas!\n", tentativas);
            break;
        }

        int diferenca = abs(chute - numerosecreto);
        if (diferenca <= 5) {
            printf("Quente! Você está muito perto.\n");
        } else if (diferenca <= 15) {
            printf("Morno! Você está chegando mais perto.\n");
        } else {
            printf("Frio! Você está longe do número secreto.\n");
        }

        if (tentativas >= limite_tentativas_dicas) {
            if (numerosecreto % 2 == 0) {
                printf("Dica: O número secreto é par.\n");
            } else {
                printf("Dica: O número secreto é ímpar.\n");
            }

            if (chute < numerosecreto) {
                printf("Dica: O número secreto é maior que %d.\n", chute);
            } else {
                printf("Dica: O número secreto é menor que %d.\n", chute);
            }
        } else {
            printf("Tente novamente!\n");
        }
    }

    printf("Obrigado por jogar!\n");
    return 0;
}
