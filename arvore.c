#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arvore.h"

void converter_para_maiusculo(char *nome) {
    int i = 0;
    while (nome[i] != '\0'){
        nome[i] = toupper(nome[i]);
        i++;
    }
}

/* I - Cadastrar Artista: cadastrar os dados dos artistas organizados em uma árvore binária pelo nome do
artista a qualquer momento, o usuário pode cadastrar um artista a qualquer momento, não permita
cadastro repetido
*/

int cadastrar_artista(Arv_artista **artista, char *nome, char *tipo, char *estilo_musical, int numero_albuns){
    converter_para_maiusculo(nome); // Converte o nome para maiúsculas
    int resultado = 1;

    Arv_artista *atual = *artista;
    Arv_artista *pai = NULL;

    while (atual != NULL) {
        pai = atual;
        if (strcmp(atual->nome, nome) == 0) {
            printf("\nEsse artista já foi cadastrado!");
            resultado = 0; // Artista já cadastrado
            break;
        }
        if (strcmp(nome, atual->nome) < 0)
            atual = atual->esq; 
        else
            atual = atual->dir; 
    }
    // Se o artista não foi encontrado, cria um novo nó
    if(resultado == 1){
        Arv_artista *novo = (Arv_artista*)malloc(sizeof(Arv_artista));
        if (novo == NULL) {
            printf("\nErro na alocação");
            return -1; // Erro na alocação
        }

        // Aloca memória para strings e copia os valores
        strcpy(novo->nome, nome);
        strcpy(novo->tipo, tipo);
        strcpy(novo->estilo_musical, estilo_musical);
        novo->numero_albuns = numero_albuns;
        novo->dir = NULL;
        novo->esq = NULL;

        // Insere o novo artista na posição correta
        if (pai == NULL)
            *artista = novo;
        else if (strcmp(nome, pai->nome) < 0)
            pai->esq = novo; 
        else
            pai->dir = novo; 
    }
    return resultado;
}

/* II - Cadastrar Álbuns: cadastrar os dados de Álbuns de um determinado artista organizados em uma árvore
binária pelo título do álbum a qualquer momento, lembre-se um álbum só pode ser cadastrado para um
artista já castrado e o álbum não pode se repetir para um mesmo artista.*/
int cadastrar_album(Arv_albuns **albuns, char *titulo, int ano_lancamento, int qtd_musicas){
    int resultado = 1;
    converter_para_maiuscula(titulo);
    Arv_albuns *atual = *albuns;
    Arv_albuns *ptr = NULL;
    while (atual != NULL){
        ptr = atual;
        if(strcmp(titulo, atual->titulo) == 0){
            printf("\nEsse album já foi cadastrado!");
            resultado = 0;
            break;
        }
        if(strcmp(titulo, atual->titulo) < 0)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    if(resultado == 1){
        Arv_albuns *novo = (Arv_albuns*)malloc(sizeof(Arv_albuns));
        if(novo == NULL){
            printf("Erro de alocação!");
            return -1;
        }
        strcpy(novo->titulo, titulo);
        novo->ano_lancamento = ano_lancamento;
        novo->qtd_musicas = qtd_musicas;
        novo->dir = NULL;
        novo->esq = NULL;
        novo->musicas = NULL;
        if(ptr == NULL)
            *albuns = novo;
        else if(strcmp(titulo, ptr->titulo) < 0)
            ptr->esq = novo;
        else
            ptr->dir = novo;
    }
    return resultado;
}