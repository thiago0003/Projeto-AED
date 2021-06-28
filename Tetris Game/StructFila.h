
#include <iostream> // Inclusão da biblioteca padrão
using namespace std; // Name space para as funçoes standard

typedef struct pecas {
	int x[4];
	int y[4];
}pecas;

typedef struct nodeFila { //Struct com os elementos da pilha
	pecas valor;
	nodeFila* next;
}nodeFila;
