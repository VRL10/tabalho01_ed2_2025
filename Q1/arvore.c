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

Arv_albuns* alocar_arvore_album(Arv_albuns *novo){
    novo = (Arv_albuns*)malloc(sizeof(Arv_albuns));
    if (novo == NULL) {
        printf("\nErro na alocação");
    }
    return novo;
}

Arv_musicas* alocar_arvore_musica(Arv_musicas *novo){
    novo = (Arv_musicas*)malloc(sizeof(Arv_musicas));
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
    if(*artista == NULL){
        *artista = No;
        resultado = 1;
    }
    else{
        if(strcmp((*artista)->nome, No->nome) > 0)
            resultado = inserir_artista(&(*artista)->esq, No);
        else if(strcmp((*artista)->nome, No->nome) < 0)
            resultado = inserir_artista(&(*artista)->dir, No);
        else
            printf("Esse artista já foi cadastrado!");
    }

    return resultado;
}

int cadastrar_artista(Arv_artista **artista, Arv_artista *No) {
    int resultado = 0;
    if(*artista != NULL){
        converter_para_maiusculo(No->nome); // Converte o nome para maiúsculas
        resultado = inserir_artista(&(*artista), No);
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
    if(*albuns == NULL){
        *albuns = No;
        resultado = 1;
    }else{
        if(strcmp((*albuns)->titulo, No->titulo) > 0)
            inserir_album(&(*albuns)->esq, No);
        else if(strcmp((*albuns)->titulo, No->titulo) < 0)
            inserir_album(&(*albuns)->dir, No);
        else
            printf("Este álbum já existe!");
    }
    return resultado;
}

int cadastrar_album(Arv_artista **artista, Arv_albuns *No, char *nome_artista) {
    int resultado = 0;
    if(artista != NULL){
        Arv_artista *artista_encontrado = buscar_artista(*artista, nome_artista);
        if(artista_encontrado != NULL) {
            converter_para_maiusculo(No->titulo);
            int existe = album_existe((*artista)->albuns, No->titulo);
            if(existe != 1)
                resultado = inserir_album(&artista_encontrado->albuns,No);
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

int inserir_musica(Arv_musicas **musicas, Arv_musicas *No){
    int resultado = 0;

    if (*musicas == NULL) {
        *musicas = No;
        resultado = 1;
    }else {
        if (strcmp(No->titulo, (*musicas)->titulo) < 0)
            resultado = inserir_musica(&(*musicas)->esq, No);
        else if (strcmp(No->titulo, (*musicas)->titulo) > 0)
            resultado = inserir_musica(&(*musicas)->dir, No);
        else
            printf("Essa música já foi cadastrada!\n");
    }

    return resultado;
}

int cadastrar_musicas(Arv_artista **artista, Arv_musicas *No, char *nome_artista, char *titulo_album){
    int resultado = 0;
    if(*artista != NULL){
        Arv_artista *artista_encontrado = buscar_artista(*artista, nome_artista);

        if (artista_encontrado != NULL) {
            converter_para_maiusculo(No->titulo);
            Arv_albuns *album_encontrado = buscar_album(artista_encontrado->albuns, titulo_album);
            if(album_encontrado != NULL)
                resultado = inserir_musica(&artista_encontrado->albuns->musicas, No);
            else
                printf("\nO Album não existe!");
        }else
            printf("Artista não existe!");
    }

    return resultado;
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

// X - Mostrar todas as músicas de um determinado álbum de um determinado artista.
void mostrar_todas_musicas(Arv_musicas *musica) {
    if (musica != NULL) {
        mostrar_todas_musicas(musica->esq);
        printf("Título: %s, Duração: %d min\n", musica->titulo, musica->qtd_minutos);
        mostrar_todas_musicas(musica->dir);
    }
}

void mostrar_todas_musicas_album_artista(Arv_artista *artista, char *nome_artista, char *titulo_album) {
    Arv_artista *artista_encontrado = buscar_artista(artista, nome_artista);
    if (artista_encontrado != NULL) {
        Arv_albuns *album_encontrado = buscar_album(artista_encontrado->albuns, titulo_album);
        if (album_encontrado != NULL) {
            printf("\n--- Músicas do álbum '%s' do artista '%s' ---\n", titulo_album, nome_artista);
            mostrar_todas_musicas(album_encontrado->musicas);
        } else
            printf("Álbum não encontrado.\n");
    }else
        printf("Artista não encontrado.\n");
}

// XI - Mostrar todos os álbuns de um determinado ano de todos os artistas cadastrados.

void mostrar_todos_albuns_determinado_ano_todos_artistas(Arv_artista *artistas, int ano_album) {
    if (artistas != NULL) {
        mostrar_todos_albuns_determinado_ano_todos_artistas(artistas->esq, ano_album);
        
        printf("\n--- Álbuns de %d do artista: %s ---\n", ano_album, artistas->nome);
        mostrar_albuns_ano(artistas->albuns, ano_album);

        mostrar_todos_albuns_determinado_ano_todos_artistas(artistas->dir, ano_album);
    }
}

//XII - Mostrar os dados de uma determinada Música (usuário entrar com o título da música): nome artista, título do álbum, ano de lançamento.
Arv_musicas* buscar_musica(Arv_musicas *musicas, char *titulo) {
    Arv_musicas *resultado = alocar_arvore_musica(NULL);
    while (musicas != NULL) {
        if (strcmp(musicas->titulo, titulo) == 0)
            resultado = musicas; // Música encontrada
        else if (strcmp(titulo, musicas->titulo) < 0)
            musicas = musicas->esq;
        else
            musicas = musicas->dir;
    }
    return resultado; // Música não encontrada
}

void mostrar_dados_musica(Arv_artista *artistas, char *titulo_musica) {
    if (artistas != NULL) {
        // Percorre a árvore de artistas
        mostrar_dados_musica(artistas->esq, titulo_musica);

        // Percorre a árvore de álbuns do artista atual
        Arv_albuns *album_atual = artistas->albuns;
        while (album_atual != NULL) {
            // Busca a música no álbum atual
            Arv_musicas *musica_encontrada = buscar_musica(album_atual->musicas, titulo_musica);
            if (musica_encontrada != NULL) {
                printf("\n=== Dados da Música ===\n");
                printf("Título: %s\n", musica_encontrada->titulo);
                printf("Artista: %s\n", artistas->nome);
                printf("Álbum: %s\n", album_atual->titulo);
                printf("Ano de Lançamento: %d\n", album_atual->ano_lancamento);
                break; // Música encontrada, pode sair da função
            }
            // Percorre os álbuns em ordem na árvore
            if (strcmp(titulo_musica, album_atual->titulo) < 0)
                album_atual = album_atual->esq;
            else
                album_atual = album_atual->dir;
        }

        mostrar_dados_musica(artistas->dir, titulo_musica);
    }
}

