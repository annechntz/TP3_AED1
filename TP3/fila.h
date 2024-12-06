typedef struct lista Lista;
typedef struct listano ListaNo;

/*dados importados*/
struct listano {
    int idade;       
    ListaNo* prox;   
    ListaNo* ant;    
};

struct lista {
    ListaNo* prim;  
    ListaNo* ult;  

}; 
/*Essa função não recebe nada. Retorna o endereço de uma lista duplamente encadeada.*/
Lista* lst_cria(void);      
/*Essa função recebe como parâmetro a lista. Ela tem a função de inserir os elementos lidos da direita para a esquerda, a partir do endereço prim.*/                
void lst_insere_inicio(Lista* l, int idade);  
/*Age de forma semelhante a outra função, porém, ela insere da esquerda para direita, iniciando do ultimo elemento e percorrendo até o primeiro elemento. */ 
void lst_insere_final(Lista* l, int idade);   
/*A função desenfileirar remove e retorna o valor (idade) do primeiro elemento de uma lista duplamente encadeada, que provavelmente está sendo usada como uma fila. Se a lista estiver vazia, a função retorna -1. Caso contrário, ela atualiza os ponteiros da lista para refletir a remoção do primeiro nó e libera a memória desse nó.*/
int desenfileirar(Lista* l);     
/*A função liberarLista remove e libera todos os nós de uma lista duplamente encadeada, chamando repetidamente a função desenfileirar até que a lista esteja vazia. Ela garante que toda a memória alocada para os nós da lista seja liberada.A função liberarLista remove e libera todos os nós de uma lista duplamente encadeada, chamando repetidamente a função desenfileirar até que a lista esteja vazia. Ela garante que toda a memória alocada para os nós da lista seja liberada.*/
void liberarLista(Lista* l);                
