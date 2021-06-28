#include <iostream>
#include "fila.h"
using namespace std;

fila::fila(){
    nodePtrFila = NULL; 
    nodeUltFila = NULL;
} // Construtor padrão definindo valor NULL

fila::~fila() { // Destrutor padrão
    delete nodePtrFila;
}

bool fila::vazia() { // Verifica se o final e a frente da fila estão vazias
    if (nodePtrFila == NULL)
        return true; // Retorna verdadeiro
    else
        return false; // Retorna falso
}

void fila::inserir(pecas dados)
{
    // ***  Armazena o valor no novo nó  ***

    nodeFila* Paux = new nodeFila; // Aloca um nó
    Paux->next = NULL;

    //Percorre o vetor de dados da peça colocando no novo nó
    for (int i = 0; i < 4; i++)
    {
        Paux->valor.x[i] = dados.x[i];
        Paux->valor.y[i] = dados.y[i];
    }

    if (vazia())
    {
        nodePtrFila = Paux;
        nodeUltFila = Paux;
    }
    else
    {
        nodeUltFila->next = Paux;
        nodeUltFila = Paux;
    }

    //Paux->next = nodePtrFila; // O próximo deste novo nó será o elemento do topo
    //nodePtrFila= Paux; // O topo da fila vira o novo nó
}

pecas fila::retirar() { // Função para retirar valor
    pecas valor;
    nodeFila* Paux = new nodeFila; // alocação dinâmica do nó

    //Percorre o vetor de dados colocando na variável auxiliar
    for (int i = 0; i < 4; i++)
    {
        valor.x[i] = nodePtrFila->valor.x[i];
        valor.y[i] = nodePtrFila->valor.y[i];
    }

    Paux = nodePtrFila; // aponta para o topo guardando o endereço antes de mudar de lugar
    nodePtrFila = nodePtrFila->next; // topo da fila vai para o próximo elemento
    delete (Paux); // desaloca o nó que armazenava o elemento do topo

    return valor;
}

pecas fila::retornarValor(int posicao)
{
    pecas valor = pecas();
    fila Aux;
    int i = 0;

    while (!vazia())
    {
        pecas retirado = retirar();

        if (posicao == i)
            valor = retirado;

        Aux.inserir(retirado);

        i++;
    }

    while (!Aux.vazia())
    {
        inserir(Aux.retirar());
    }


    return valor;
}


