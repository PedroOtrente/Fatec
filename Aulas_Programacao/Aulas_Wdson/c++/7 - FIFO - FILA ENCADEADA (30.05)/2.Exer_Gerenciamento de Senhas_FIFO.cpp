#include <iomanip>
#include <Windows.h>
#include <iostream>

using namespace std;

struct No {
	int dado;
	No* proximo;
};

No* inicio = nullptr;
No* fim = nullptr;
int senhas_totais = 0;


void menu() {
    cout << "\n==== Menu de Operações da Fila ====\n";
    cout << "1. Gerar Nova Senha (Enfileirar)\n";
    cout << "2. Chamar Próximo Cliente (Desenfileirar)\n";
    cout << "3. Visualizar Próximo Cliente (Front)\n";
    cout << "4. Exibir Fila de Atendimento\n";
    cout << "5. Exibir o Último da Fila\n";
    cout << "6. Exibir o Número de Clientes\n";
    cout << "7. Exibir Senhas Já Atendidas\n";
    cout << "8. Sair\n";
}

// Pega e valida o valor do Nó
int pega_inteiro_positivo(string mensagem) {
    int valor;
    while (true) {
        cout << mensagem;
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nEntrada inválida !!\n";
            continue;
        }
        if (valor <= 0) { 
            cout << "\nValor não pode ser negativo ou zero\n";
            continue;
        }
        return valor; // Retorna a entrada válida
    }
}

bool isEmpty(){
	return inicio == nullptr;
}

int valida_opcao(int menor, int maior) {
    int op;
    while (true) {
        cout << "\nDigite a opção desejada : ";
        cin >> op;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nEntrada inválida: não aceita caracter !!\n";
            continue;
        }
        if (op >= menor && op <= maior) {
            return op; // retorna a opção válida
        } else {
            cout << "\nEntrada inválida: Digite um nro entre "
                 << menor << " e " << maior << "\n";
        }
    }
}

void enqueue(){
	senhas_totais += 1;
	No* novo = new No();
	novo->dado = senhas_totais;
	novo->proximo = nullptr;
	if (isEmpty()) {
        inicio = novo;
		fim = novo;
    }else {
        fim->proximo = novo;
        fim = novo;
    }
    cout << "Senha Inserida: " << senhas_totais << endl;
}

void exibir_header(string mensagem){
	system("cls");
	cout << "--------------------------------------" << endl;
	cout << mensagem << endl;
	cout << "--------------------------------------" << endl;
	cout << "\n";
}

void dequeue(){
	if (isEmpty()) {
        cout << "A fila está vazia!" << endl;
        return;
    }
    No* temp = inicio;
    inicio = inicio->proximo;
    cout << "Senha Atendida: " << temp->dado << endl;
    delete temp;
    
    if (inicio ==nullptr){
    	fim = nullptr;
	}
    
}

void front(){
    if (isEmpty()) {
	    cout << "Fila vazia!" << endl;
	    return;
	}
	cout << "Próxima Senha: " << inicio->dado << endl;
}

void exibirFila(){
	No* atual = inicio;
	cout << "\n=== Fila Atual ===\n";
	if (atual == nullptr){
		cout << "Fila Vazia!\n";
		return;
	}
	while (atual != nullptr){
		cout << atual->dado;
		if (atual->proximo != nullptr){
			cout << " -> ";
		}else{
			cout << " -> NULL";
		}
		atual = atual->proximo;
	}
	cout << endl;
}

void exibirUltimoFila(){
	if (isEmpty()) {
	    cout << "Fila vazia!" << endl;
	    return;
	}
	cout << "Último: " << fim->dado << endl;
}

void size(){
	No* atual = inicio;
	int total = 0;
	
	if (atual == nullptr){
		cout << "Fila Vazia!\n";
		return;
	}
	while (atual != nullptr){
		total += 1;
		atual = atual->proximo;
	}
	cout << "O Número Total de Clientes na Fila é: " << total << endl;
}

void senhasJaAtendidas() {
    if (senhas_totais == 0) {
        cout << "Ainda nenhuma senha foi cadastrada\n";
        return;
    }

    int atual;

    if (inicio == nullptr) {
        atual = senhas_totais;
    } else {
        if (inicio->dado == 1) {
            cout << "Ainda ninguém foi atendido\n";
            return;
        }
        atual = inicio->dado - 1;  
    }

    cout << "\n=== CLIENTES JÁ ATENDIDOS ===\n";
    for (int i = 1; i <= atual; i++) {
        cout << i;
        if (i < atual) cout << ", ";
    }
    cout << "\n\n";
}

// INÍCIO DO PROGRAMA PRINCIPAL
int main(){
	SetConsoleOutputCP(CP_UTF8);
	int opc, valor;
	while (true){
		menu();
		opc = valida_opcao(1, 8);
		if (opc == 8){
			system("cls");
			break;
		}
		switch (opc) {
			case 1:
				exibir_header("Gerar Nova Senha");
				enqueue();
				break;	
			case 2:
				exibir_header("Chamar Próximo Cliente");
				dequeue();
				break;
			case 3:
				exibir_header("Visualizar Próximo Cliente ");
				front();
				break;
			case 4:
				exibir_header("Exibir fila de Atendimento");
				exibirFila();
				break;
			case 5:
				exibir_header("Exibir o Último da fila");
				exibirUltimoFila();
				break;
			case 6:
				exibir_header("Exibir o Número de Clientes na Fila");
				size();
				break;
			case 7:
				exibir_header("Exibir as Senhas já Atendidas");
				senhasJaAtendidas();
				break;
		}
		system("pause");
		system("cls");
	}
	
	if (inicio != nullptr){
		No* atual = inicio;
		No* proximo;
		
		while (atual != nullptr){
			proximo = atual->proximo;
			delete atual;
			atual = proximo;
		}
		cout << "Todos os nós da fila foram deletados\n\n";
	}
	
	inicio = nullptr;
	fim = nullptr;
	
	return 0;
}