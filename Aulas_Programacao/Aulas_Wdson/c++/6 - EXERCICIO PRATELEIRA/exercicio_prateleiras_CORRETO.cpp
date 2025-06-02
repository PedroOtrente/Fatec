#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

// VARIÁVEIS GLOBAIS
struct No{
	int valor;
	No* proximo;
};

No* topo = nullptr;
No* topo2 = nullptr;
No* lista = nullptr;

// FUNÇÕES GERAIS
double pegar_valor_numerico(string mensagem){
	int valor;
	
	while (true){
		cout << mensagem;
		cin >> valor;
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "[ERRO] -> Digite um valor válido!\n\n";
			system("pause");
			continue;
		}
	return valor;
	}
}

void exibir_header(string mensagem){
	system("cls");
	cout << "=================================\n";
	cout << mensagem << endl;
	cout << "=================================\n\n";
}

// FUNÇÕES PRÓPRIAS
void menu(){
	cout << "=== ORGANIZADOR DE LIVROS EM PRATELEIRAS ===\n" << endl;
	cout << "1. Chegada de livros (Empilhar)\n";
	cout << "2. Retirar Livro\n";
	cout << "3. Ver Conteúdo das Prateleiras\n";
	cout << "4. Ver Conteúdo da Lista de Espera\n";
	cout << "5. Sair\n\n";
}

bool verifica_valor_existe(int valor){
	No* atual = topo;
	while (atual != nullptr){
		if (atual->valor == valor){
			return true;
		}
		atual = atual->proximo;
	}
	atual = topo2;
	while (atual != nullptr){
		if (atual->valor == valor){
			return true;
		}
		atual = atual->proximo;
	}
	atual = lista;
	while (atual != nullptr){
		if (atual->valor == valor){
			return true;
		}
		atual = atual->proximo;
	}
	return false;
}

int size(No*& topoRestrito){
	No* atual = topoRestrito;
	int contador  = 0;
	
	while (atual != nullptr){
		contador += 1;
		atual = atual->proximo;
	}
	return contador;
}

void push (No*& topoRestrito, int valor){
	No* novo = new No();
	novo->proximo = topoRestrito;
	novo->valor = valor;
	topoRestrito = novo; 
}

bool isEmpty(No* topoRestrito){
	return (topoRestrito == nullptr);
}

void pop(No*& topoRestrito){
	No* temp = topoRestrito;
	topoRestrito = topoRestrito->proximo;
	delete temp;
}

void adicionar_lista(No*& topoRestrito, int valor){
	No* novo = new No();
	No* atual = topoRestrito;
	
	novo->proximo = nullptr;
	novo->valor = valor;
	
	if (atual == nullptr){
		topoRestrito = novo;
		return;
	}
	while (atual->proximo != nullptr){
		atual = atual->proximo;
	}
	atual->proximo = novo;
}

void display(No* topoRestrito){
	No* atual = topoRestrito;
	
	while (atual != nullptr){
		cout << "- " << atual->valor << endl;
		atual = atual->proximo;
	}
}

void displayLista(No* topoRestrito){
	No* atual = topoRestrito;
	
	while (atual != nullptr){
		cout << atual->valor;
		if (atual->proximo == nullptr){
			cout << " -> NULL";
		}else{
			cout << " -> ";
		}
		atual = atual->proximo;
	}
	cout << "\n\n";
}

void limpar_ponteiros(){
	No* temp;
	while (topo != nullptr){
		temp = topo;
		topo = topo->proximo;
		delete temp;
	}
	while (topo2 != nullptr){
		temp = topo2;
		topo2 = topo2->proximo;
		delete temp;
	}
	while (lista != nullptr){
		temp = lista;
		lista = lista->proximo;
		delete temp;
	}
	topo, topo2, lista = nullptr;
	cout << "Todos os ponteiros foram limpos!\n\n";	
}

// PROGRAMA PRINCIPAL
int main(){
	SetConsoleOutputCP(CP_UTF8);
	int opc, valor;
	
	while (true){
		system("cls");
		menu();
		opc = pegar_valor_numerico("Digite a Opção Desejada: ");
		
		switch(opc){
			case 1:
				exibir_header("CHEGADA DE LIVROS");
				valor = pegar_valor_numerico("Digite o código do livro OU '0' para voltar: ");
				if (valor == 0){
					continue;
				}
				if (verifica_valor_existe(valor)){
					cout << "\n[ERRO] -> Valor já cadastrado!\n";
					break;
				}
				if (size(topo) <= 2){
					push(topo, valor);
					cout << "\nLivro adicionado na PRIMEIRA estante!\n\n";
					break;
				}
				if (size(topo2) <= 2){
					push(topo2, valor);
					cout << "\nLivro adicionado na SEGUNDA estante!\n\n";
					break;
				}
				adicionar_lista(lista, valor);
				cout << "\nLivro adicionado na LISTA DE ESPERA!\n\n";
				break;
			case 2:
				exibir_header("RETIRADA DE LIVROS");
				valor = pegar_valor_numerico("Digite a prateleira que você gostaria de retirar [1 ou 2] OU '0' para voltar: ");
				if (valor == 0){
					continue;
				}
				if (valor == 1){
					if (isEmpty(topo)){
						cout << "[ERRO] -> Prateleira vazia!\n";
						break;
					}
					pop(topo);
					cout << "\nLivro removido da PRIMEIRA estante com sucesso!\n\n";
					if (isEmpty(lista)){
						break;
					}else{
						push(topo, lista->valor);
						pop(lista);
					}
					break;
				}if (valor == 2){
					if (isEmpty(topo2)){
						cout << "[ERRO] -> Prateleira vazia!\n";
						break;
					}
					pop(topo2);
					cout << "\nLivro removido da SEGUNDA estante com sucesso!\n\n";
					if (isEmpty(lista)){
						break;
					}else{
						push(topo2, lista->valor);
						pop(lista);
					}
					break;
				}
				cout << "\n[ERRO] -> Valor digitado fora do escopo fornecido!\n\n";
				break;
			case 3:
				exibir_header("VER CONTEÚDO NAS PRATELEIRAS");
				if (isEmpty(topo)){
					cout << "==== Prateleira [1] VAZIA! ====\n\n";
				}else{
					cout << "==== Prateleira [1]:\n";
					display(topo);
				}
				cout << "\n\n";
				if (isEmpty(topo2)){
					cout << "==== Prateleira [2] VAZIA! ====\n\n\n";
				}else{
					cout << "==== Prateleira [2]:\n";
					display(topo2);
				}
				cout << "\n\n";
				break;
			case 4:
				exibir_header("VER CONTEÚDO NA LISTA DE ESPERA");
				if (isEmpty(lista)){
					cout << "Não há itens na lista de espera\n\n";
					break;
				}else{
					displayLista(lista);
				}
				break;
			case 5:
				system("cls");
				limpar_ponteiros();
				cout << "Saindo....\n\n";
				return 0;
			default: 
				cout << "[ERRO] -> Opção fora do escopo!\n";
		}

		system("pause");
	}
	
	return 0;
}




