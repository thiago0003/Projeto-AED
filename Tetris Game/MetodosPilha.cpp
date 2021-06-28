#include <iostream> // Inclusão da biblioteca padrão
#include "pilha.h" // Inclusão do header.h
using namespace std; // Name space para as funçoes standard

pilha::pilha() {
    nodePtrPilha = NULL;
} // Construtor padrão definindo valor NULL

pilha::~pilha() { // Destrutor padrão
}

bool pilha::vazia() { // Verifica se o final e a frente da pilha estão vazias
    if (nodePtrPilha == NULL)
        return true; // Retorna verdadeiro
    else
        return false; // Retorna falso
}

void pilha::inserir(dadosJogador dados) { // Função para inserir valor
    
    nodePilha* Paux = new nodePilha; // Aloca um nó

    // Armazena o valor no novo nó
    Paux->valor.pontuacao = dados.pontuacao;
    Paux->valor.timer = dados.timer;
    
    Paux->next = nodePtrPilha; // O próximo deste novo nó será o elemento do topo
    nodePtrPilha = Paux; // O topo da pilha vira o novo nó
}

dadosJogador pilha::retirar() { // Função para retirar valor
    dadosJogador valor = dadosJogador();
    nodePilha* Paux = new nodePilha; // alocação dinâmica do nó
    
    if (!vazia())
    {
        valor = nodePtrPilha->valor;

        Paux = nodePtrPilha; // aponta para o topo guardando o endereço antes de mudar de lugar
        nodePtrPilha = nodePtrPilha->next; // topo da pilha vai para o próximo elemento
        delete (Paux); // desaloca o nó que armazenava o elemento do topo
    }
        
    return valor;
}
