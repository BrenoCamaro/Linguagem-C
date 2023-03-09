#include <stdio.h>
#include <stdlib.h>
//Dados
typedef struct {
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;
//NO
typedef struct{
    Pessoa p;
    struct no *proximo;
}No;

Pessoa lerPessoa();
void imprimirPessoa(Pessoa p);

//Funções da pilha
No* empilhar(No *topo);
No* desempilhar(No **topo);
void imprimirPilha(No *topo);

//Programa principal
int main (void){

    No *remover, *topo =  NULL;
    int opcao;

    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
                topo = empilhar(topo);
                break;
            case 2:
                remover = desempilhar(&topo);
                if(remover != NULL){
                    printf("\nElemento removido com sucesso! \n");
                    imprimirPessoa((*remover).p);
                }else{
                    printf("\nSem no a remover! \n");
                }
                break;
            case 3:
                imprimirPilha(topo);
                break;
            default:
                if(opcao != 0){
                    printf("\nOpcao invalida! \n");
                }

        }
    }while(opcao != 0);

    getchar();
    return 0;
}
//Fim do programa principal

Pessoa lerPessoa(){
    Pessoa p;

    printf("\nDigite o nome e a data de nascimento dd mm aaaa: \n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    fflush(stdin);
    return p;
}

void imprimirPessoa(Pessoa p){
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

//Função para a operação push (empilhar)
 No* empilhar(No *topo){
    No *novo = (No *) malloc(sizeof(No));
    if(novo){
        (*novo).p = lerPessoa();
        (*novo).proximo = topo;
        return novo;
    }else{
        printf("\nErro ao alocar memoria! \n");
        return NULL;
    }
}
//Função para a operação pop (desempilhar) - RETORNA O NO DESEMPILHADO
No* desempilhar(No **topo){
    if(*topo != NULL){
        No *remover = *topo; // 1 passo
        *topo = (*remover).proximo; // 2 passo
        return remover;
    }else{
        printf("\nPilha vazia! \n");
        return NULL;
    }
}
//Função para imrpimir os elementos da pilha
void imprimirPilha(No *topo){
    printf("\n----------- PILHA -----------\n");
    while(topo != NULL){
        imprimirPessoa((*topo).p);
        topo = (*topo).proximo;
    }
    printf("\n----------- FIM PILHA -----------\n");
}
