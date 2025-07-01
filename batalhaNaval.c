#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro
#define NAVIO 3       // Valor que representa um navio no tabuleiro
#define AGUA 0        // Valor que representa água no tabuleiro
#define TAM_NAVIO 3   // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM]; // Matriz que representa o tabuleiro
    int i, j;

    // 1. Inicializando o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Coordenadas iniciais do navio horizontal
    int linhaH = 2;
    int colunaH = 4;

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaH + TAM_NAVIO <= TAM) {
        for (j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linhaH][colunaH + j] = NAVIO;
        }
    } else {
        printf("Navio horizontal fora dos limites!\n");
    }

    // 3. Coordenadas iniciais do navio vertical
    int linhaV = 5;
    int colunaV = 6;

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaV + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;

        // Verifica se já tem navio nas posições antes de posicionar
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        // Se não houver sobreposição, posiciona o navio vertical
        if (!sobreposicao) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        } else {
            printf("Navio vertical se sobrepõe ao navio horizontal!\n");
        }
    } else {
        printf("Navio vertical fora dos limites!\n");
    }

    // 4. Exibindo o tabuleiro com printf
    printf("\nTabuleiro Batalha Naval:\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}