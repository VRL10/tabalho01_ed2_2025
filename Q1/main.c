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
    printf("5. Sair\n");
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
                // Cadastrar Artista
                printf("Digite o nome do artista: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove a nova linha

                printf("Digite o tipo do artista: ");
                fgets(tipo, sizeof(tipo), stdin);
                tipo[strcspn(tipo, "\n")] = 0; // Remove a nova linha

                printf("Digite o estilo musical do artista: ");
                fgets(estilo_musical, sizeof(estilo_musical), stdin);
                estilo_musical[strcspn(estilo_musical, "\n")] = 0; // Remove a nova linha

                printf("Digite o numero de albuns: ");
                scanf("%d", &numero_albuns);
                getchar(); // Limpa o buffer do teclado

                int resultado = cadastrar_artista(&artistas, nome, tipo, estilo_musical, numero_albuns);
                if (resultado == 1)
                    printf("Artista cadastrado com sucesso!\n");
                else if (resultado == 0)
                    printf("Erro: Artista ja cadastrado!\n");
                else
                    printf("Erro ao cadastrar artista!\n");
                
                break;
            }
            case 2: {
                // Cadastrar Álbum
                if (artistas == NULL) {
                    printf("Nenhum artista cadastrado. Cadastre um artista primeiro.\n");
                    break;
                }

                printf("Digite o nome do artista para o album: ");
                fgets(nome_artista, sizeof(nome_artista), stdin);
                nome_artista[strcspn(nome_artista, "\n")] = 0; // Remove a nova linha

                printf("Digite o titulo do album: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = 0; // Remove a nova linha

                printf("Digite o ano de lancamento: ");
                scanf("%d", &ano_lancamento);
                getchar(); // Limpa o buffer do teclado

                printf("Digite a quantidade de musicas: ");
                scanf("%d", &qtd_musicas);
                getchar(); // Limpa o buffer do teclado

                int resultado = cadastrar_album(artistas, &artistas->albuns, titulo, ano_lancamento, qtd_musicas, nome_artista);
                if (resultado == 1)
                    printf("Album cadastrado com sucesso!\n");
                else if (resultado == 0)
                    printf("Erro: Album ja cadastrado!\n");
                else
                    printf("Erro ao cadastrar album!\n");
                
                break;
            }
            case 3: {
                // Cadastrar Música
                if (artistas == NULL) {
                    printf("Nenhum artista cadastrado. Cadastre um artista primeiro.\n");
                    break;
                }
            
                printf("Digite o nome do artista para a musica: ");
                fgets(nome_artista, sizeof(nome_artista), stdin);
                nome_artista[strcspn(nome_artista, "\n")] = 0; // Remove a nova linha
            
                printf("Digite o titulo da musica: ");
                fgets(musica_titulo, sizeof(musica_titulo), stdin);
                musica_titulo[strcspn(musica_titulo, "\n")] = 0; // Remove a nova linha
            
                printf("Digite a duracao da musica (em minutos): ");
                scanf("%d", &duracao);
                getchar(); // Limpa o buffer do teclado
            
                // Aqui, precisamos buscar o álbum correspondente ao artista
                char titulo_album[50];
                printf("Digite o titulo do album: ");
                fgets(titulo_album, sizeof(titulo_album), stdin);
                titulo_album[strcspn(titulo_album, "\n")] = 0; // Remove a nova linha
            
                Arv_albuns *album = buscar_album(artistas->albuns, titulo_album); // Busca o álbum pelo título
                if (album == NULL) {
                    printf("Album nao encontrado. Cadastre um album primeiro.\n");
                    break;
                }
            
                int resultado = cadastrar_musicas(album, &album->musicas, musica_titulo, duracao, titulo_album);
                if (resultado == 1)
                    printf("Musica cadastrada com sucesso!\n");
                else if (resultado == 0)
                    printf("Erro: Musica ja cadastrada!\n");
                else
                    printf("Erro ao cadastrar musica!\n");
                
                break;
            }
            case 4: {
                // Mostrar todos os artistas
                if (artistas == NULL)
                    printf("Nenhum artista cadastrado.\n");
                else {
                    printf("\n--- Lista de Artistas ---\n");
                    mostrar_todos_artistas_cadastrados(artistas);
                }
                break;
            }
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
