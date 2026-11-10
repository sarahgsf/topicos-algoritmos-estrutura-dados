def alien_order(words):
    grafo = {c: set() for w  in words for c in w}

    grau_entrada = {c: 0 for c in grafo}

    for w1,  w2 in zip(words, words[1:]):
        for c1, c2 in zip(w1, w2):

            if c1 != c2:

                if c2 not in grafo[c1]:
                    grafo[c1].add(c2)
                    grau_entrada[c2] += 1

                break
        else:
            if len(w2) < len(w1):
                return ""

    fila = [c for c in grafo if grau_entrada[c] == 0]

    ordem = []

    while fila:
        c = fila.pop()
        ordem.append(c)

        for vizinho in grafo[c]:
            grau_entrada[vizinho] -= 1

            if grau_entrada[vizinho] == 0:
                fila.append(vizinho)

    if len(ordem) < len(grafo):
        return ""

    return "".join(ordem)

palavras = ["wrt", "wrf", "er", "ett", "rftt"]
print(alien_order(palavras))