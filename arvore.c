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
int cadastrar_artista(Arv_artista **artista, char *nome, char *tipo, char *estilo_musical, int numero_albuns){
    converter_nome(nome); // Converte o nome para maiúsculas
    int resultado = 1;

    // Verifica se já existe um artista com a mesma matrícula
    Arv_artista *atual = *artista;
    while (atual != NULL){
        if(atual->nome == nome){
            printf("\nEsse artista já foi cadastrado!");
            resultado = 0;
            break;
        }
        if(strcmp(nome, atual->nome) < 0)
            artista = &atual->esq;
        else
            artista = &atual->dir;
    }

    // Se o artista não foi encontrado, insere o novo artista
    if(resultado == 1){
        Arv_artista *novo = (Arv_artista*)malloc(sizeof(Arv_artista));
        if(novo == NULL){
            printf("\nErro na alocação");
            resultado = -1;
        }else{
            novo->nome = strdup(nome);
            novo->tipo = strdup(tipo);
            novo->estilo_musical = strdup(estilo_musical);
            novo->numero_albuns = numero_albuns;
            novo->dir = NULL;
            novo->esq = NULL;
            if(*artista == NULL)
                *artista = novo;
            else{
                if(strcmp(novo,artista) < 0)
                    resultado = cadastrar_artista(&(*artista)->esq, nome, tipo, estilo_musical, numero_albuns);
                else
                    resultado = cadastrar_artista(&(*artista)->dir, nome, tipo, estilo_musical, numero_albuns);
            }
        }
    }
    return resultado;
}