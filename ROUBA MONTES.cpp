#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Carta{ //estrutura para representar as cartas do baralho
	int numero;
	int naipe;
	Carta* prox;
}Carta;

typedef struct PilhaDeCartas{ //estrutura para os montes dos jogadores e a pilha de compra
	Carta* topo;
}PilhaDeCartas;

PilhaDeCartas* criar_pilha(){ //funcao para criar um monte
	PilhaDeCartas* p = (PilhaDeCartas*) malloc (sizeof(PilhaDeCartas));
	p->topo=NULL;
	return p;
}

typedef struct Jogador{ //estrutura para representar um jogador
	char nome[20];
	PilhaDeCartas* monte;
}Jogador;

void empilhar (PilhaDeCartas* monte, int n, int naipe){
	Carta* nova_carta = (Carta*) malloc (sizeof(Carta));
	nova_carta->numero=n;
	nova_carta->naipe=naipe;
	nova_carta->prox=monte->topo;
	monte->topo=nova_carta;
}

PilhaDeCartas* baralho(){
	PilhaDeCartas* baralho=criar_pilha();
	int naipe, numero;
	for(naipe=0; naipe<4; naipe++){
		for(numero=1; numero<=13; numero++){
			
		}
	}
}

void imprimir_monte (Jogador* j){
	Carta* atual=j->monte->topo;
	printf("elementos da pilha do jogador %s:\n", j->nome);
	while(atual!=NULL){
		printf("%d\n", atual->naipe);
		printf("%d\n", atual->numero);
		atual=atual->prox;
	}
}

void imprimir_jogador (Jogador* j, int qtde){
	for(int i=0; i<qtde; i++){
		printf("%s", j[i].nome);
		imprimir_monte(&j[i]);
	}
}



int main(){
	int qtde_jogadores, qtde_cartas;
	
	printf("Bem-vindo a uma partir de ROUBA-MONTE!\n");
	printf("Digite o numero de jogadores: ");
	scanf("%d", &qtde_jogadores);
	while(qtde_jogadores<2){
		printf("Quantidade invalida. Digite um numero maior que 1. \n");
		scanf("%d", &qtde_jogadores);
	}
	printf("Com quantas cartas desejam jogar?\n"); //escolhe a quantidade de cartas
	scanf("%d", &qtde_cartas);
	while(qtde_cartas<52){
		printf("Quantidade invalida. Digite novamente.");
		scanf("%d", &qtde_cartas);
	}
	
	Jogador jogador= (Jogador*) malloc (qtde_jogadores*sizeof(Jogador));
	
	for(int i=0; i<qtde_jogadores; i++){ //preenche o nome dos jogadores
		printf("Digite  o nome do jogador %d: ", i+1);
		setbuf(stdin, NULL);
		fgets(jogador[i].nome, 20, stdin);
		jogador[i].monte=criar_pilha();
	}
	
	printf("%s comeca.\n", jogador[0].nome); //início do jogo
	
	PilhaDeCartas* pilha_compra=criar_pilha();
	
	imprimir_jogador(&jogador[0], 1);
	
	
	free(jogador);
	return 0;
}
