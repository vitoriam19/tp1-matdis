#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 51

//Funcao que verifica se o conjunto e reflexivo
int reflexiva(int ligacoes[TAMANHO_MAX][TAMANHO_MAX], int *indices, int num_nos){
    for(int i = 0; i < num_nos; i++){
        if(ligacoes[indices[i]][indices[i]] != 1){
            return 0;
        }
    }
    return 1;
}

//Funcao que verifica se o conjunto e irreflexivo
int irreflexiva(int ligacoes[TAMANHO_MAX][TAMANHO_MAX], int *indices, int num_nos){
    for(int i = 0; i < num_nos; i++){
        if(ligacoes[indices[i]][indices[i]] == 1){
            return 0;
        }
    }
    return 1;
}

//Funcao que retorna os pares que fazem com que a propriedade irreflexiva nao seja satisfeita
void irreflexiva_pares(int ligacoes[TAMANHO_MAX][TAMANHO_MAX], int *indices, int num_nos){

    for(int i = 0; i < num_nos; i++){
        if(ligacoes[indices[i]][indices[i]] == 1){
            printf("(%d,%d); ", indices[i], indices[i]);
        }
    }
    printf("\n");
}

//Funcao que verifica se o conjunto e simetrico
int simetrico(int ligacoes[TAMANHO_MAX][TAMANHO_MAX], int *indices, int num_nos){

    for(int i = 0; i < num_nos; i++){
        for(int j = 0; j  < num_nos; j++){
            if(ligacoes[indices[i]][indices[j]] == 1 && ligacoes[indices[j]][indices[i]] != 1){
                return  0;
            }
        }
    }
    return 1;
}

//Funcao que retorna os pares que fazem com que a propriedade simetrico nao seja satisfeito
void simetrico_pares(int ligacoes[TAMANHO_MAX][TAMANHO_MAX], int *indices, int num_nos){

    for(int i = 0; i < num_nos; i++){
        for(int j = 0; j  < num_nos; j++){
            if(ligacoes[indices[i]][indices[j]] == 1 && ligacoes[indices[j]][indices[i]] != 1){
                printf("(%d,%d); ", indices[j], indices[i]);
            }
        }
    }
    printf("\n");
}

//Funcao que verifica se o conjunto e anti-simetrico
int anti_simetrico(int ligacoes[TAMANHO_MAX][TAMANHO_MAX], int *indices, int num_nos){

    for(int i = 0; i < num_nos; i++){
        for(int j = 0; j  < num_nos; j++){
            if(ligacoes[indices[i]][indices[j]] == 1 && ligacoes[indices[j]][indices[i]] == 1 && (i != j)){
                return  0;
            }
        }
    }
    return 1;
}

//Funcao que retorna os pares que fazem com que a propriedade anti-simetrico nao seja satisfeito
void anti_simetrico_pares(int ligacoes[TAMANHO_MAX][TAMANHO_MAX], int *indices, int num_nos){

    for(int i = 0; i < num_nos; i++){
        for(int j = 0; j  < num_nos; j++){
            if(ligacoes[indices[i]][indices[j]] == 1 && ligacoes[indices[j]][indices[i]] == 1 && (i != j)){
                printf("(%d,%d); ", indices[i], indices[j]);
            }
        }
    }
    printf("\n");
}


//Funcao que verifica se o conjunto e assimetrico
int assimetrico(int ligacoes[TAMANHO_MAX][TAMANHO_MAX], int *indices, int num_nos){

    for(int i = 0; i < num_nos; i++){
        for(int j = 0; j  < num_nos; j++){
            if(ligacoes[indices[i]][indices[j]] == 1 && ligacoes[indices[j]][indices[i]] == 1){
                return  0;
            }
        }
    }
    return 1;
}

//Funcao que verifica se o conjunto e transitivo
int transitivo(int ligacoes[TAMANHO_MAX][TAMANHO_MAX], int *indices, int num_nos){

    for(int i = 0; i < num_nos; i++){
        for(int j = 0; j  < num_nos; j++){
            for(int k = 0; k < num_nos; k++){
                if(ligacoes[indices[i]][indices[j]] == 1 && ligacoes[indices[j]][indices[k]] == 1 && ligacoes[indices[i]][indices[k]] != 1){
                    return  0;
                }
            }
        }
    }
    return 1;
}

