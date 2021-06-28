#include <iostream>
#include "fila.h"
using namespace std;

fila::fila(){
    nodePtrFila = NULL; 
    nodeUltFila = NULL;
} // Construtor padr�o definindo valor NULL

fila::~fila() { // Destrutor padr�o
    delete nodePtrFila;
}

bool fila::vazia() { // Verifica se o final e a frente da fila est�o vazias
    if (nodePtrFila == NULL)
        return true; // Retorna verdadeiro
    else
        return false; // Retorna falso
}

void fila::inserir(pecas dados)
{
    // ***  Armazena o valor no novo n�  ***

    nodeFila* Paux = new nodeFila; // Aloca um n�
    Paux->next = NULL;

    //Percorre o vetor de dados da pe�a colocando no novo n�
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

    //Paux->next = nodePtrFila; // O pr�ximo deste novo n� ser� o elemento do topo
    //nodePtrFila= Paux; // O topo da fila vira o novo n�
}

pecas fila::retirar() { // Fun��o para retirar valor
    pecas valor;
    nodeFila* Paux = new nodeFila; // aloca��o din�mica do n�

    //Percorre o vetor de dados colocando na vari�vel auxiliar
    for (int i = 0; i < 4; i++)
    {
        valor.x[i] = nodePtrFila->valor.x[i];
        valor.y[i] = nodePtrFila->valor.y[i];
    }

    Paux = nodePtrFila; // aponta para o topo guardando o endere�o antes de mudar de lugar
    nodePtrFila = nodePtrFila->next; // topo da fila vai para o pr�ximo elemento
    delete (Paux); // desaloca o n� que armazenava o elemento do topo

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


