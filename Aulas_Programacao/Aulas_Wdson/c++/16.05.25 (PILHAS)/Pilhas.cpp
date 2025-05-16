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

//====== Implementação das funções da Pilha  ======//

void menu()
{
    cout << "\n===== Menu da Pilha =====\n\n";
    cout << "1. Push (Inserir elemento)\n";
    cout << "2. Pop (Remover elemento do topo)\n";
    cout << "3. Peek (Ver o topo)\n";
    cout << "4. Exibir Pilha\n";
    cout << "5. Size (Tamanho da Pilha)\n";
    cout << "6. Sair\n";
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
		
No* push(No* topo){
	int valor = pega_valor_inteiro("Digite o valor do nó\n");
	No* novoNo = new No;
	
	novoNo->valor = valor;
	novoNo->proximo = topo;
	return novoNo;
	
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

No* pop(No* topo){
	if (isEmpty(topo)){
		cout << "Pilha vazia!!" << endl;
		return nullptr;
	}
	
	No* temp = topo;
	No* novoTopo = topo->proximo;
	delete temp;
	return novoTopo;
	
}

int peek(No* topo){
		if (topo == nullptr){
		return -1;
	}
	return topo->valor;
}

void exibir_pilha(No* topo){
    if (isEmpty(topo)) {
    cout << "Pilha vazia!" << endl;
    return;
    }
    
    cout << "Elementos da pilha (Topo -> Base)" << endl;
    No* atual = topo;
    
    while (atual != nullptr){
    	cout << " - ";
    	cout << atual->valor << endl;
    	atual = atual->proximo;
	}
	cout << endl;
}

void size(No* topo){
	if (isEmpty(topo)) {
    cout << "Pilha vazia!" << endl;
    return;
    }
    
    int indice = 0;
    No* atual = topo;
    while (atual != nullptr){
    	indice +=1;
    	atual = atual->proximo;
	}
	cout << "O número total de itens na pilha é [" << indice << "]" << endl;
}

No* limpar_nos(No* topo){
	while (topo != nullptr){
		No* temp = topo;
		No* novoNo = topo->proximo;
		delete temp;
	}
	system("cls");
	return topo;
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
	
	No* topop = nullptr;
	
	
	while (true){
		
		system("cls");
		menu();
		int opt = pega_valor_inteiro("\nDigite a opção desejada\n");
		
		switch (opt){
			case 1:
				exibir_header("Inserir elemento");
				topop = push(topop);
				break;
			case 2:
				exibir_header("Remover elemento do topo");
				topop = pop(topop);
				break;
			case 3:
				exibir_header("Ver o topo");
				if (peek(topop) == -1){
					cout << "A lista está vazia!" << endl;
				}else{
				cout << "Topo: " << peek(topop) << endl;
				}
				break;
			case 4:
				exibir_header("Exibir pilha");
				exibir_pilha(topop);
				break;
			case 5:
				exibir_header("Tamanho da Pilha");
				size(topop);
				break;
			case 6:
				topop = limpar_nos(topop);
				cout << "Encerrando o programa..." << endl;
				return 0;
			default:
				cout << "Opção inválida!" << endl;
				break;
		}
		cout << "\n\n";
	system("pause");
	
}
	return 0;
}
