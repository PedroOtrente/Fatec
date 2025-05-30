/* Conceito de Filas encadeadas */

/*Uma Fila Encadeada é uma estrutura de dados 
dinâmica que segue o princípio FIFO (First-In, 
First-Out), ou seja, "Primeiro a Entrar, 
Primeiro a Sair". 

1.Fila Dinâmica: Usa ponteiros para criar e
remover elementos dinamicamente.
2. Controle do Início e do Fim: inicio aponta
para o primeiro elemento e fim para o último.
3. Eficiência: As operações de inserção e remoção
são rápidas, pois não há realocação de memória.*/

/*Exemplos de uso:

-Controle de documentos para impressão.
-Troca de mensagens entre computadores em uma rede.
-Sistemas de agendamento.
-Operações internas de sistemas operacionais.
-Políticas de cache.*/

#include <iostream>
#include <Windows.h> 

using namespace std;

// Estrutura do Nó
struct No {
    int dado;
    No* proximo;
};

No* inicio = nullptr;
No* fim = nullptr;

// Menu de opções
void menu() {
    cout << "\n==== Menu de Operações da Fila ====\n";
    cout << "1. Enfileirar (Enqueue)\n";
    cout << "2. Desenfileirar (Dequeue)\n";
    cout << "3. Exibir Primeiro Elemento (Front)\n";
    cout << "4. Exibir Fila\n";
    cout << "5. Sair\n";
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

// Valida a opção digitada 
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

// Verifica se a fila está vazia
bool isEmpty() {
    return inicio == nullptr;
}

// Insere um elemento na fila
void enqueue(int valor) {
    No* novo = new No();
    novo->dado = valor;
    novo->proximo = nullptr;

    if (isEmpty()) {
        inicio = novo;
		fim = novo;
    } else {
        fim->proximo = novo;
        fim = novo;
    }
    cout << "Inserido: " << valor << endl;
}

// Remove um elemento da fila
void dequeue() {
    if (isEmpty()) {
        cout << "Erro: Fila vazia!" << endl;
        return;
    }
    No* temp = inicio;
    inicio = inicio->proximo;
    cout << "Removido: " << temp->dado << endl;
    delete temp;

    if (inicio == nullptr) {
        fim = nullptr;
    }
}

// Exibe o primeiro elemento
void front() {
    if (isEmpty()) {
        cout << "Fila vazia!" << endl;
        return;
    }
    cout << "Primeiro elemento: " << inicio->dado << endl;
}

// Exibe todos os elementos da fila 
void exibirFila() {
    No* atual = inicio;
    cout << "\n<<<< Fila Atual >>>\n";
    if (atual == nullptr) {
        cout << "Fila vazia.\n";
        return;
    }
    while (atual != nullptr) {
        cout << atual->dado;
        if (atual->proximo != nullptr) {
            cout << " -> ";
        } else {
            cout << " -> NULL";
        }
        atual = atual->proximo;
    }
    cout << endl;
}

// Programa principal //

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int opcao, valor;
    while(true)
	{
        menu();
        opcao = valida_opcao(1,5); // Opções são de 1 a 5
		if (opcao == 5){		
			system("cls");
			break;
	    }			
        switch (opcao) {
            case 1: // Enfileirar
                valor = pega_inteiro_positivo("Digite o valor a ser enfileirado ou 0 para voltar: ");
                if (valor == 0){
                	system("cls");
                	continue;
				}
				enqueue(valor);
                break;
            case 2: // Desenfileirar
                dequeue();
                break;
            case 3: // Exibir Primeiro Elemento
                front();
                break;
            case 4: // Exibir Fila
                exibirFila();
                break;
        }
    }

    // Limpar a memória alocada para a fila (boa prática)
    if (inicio != nullptr) {
        No* atual = inicio;
        No* proximo;
        while (atual != nullptr) {
            proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
        cout << "Todos os nós da fila foram deletados. Fila vazia !!\n";
    }
    inicio = nullptr;
    fim = nullptr;
    return 0;
}