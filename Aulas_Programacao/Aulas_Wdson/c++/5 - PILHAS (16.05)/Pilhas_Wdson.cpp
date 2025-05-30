/*===== Pilhas =====
====================*/

/*O que é uma Pilha?

Definição:

Pilha (Stack) é uma estrutura de dados do 
tipo LIFO (Last In, First Out), 
onde o último elemento inserido é o primeiro 
a ser removido.

Operações principais
====================

Push: Adicionar um elemento ao topo da pilha.
Pop:  Remover o elemento do topo da pilha.
Peek: Obter o elemento no topo da pilha 
      sem removê-lo.
IsEmpty: Verificar se a pilha está vazia.
Size: Retornar o número de elementos na pilha.

Duas abordagens principais:
===========================

1.Baseada em array.
2.Baseada em lista encadeada. 

Principais aplicações
=====================

-> Gerenciamento de Chamadas de Funções.
-> Navegação em Histórico.
-> Desfazer/Refazer.
-> Balanceamento de Parênteses. 
*/

//====== Biliotecas ====== //
#include <iostream>
#include <Windows.h>

using namespace std;

//====== Estrutura do Nó (Apenas um inteiro) ====== //
struct No
{
    int valor;
    No* proximo;
};

//====== Implementação das funções da Pilha  =======//


// Verifica se a pilha está vazia
bool isEmpty(No* topo) 
{
    bool vazia;
    if (topo == nullptr) {
        vazia = true;
    } else {
        vazia = false;
    }
    return vazia;
}

// Adiciona um elemento na pilha (push)
No* push(No* topo, int valor) 
{
    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->proximo = topo;
    return novoNo;
}

// Remove o elemento do topo da pilha (pop)
No* pop(No* topo) {
    if (isEmpty(topo)) {
        cout << "Pilha vazia!" << endl;
        return nullptr;
    }
    No* temp = topo;
    No* novoTopo = topo->proximo;
    delete temp;
    return novoTopo;
}

// Retorna o elemento do topo da pilha (peek)
int peek(No* topo) {
    if (isEmpty(topo)) {
        cout << "Pilha vazia!" << endl;
        return -1; // Valor de erro
    }
    return topo->valor;
}

// Exibe os elementos da pilha
void displayPilha(No* topo) {
    if (isEmpty(topo)) {
        cout << "Pilha vazia!" << endl;
        return;
    }
    cout << "Elementos da pilha (Topo -> Base): ";
    No* atual = topo;
    while (atual != nullptr) {
        cout << atual->valor << " - ";
        atual = atual->proximo;
    }
    cout << endl;
}

/*======= Programa Principal Pilha  =====*/

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Exemplo de uso da pilha
    No* topop = nullptr;

    displayPilha(topop);
    
    topop = push(topop, 10);
    topop = push(topop, 40);
    topop = push(topop, 30);
    
    cout << "\n--- Conteúdo da Pilha ---" << endl;
    displayPilha(topop);

    cout << "\n--- Topo da Pilha ---" << endl;
    if (!isEmpty(topop)) {
        cout << "Topo: " << peek(topop) << endl;
    }
    
    topop = pop(topop);    
    cout << "\n--- Pilha após Pop ---" << endl;
    displayPilha(topop);

    // Limpeza da memória
    while (topop != nullptr) {
        No* temp = topop;
        topop = topop->proximo;
        delete temp;
    }

    return 0;
}