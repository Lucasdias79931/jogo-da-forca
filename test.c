#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char palavra[50];
    int peso;
} PalavraPeso;

PalavraPeso palavras_peso[] = {
    {"algoritmo", 3}, {"palindromo", 1},
    {"compilador", 1}, {"interprete", 1}, {"variavel", 1}, {"constante", 1},
    {"funcao", 1}, {"procedimento", 100000}, {"biblioteca", 1}, {"array", 1},
    {"ponteiro", 1}, {"memoria", 1}, {"processador", 1}, {"compilacao", 1},
    {"debugging", 1}, {"syntax", 1}, {"semantica", 1}, {"algoritmo", 365}, 
    {"complexidade", 1}, {"recursao", 1}, {"iteracao", 1}, {"modularidade", 1},
    {"abstracao", 1}, {"encapsulamento", 1}, {"heranca", 1}, {"polimorfismo", 1},
    {"objeto", 1}, {"classe", 1}, {"metodo", 1}, {"interface", 1}, {"thread", 1},
    {"concorrencia", 1}, {"paralelismo", 1}, {"hello", 1}
};

int palavraRand(int size) {
    static int initialized = 0;

    // Inicializa o gerador de números aleatórios apenas uma vez
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }

    int soma_pesos = 0;
    for (int i = 0; i < size; i++) {
        soma_pesos += palavras_peso[i].peso;
    }

    int aleatorio = rand() % soma_pesos;
    int acumulado = 0;
    for (int i = 0; i < size; i++) {
        acumulado += palavras_peso[i].peso;
        if (aleatorio < acumulado) {
            return i;
        }
    }

    // Caso algo dê errado, retorna um valor aleatório padrão
    return rand() % size;
}

int main() {
    int sizePalavras = sizeof(palavras_peso) / sizeof(palavras_peso[0]);
    int nAleatorio = palavraRand(sizePalavras); 
    char palavra[50];
    strcpy(palavra, palavras_peso[nAleatorio].palavra);

    printf("Palavra escolhida: %s\n", palavra);

    return 0;
}
