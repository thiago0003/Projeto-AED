#include <iostream> // Inclusão da biblioteca padrão
using namespace std; // Name space para as funçoes standard

typedef struct dadosJogador {
	int pontuacao = 0;
	time_t  timer;
}dadosJogador;

typedef struct nodePilha { //Struct com os elementos da pilha
	dadosJogador valor;
	nodePilha* next;
}nodePilha;
