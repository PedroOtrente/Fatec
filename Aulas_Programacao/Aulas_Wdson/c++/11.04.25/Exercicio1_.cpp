#include <iostream>
#include <Windows.h>
using namespace std;

// Estrutura do nó
struct No {
    int valor;
    No* proximo;
};

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->proximo = nullptr;
    return novoNo;
}

// Função para exibir a lista encadeada
void exibirLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != nullptr) {
        cout << atual->valor;
        if (atual->proximo != nullptr)
            cout << " -> ";
        else
            cout << " -> NULL";
        atual = atual->proximo;
    }
    cout << endl;
}

// Função para remover um nó com valor específico
No* removerNo(No* cabeca, int valorRemover) {
    // Caso especial: primeiro nó
    if (cabeca != nullptr && cabeca->valor == valorRemover) {
        No* temp = cabeca;
        cabeca = cabeca->proximo;
        delete temp;
        return cabeca;
    }

    // Para demais nós
    No* atual = cabeca;
    while (atual != nullptr && atual->proximo != nullptr) {
        if (atual->proximo->valor == valorRemover) {
            No* temp = atual->proximo;
            atual->proximo = temp->proximo;
            delete temp;
            return cabeca;
        }
        atual = atual->proximo;
    }

    cout << "Valor não encontrado.\n";
    return cabeca;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n, valor;
    No* cabeca = nullptr;
    No* ultimo = nullptr;

    cout << "Quantos elementos deseja inserir? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Digite o valor #" << i + 1 << ": ";
        cin >> valor;
        No* novo = criarNo(valor);
        if (cabeca == nullptr) {
            cabeca = novo;
            ultimo = novo;
        } else {
            ultimo->proximo = novo;
            ultimo = novo;
        }
    }

    cout << "\nLista original:\n";
    exibirLista(cabeca);

    int valorRemover;
    cout << "\nDigite o valor que deseja remover: ";
    cin >> valorRemover;

    cabeca = removerNo(cabeca, valorRemover);

    cout << "\nLista após remoção:\n";
    exibirLista(cabeca);

    // Liberação de memória
    No* atual = cabeca;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->proximo;
        delete temp;
    }

    return 0;
}
