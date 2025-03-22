#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

// Variáveis globais
Arv_artista *artistas = NULL; // Árvore de artistas
char nome[50], tipo[20], estilo_musical[50], musica_titulo[50], titulo[50], nome_artista[50];
int numero_albuns, duracao, ano_lancamento, qtd_musicas;


void menu() {
    printf("\n--- Menu ---\n");
    printf("1. Cadastrar Artista\n");
    printf("2. Cadastrar Album\n");
    printf("3. Cadastrar Musica\n");
    printf("4. Mostrar Todos os Artistas\n");
    printf("5. Mostrar Todos os de um determinado tipo\n");
    printf("6. Mostrar Todos os de um determinado estilo musical\n");
    printf("7. Mostrar Todos os de um determinado estilo musical e tipo\n");
    printf("8. Mostrar todos os Albuns de um determinado artista\n");
    printf("9. Mostrar todos os álbuns de um determinado ano de um artista\n");
    printf("10. Sair\n");
}

int main() {
    int opcao;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

    switch (opcao) {
        case 1: {
                
        }
    } while (opcao != 10);
    return 0;
}