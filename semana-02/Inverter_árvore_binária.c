#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *esquerda;
    struct No *direita;
}No;

No* criarNo(int valor){
    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        printf("ERRO: Alocação de memória falhou!!"/n);
        exit(1);
    }


    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
    
    No* inverterArvore(No* raiz){
        if(raiz ==NULL){
            reutrn NULL;
        }
    No* temp = raiz -> esquerda;
    raiz -> esquerda = raiz -> direita;
    raiz -> direita = temp;

    inverterArvore(raiz->esquerda);
    inverterArvore(raiz->direita);

    return raiz;

    }
void mostrarArvore(No* raiz) {

        if (raiz == NULL) {
            return;
        }

        printf("%d ", raiz->valor);

        mostrarArvore(raiz->esquerda);

        mostrarArvore(raiz->direita);
    }
void liberarArvore(No* raiz) {

    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);

    free(raiz);
}
int main() {
     No* raiz = criarNo(1);

    raiz->esquerda = criarNo(3);
    raiz->direita = criarNo(6);

    raiz->esquerda->esquerda = criarNo(2);
    raiz->esquerda->direita = criarNo(4);

    raiz->direita->direita = criarNo(9);

   printf("Arvore original: ");
    mostrarArvore(raiz);

    printf("\n");

    inverterArvore(raiz);

    printf("Arvore invertida: ");
    mostrarArvore(raiz);

    printf("\n");
   liberarArvore(raiz);

    return 0;
}
}
