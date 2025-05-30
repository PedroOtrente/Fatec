#include <iomanip>
#include <iostream>
#include <Windows.h>

using namespace std;

struct No {
    int valor;
    No* proximo = nullptr;
};

No* primeiro = nullptr;

void cabecalho(string mensagem) {
    cout << "-------------------\n";
    cout << mensagem << "\n";
    cout << "-------------------\n";
}

void menu() {
    cout << "1. Inserir na sequência (no final)\n2. Inserir no início\n3. Inserir após um nó específico\n4. Remover um nó em qualquer lugar\n5. Exibir lista\n6. Sair\n";
}

int pegaValorInteiro(string mensagem) {
    int novoValor;
    
    while (true) {
        cout << mensagem;
        cin >> novoValor;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Digite um valor válido!\n";
            system("pause");
            system("cls");
            continue;
        }
    
        return novoValor;
    }
}

void inserirSequencia(int valor1) {
    No* novoNo = new No;
    novoNo->valor = valor1;
    novoNo->proximo = nullptr;
    
    if (primeiro == nullptr) {
        primeiro = novoNo;
    } else {
        No* temp = primeiro;
        while (temp->proximo != nullptr) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }
}

void inserirInicio(int valor1) {
    No* novoNo = new No;
    novoNo->valor = valor1;
    novoNo->proximo = primeiro;
    primeiro = novoNo;
}

void inserirNoEspecifico(int valor1, int valor2) {
    No* novoNo = new No;
    novoNo->valor = valor1;
    novoNo->proximo = nullptr;
    
    if (primeiro == nullptr) {
        cout << "A lista está vazia!\n";
        return;
    }

    No* temp = primeiro;
    while (temp != nullptr && temp->valor != valor2) {
        temp = temp->proximo;
    }

    if (temp != nullptr) {
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;
    } else {
        cout << "Valor não encontrado!\n\n";
    }
}

void exibirLista() {
    system("cls");
    cabecalho("LISTA ENCADEADA");
    
    No* atual = primeiro;
    while (atual != nullptr) {
        cout << atual->valor;
        if (atual->proximo != nullptr) {
            cout << " -> ";
        } else {
            cout << " -> NULL";
        }
        atual = atual->proximo;
    }
    cout << endl;
}

void removerNo(int valor1) {
    if (primeiro == nullptr) {
        cout << "Nenhum nó foi cadastrado até o momento!\n\n";
        system("pause");
        system("cls");
        return;
    }


    if (primeiro->valor == valor1) {
        No* temp = primeiro;
        primeiro = primeiro->proximo; 
        delete temp;
        cout << "Nó deletado com sucesso!\n";
        system("pause");
        return;
    }


    No* temp = primeiro;
    while (temp->proximo != nullptr && temp->proximo->valor != valor1) {
        temp = temp->proximo;
    }

    
    if (temp->proximo != nullptr) {
        No* atualDelete = temp->proximo;
        temp->proximo = temp->proximo->proximo; 
        delete atualDelete;
        cout << "Nó deletado com sucesso!\n";
        system("pause");
    } else {
        cout << "Valor não encontrado na lista\n\n";
        system("pause");
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    system("cls");
    int opc, valor1, valor2;
    
    while (true) {
        cabecalho("MENU DE OPÇÕES");
        menu();
        opc = pegaValorInteiro("Digite uma opção\n");
        
        switch (opc) {
            case 1:
            	system("cls");
                valor1 = pegaValorInteiro("Digite um valor para o novo nó\n");
                inserirSequencia(valor1);
                break;
            case 2:
            	system("cls");
                valor1 = pegaValorInteiro("Digite um valor para o novo nó\n");
                inserirInicio(valor1);
                break;
            case 3:
            	system("cls");
            	    if (primeiro == nullptr) {
			        cout << "Nenhum nó foi cadastrado até o momento!\n\n";
			        system("pause");
			        system("cls");
			        break;
    			}
                valor1 = pegaValorInteiro("Digite um valor para o novo nó\n");
                valor2 = pegaValorInteiro("Depois de qual valor ele será posicionado?\n");
                inserirNoEspecifico(valor1, valor2);
                break;
            case 4:
            	system("cls");
                if (primeiro == nullptr) {
                    cout << "Nenhum nó foi cadastrado até o momento!\n\n";
                    system("pause");
                    system("cls");
                    break;
                }
                valor1 = pegaValorInteiro("Digite o valor que será removido\n");
                removerNo(valor1);
                break;
            case 5:
            	system("cls");
                if (primeiro == nullptr) {
                    cout << "Nenhum nó foi cadastrado até o momento!\n\n";
                    system("pause");
                    system("cls");
                    break;
                }
                exibirLista();
                break;
            case 6:
                system("cls");
                cout << "Encerrando o programa....\n\n";
                system("pause");
                return 0;
            default:
                cout << "Digite uma opção válida!\n";
                break;
        }
    }    
    
    return 0;
}
