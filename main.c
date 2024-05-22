#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char palavras[][50] = {
    "algoritmo", "palindromo",
    "compilador", "interprete", "variavel", "constante",
    "funcao", "procedimento", "biblioteca", "array",
    "ponteiro", "memoria", "processador", "compilacao",
    "debugging", "syntax", "semantica", "algoritmo", 
    "complexidade", "recursao", "iteracao", "modularidade",
    "abstracao", "encapsulamento", "heranca", "polimorfismo",
    "objeto", "classe", "metodo", "interface", "thread",
    "concorrencia", "paralelismo","hello"
};


int palavraRand(int size) {
    static int initialized = 0;

    // Inicializa o gerador de números aleatórios apenas uma vez
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }

    // Retorna um número aleatório entre 0 e size-1
    return rand() % size;
}

int main() {
    int sizePalavras = sizeof(palavras) / sizeof(palavras[0]); //obtém a quantidade de elementos do vetor de palavras
    int nAleatorio = palavraRand(sizePalavras); 
    char palavra[50];
    strcpy(palavra, palavras[nAleatorio]);

    int sizePalavra = strlen(palavra);

    char user[50] = {0};  // Inicializa todos os elementos com '\0'
    char faladas[26] = {0};  // Inicializa todos os elementos com '\0'

    int vidas = 5;
    int jogadas = 0;

    // Inicializa `user` com '-'
    for (int i = 0; i < sizePalavra; i++) {
        user[i] = '-';
    }

    while (vidas > 0) {
        int controle = 0;

        printf("\nLetras já faladas: %s", faladas);
        printf("\nAdivinhada:       %s", user);

        char aux;
        printf("\nQual letra: ");
        scanf("%c", &aux);
        getchar();  // Consome o \n do buffer de entrada

        aux = tolower(aux);  // Transforma em minúscula

        // Verifica se o user já falou a letra
        for (int i = 0; i < 26; i++) {
            if (aux == faladas[i]) {
                printf("\nJá falou essa letra");
                controle = 1;
                vidas--;
                break;
            }
        }

        if (controle == 0) {
            int verificaLetraErrada = 0;

            // Atualiza letras faladas
            for (int i = 0; i < 26; i++) {
                if (faladas[i] == '\0') {
                    faladas[i] = aux;
                    break;
                }
            }

            // Verifica se a letra está na palavra
            for (int i = 0; i < sizePalavra; i++) {
                if (palavra[i] == aux) {
                    user[i] = aux;
                    verificaLetraErrada = 1;
                }
            }

            if (verificaLetraErrada == 0) {
                printf("\nLetra errada!");
                vidas--;
            }
        }

        jogadas++;

        // Verifica se todas as letras foram adivinhadas
        if (strcmp(user, palavra) == 0) {
            printf("\nVocê Ganhou!");
            printf("\nNúmero de jogadas: %d", jogadas);
            printf("\nVidas perdidas: %d", 5 - vidas);
            printf("\nPalavra: %s\n\n", user);
            break;
        }
    }

    if (vidas == 0) {
        printf("\nVocê perdeu!\n\n");
        printf("\nNúmero de jogadas: %d", jogadas);
        printf("\nVidas perdidas: %d", 5);
        printf("\nPalavra certa: %s\n\n", palavra);
    }

    return 0;
}
