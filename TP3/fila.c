#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Lista* lst_cria(void){
    Lista* l = malloc(sizeof(Lista));
    l->prim = NULL;
    l->ult = NULL;  
    return l;
}

void lst_insere_inicio(Lista* l, int idade){
    ListaNo* novo = malloc(sizeof(ListaNo)); 
    novo->idade = idade;  
    novo->prox = l->prim;  
    novo->ant = NULL;      
    if (l->prim != NULL){  
        l->prim->ant = novo; 
    } else {  
        l->ult = novo;  
    }
    l->prim = novo;  
}

void lst_insere_final(Lista* l, int idade){
    ListaNo* novo = malloc(sizeof(ListaNo));  
    novo->idade = idade; 
    novo->prox = NULL;  
    if (l->ult != NULL) {  
        l->ult->prox = novo;  
        novo->ant = l->ult;  
    } else {  
        l->prim = novo;  
        novo->ant = NULL;  
    }
    l->ult = novo;  
}

int desenfileirar(Lista* l){
    if (l->prim == NULL) {
        return -1;  
    }

    ListaNo* temp = l->prim;  
    int idade = temp->idade;   
    l->prim = l->prim->prox;   
    if(l->prim != NULL){
        l->prim->ant = NULL;  
    } 
    else{
        l->ult = NULL;  
    }

    free(temp);  
    return idade; 
}

void liberarLista(Lista* l){
    while(l->prim != NULL){
        desenfileirar(l);  
    }
}