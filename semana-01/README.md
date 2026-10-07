<div align="center">

# 🌳 Flatten Binary Tree

### Transformando uma árvore binária em uma lista encadeada

![Language](https://img.shields.io/badge/Linguagem-C-blue)
![Estrutura](https://img.shields.io/badge/Estrutura-%C3%81rvore%20Bin%C3%A1ria-8A2BE2)
![Complexidade](https://img.shields.io/badge/Tempo-O(N)-green)
![Espaço](https://img.shields.io/badge/Espa%C3%A7o-O(1)-orange)

</div>

---

## 📌 Sobre o exercício

Neste exercício foi implementado o **achatamento (*flatten*) de uma árvore binária**, transformando sua estrutura em uma lista encadeada.

A lista utiliza os próprios nós da árvore: o ponteiro `right` passa a representar o próximo elemento, enquanto o ponteiro `left` deve permanecer `NULL`.

A ordem dos elementos deve ser mantida de acordo com a **travessia em pré-ordem (*preorder*)**.

---

## 🎯 Conceitos trabalhados

- **Árvore binária** — estrutura utilizada como base para o exercício.
- **Lista encadeada** — estrutura obtida após o achatamento da árvore.
- **Ponteiros** — utilizados para reorganizar as conexões entre os nós.
- **`struct`** — utilizada para representar os nós da árvore.
- **Pré-ordem (*preorder*)** — ordem que deve ser preservada após o achatamento.
- **Reorganização de ponteiros** — utilizada para transformar a árvore sem criar uma nova estrutura.
- **Manipulação *in-place*** — a transformação é realizada utilizando os próprios nós da árvore.
- **Complexidade** — análise do tempo e do espaço utilizados pelo algoritmo.

---

## 💡 Ideia da solução

A solução reorganiza os próprios ponteiros da árvore, sem utilizar uma estrutura auxiliar.

Quando um nó possui uma subárvore à esquerda, ela é colocada à frente da antiga subárvore direita. O último nó da subárvore esquerda é então conectado à antiga subárvore direita.

Ao final, `left` permanece `NULL` e `right` é utilizado para percorrer todos os nós na ordem de pré-ordem.

---

## 🔄 Exemplo

### Árvore original

```text
        1
       / \
      2   5
     / \   \
    3   4   6
```
Após o flatten
```
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
