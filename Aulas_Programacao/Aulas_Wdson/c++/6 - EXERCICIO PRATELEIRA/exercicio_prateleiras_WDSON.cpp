#include <iostream>
#include <Windows.h>

using namespace std;

//====== Estrutura do Nó ====== //
struct No
{
    int codigo;
    No* proximo;
};

// Codigo do livro a ser removido da espera e empilhado
int codigo_espera=0;

//====== Implementação das funções da Pilha  ======//

// Menu de opções 
void menu()
{
    cout << "\n===== Organizador de Livros em Prateleiras =====\n\n";
    cout << "1. Chegada de Livro (Empilhar)\n";
    cout << "2. Retirar Livro (Escolher Prateleira)\n";
    cout << "3. Ver Conteúdo das Prateleiras\n";
    cout << "4. Ver Conteúdo da lista de espera\n";
    cout << "5. Sair\n";
}

// Verifica se a pilha está vazia
bool isEmpty(No* topo)
{
    return (topo == nullptr);
}

// Criar e adiciona um elemento na pilha (push)
// Retorna o novo topo da pilha
No* push(No* topo, int codigo)
{
    No* novoNo = new No;
    novoNo->codigo = codigo;
    novoNo->proximo = topo;
    return novoNo;
}

// Remove o elemento do topo da pilha (pop)
// Retorna o novo topo da pilha
No* pop(No* topo)
{
    if (isEmpty(topo))
    {
        cout << "Pilha vazia! Não existe livros para remover." << endl;
        return nullptr; // Retorna nullptr se a pilha estiver vazia
    }
    No* temp = topo;
    No* novoTopo = topo->proximo;
    cout << "Livro " << temp->codigo << " removido do topo." << endl;
    delete temp;
    return novoTopo;
}

// Exibe todos os elementos da pilha (do topo para a base)
void displayPilha(No* topo, string nomePilha) 
{
    cout << "\n--- Conteúdo da " << nomePilha << " (TOPO -> BASE) ---\n";
    if (isEmpty(topo))
    {
        cout << "[ Vazia ]\n";
        return;
    }
    No* atual = topo;
    while (atual != nullptr)
    {
        cout << "Livro: " << atual->codigo << "\n"; 
        atual = atual->proximo;
    }
    cout << "-----------\n"; 
}

// Calcula tamanho da pilha
int size(No* topo)
{
    int count = 0;
    No* atual = topo;
    while (atual != nullptr){
        count++;
        atual = atual->proximo;
    }
    return count;
}

// lê e valida um valor //
int le_valida_valor(string mensagem)
{
	int valor;
	while(true){
		cout << mensagem;
		cin >> valor;
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\nEntrada inválida: não aceita caracter !!\n";
			continue;
		}
		if (valor < 0){
			cout << "\nEntrada inválida: valor não pode ser negativo\n";
			continue;
		}
		return valor;		
	}
}

// Valida a opção digitada //
int le_valida_opcao(int menor,int maior)
{
	int op;
	while(true)
	{
		cout << "\nDigite a opção desejada : ";
		cin >> op;
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\nEntrada inválida: não aceita caracter !!\n";
			continue;
		}
		if (op >= menor and op <= maior){
			return op; // retorna a opção válida
		}
		else{
			cout << "\nEntrada inválida: Digite um nro entre " 
			     << menor << " e " << maior << "\n";	
		}
	}
}

// Verifica código repetido
bool verifica_repetido(No* prateleira1, No* prateleira2, int codigoLivro) 
{
    bool achou = false; // indica se o livro foi encontrado
    // Verifica a prateleira 1
    No* atual = prateleira1;
    while (atual != nullptr) {
        if (atual->codigo == codigoLivro) {
            achou = true;
            break; // Sai do loop da prateleira 1 assim que encontrar
        }
        atual = atual->proximo;
    }

    // Se não achou na prateleira 1, verifica a prateleira 2
    if (!achou) { // Só verifica a segunda se não achou na primeira
        atual = prateleira2; 
        while (atual != nullptr) {
            if (atual->codigo == codigoLivro) {
                achou = true;
                break; // Sai do loop da prateleira 2 assim que encontrar
            }
            atual = atual->proximo;
        }
    }    
    // Retorna true se achou em qualquer prateleira, false caso contrário
    return achou; 
}

// Criar um novo nó (lista de espera)
No* criarNo(int valor){
    No* novoNo = new No;
    novoNo->codigo = valor;
    novoNo->proximo = nullptr;
    return novoNo;
}

// Inserir um livro na lista de espera
void inseri_lista_espera(No* cabeca, int codigoLivro){
    No* atual = cabeca;
    while (atual->proximo != nullptr){
        atual = atual->proximo;
    }
    atual->proximo = criarNo(codigoLivro);    
}

