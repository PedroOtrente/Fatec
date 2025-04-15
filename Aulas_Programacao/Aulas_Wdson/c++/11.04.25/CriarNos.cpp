#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct No {
    int valor;
    No* proximo;
};

// Ponteiro para o início da lista
No* inicio = nullptr;
int totalNos = 0;

void menu() {
    cout << "\n----- MENU -----\n";
    cout << "1. Criar nó\n";
    cout << "2. Listar nós\n";
    cout << "3. Deletar primeiro nó\n";
    cout << "4. Sair\n";
}

void criarNo() {
    int valor;
    cout << "Digite o valor do novo nó: ";
    cin >> valor;

    if (cin.fail()) {
        cout << "Valor inválido. Tente novamente.\n";
        cin.clear();
        cin.ignore(100, '\n');
        return;
    }

    No* novo = new No;
    novo->valor = valor;
    novo->proximo = nullptr;

    // Caso 1: Lista vazia ou valor menor que o primeiro
    if (inicio == nullptr || valor < inicio->valor) {
        novo->proximo = inicio;
        inicio = novo;
    } else {
        // Caso 2: Inserção no meio ou fim
        No* atual = inicio;
        while (atual->proximo != nullptr && atual->proximo->valor < valor) {
            atual = atual->proximo;
        }

        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    totalNos++;
    cout << "Nó inserido em ordem!\n";
}


void listarNos() {
    if (inicio == nullptr) {
        cout << "A lista está vazia.\n";
        return;
    }

    No* temp = inicio;
    int i = 1;
    cout << "\n--- Lista de Nós ---\n";
    while (temp != nullptr) {
        cout << i << ". Valor: " << temp->valor << endl;
        temp = temp->proximo;
        i++;
    }
}

void deletarNo() {
    if (inicio == nullptr) {
        cout << "A lista já está vazia.\n";
        return;
    }

    No* temp = inicio;
    inicio = inicio->proximo;
    delete temp;

    totalNos--;
    cout << "Primeiro nó deletado com sucesso.\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Suporte a acentuação no terminal do Windows

    int escolha;

    while (true) {
        menu();
        cout << "\nEscolha uma opção: ";
        cin >> escolha;

        if (cin.fail()) {
            cout << "Digite apenas números!" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }

        switch (escolha) {
            case 1:
                criarNo();
                break;
            case 2:
                listarNos();
                break;
            case 3:
                deletarNo();
                break;
            case 4:
                cout << "Até breve!\n";
                system("pause");
                return 0;
            default:
                cout << "Opção não disponível\n";
        }
    }

    return 0;
}
