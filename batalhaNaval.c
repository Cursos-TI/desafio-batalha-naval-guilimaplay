#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro
#define NAVIO 3       // Valor que representa um navio
#define AGUA 0        // Valor que representa água
#define TAM_NAVIO 3   // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // Inicializa o tabuleiro com água (0 em todas as posições)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ----------------------------
    // Posicionando o navio HORIZONTAL
    int linhaH = 1;
    int colunaH = 2;

    if (colunaH + TAM_NAVIO <= TAM) {
        int podeColocar = 1;

        for (j = 0; j < TAM_NAVIO; j++) {
            if (tabuleiro[linhaH][colunaH + j] != AGUA) {
                podeColocar = 0;
                break;
            }
        }

        if (podeColocar) {
            for (j = 0; j < TAM_NAVIO; j++) {
                tabuleiro[linhaH][colunaH + j] = NAVIO;
            }
        }
    }

    // ----------------------------
    // Posicionando o navio VERTICAL
    int linhaV = 3;
    int colunaV = 6;

    if (linhaV + TAM_NAVIO <= TAM) {
        int podeColocar = 1;

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                podeColocar = 0;
                break;
            }
        }

        if (podeColocar) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    }

    // ----------------------------
    // Posicionando o navio DIAGONAL PRINCIPAL (↘)
    int linhaD1 = 5;
    int colunaD1 = 1;

    if (linhaD1 + TAM_NAVIO <= TAM && colunaD1 + TAM_NAVIO <= TAM) {
        int podeColocar = 1;

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA) {
                podeColocar = 0;
                break;
            }
        }

        if (podeColocar) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            }
        }
    }

    // ----------------------------
    // Posicionando o navio DIAGONAL SECUNDÁRIA (↙)
    int linhaD2 = 2;
    int colunaD2 = 8;

    if (linhaD2 + TAM_NAVIO <= TAM && colunaD2 - TAM_NAVIO + 1 >= 0) {
        int podeColocar = 1;

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != AGUA) {
                podeColocar = 0;
                break;
            }
        }

        if (podeColocar) {
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            }
        }
    }

    // ----------------------------
    // Exibindo o tabuleiro
    printf("\nTABULEIRO 10x10 - BATALHA NAVAL\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}