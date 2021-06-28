#include <iostream> // Inclus�o da biblioteca padr�o
#include "pilha.h" // Inclus�o do header.h
using namespace std; // Name space para as fun�oes standard

pilha::pilha() {
    nodePtrPilha = NULL;
} // Construtor padr�o definindo valor NULL

pilha::~pilha() { // Destrutor padr�o
}

bool pilha::vazia() { // Verifica se o final e a frente da pilha est�o vazias
    if (nodePtrPilha == NULL)
        return true; // Retorna verdadeiro
    else
        return false; // Retorna falso
}

void pilha::inserir(dadosJogador dados) { // Fun��o para inserir valor
    
    nodePilha* Paux = new nodePilha; // Aloca um n�

    // Armazena o valor no novo n�
    Paux->valor.pontuacao = dados.pontuacao;
    Paux->valor.timer = dados.timer;
    
    Paux->next = nodePtrPilha; // O pr�ximo deste novo n� ser� o elemento do topo
    nodePtrPilha = Paux; // O topo da pilha vira o novo n�
}

dadosJogador pilha::retirar() { // Fun��o para retirar valor
    dadosJogador valor = dadosJogador();
    nodePilha* Paux = new nodePilha; // aloca��o din�mica do n�
    
    if (!vazia())
    {
        valor = nodePtrPilha->valor;

        Paux = nodePtrPilha; // aponta para o topo guardando o endere�o antes de mudar de lugar
        nodePtrPilha = nodePtrPilha->next; // topo da pilha vai para o pr�ximo elemento
        delete (Paux); // desaloca o n� que armazenava o elemento do topo
    }
        
    return valor;
}
