#ifndef COMPACT_H
#define COMPACT_H
#include "structs.h"

/* 
      "Toda a documentação vai estar no padrão listado abaixo pela equipe de desenvolvimento."
    | 1° - Tipo e nome da função
    | 2° - Argumentos recebidos pela função
    | 3° - Utilidade da função
    | 4° - Retorno da função
*/

/*--------------------------------------------------------------------------------------------------------*/
FILE* compact(FILE *file, char *filename);
/*
    | 1° - FILE* compact
    | 2° - A função compact recebe um ponteiro para um arquivo e a string com o nome do arquivo original
    | 3° - A função compact é responsável por compactar todo o arquivo e retornar um novo arquivo já compactado
    | 4° - Retorna o arquivo já compactado
*/

/*--------------------------------------------------------------------------------------------------------*/
int *frenquencies(FILE *file) 
{
    int *new_freq = (int *) calloc(256, sizeof(int)); // criação do vetor que vai guardar os caracteres
    unsigned char c;
    while(!feof(file))
    {
        c = fegtc(file);
        new_freq[(int)c]++;
    }
    return new_freq;
}
/*
    | 1° - int* frequencies
    | 2° - A função frequencias recebe um ponteiro para o arquivo original que o usuário quer compactar
    | 3° - A função frequencias é responsável por criar um vetor que vai guardar as frequencias dos
    | caracteres apresentados no arquivo
    | 4° - Retorna um vetor do tipo inteiro (frequencias)
*/

/*--------------------------------------------------------------------------------------------------------*/
void huffman_tree(node *root, int c, hash_table *hash, char *way) 
{ 
    if(root->left == NULL && root->right == NULL) 
    {
        add_hash(hash, root->item, way, c);
    }
    else
    {
        way[c] = '0';
        huffman_tree(root->left, c+1, hash, way);
        way[c] = '1';
        huffman_tree(root->right, c+1, hash, way);
    }
}
/*
    | 1° - void huffman_tree
    | 2° - A função recebe o nó raiz, um contador(c), uma Hash table e uma string representando
    | o caminho percorrido na árvore
    | 3° - A função arvore_de_huffman adiciona os valores do bytes compactados na hash table, juntamente
    | de seus caminhos na árvore
    | 4° - Sem retorno 
*/

/*--------------------------------------------------------------------------------------------------------*/
int size_trash(hash_table *hash, int *frequencias) 
{
    int i = 0;
    int soma = 0;

    while(i < 256)
    {
        if(frenquencias[i] != 0)
        {
            soma += (hash->table[i]->n) * frequencias[i];
        }
    }
    //Verificar o calculo do retorno do tamanho do lixo
}
/*
    | 1° - int size_trash
    | 2° - A função recebe a Hash que foi criada e o vetor de frenquencia dos caracteres
    | 3° - A função tamanho_do_lixo é responsável por calcular o tamanho do lixo gerado pelo arquivo compactado
    | 4° - Retorna o tamanho do lixo  
*/ 