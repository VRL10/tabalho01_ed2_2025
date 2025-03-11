#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
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
Arv_artista* buscar_artista(Arv_artista *artista, char *nome) {
    while (artista != NULL) {
        if (strcmp(artista->nome, nome) == 0)
            return artista; // Artista encontrado
        if (strcmp(nome, artista->nome) < 0)
            artista = artista->esq; 
        else
            artista = artista->dir;
    }
    return NULL; // Retorna o artista encontrado ou NULL se não existir
}


int cadastrar_album(Arv_artista *artista, Arv_albuns **albuns, char *titulo, int ano_lancamento, int qtd_musicas, char *nome_artista){
    if(buscar_artista(artista, nome_artista) == NULL){
        printf("O artista não existe!");
        return 0;
    }
    int resultado = 1;
    converter_para_maiusculo(titulo);
    Arv_albuns *atual = *albuns;
    Arv_albuns *ptr = NULL;
    while (atual != NULL){
        ptr = atual;
        if(strcmp(titulo, atual->titulo) == 0){
            printf("\nEsse album já foi cadastrado!");
            resultado = 0; // album já foi cadastrado
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

/* III - Cadastrar Músicas: cadastrar as músicas de um álbum de um artista em uma árvore binária organizada
pelo título, lembre-se uma música só pode ser cadastrada para um álbum que já existe e a música não
pode se repetir para um mesmo álbum.*/
Arv_albuns* buscar_album(Arv_albuns *albuns, char *titulo) {
    while (albuns != NULL) {
        if (strcmp(albuns->titulo, titulo) == 0) {
            return albuns; // Álbum encontrado
        }
        if (strcmp(titulo, albuns->titulo) < 0) {
            albuns = albuns->esq; 
        } else {
            albuns = albuns->dir; 
        }
    }
    return NULL; // Retorna NULL se o álbum não existir
}

int cadastrar_musicas(Arv_albuns *albuns, Arv_musicas **musicas, char *titulo, int qtd_minutos, char *titulo_album){
    if (buscar_album(albuns, titulo_album) == NULL){
        printf("O álbum não existe!\n");
        return 0; // Álbum não encontrado
    }
    int resultado = 1;
    converter_para_maiusculo(titulo); 
    Arv_musicas *atual = *musicas;
    Arv_musicas *ptr = NULL;

    while (atual != NULL) {
        ptr = atual;
        if (strcmp(titulo, atual->titulo) == 0) {
            printf("\nEssa música já foi cadastrada!");
            resultado = 0; // Música já cadastrada
            break;
        }
        if (strcmp(titulo, atual->titulo) < 0) {
            atual = atual->esq; 
        } else {
            atual = atual->dir;
        }
    }

    if (resultado == 1) {
        Arv_musicas *novo = (Arv_musicas*)malloc(sizeof(Arv_musicas));
        if (novo == NULL) {
            printf("Erro de alocação!");
            return -1; // Erro na alocação
        }
        strcpy(novo->titulo, titulo);
        novo->qtd_minutos = qtd_minutos;
        novo->dir = NULL;
        novo->esq = NULL;

        // Insere a nova música na posição correta
        if (ptr == NULL) {
            *musicas = novo; // A árvore estava vazia
        } else if (strcmp(titulo, ptr->titulo) < 0) {
            ptr->esq = novo;
        } else {
            ptr->dir = novo;
        }
    }
    return resultado; // Retorna 1 para sucesso ou 0 para falha
}

/* IV - Mostrar todos os artistas cadastrados. */
void mostrar_todos_artistas_cadastrados(Arv_artista *artista) {
    if (artista != NULL) {
        mostrar_todos_artistas_cadastrados(artista->esq);
        printf("Nome: %s, Tipo: %s, Estilo: %s, Número de Álbuns: %d\n", 
            artista->nome, artista->tipo, artista->estilo_musical, artista->numero_albuns);
        mostrar_todos_artistas_cadastrados(artista->dir);
    }
}

/* V - Mostrar todos os artistas cadastrados de um determinado tipo. */
void mostrar_todos_artistas_cadastrados_determinado_tipo(Arv_artista *artista, char *tipo){
    if (artista != NULL){
        mostrar_todos_artistas_cadastrados_determinado_tipo(artista->esq, tipo);
        if (strcmp(artista->tipo, tipo) == 0)
            printf("Artista: %s, Tipo: %s\n",artista->nome, artista->tipo);
        mostrar_todos_artistas_cadastrados_determinado_tipo(artista->dir, tipo);
    }
}

/* VI - Mostrar todos os artistas cadastrados de um determinado estilo musical */
void mostrar_todos_artistas_cadastrados_determinado_estilo_musical(Arv_artista *artista, char *estilo_musical){
    if (artista != NULL){
        mostrar_todos_artistas_cadastrados_determinado_estilo_musical(artista->esq, estilo_musical);
        if (strcmp(artista->estilo_musical, estilo_musical) == 0)
            printf("Artista: %s, Estilo: %s",artista->nome, artista->estilo_musical);
        mostrar_todos_artistas_cadastrados_determinado_estilo_musical(artista->dir, estilo_musical);
    }
}

// VII - Mostrar todos os artistas cadastrados de um determinado estilo musical e tipo de artista.
void mostrar_todos_artistas_cadastrados_determinado_estilo_musical_e_tipo(Arv_artista *artista, char *estilo_musical, char *tipo){
    if (artista != NULL){
        mostrar_todos_artistas_cadastrados_determinado_estilo_musical_e_tipo(artista->esq, estilo_musical, tipo);
        if (strcmp(artista->tipo, tipo) == 0 && strcmp(artista->estilo_musical, estilo_musical) == 0)
            printf("Artista: %s, Tipo: %s, Estilo: %s", 
               artista->nome, artista->tipo, artista->estilo_musical);
        mostrar_todos_artistas_cadastrados_determinado_estilo_musical_e_tipo(artista->dir, estilo_musical, tipo);
    }
}