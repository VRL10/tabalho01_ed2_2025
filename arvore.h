#ifndef ARVORE_H
#define ARVORE_H

typedef struct arvore_artista{ // organizada pelo nome
    char nome[50],tipo[20],estilo_musical[50];
    int numero_albuns;
    struct arvore_artista *dir,*esq;
    struct arvore_albuns *albuns;
}Arv_artista;

typedef struct arvore_albuns{ // organizada pelo título
    char titulo[50];
    int ano_lancamento,qtd_musicas;
    struct arvore_albuns *dir,*esq;
    struct arvore_musicas *musicas;
}Arv_albuns;

typedef struct arvore_musicas{ // organizada pelo título
    char titulo[50];
    int qtd_minutos;
    struct arvore_musicas *dir,*esq;
}Arv_musicas;


int cadastrar_artista(Arv_artista **artista, char *nome, char *tipo, char *estilo_musical, int numero_albuns);

#endif