#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

// Variáveis globais
Arv_artista *artistas = NULL; // Árvore de artistas

void menu() {
    printf("\n--- Menu ---\n");
    printf("1. Cadastrar Artista\n");
    printf("2. Cadastrar Álbum\n");
    printf("3. Cadastrar Música\n");
    printf("4. Mostrar Todos os Artistas\n");
    printf("5. Sair\n");
}



int main() {
    int opcao;

    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                // Cadastrar Artista
                char nome[50], tipo[20], estilo_musical[50];
                int numero_albuns;

                printf("Digite o nome do artista: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove a nova linha

                printf("Digite o tipo do artista: ");
                fgets(tipo, sizeof(tipo), stdin);
                tipo[strcspn(tipo, "\n")] = 0; // Remove a nova linha

                printf("Digite o estilo musical do artista: ");
                fgets(estilo_musical, sizeof(estilo_musical), stdin);
                estilo_musical[strcspn(estilo_musical, "\n")] = 0; // Remove a nova linha

                printf("Digite o número de álbuns: ");
                scanf("%d", &numero_albuns);
                getchar(); // Limpa o buffer do teclado

                int resultado = cadastrar_artista(&artistas, nome, tipo, estilo_musical, numero_albuns);
                if (resultado == 1)
                    printf("Artista cadastrado com sucesso!\n");
                else if (resultado == 0)
                    printf("Erro: Artista já cadastrado!\n");
                else
                    printf("Erro ao cadastrar artista!\n");
                break;

            case 2:
                // Cadastrar Álbum
                if (artistas == NULL) {
                    printf("Nenhum artista cadastrado. Cadastre um artista primeiro.\n");
                    break;
                }

                char titulo[50];
                int ano_lancamento, qtd_musicas;
                char nome_artista[50];

                printf("Digite o nome do artista para o álbum: ");
                fgets(nome_artista, sizeof(nome_artista), stdin);
                nome_artista[strcspn(nome_artista, "\n")] = 0; // Remove a nova linha

                printf("Digite o título do álbum: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = 0; // Remove a nova linha

                printf("Digite o ano de lançamento: ");
                scanf("%d", &ano_lancamento);
                getchar(); // Limpa o buffer do teclado

                printf("Digite a quantidade de músicas: ");
                scanf("%d", &qtd_musicas);
                getchar(); // Limpa o buffer do teclado

                resultado = cadastrar_album(artistas, &artistas->albuns, titulo, ano_lancamento, qtd_musicas, nome_artista);
                if (resultado == 1)
                    printf("Álbum cadastrado com sucesso!\n");
                else if (resultado == 0)
                    printf("Erro: Álbum já cadastrado!\n");
                else
                    printf("Erro ao cadastrar álbum!\n");
                break;

            case 3:
                // Cadastrar Música
                if (artistas == NULL) {
                    printf("Nenhum artista cadastrado. Cadastre um artista primeiro.\n");
                    break;
                }

                char titulo_musica[50], nome_artista_musica[50];
                int duracao;

                printf("Digite o nome do artista para a música: ");
                fgets(nome_artista_musica, sizeof(nome_artista_musica), stdin);
                nome_artista_musica[strcspn(nome_artista_musica, "\n")] = 0; // Remove a nova linha

                printf("Digite o título da música: ");
                fgets(titulo_musica, sizeof(titulo_musica), stdin);
                titulo_musica[strcspn(titulo_musica, "\n")] = 0; // Remove a nova linha

                printf("Digite a duração da música (em minutos): ");
                scanf("%d", &duracao);
                getchar(); // Limpa o buffer do teclado

                resultado = cadastrar_musica(artistas, nome_artista_musica, titulo_musica, duracao);
                if (resultado == 1)
                    printf("Música cadastrada com sucesso!\n");
                else if (resultado == 0)
                    printf("Erro: Música já cadastrada!\n");
                else
                    printf("Erro ao cadastrar música!\n");
                break;

            case 4:
                // Mostrar todos os artistas
                if (artistas == NULL)
                    printf("Nenhum artista cadastrado.\n");
                else {
                    printf("\n--- Lista de Artistas ---\n");
                    mostrar_todos_artistas_cadastrados(artistas);
                }
                break;

            case 5:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    // Liberação de memória e finalização do programa
    liberar_artistas(artistas);
    return 0;
}
