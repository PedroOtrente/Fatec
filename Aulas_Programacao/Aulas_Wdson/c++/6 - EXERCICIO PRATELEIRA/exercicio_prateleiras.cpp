#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;
//====== Estrutura do Nó (Apenas um inteiro) ====== //
struct No
{
    int valor;
    No* proximo;
};
	No* topop = nullptr;
	No* topop2 = nullptr;
	No* Lista = nullptr;
//====== Implementação das funções da Pilha  ======//
void menu()
{
    cout << "\n===== Menu da Pilha =====\n\n";
    cout << "1. Chegada de Livros\n";
    cout << "2. Retirar Livro\n";
    cout << "3. Ver Conteúdo das Prateleiras\n";
    cout << "4. Sair\n";
}
bool verifica_valor_existente(int valor){
	No* atual;
 
	atual = topop;
	while (atual != nullptr){
		if  (atual->valor == valor){
			return true;
		}
		atual = atual->proximo;
	}
 
	atual = topop2;
	while (atual != nullptr){
		if  (atual->valor == valor){
			return true;
	}
		atual = atual->proximo;
	}

	atual = Lista;
	while (atual != nullptr){
		if (atual->valor == valor){
			return true;
		}
		atual = atual->proximo;
	}
	return false;
}

double pega_valor_inteiro(string mensagem){
	int valor;
	No* topop = nullptr;
	while (true){
		cout << mensagem;
		cin >> valor;
		if(cin.fail()){
			cout << "Digite um número válido!\n";
			cin.clear();
			cin.ignore(100,'\n');
			system("pause");
			continue;
		}
		return valor;
	}
}
int push(){
	int valor = pega_valor_inteiro("Digite o código do livro\n");
	bool verificacao = verifica_valor_existente(valor);
	if (verificacao == true){
		cout << "Não foi possível adicionar o livro. Código já cadastrado!\n";
		return 0;
	}
	No* novoNo = new No;
 
	int indice = 0;
    No* atual = topop;
    while (atual != nullptr){
    	indice +=1;
    	atual = atual->proximo;
	}
 
	if (indice < 2){
	novoNo->valor = valor;
	novoNo->proximo = topop;
	topop = novoNo;
	cout << "Livro adicionado na 1° fila!\n";
	topop = novoNo;
	return 0;
	}
	indice = 0;
    atual = topop2;
    while (atual != nullptr){
    	indice +=1;
    	atual = atual->proximo;
	}
	if (indice < 2){
	novoNo->valor = valor;
	novoNo->proximo = topop2;
	topop2 = novoNo;
	cout << "Livro adicionado na 2° fila!\n";
	return 0;
	}
	atual = Lista;
	novoNo->valor = valor;
	novoNo->proximo = nullptr;
	if (Lista == nullptr){
		Lista = novoNo;
	}else{
	while (atual != nullptr){
		if (atual->proximo == nullptr) {
			atual->proximo = novoNo;
			break;
		}
		atual = atual->proximo;
	}
	}
	cout << "Prateleiras cheias! Livro adicionado na fila de espera\n";
	return 0;
}
bool isEmpty(No* topo){
	bool vazia;
	if (topo == nullptr){
		vazia = true;
	}else{
		vazia = false;
	}
	return vazia;
}
int pop(){
	int valor = pega_valor_inteiro("De qual prateleira você gostaria de retirar? [1 ou 2]\n");
	if (valor != 1 && valor != 2){
		cout << "Opção não disponível!\n";
		return 0;	
	}
	if (valor == 1){
		if (isEmpty(topop)){
			cout << "Pilha vazia!!" << endl;
			return 0;
		}else{
			No* temp = topop;
			No* novoTopo = topop->proximo;
			delete temp;
			topop = novoTopo;
			cout << "Livro retirado da prateleira 1 com sucesso!\n";
		if (isEmpty(Lista)){
				return 0;
			}else{
				No* novoNo = new No;
				novoNo->valor = Lista->valor;
				novoNo->proximo = topop;
				topop = novoNo;
				No* temp = Lista;
				No* novoInicio = Lista->proximo;
				delete temp;
				Lista = novoInicio;
				return 0;
			}
		}
	}
	if (valor == 2){
		if (isEmpty(topop2)){
			cout << "Pilha vazia!!" << endl;
			return 0;
		}else{
			No* temp = topop2;
			No* novoTopo = topop2->proximo;
			delete temp;
			topop2 = novoTopo;
			cout << "Livro retirado da prateleira 2 com sucesso!\n";
		if (isEmpty(Lista)){
				return 0;
			}else{
				No* novoNo = new No;
				novoNo->valor = Lista->valor;
				novoNo->proximo = topop2;
				topop2 = novoNo;
				No* temp = Lista;
				No* novoInicio = Lista->proximo;
				delete temp;
				Lista = novoInicio;
				return 0;
			}
		}
	}
}
void exibir_pilha(){
    if (isEmpty(topop)) {
    cout << "Pilha 1 vazia!" << endl;
    }else{
    cout << "Elementos da pilha 1 (Topo -> Base)" << endl;
    No* atual = topop;
    while (atual != nullptr){
    	cout << " - ";
    	cout << atual->valor << endl;
    	atual = atual->proximo;
	}
	cout << endl;
	}
 
	if (isEmpty(topop2)) {
    cout << "Pilha 2 vazia!" << endl;
    }else{
	cout << "Elementos da pilha 2 (Topo -> Base)" << endl;
    No* atual = topop2;
        while (atual != nullptr){
    	cout << " - ";
    	cout << atual->valor << endl;
    	atual = atual->proximo;
	}
	cout << endl;
	}
 
	if (isEmpty(Lista)){
		cout << "Lista de espera vazia!" << endl;
	}else{
	cout << "Elementos na fila de espera\n";
	No* atual = Lista;
	while (atual != nullptr){
    	cout << atual->valor;
    	if (atual->proximo != nullptr){
    		cout << " -> ";
		}else{
			cout << " -> NULL";
		}
    	atual = atual->proximo;
	}
	cout << endl;
	}
}

int limpar_nos(){
	while (topop != nullptr){
		No* temp = topop;
		No* novoNo = topop->proximo;
		delete temp;
	}
	while (topop2 != nullptr){
		No* temp = topop2;
		No* novoNo = topop2->proximo;
		delete temp;
}
	while (Lista != nullptr){
		No* temp = Lista;
		No* novoNo = Lista->proximo;
		delete temp;
	}
	system("cls");
	return 0;
}
void exibir_header(string mensagem){
	system("cls");
	cout << "--------------------------------------" << endl;
	cout << mensagem << endl;
	cout << "--------------------------------------" << endl;
	cout << "\n";
}

 
int main(){
	SetConsoleOutputCP(CP_UTF8);
	while (true){
		system("cls");
		menu();
		int opt = pega_valor_inteiro("\nDigite a opção desejada\n");
		switch (opt){
			case 1:
				exibir_header("Chegada de Livros");
				push();
				break;
			case 2:
				exibir_header("Retirar Livro");
				pop();
				break;
			case 3:
				exibir_header("Exibir pilhas");
				exibir_pilha();
				break;
			case 4:
				limpar_nos();
				cout << "Encerrando o programa..." << endl;
				return 0;
			default:
				cout << "Opção inválida!" << endl;
				break;
		}
		cout << "\n\n";
	system("pause");
	system("cls");
}
	return 0;
}