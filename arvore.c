#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arvore.h"

void converter_nome(char *nome) {
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arv_artista {
    char *nome;
    char *tipo;
    char *estilo_musical;
    int numero_albuns;
    struct Arv_artista *esq, *dir;
} Arv_artista;

void converter_nome(char *nome); // Defina essa função se necessário

int cadastrar_artista(Arv_artista **artista, char *nome, char *tipo, char *estilo_musical, int numero_albuns) {
    converter_nome(nome); // Converte o nome para maiúsculas
    int resultado = 1;

    Arv_artista *atual = *artista;
    Arv_artista *pai = NULL;

    while (atual != NULL) {
        pai = atual;
        if (strcmp(atual->nome, nome) == 0) {
            printf("\nEsse artista já foi cadastrado!");
            return 0; // Artista já cadastrado
        }
        if (strcmp(nome, atual->nome) < 0) {
            atual = atual->esq; 
        } else {
            atual = atual->dir; 
        }
    }

    // Se o artista não foi encontrado, cria um novo nó
    Arv_artista *novo = (Arv_artista*)malloc(sizeof(Arv_artista));
    if (novo == NULL) {
        printf("\nErro na alocação");
        return -1; // Erro na alocação
    }

    // Aloca memória para strings e copia os valores
    novo->nome = strdup(nome);
    novo->tipo = strdup(tipo);
    novo->estilo_musical = strdup(estilo_musical);
    novo->numero_albuns = numero_albuns;
    novo->dir = NULL;
    novo->esq = NULL;

    // Insere o novo artista na posição correta
    if (pai == NULL) {
        *artista = novo;
    } else if (strcmp(nome, pai->nome) < 0) {
        pai->esq = novo; 
    } else {
        pai->dir = novo; 
    }

    return 1; // Sucesso
}
