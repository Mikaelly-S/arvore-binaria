#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <malloc.h>
#include "Arvore.h"
//Mikaelly S

//Estrutura da árvore
typedef struct arvB {
	int info;
	struct arvB *esq;
	struct arvB *dir;
} arv;

//Criar árvore vazia
void criarVazia(arv **T){
	*T = NULL;
}

//Verificar se a árvore está vazia
int verificarVazia(arv *T){
	if (T == NULL)
		return 1;
	else
		return 0;
}

//Inserir raiz da árvore
int inserirRaiz(arv **T, int valor){
	if(*T!=NULL)
		return 0;
	*T = (arv*) malloc(sizeof(arv));
	if(*T==NULL)
		return 0; 
	(*T)->info=valor;
	(*T)->esq=NULL;
	(*T)->dir=NULL;
	return 1;
}

//Procurar elemento(nó) na árvore
arv* procura(arv* T, int valor){
	arv* achou;
	if(T==NULL)
		return NULL;
	if(T->info==valor)
		return T;
	achou = procura(T->esq, valor);
	if(achou==NULL)
		achou = procura(T->dir, valor);
	return achou;
}

//Procura pai de um nó
arv* procuraPai(arv* T, int valor){
	arv* achou;
	if(T==NULL)
		return NULL;
	if((T->dir != NULL && T->dir->info==valor) || (T->esq != NULL && T->esq->info==valor))
		return T;
	achou = procuraPai(T->esq, valor);
	if(achou==NULL)
		achou = procuraPai(T->dir, valor);
	return achou;
}

//Inserir elemento na direita de um nó
int inserirDir(arv *T, int no, int valor){
	arv *noPai = procura(T,no);
	if(noPai==NULL)
		return 0;
	if(noPai->dir!=NULL)
		return 0;
	arv *novo= (arv*)malloc(sizeof(arv));
	novo->info = valor;
	novo->dir=NULL;
	novo->esq=NULL;
	noPai->dir = novo;
	return 1;
}

//Inserir elemento na esquerda de um nó
int inserirEsq(arv *T, int Pai, int valor){
	arv *noPai = procura(T,Pai);
	if(noPai==NULL)
		return 0;
	if(noPai->esq!=NULL)
		return 0;
	arv *novo= (arv*)malloc(sizeof(arv));
	novo->info = valor;
	novo->dir=NULL;
	novo->esq=NULL;
	noPai->esq = novo;
	return 1;
}

//Imprimir árvore inteira
void imprimir_arvore(arv* T){

	if(!verificarVazia(T))
	{
		printf("%d ", T->info); 
		imprimir_arvore(T->esq); 
		imprimir_arvore(T->dir);
	}

}

//Exibir os filhos de um nó
void exibirFilhos(arv* T, int info){

	if(!verificarVazia(T))
	{
		arv *suporte = procura(T,info);
		if (suporte == T){
			if(T->esq != NULL)
				printf("%d ", T->esq->info); 
			if(T->dir != NULL)
				printf("%d ", T->dir->info);
		} else {
			if(suporte->esq != NULL)
				imprimir_arvore(suporte->esq);
			if(suporte->dir != NULL)
				imprimir_arvore(suporte->dir); 
		}
	}

}

//Exibir filho direito de um nó
void exibirFilhoDireito(arv* T, int info){

	if(!verificarVazia(T))
	{
		arv *suporte = procura(T,info);
		if (suporte == T){
			printf("%d ", T->dir->info);
		} else {
			imprimir_arvore(suporte->dir); 
		}
	}

}

//Exibir filho esquerdo de um nó
void exibirFilhoEsquerdo(arv* T, int info){

	if(!verificarVazia(T))
	{
		arv *suporte = procura(T,info);
		if (suporte == T){
			printf("%d ", T->esq->info); 
		} else {
			imprimir_arvore(suporte->esq); 
		}
	}

}

//Exibir o pai de um nó
void exibirPai(arv *T, int info){
	if(!verificarVazia(T)){
		if (T->info != info){
		arv* suporte = procuraPai(T,info);
		printf("%d", suporte->info);
		}
	}
}

//Remover nó folha
void removerNo (arv *T, int info){
		if (!verificarVazia(T)){
			arv *suporte = procura(T,info);
			arv *noPai = procuraPai(T,info);
			if (suporte->esq == NULL && suporte->dir == NULL){
					if(noPai->dir->info == suporte->info){
					noPai->dir = NULL;
					free(suporte);
					} else {
						noPai->esq = NULL;
						free(suporte);
					}
			} else {
					printf("Não é uma folha");
			}
		}
}

//Menu
void menu(){
	printf("\n\nEDITOR DE ÁRVORE BINÁRIA\n\n");
	printf("1 - Inserir raiz\n");
	printf("2 - Inserir filho esquerdo\n");
	printf("3 - Inserir filho direito\n");
	printf("4 - Verificar se a árvore tem algum nó\n");
	printf("5 - Exibir o pai de um nó\n");
	printf("6 - Exibir os filhos de um nó\n");
	printf("7 - Exibir o filho direito\n");
	printf("8 - Exibir o filho esquerdo\n");
	printf("9 - Remover um nó folha\n");
	printf("0 - Sair\n\n");
	printf("DIGITE SUA OPÇÃO: ");
}
