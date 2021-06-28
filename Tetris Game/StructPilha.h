#include <iostream> // Inclus�o da biblioteca padr�o
using namespace std; // Name space para as fun�oes standard

typedef struct dadosJogador {
	int pontuacao = 0;
	time_t  timer;
}dadosJogador;

typedef struct nodePilha { //Struct com os elementos da pilha
	dadosJogador valor;
	nodePilha* next;
}nodePilha;
