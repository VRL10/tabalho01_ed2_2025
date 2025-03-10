#ifndef ARVORE_H
#define ARVORE_H

/*Faça um programa em C de uma Biblioteca de Música. As informações são organizadas por
Artista. E para cada artista deve ser ter o nome do artista, tipo (cantor(a), Dupla, Banda, Grupo, …), o estilo
musical, o número de álbuns, e os Álbuns (endereço da árvore binária para Álbuns). Cada álbum deve ter,
o título, o ano de lançamento, a quantidade de músicas e as Músicas (endereço da árvore binária para
Músicas). Para cada música deve se ter o título, e a quantidade de minutos. Quando o usuário executar o
programa o mesmo deve permitir:*/

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

// Funções Relacionadas a Artista
int cadastrar_artista(Arv_artista **artista, char *nome, char *tipo, char *estilo_musical, int numero_albuns);
void converter_nome(char *nome);


// Funções Relacionadas a Álbum


// Funções Relacionadas a Músicas

#endif