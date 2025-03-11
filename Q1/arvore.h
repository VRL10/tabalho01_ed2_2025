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
Arv_artista* buscar_artista(Arv_artista *artista, char *nome);
int cadastrar_artista(Arv_artista **artista, char *nome, char *tipo, char *estilo_musical, int numero_albuns);
void mostrar_todos_artistas_cadastrados(Arv_artista *artista);
void mostrar_todos_artistas_cadastrados_determinado_tipo(Arv_artista *artista, char *tipo);
void mostrar_todos_artistas_cadastrados_determinado_estilo_musical(Arv_artista *artista, char *estilo_musical);
void mostrar_todos_artistas_cadastrados_determinado_estilo_musical_e_tipo(Arv_artista *artista, char *estilo_musical, char *tipo);

// Funções Relacionadas a Álbum
int cadastrar_album(Arv_artista *artista, Arv_albuns **albuns, char *titulo, int ano_lancamento, int qtd_musicas, char *nome_artista);
Arv_albuns* buscar_album(Arv_albuns *albuns, char *titulo);
void mostrar_todos_albuns(Arv_albuns *album);
void mostrar_todos_albuns_determinado_artista(Arv_artista *artista, char *nome_artista);

// Funções Relacionadas a Músicas
Arv_musicas* buscar_musica(Arv_musicas *musicas, char *titulo);
int cadastrar_musicas(Arv_albuns *albuns, Arv_musicas **musicas, char *titulo, int qtd_minutos, char *titulo_album);
#endif