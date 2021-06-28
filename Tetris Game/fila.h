#include <iostream> // Inclusão da biblioteca padrão
#include "StructFila.h" // Inclusão do Struct.h
using namespace std; // Name space para as funçoes standard

// Implementação da classe fila
class fila
{
private: // Atributos privados
	nodeFila* nodePtrFila;
	nodeFila* nodeUltFila;

public: // Atributos públicos
	fila(); // Construtor padrão
	~fila(); // Destrutor padrão

	bool vazia(); // Função para verificar se está vazia
	void inserir(pecas); // Função para inserir valor
	pecas retirar(); // Retirar um valor
	pecas retornarValor(int); //Retorna o valor da posicão desejada
};