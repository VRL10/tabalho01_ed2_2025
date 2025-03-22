#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include "arvore.h"

Arv_artista* alocar_arvore_artista(Arv_artista *novo){
    novo = (Arv_artista*)malloc(sizeof(Arv_artista));
    if (novo == NULL) {
        printf("\nErro na alocação");
    }
    return novo;
}

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
int artista_existe(Arv_artista* artista, char *nome){
    int existe = 0;
    while (artista != NULL) {
        if (strcmp(artista->nome, nome) == 0)
            existe = 1; // Artista encontrado
        else if (strcmp(nome, artista->nome) < 0)
            artista = artista->esq; 
        else
            artista = artista->dir;
    }
    return existe; // Retorna o artista encontrado ou NULL se não existir
}
int inserir_artista(Arv_artista **artista, Arv_artista *No){
    int resultado = 0;
    if(strcmp((*artista)->nome, No->nome) == 0){
        *artista = No;
        resultado = 1;
    }
    else if(strcmp((*artista)->nome, No->nome) > 0)
        resultado = inserir_artista(&(*artista)->esq, No);
    else
        resultado = inserir_artista(&(*artista)->dir, No);

    return resultado;
}

int cadastrar_artista(Arv_artista **artista, Arv_artista *No) {
    int resultado = 0;
    if(*artista != NULL){
        converter_para_maiusculo(No->nome); // Converte o nome para maiúsculas
        
        int existe = artista_existe(artista, No->nome);
        if(existe != 1)
            resultado = inserir_artista(&(*artista), No);
        else
            printf("Artista já existe!");
    }else{
        *artista = No;
        resultado = 1;
    }
    return resultado;
}

/* II - Cadastrar Álbuns: cadastrar os dados de Álbuns de um determinado artista organizados em uma árvore
binária pelo título do álbum a qualquer momento, lembre-se um álbum só pode ser cadastrado para um
artista já castrado e o álbum não pode se repetir para um mesmo artista.*/
Arv_artista* buscar_artista(Arv_artista *artista, char *nome) {
    while (artista != NULL) {
        if (strcmp(artista->nome, nome) == 0)
            break; // Artista encontrado
        if (strcmp(nome, artista->nome) < 0)
            artista = artista->esq; 
        else
            artista = artista->dir;
    }
    return artista; // Retorna o artista encontrado ou NULL se não existir
}

int album_existe(Arv_albuns *albuns, char *titulo){
    int existe = 0;
    while (albuns != NULL) {
        if (strcmp(albuns->titulo, titulo) == 0) 
            existe = 1; // Álbum encontrado
        else if (strcmp(titulo, albuns->titulo) < 0) {
            albuns = albuns->esq; 
        } else {
            albuns = albuns->dir; 
        }
    }
    return existe;
}

int inserir_album(Arv_albuns **albuns, Arv_albuns *No){
    int resultado = 0;
    if(strcmp((*albuns)->titulo, No->titulo) == 0){
        *albuns = No;
        resultado = 1;
    }else if(strcmp((*albuns)->titulo, No->titulo) > 0)
        inserir_album(&(*albuns)->esq, No);
    else
        inserir_album(&(*albuns)->dir, No);

    return resultado;
}

int cadastrar_album(Arv_artista **artista, Arv_albuns *No, char *nome_artista) {
    int resultado = 0;
    if(artista != NULL){
        if(buscar_artista(artista, nome_artista) != NULL) {
            converter_para_maiusculo(No->titulo);
            int existe = album_existe((*artista)->albuns, No->titulo);
            if(existe != 1)
                resultado = inserir_album(&(*artista)->albuns,No);
            else
                printf("Este álbum já existe!");
        }else
            printf("Artista não existe!");
    }else
        printf("Não existe artistas cadastrados");

    return resultado;
}


/* III - Cadastrar Músicas: cadastrar as músicas de um álbum de um artista em uma árvore binária organizada
pelo título, lembre-se uma música só pode ser cadastrada para um álbum que já existe e a música não
pode se repetir para um mesmo álbum.*/
Arv_albuns* buscar_album(Arv_albuns *albuns, char *titulo) {
    while (albuns != NULL) {
        if (strcmp(albuns->titulo, titulo) == 0) 
            break; // Álbum encontrado
        else if (strcmp(titulo, albuns->titulo) < 0) 
            albuns = albuns->esq; 
        else 
            albuns = albuns->dir; 
        
    }
    return albuns; // Retorna NULL se o álbum não existir
}

int cadastrar_musicas(Arv_albuns *albuns, Arv_musicas **musicas, Arv_musicas *No){
    int resultado = 1;
    Arv_albuns *album_encontrado = buscar_album(albuns, No->titulo);
    if (album_encontrado != NULL){
        converter_para_maiusculo(No->titulo);


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
            printf("\nArtista: %s, Tipo: %s, Estilo: %s",artista->nome, artista->tipo, artista->estilo_musical);
        mostrar_todos_artistas_cadastrados_determinado_estilo_musical_e_tipo(artista->dir, estilo_musical, tipo);
    }
}

// VIII - Mostrar todos os álbuns de um determinado artista
void mostrar_todos_albuns(Arv_albuns *album){
    if(album != NULL){
        mostrar_todos_albuns(album->esq);
        printf("\n%s",album->titulo);
        mostrar_todos_albuns(album->dir);
    }
}

void mostrar_todos_albuns_determinado_artista(Arv_artista *artista, char *nome_artista){
    Arv_artista *artista_encontrado = buscar_artista(artista, nome_artista);
    if (artista_encontrado != NULL){
        printf("\n------- Todos os álbuns do artista %s --------", artista_encontrado->nome);
        mostrar_todos_albuns(artista_encontrado->albuns);
    }else
        printf("Artista não encontrado.\n");
}

// IX - Mostrar todos os álbuns de um determinado ano de um artista.
void mostrar_albuns_ano(Arv_albuns *album, int ano_album){
    if(album != NULL){
        mostrar_albuns_ano(album->esq, ano_album);
        if(album->ano_lancamento == ano_album)
            printf("\nTítulo: %s\nAno de lançamento: %d",album->titulo, album->ano_lancamento);
        mostrar_albuns_ano(album->dir, ano_album);
    }
}

void mostrar_todos_albuns_determinado_ano_artista(Arv_artista *artistas, char *nome_artista, int ano_album){
    Arv_artista *artista_encontrado = buscar_artista(artistas, nome_artista);
    if (artista_encontrado != NULL){
        printf("\n------- Todos os álbuns do ano %d --------", ano_album);
        mostrar_albuns_ano(artista_encontrado->albuns, ano_album);
    }else
        printf("Artista não encontrado.\n");
}