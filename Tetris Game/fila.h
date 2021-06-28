#include <iostream> // Inclus�o da biblioteca padr�o
#include "StructFila.h" // Inclus�o do Struct.h
using namespace std; // Name space para as fun�oes standard

// Implementa��o da classe fila
class fila
{
private: // Atributos privados
	nodeFila* nodePtrFila;
	nodeFila* nodeUltFila;

public: // Atributos p�blicos
	fila(); // Construtor padr�o
	~fila(); // Destrutor padr�o

	bool vazia(); // Fun��o para verificar se est� vazia
	void inserir(pecas); // Fun��o para inserir valor
	pecas retirar(); // Retirar um valor
	pecas retornarValor(int); //Retorna o valor da posic�o desejada
};