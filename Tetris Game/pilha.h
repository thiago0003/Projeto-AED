#include <iostream> // Inclus�o da biblioteca padr�o
#include "StructPilha.h" // Inclus�o do Struct.h
using namespace std; // Name space para as fun�oes standard

// Implementa��o da classe pilha
class pilha 
{ 
	private: // Atributos privados
		nodePilha* nodePtrPilha;

public: // Atributos p�blicos
	pilha(); // Construtor padr�o
	~pilha(); // Destrutor padr�o

	bool vazia(); // Fun��o para verificar se est� vazia
	void inserir(dadosJogador); // Fun��o para inserir valor
	dadosJogador retirar(); // Retirar um valor
};