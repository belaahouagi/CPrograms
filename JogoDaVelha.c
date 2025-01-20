#include <stdio.h>

#define SIZE 3

void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE; k++) {
                printf("---");
                if (k < SIZE - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int verificarVencedor(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return 1; // Linha
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return 1; // Coluna
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return 1;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return 1;

    return 0;
}

int verificarEmpate(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tabuleiro[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void realizarJogada(char tabuleiro[SIZE][SIZE], int jogador) {
    int linha, coluna;
    char simbolo = (jogador == 1) ? 'X' : 'O';
    while (1) {
        printf("Jogador %d (%c), insira linha e coluna (1-3): ", jogador, simbolo);
        scanf("%d %d", &linha, &coluna);
        linha--;
        coluna--;
        if (linha >= 0 && linha < SIZE && coluna >= 0 && coluna < SIZE && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = simbolo;
            break;
        } else {
            printf("Posição inválida! Tente novamente.\n");
        }
    }
}

int main() {
    char tabuleiro[SIZE][SIZE];
    int jogadorAtual = 1;

    inicializarTabuleiro(tabuleiro);

    while (1) {
        exibirTabuleiro(tabuleiro);
        realizarJogada(tabuleiro, jogadorAtual);

        if (verificarVencedor(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("Jogador %d venceu!\n", jogadorAtual);
            break;
        }

        if (verificarEmpate(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("O jogo terminou em empate!\n");
            break;
        }

        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
    }

    return 0;
}
