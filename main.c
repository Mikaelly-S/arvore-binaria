#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <malloc.h>
#include "Arvore.h"
//Mikaelly S

int main(){
	arv *T;
	int opcao, info, noPai;
	criarVazia(&T);
	
	menu();
	scanf("%d", &opcao);
	system("clear");
	while (opcao !=0){
		
		//Inserir raiz
		if (opcao == 1){
				printf("Digite o valor da raiz: ");
				scanf("%d", &info);
				if (inserirRaiz(&T,info))
						printf("Raiz inserida");
				else
						printf("Raiz não inserida");
		} else if (opcao == 2) { //Inserir filho esquerdo
				printf("Digite o valor do nó pai: ");
				scanf("%d", &noPai);
				printf("Digite o valor do nó filho: ");
				scanf("%d", &info);
				if (inserirEsq(T,noPai,info))
					printf("Nó filho inserido");
				else
					printf("Nó filho não foi inserido");
		} else if (opcao == 3) { //Inserir filho direito
				printf("Digite o valor do nó pai: ");
				scanf("%d", &noPai);
				printf("Digite o valor do nó filho: ");
				scanf("%d", &info);
				if (inserirDir(T,noPai,info))
					printf("Nó filho inserido");
				else
					printf("Nó filho não foi inserido");
		} else if (opcao == 4) { //Verificar se a árvore tem algum nó
				printf("Digite o valor do nó: ");
				scanf("%d", &info);
				if (procura(T, info))
					printf("A árvore tem esse nó");
				else
					printf("A árvore não tem esse nó");
		} else if (opcao == 5) { //Exibir o pai de um nó
				printf("Digite o valor do nó: ");
				scanf("%d", &info);
				exibirPai(T,info);
		} else if (opcao == 6) { //Exibir os filhos de um nó
				printf("Digite o valor do nó: ");
				scanf("%d", &info);
				exibirFilhos(T,info);
		} else if (opcao == 7) { //Exibir o filho direito
				printf("Digite o valor do nó: ");
				scanf("%d", &info);
				exibirFilhoDireito(T,info);
		} else if (opcao == 8) { //Exibir o filho esquerdo
				printf("Digite o valor do nó: ");
				scanf("%d", &info);
				exibirFilhoEsquerdo(T,info);
		} else if (opcao == 9){ //Remover um nó folha
				printf("Digite o valor do nó: ");
				scanf("%d", &info);
				removerNo(T,info);
		}
		
		menu();
		scanf("%d", &opcao);
		system("clear");
	}
	
	return 0;
}

