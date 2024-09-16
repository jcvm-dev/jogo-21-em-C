#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

#if defined _WIN32 || defined _WIN64
    #define CLEAR_COMMAND "CLS"
    #define WIN
#else
    #define CLEAR_COMMAND "clear"
#endif

#define TAMANHO_NOME 50

const int CARTAS[4][14] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10},
                           {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10},
                           {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10},
                           {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}};

void printCabecalho() {
    system(CLEAR_COMMAND);
    printf("====================== .: Jogo de 21 :. =======================\n\n");
}

void printInstrucoes() {
    printf("INSTRUÇÕES:\n\n");
    printf("\t\t\tBem vindo ao Jogo de 21\n\n");
    printf("O Jogo de 21 é jogado com um baralho comum com 52 cartas\n(sem os coringas)");
    printf("em que o objetivo é ter mais pontos do que o adversário,mas sem ultrapassar os 21 (caso em que se perde).\n\n");
    printf("Lembrando que:\n");
    printf(" - As cartas de 2 a 10 tem o número de pontos de acordo com seu valor facial.\n");
    printf(" - Todas as cartas de figuras valem 10 pontos.\n");
    printf(" - Os ases podem valer 1 ou 11 pontos.\n");
    printf(" - O naipe das cartas não interferem em seu valor.\n");
    printf("\n\nPara começar a jogar pressione qualquer tecla.");
    printf("\n\n\t\t\t...... START .......");

    char temp;
    scanf("%[^\n]", &temp);
}

int jogarNovamente(char resposta) {
    return resposta == 'S' || resposta == 's' ? 1 : 0;
}

int jogar(char nome[TAMANHO_NOME]) {
    printf("\n\n%s é a sua vez!", nome);

    char resp = 's';
    int i, j, carta;
    int soma = 0;
    
    while (jogarNovamente(resp)) {
        i = rand()%4;
        j = rand()%13;
        carta = CARTAS[i][j];

        carta = carta == 1 && soma <= 10 ? 11 : carta;
        soma += carta;

        printf("\n\n\n");
        printf("%s, sua carta sorteada foi: %d\n", nome, carta);
        printf("A soma de suas cartas é: %d\n", soma);
        printf("Deseja outra carta [S/n]: ");
        scanf(" %1[^\n]", &resp);
    };

    return soma;
}

void printVencedor(char vencedor[TAMANHO_NOME], char perdedor[TAMANHO_NOME], int pontuacaoVencedor, int pontuacaoPerdedor) {
    printf("\a\a\n\n%s, você perdeu!!", perdedor);
    printf("\n\nParabéns %s, você ganhou!!\nVocê marcou: %d pontos", vencedor, pontuacaoVencedor);
    printf("\n\nEnquanto o jogador %s, marcou: %d pontos\n", perdedor, pontuacaoPerdedor);
}

void validaVencedor(char nome1[TAMANHO_NOME], char nome2[TAMANHO_NOME], int soma1, int soma2) {
    if (soma1 > 21 && soma2 > 21) {
        printf("\n\nO jogo não teve ganhadores!\nAmbos jogadores marcaram mais que 21 pontos.\n");
    } else if (soma1 < soma2) {
        printVencedor(nome1, nome2, soma1, soma2);
    } else if (soma1 > soma2) {
        printVencedor(nome2, nome1, soma2, soma1);
    } else if (soma1 == soma2) {
        printf("\n\nO jogo terminou empatadado.\nAmbos jogadores marcaram: %d pontos\n", soma2);
    }
}

int main () {
    setlocale(LC_ALL, "");
    srand(time(NULL));

    char nome1[TAMANHO_NOME], nome2[TAMANHO_NOME];
    int soma1, soma2;
    soma1 = soma2 = 0;

    printInstrucoes();
    printCabecalho();
    
    printf("Jogador %d, digite o seu nome: ", 1);
    scanf(" %50[^\n]", nome1);
    printf("Jogador %d, digite o seu nome: ", 2);
    scanf(" %50[^\n]", nome2);

    soma1 = jogar(nome1);
    printCabecalho();

    soma2 = jogar(nome2);
    printCabecalho();

    validaVencedor(nome1, nome2, soma1, soma2);

    #ifdef WIN
        getch();
    #endif
}
