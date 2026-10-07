#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NULO INT_MIN

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *criar_no(int val) {
    struct TreeNode *no = malloc(sizeof(struct TreeNode));

    if (no == NULL) {
        fprintf(stderr, "Erro: falha de alocacao\n");
        exit(1);
    }

    no->val = val;
    no->left = NULL;
    no->right = NULL;

    return no;
}

struct TreeNode *construir_arvore(const int *v, int n) {
    if (n == 0 || v[0] == NULO)
        return NULL;

    struct TreeNode **fila = malloc(n * sizeof(struct TreeNode *));

    if (fila == NULL) {
        fprintf(stderr, "Erro: falha de alocacao\n");
        exit(1);
    }

    int ini = 0;
    int fim = 0;
    int i = 1;

    struct TreeNode *raiz = criar_no(v[0]);
    fila[fim++] = raiz;

    while (ini < fim && i < n) {
        struct TreeNode *pai = fila[ini++];

        if (i < n && v[i] != NULO) {
            pai->left = criar_no(v[i]);
            fila[fim++] = pai->left;
        }

        i++;

        if (i < n && v[i] != NULO) {
            pai->right = criar_no(v[i]);
            fila[fim++] = pai->right;
        }

        i++;
    }

    free(fila);

    return raiz;
}

void liberar(struct TreeNode *raiz) {
    while (raiz != NULL) {
        if (raiz->left != NULL) {
            struct TreeNode *esq = raiz->left;

            raiz->left = esq->right;
            esq->right = raiz;
            raiz = esq;
        } else {
            struct TreeNode *prox = raiz->right;

            free(raiz);
            raiz = prox;
        }
    }
}

void flatten(struct TreeNode *root) {
    struct TreeNode *atual = root;

    while (atual != NULL) {
        if (atual->left != NULL) {
            struct TreeNode *pred = atual->left;

            while (pred->right != NULL)
                pred = pred->right;

            pred->right = atual->right;
            atual->right = atual->left;
            atual->left = NULL;
        }

        atual = atual->right;
    }
}

void imprimir_preordem(const struct TreeNode *no) {
    if (no == NULL)
        return;

    printf("%d ", no->val);

    imprimir_preordem(no->left);
    imprimir_preordem(no->right);
}

void imprimir_lista(const struct TreeNode *no) {
    printf("[");

    for (const struct TreeNode *p = no; p != NULL; p = p->right) {
        if (p != no)
            printf(",null,");

        printf("%d", p->val);
    }

    printf("]");
}

int lista_valida(const struct TreeNode *no) {
    for (const struct TreeNode *p = no; p != NULL; p = p->right) {
        if (p->left != NULL)
            return 0;
    }

    return 1;
}

void testar(const char *nome, const int *v, int n) {
    struct TreeNode *raiz = construir_arvore(v, n);

    printf("%s\n", nome);

    printf("  Pre-ordem antes : ");
    imprimir_preordem(raiz);
    printf("\n");

    flatten(raiz);

    printf("  Lista achatada  : ");
    imprimir_lista(raiz);
    printf("\n");

    printf("  left sempre NULL: %s\n\n",
           lista_valida(raiz) ? "sim" : "NAO");

    liberar(raiz);
}

int main(void) {

    int ex1[] = {1, 2, 5, 3, 4, NULO, 6};
    testar("Exemplo 1: [1,2,5,3,4,null,6]", ex1, 7);

    testar("Exemplo 2: []", NULL, 0);

    int ex3[] = {0};
    testar("Exemplo 3: [0]", ex3, 1);

    int ex4[] = {1, 2, NULO, 3};
    testar("Extra: [1,2,null,3] (so esquerda)", ex4, 4);

    return 0;
}
