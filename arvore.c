#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"

void converter_nome(char *nome) {
    int i = 0;
    while (nome[i] != '\0'){
        nome[i] = toupper(nome[i]);
        i++;
    }
}

int cadastrar_artista(Arv_artista **artista, char *nome, char *tipo, char *estilo_musical, int numero_albuns){
    converter_nome(nome); // Converte o nome para maiúsculas
    int resultado = 1;

    // Verifica se já existe um aluno com a mesma matrícula
    


    // Se o aluno não foi encontrado, insere o novo aluno
}