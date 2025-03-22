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
void converter_para_maiusculo(char *nome);
int artista_existe(Arv_artista* artista, char *nome);
int inserir_artista(Arv_artista **artista, Arv_artista *No);
Arv_artista* buscar_artista(Arv_artista *artista, char *nome);
int cadastrar_artista(Arv_artista **artista, Arv_artista *No);
void mostrar_todos_artistas_cadastrados(Arv_artista *artista);
void mostrar_todos_artistas_cadastrados_determinado_tipo(Arv_artista *artista, char *tipo);
void mostrar_todos_artistas_cadastrados_determinado_estilo_musical(Arv_artista *artista, char *estilo_musical);
void mostrar_todos_artistas_cadastrados_determinado_estilo_musical_e_tipo(Arv_artista *artista, char *estilo_musical, char *tipo);

// Funções Relacionadas a Álbum
int album_existe(Arv_albuns *albuns, char *titulo);
int inserir_album(Arv_albuns **albuns, Arv_albuns *No);
int cadastrar_album(Arv_artista **artista, Arv_albuns *No, char *nome_artista);
Arv_albuns* buscar_album(Arv_albuns *albuns, char *titulo);
void mostrar_todos_albuns(Arv_albuns *album);
void mostrar_todos_albuns_determinado_artista(Arv_artista *artista, char *nome_artista);
void mostrar_albuns_ano(Arv_albuns *album, int ano_album);
void mostrar_todos_albuns_determinado_ano_artista(Arv_artista *artistas, char *nome_artista, int ano_album);

// Funções Relacionadas a Músicas
int inserir_musica(Arv_musicas **musicas, Arv_musicas *No);
int cadastrar_musicas(Arv_artista **artista, Arv_musicas *No, char *nome_artista, char *nome_album);

// Funções auxiliares
Arv_artista* alocar_arvore_artista(Arv_artista *novo);
Arv_albuns* alocar_arvore_album(Arv_albuns *novo);
Arv_musicas* alocar_arvore_musica(Arv_musicas *novo);

#endif