// Exibir a lista encadeada
void exibirLista(No* cabeca){
    No* atual = cabeca;
    cout << "\n<<<< Lista de Espera >>>\n";
    if (atual == nullptr) {
        cout << "Lista vazia\n";
        return;
    }
    while (atual != nullptr)
    {
        cout << atual->codigo;
        if (atual->proximo != nullptr) {
            cout << " -> ";
        }
        else {
            cout << " -> NULL";
        }
        atual = atual->proximo;
    }
    cout << endl;
}

// Remover um livro da lista de espera
No* remover_no(No* cabeca)
{
	if (cabeca == nullptr){
		return 0;
	}
	else{
		No* temp = cabeca;
		codigo_espera = cabeca->codigo;
        cabeca = cabeca->proximo;
        delete temp;  
		return cabeca;	
	}
}

/*======= Programa Principal =====*/

int main()
{
    SetConsoleOutputCP(CP_UTF8);
	// Pilha para a Prateleira 1
    No* prateleira1 = nullptr;     
    // Pilha para a Prateleira 2
    No* prateleira2 = nullptr;     
    // Lista de espera
    No* cabeca = nullptr;
	// Capacidade máxima de cada prateleira
    const int capacidade_prateleira = 2; 
    int opcao,codigoLivro,escolhaPrateleira,cod;

    while(true)
    {    	
	    menu(); 
        opcao = le_valida_opcao(1,5); 	    
        if (opcao == 5) // Opção Sair
        {
 	    	cout << "Saindo do programa. Liberando memoria..." << endl;
            while (!isEmpty(prateleira1)) {
                No* temp = prateleira1;
                prateleira1 = prateleira1->proximo;
                delete temp;
            }
            while (!isEmpty(prateleira2)) {
                No* temp = prateleira2;
                prateleira2 = prateleira2->proximo;
                delete temp;
            }
 	    	system("cls"); 
 	    	break; 
	    }
        switch (opcao)
        {
            case 1: // Chegada de Livro (Empilhar Inteligente)
                codigoLivro = le_valida_valor("Digite o código do livro ou '0' para voltar : ");  
                if (codigoLivro==0){
                	system("cls");
                	continue;
				}
				if (verifica_repetido(prateleira1,prateleira2,codigoLivro)){
					cout << "\nCódigo do livro já existe na pilha\n";
					system("pause"); 
        			system("cls");
					continue; 
				}      
                // Tenta empilhar na prateleira 1
                if (size(prateleira1) < capacidade_prateleira ){
                    prateleira1 = push(prateleira1, codigoLivro);
                    cout << "Livro " << codigoLivro << " empilhado na Prateleira 1." << endl;
                }
                // Se a prateleira 1 estiver cheia, tenta a prateleira 2
                else 
					if (size(prateleira2) < capacidade_prateleira ){
                    	prateleira2 = push(prateleira2, codigoLivro);
                    	cout << "Livro " << codigoLivro << " empilhado na Prateleira 2." << endl;
                	}
                	// Se ambas estiverem cheias
                	else{
                    	cout << "Ambas as prateleiras estão lotadas! Não é possivel empilhar o livro " 
						     << codigoLivro << "." << endl;
						// inserir na lista de espera
						if (cabeca == nullptr) {
        					cabeca = criarNo(codigoLivro);
    					} 
    					else{
    						inseri_lista_espera(cabeca,codigoLivro);
						}
						cout << "\nLivro " << codigoLivro << " inserido na lista de espera\n";
                	}
                break;
            case 2: // Retirar Livro (Escolher Prateleira)
                escolhaPrateleira = le_valida_valor("De qual prateleira deseja retirar o livro? (1 ou 2/ ou 0 para voltar): "); 
				if (escolhaPrateleira == 0){
                	system("cls");
                	continue;	
				}               
                // Valida a escolha da prateleira
                while (escolhaPrateleira != 1 && escolhaPrateleira != 2) {
                    cout << "Escolha inválida. Digite 1 ou 2: ";
                    escolhaPrateleira = le_valida_valor("");
                }
                // escolhe a prateleira!
                if (escolhaPrateleira == 1){
                    prateleira1 = pop(prateleira1);
                    cabeca = remover_no(cabeca);
                    if (codigo_espera>0){
                    	prateleira1 = push(prateleira1, codigo_espera);
                    	cout << "\nLivro " << codigo_espera << " empilhado na Prateleira 1\n";
                    	codigo_espera = 0;
					}
                }
                else{
                    prateleira2 = pop(prateleira2);
                    cabeca = remover_no(cabeca);
                    if (codigo_espera>0){
                    	prateleira2 = push(prateleira2, codigo_espera);
                    	cout << "\nLivro " << codigo_espera << " empilhado na Prateleira 2\n";
                    	codigo_espera = 0;
					}
                }
                break;
            case 3: // Ver Conteudo das Prateleiras
            	system("cls");
                displayPilha(prateleira1, ">> Prateleira 1 <<");
                displayPilha(prateleira2, ">> Prateleira 2 <<");
                break;
            case 4: // Ver lista de espera
            	system("cls");
            	exibirLista(cabeca);
            	break;            	
        }
        cout << "\n";
        system("pause"); 
        system("cls");   
    }
    return 0;
}