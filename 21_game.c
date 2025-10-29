#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

char INSTRUCOES(char nome1[50],char nome2[50]) {

    setlocale(LC_ALL,"");

    printf("INSTRUÇÕES:\n\n");
    printf("\t\t\tBem vindo ao Jogo de 21\n\n");
    printf("O Jogo de 21 é jogado com um baralho comum com 52 cartas\n(sem os coringas)");
    printf("em que o objetivo é ter mais pontos do que o adversário,mas sem ultrapassar os 21 (caso em que se perde).\n\n");
    printf("Lembrando que:\n");
    printf(" - As cartas de 2 a 10 têm o número de pontos de acordo com seu valor facial.\n");
    printf(" - Todas as cartas de figuras valem 10 pontos.\n");
    printf(" - Os ases podem valer 1 ou 11 pontos.\n");
    printf(" - O naipe das cartas não interferem em seu valor.\n");
    printf("\n\nPara começar a jogar pressione qualquer tecla.");
    printf("\n\n\t\t\t...... START .......");
    getch();
    system("CLS");
    printf("====================== .: Jogo de 21 :. =======================\n\n");
    printf("Jogador 1,digite o seu nome: ");
    gets(nome1);
    printf("\nJogador 2,digite o seu nome: ");
    gets(nome2);
}

int main () {

    setlocale(LC_ALL,"");
    srand(time(NULL));

    char nome1[50],nome2[50],resp;
    int num,i,j,numGer,soma1,soma2,cont;
    soma1 = soma2 = cont = i = j = 0;
//Matriz com os possiveis numeros que podem aparecer em cada carta:
    int m[4][14] = {{1,2,3,4,5,6,7,8,9,10,10,10,10},
                    {1,2,3,4,5,6,7,8,9,10,10,10,10},
                    {1,2,3,4,5,6,7,8,9,10,10,10,10},
                    {1,2,3,4,5,6,7,8,9,10,10,10,10}};
    INSTRUCOES(nome1,nome2);

     m[i][j] = 0 ;    //Esvazia os vetores.

    printf("\n\n%s é a sua vez!",nome1);
    VOLTA:;
    i = rand()%3+0;
    j = rand()%13+0;
    numGer = m[i][j];
    do {
//If usado por causa do As,que pode valer 1 ou 11,se a soma for menor ou igual a 10 o As vale 11,e se a soma for maior que 10 o As vale 1
         if(numGer == 1) {
              if(soma1 <= 10) {
                    numGer = 11;
              }
              if(soma1 > 10) {
                    numGer = 1;
              }
         }
         soma1=soma1 + numGer;
         cont++;
    }while (cont<0);

    printf("\n\n\n");
    printf("%s sua carta sorteada foi: %d",nome1,numGer);
    printf("\nA soma de suas cartas é: %d",soma1);
    printf("\nDeseja outra carta: [S/N]");
    do{
           resp = getch();
       }while(isdigit(resp)!=0);
    printf("\nResposta: %c ",resp);
    resp = toupper(resp);

    if(resp == 'S') {
        goto VOLTA;
    }
    if(resp == 'N') {

            system("CLS");
            printf("====================== .: Jogo de 21 :. =======================\n\n");
            printf("%s é a sua vez!",nome2);
            RETORNO:;
            i = rand()%3+0;
            j = rand()%13+0;
            numGer = m[i][j];
            do {
                 if(numGer == 1) {
                      if(soma2 <= 10) {
                            numGer = 11;
                      }
                          if(soma2 > 10) {
                                numGer = 1;
                          }
                }
                soma2=soma2+numGer;
                cont++;
             } while (cont<0);

            printf("\n\n\n");
            printf("%s sua carta sorteada foi: %d",nome2,numGer);
            printf("\nA soma de suas cartas é: %d",soma2);
            printf("\nDeseja outra carta: [S/N]");
            do{
                   resp = getch();
               }while(isdigit(resp)!=0);
            printf("\nResposta: %c ",resp);
            resp = toupper(resp);

            if(resp == 'S') {
                goto RETORNO;
            }
            if(resp == 'N') {

                system("CLS");
                printf("====================== .: Jogo de 21 :. =======================\n\n");

                if((soma1 > soma2) && (soma1 <= 21) && (soma2 > 21)) {
                     printf("\a\a%s você perdeu!!Você marcou mais que 21 pontos",nome2);
                     printf("\n\nParabéns %s,você ganhou!!\nVocê marcou: %d pontos",nome1,soma1);
                     printf("\n\nEnquanto o jogador %s,marcou: %d pontos",nome1,soma1);
                }
                if((soma2 > soma1) && (soma2 <= 21) && (soma1 > 21)) {
                     printf("\a\a\n\n%s você perdeu!!Você marcou mais que 21 pontos",nome1);
                     printf("\n\nParabéns %s,você ganhou!!\nVocê marcou: %d pontos",nome2,soma2);
                     printf("\n\nEnquanto o jogador %s,marcou: %d pontos",nome1,soma1);
                }
                if(soma2 == soma1){
                     printf("\n\nO jogo terminou empatadado.\nAmbos jogadores marcaram: %d pontos",soma2);
                }
                if((soma1 > soma2) && (soma1 <= 21) && (soma2 < 21)) {
                     printf("\a\a\n\n%s você perdeu!!",nome2);
                     printf("\n\nParabéns %s,você ganhou!!\nVocê marcou: %d pontos",nome1,soma1);
                     printf("\n\nEnquanto o jogador %s,marcou: %d pontos",nome2,soma2);
                }
                if((soma2 > soma1) && (soma2 <= 21) && (soma1 < 21)) {
                     printf("\a\a\n\n%s você perdeu!!",nome1);
                     printf("\n\nParabéns %s,você ganhou!!\nVocê marcou: %d pontos",nome2,soma2);
                     printf("\n\nEnquanto o jogador %s,marcou: %d pontos",nome1,soma1);
                }
                if((soma1 > 21) && (soma2 > 21)) {
                         printf("\n\nO jogo não teve ganhadores!\nAmbos jogadores marcaram mais que 21 pontos.");
                }
            }

            }
    getch();
}
