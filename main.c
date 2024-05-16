#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char palavra[] = "algoritmo";
    char user[] = "---------";
    char faladas[] = "---------";
    int vidas = 5;
    int i = 0;
    int jogadas = 0;

    
    

    while (vidas > 0) {
        int controle = 0;

        printf("\nLetras já faladas:%s",faladas);
        printf("\nAdivinhada:       %s",user);

        char aux;
        printf("\nQual letra: ");
        scanf("%c",&aux);
        getchar(); // consome o \n do buffer de entrada 

        aux = tolower(aux); // transforma em minuscula
     
        //verifica se o user já falou a letra
        for (i = 0; i < 9; i++) {
            if (aux == faladas[i]) {
                printf("\nJá falou essa letra");
                controle = 1;
                vidas--;
                break;
            }
        }

        

        if (controle == 0) {
            int verificaLetraErrada = 0;

            //atualiza letras faladas
            for (i = 0; i < 9; i++) {
                if(faladas[i] == '-'){
                    faladas[i] = aux;
                    break;
                }
            }

            for (i = 0; i < 9; i++) {
                if (palavra[i] == aux) {
                    user[i] = aux;

                    verificaLetraErrada = 1;
                }
            }

            if (verificaLetraErrada == 0) {
                printf("\nletra errada!");
                vidas--;
            }

            
        }
        
        jogadas++;

        if(jogadas>=8 && strcmp(user,palavra) == 0){
            printf("\nVocê Ganhou!");
            printf("\nNúmero de jogadas:%d",jogadas);
            printf("\nVidas perdidas:%d",5-vidas);
            printf("\npalavra:%s\n\n",user);
            break;
        }
    }

    if (vidas == 0){
        printf("\nVocê perdeu!\n\n");
        printf("\nNúmero de jogadas:%d",jogadas);
        printf("\nVidas perdidas:%d",5+vidas);
        printf("\npalavra certa:%s",palavra);
        printf("\npalavra:%s\n\n",user);
    }
    

    return 0;
}
