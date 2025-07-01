#include <stdio.h>

#define TAM 10         // Tamanho do tabuleiro
#define TAM_HAB 5      // Tamanho das matrizes de habilidade (5x5)
#define NAVIO 3        // Valor do navio no tabuleiro
#define AGUA 0         // Valor da água
#define HABILIDADE 5   // Valor da área de efeito da habilidade

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = AGUA;
        }
    }
}

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("\nTABULEIRO 10x10\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tab[TAM][TAM], int matriz[TAM_HAB][TAM_HAB], int centroLinha, int centroColuna) {
    int offset = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = centroLinha - offset + i;
            int coluna = centroColuna - offset + j;

            // Verifica se a posição está dentro do tabuleiro
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (matriz[i][j] == 1 && tab[linha][coluna] == AGUA) {
                    tab[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // --------------------
    // POSICIONA 4 NAVIOS
    // --------------------

    // Navio Horizontal
    int h_linha = 1, h_coluna = 2;
    for (int j = 0; j < 3; j++) tabuleiro[h_linha][h_coluna + j] = NAVIO;

    // Navio Vertical
    int v_linha = 3, v_coluna = 6;
    for (int i = 0; i < 3; i++) tabuleiro[v_linha + i][v_coluna] = NAVIO;

    // Navio Diagonal ↘
    int d1_linha = 5, d1_coluna = 1;
    for (int i = 0; i < 3; i++) tabuleiro[d1_linha + i][d1_coluna + i] = NAVIO;

    // Navio Diagonal ↙
    int d2_linha = 2, d2_coluna = 8;
    for (int i = 0; i < 3; i++) tabuleiro[d2_linha + i][d2_coluna - i] = NAVIO;

    // --------------------
    // MATRIZES DE HABILIDADE
    // --------------------

    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    // Cone (ponta em cima, abrindo para baixo)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i)) {
                cone[i][j] = 1;
            }
        }
    }

    // Cruz (linha do meio e coluna do meio)
    for (int i = 0; i < TAM_HAB; i++) {
        cruz[i][TAM_HAB / 2] = 1;         // Coluna central
        cruz[TAM_HAB / 2][i] = 1;         // Linha central
    }

    // Octaedro (losango com centro no meio)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // --------------------
    // APLICANDO HABILIDADES
    // --------------------
    aplicarHabilidade(tabuleiro, cone, 2, 2);      // Cone no topo-esquerda
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Octaedro no canto inferior-direito

    // --------------------
    // MOSTRAR TABULEIRO FINAL
    // --------------------
    exibirTabuleiro(tabuleiro);

    return 0;
}