void transitivo_pares(int ligacoes[TAMANHO_MAX][TAMANHO_MAX], int *indices, int num_nos){

    for(int i = 0; i < num_nos; i++){
        for(int j = 0; j  < num_nos; j++){
            for(int k = 0; k < num_nos; k++){
                if(ligacoes[indices[i]][indices[j]] == 1 && ligacoes[indices[j]][indices[k]] == 1 && ligacoes[indices[i]][indices[k]] != 1){
                    printf("(%d,%d); ", indices[i], indices[k]);
                }
            }
        }
    }
    printf("\n");
}

//Funcao principal
int main(){
    int num_nos,i,j,k,x,y;
    int ligacoes[TAMANHO_MAX][TAMANHO_MAX] = {0}; //cria uma matriz de tamanho maximo e preenche com zero
    int * indices;

    scanf("%d", &num_nos);
/************************** PREENCHE A MATRIZ DE ACORDO COM A ENTRADA **************************/
    //cria um vetor dinamico para armazenar os indices e o preenche de acordo com a entrada
    indices = (int *) malloc (sizeof(int) * (num_nos));
    for(i = 0; i < num_nos; i++){
        scanf("%d", &indices[i]);
    }

    //preenche a matriz ligacoes de acordo com os pares fornecidos na entrada
    while(scanf("%d %d", &x, &y) != EOF){
        ligacoes[x][y] = 1;
    }

/************************** CHAMA AS FUNCOES **************************/

    //Chama a funcao reflexiva
    int isReflexiva = 0;
    if(reflexiva(ligacoes, indices, num_nos)){
        printf("Reflexiva: V \n");
        isReflexiva = 1;
    }else{
        printf("Reflexiva: F\n");
    }

    //Chama a funcao irreflexiva e caso seja falso, mostra os pares 
    int isIrreflexiva = 0;
    if(irreflexiva(ligacoes, indices, num_nos)){
        printf("Irreflexiva: V\n");
        isIrreflexiva = 1;
    }else {
        printf("Irreflexiva: F\n");
        irreflexiva_pares(ligacoes, indices, num_nos);

    }

    //Chama a funcao simetrica
    int isSimetrica = 0;
    if(simetrico(ligacoes, indices, num_nos)){
        printf("Simetrica: V\n");
        isSimetrica = 1;
    }else {
        printf("Simetrica: F\n");
        simetrico_pares(ligacoes, indices, num_nos);
    }

    //Chama a funcao anti-simetrica
    int isAnti_simetrica = 0;
    if(anti_simetrico(ligacoes, indices, num_nos)){
        printf("Anti-simetrica: V\n");
        isAnti_simetrica = 1;
    }else {
        printf("Anti-simetrica: F\n");
        anti_simetrico_pares(ligacoes, indices, num_nos);
    }

    //Chama a funcao assimetrico
    int isAssimetrico = 0;
    if(assimetrico(ligacoes, indices, num_nos)){
        printf("Assimetrica: V \n");
        isAssimetrico = 1;
    }else{
        printf("Assimetrica: F\n");
    }

    //Chama a funcao transitivo
    int isTransitiva = 0;
    if(transitivo(ligacoes, indices, num_nos)){
        printf("Transitiva: V\n");
        isTransitiva = 1;
    }else {
        printf("Transitiva: F\n");
        transitivo_pares(ligacoes, indices, num_nos);
    }

    //Verifica se e uma relacao de equivalencia
    if(isReflexiva == 1 && isSimetrica == 1 && isTransitiva == 1){
        printf("Relacao de equivalencia: V\n");
    }else {
        printf("Relacao de equivalencia: F\n");
    }

    //Verifica se e uma relacao de ordem parcial
    if(isReflexiva == 1 && isAnti_simetrica == 1 && isTransitiva == 1){
        printf("Relacao de ordem parcial: V\n");
    }else {
        printf("Relacao de ordem parcial: F\n");
    }

    /*
    for(i = 0; i < TAMANHO_MAX; i++){
        for(j = 0; j < TAMANHO_MAX; j++){
            printf("%d ",ligacoes[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}