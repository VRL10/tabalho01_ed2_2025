#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void menu() {
    printf("\n===== Biblioteca de Música =====\n");
    printf("1. Cadastrar Artista\n");
    printf("2. Cadastrar Album\n");
    printf("3. Cadastrar Musica\n");
    printf("4. Mostrar todos os artistas\n");
    printf("5. Mostrar artistas por tipo\n");
    printf("6. Mostrar artistas por estilo musical\n");
    printf("7. Mostrar artistas por estilo musical e tipo\n");
    printf("8. Mostrar albuns de um artista\n");
    printf("9. Mostrar albuns de um ano para um artista\n");
    printf("10. Mostrar todas as musicas de um album de um artista\n");
    printf("11. Mostrar todos os albuns de um determinado ano de todos os artistas cadastrados\n");
    printf("12. Mostrar os dados de uma determinada música\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    Arv_artista *raiz = NULL;
    int opcao, cadastrou, ano;
    char nome[50], tipo[20], estilo[50], titulo[50];

    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                Arv_artista *novo = alocar_arvore_artista(NULL);
                printf("Nome do artista: ");
                fgets(novo->nome, 50, stdin);
                novo->nome[strcspn(novo->nome, "\n")] = 0;
                printf("Tipo do artista: ");
                fgets(novo->tipo, 20, stdin);
                novo->tipo[strcspn(novo->tipo, "\n")] = 0;
                printf("Estilo musical: ");
                fgets(novo->estilo_musical, 50, stdin);
                novo->estilo_musical[strcspn(novo->estilo_musical, "\n")] = 0;
                novo->numero_albuns = 0;
                novo->albuns = NULL;
                novo->esq = novo->dir = NULL;
                cadastrou = cadastrar_artista(&raiz, novo);
                if (cadastrou == 1)
                    printf("Artista cadastrado com sucesso!");
                else
                    printf("Falha em cadastrar o artista!");
                break;
            }
            case 2: {
                printf("Nome do artista: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                Arv_albuns *novo = alocar_arvore_album(NULL);
                printf("Título do album: ");
                fgets(novo->titulo, 50, stdin);
                novo->titulo[strcspn(novo->titulo, "\n")] = 0;
                printf("Ano de lancamento: ");
                scanf("%d", &novo->ano_lancamento);
                getchar();
                novo->qtd_musicas = 0;
                novo->musicas = NULL;
                cadastrou = cadastrar_album(&raiz, novo, nome);
                if (cadastrou == 1)
                    printf("Album cadastrado com sucesso!");
                else
                    printf("Falha em cadastrar o album!");
                break;
            }
            case 3: {
                printf("Nome do artista: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                printf("Título do album: ");
                fgets(titulo, 50, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                Arv_musicas *nova = alocar_arvore_musica(NULL);
                printf("Título da musica: ");
                fgets(nova->titulo, 50, stdin);
                nova->titulo[strcspn(nova->titulo, "\n")] = 0;
                printf("Duracao (min): ");
                scanf("%d", &nova->qtd_minutos);
                getchar();
                cadastrou = cadastrar_musicas(&raiz, nova, nome, titulo);
                if (cadastrou == 1)
                    printf("Musica cadastrada com sucesso!");
                else
                    printf("Falha em cadastrar a musica!");
                break;
            }
            case 4:
                mostrar_todos_artistas_cadastrados(raiz);
                break;
            case 5:
                printf("Tipo do artista: ");
                fgets(tipo, 20, stdin);
                tipo[strcspn(tipo, "\n")] = 0;
                mostrar_todos_artistas_cadastrados_determinado_tipo(raiz, tipo);
                break;
            case 6:
                printf("Estilo musical: ");
                fgets(estilo, 50, stdin);
                estilo[strcspn(estilo, "\n")] = 0;
                mostrar_todos_artistas_cadastrados_determinado_estilo_musical(raiz, estilo);
                break;
            case 7:
                printf("Estilo musical: ");
                fgets(estilo, 50, stdin);
                estilo[strcspn(estilo, "\n")] = 0;
                printf("Tipo do artista: ");
                fgets(tipo, 20, stdin);
                tipo[strcspn(tipo, "\n")] = 0;
                mostrar_todos_artistas_cadastrados_determinado_estilo_musical_e_tipo(raiz, estilo, tipo);
                break;
            case 8:
                printf("Nome do artista: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                mostrar_todos_albuns_determinado_artista(raiz, nome);
                break;
            case 9:
                printf("Nome do artista: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                printf("Ano do album: ");
                scanf("%d", &ano);
                getchar();
                mostrar_todos_albuns_determinado_ano_artista(raiz, nome, ano);
                break;
            case 10:
                printf("Nome do artista: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;
                printf("Título do álbum: ");
                fgets(titulo, 50, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                mostrar_todas_musicas_album_artista(raiz, nome, titulo);
                break;
            case 11:
                printf("Ano do álbum: ");
                scanf("%d", &ano);
                getchar();
                mostrar_todos_albuns_determinado_ano_todos_artistas(raiz, ano);
                break;
            case 12:
                printf("Título da música: ");
                fgets(titulo, 50, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                mostrar_dados_musica(raiz, titulo);
                break;
            
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
