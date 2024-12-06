#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


/*A função bubblesort ordena uma lista duplamente encadeada de nós com base no campo idade, em ordem decrescente. Ela utiliza o algoritmo Bubble Sort, onde os valores dos nós adjacentes são comparados e trocados repetidamente até que a lista esteja ordenada. O processo continua enquanto houver trocas, garantindo que o maior valor "suba" para o início da lista a cada iteração.*/
void bubblesort(Lista* l) {
    if(l->prim == NULL){
        return;  
    }
    else if(l->prim->prox == NULL){
        return; 
    }

    int troca;

    do{
        troca = 0;  
        ListaNo* atual = l->prim;
        
        while (atual != NULL && atual->prox != NULL) {
            if(atual->idade < atual->prox->idade){  

                int temp = atual->idade;
                atual->idade = atual->prox->idade;
                atual->prox->idade = temp;
                troca = 1;  
            }
            atual = atual->prox;
        }
    }while(troca); 
}


int main(void) {
    Lista* fila = lst_cria();  


    FILE* arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        exit(1); 
    }

    int idade;

    while (fscanf(arquivo, "%d", &idade) != EOF) {
        lst_insere_final(fila, idade); 
    }

    fclose(arquivo);  

    bubblesort(fila);

    ListaNo* atual = fila->prim;
    while (atual != NULL) {
        printf("%d\n", atual->idade);  
        atual = atual->prox;
    }

    while (fila->prim != NULL) {
        int idadeAtendida = desenfileirar(fila);  
    }

    liberarLista(fila);
    free(fila);
    printf("\n");
    return 0;
}