#include <iostream> // Inclusão da biblioteca padrão
#include "StructPilha.h" // Inclusão do Struct.h
using namespace std; // Name space para as funçoes standard

// Implementação da classe pilha
class pilha 
{ 
	private: // Atributos privados
		nodePilha* nodePtrPilha;

public: // Atributos públicos
	pilha(); // Construtor padrão
	~pilha(); // Destrutor padrão

	bool vazia(); // Função para verificar se está vazia
	void inserir(dadosJogador); // Função para inserir valor
	dadosJogador retirar(); // Retirar um valor
};