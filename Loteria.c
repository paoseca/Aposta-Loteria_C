
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM 6
//
void sortear(int *vet, int tam){
    int i;
    int j;
    int temp, achou;
    vet[0] = rand() %60 + 1;
    for(i = 0; i < TAM; i++){
        temp = rand() %60 + 1;
        j = i -1;
        achou = 0;
        while (j >= 0 && !achou){
            if (vet[j] == temp ){
                achou = 1;
            }
            else{
                j--;
            }
        }
        if (achou){
            i--;
        }
        else{
            vet[i] = temp;
        }
    }
}

void exibe_vetor (char *msg, int *vet, int tam){
    int i;

    printf("\n%s\n", msg);
    for (i = 0; i < tam; i++){
        printf("| %d |", vet[i]);
    }
    printf("\n");
}


void entrada(int *vet, int n) {
  printf("Faça a sua aposta\n", TAM);
  // pede ao usuário para digitar os 5 números
  for (int i = 0; i < n; i++) {
    scanf("%d", &vet[i]);
  }
}


int verifica_acertos(int *loteria, int n, int *jogo, int apostas, int **acertos){
    *acertos = (int *) malloc(n * sizeof(int));
    int i, j, k = 0;

    for (i = 0; i < n ; i++){
        for (j  = 0 ; j < n; j++){
            if(loteria[i] == jogo[j]){
                (*acertos)[k++] = jogo[j];
                j++;
            }
        }
    }
    *acertos  =  (int *)realloc(*acertos, k * sizeof(int));
    return k;
}

int main(){
    setlocale (LC_ALL, "Portuguese");
    int *loteria;
    int *jogo;
    int *acertos, quantos; //quantos -> a quantidade de acertos
    srand(time(0));

//alocando vetores
    loteria = (int *) malloc(TAM *sizeof(int));
    jogo = (int *) malloc(TAM * sizeof(int));


    sortear(loteria, TAM);
    exibe_vetor("numeros sorteados", loteria, TAM);

    entrada(jogo, TAM);
    exibe_vetor("seu jogo", jogo, TAM);

    quantos = verifica_acertos(loteria, TAM, jogo, TAM, &acertos);
    exibe_vetor("Números que você acertou", acertos, quantos);   //ERROOOO


    return 0;
}
