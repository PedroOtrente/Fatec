#include <iostream>
#include <windows.h>
 
using namespace std;
 
struct No{
	int valor;
	No* proximo;
};
 
No* first = nullptr;
 
void exibir_header(string text){
	system("cls");
	cout<< "---------------------" << endl;
	cout<< text << endl;
	cout<< "---------------------" << endl << endl;
}
 
void exibir_menu(){
	cout << "1. Inserir na Sequência (final)" << endl;
	cout << "2. Inserir no Início" << endl;
	cout << "3. Inserir após um nó específico" << endl;
	cout << "4. Remover Nó" << endl;
	cout << "5. Exibir Lista" << endl;
	cout << "6. Sair" << endl << endl;
}
 
double pegar_valor(string mensagem){
	double valor;
	while(true){
		cout << mensagem;
		cin >> valor;
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "Entrada inválida !!" << endl << endl;
			continue;
		}
		if (valor < 0){
			cout << "Valor não pode ser negativo" << endl << endl;
			continue;
		}
		return valor;
	}
}
 
void exibir_nos(){
	No* atual = first;
    exibir_header("Lista Encadeada");
    while (atual != nullptr) 
	{
    	cout << "- "<< atual->valor << endl;
    	atual = atual->proximo;
	}   
    cout << endl;
}
 
bool verificar_existencia(int valor){
	if (first != nullptr){
		No* atual = first;
		while (atual != nullptr){
			if(atual->valor == valor){
				return false;
			}
			atual=atual->proximo;
		}
		return true;
	}
	return true;
}
 
void excluir_no(int valor){
	No* atual = first;
	No* anterior = nullptr;
	while (atual != nullptr){
		if(atual->valor == valor){
			if (atual==first){
				first = atual->proximo;
				delete atual;
			}else if (atual->proximo == nullptr){
				anterior->proximo = nullptr;
				delete atual;
			}else{
				anterior->proximo = atual->proximo;
				delete atual;
			}
			exibir_header("Valor excluido com sucesso!");
			break;
		}
		anterior = atual;
		atual = atual->proximo;
	}
}
 
No* criar_no(int valor){
	No* newNo = new No;
	newNo->valor = valor;
	newNo->proximo = nullptr;
	return newNo;
}
 
void encadear_no_final(No* newNo){
	No* atual = first;
	if (atual != nullptr){
		while(atual->proximo != nullptr){
			atual = atual->proximo;
		}
		atual->proximo = newNo;
	}else{
		first = newNo;
	}
}
 
void encadear_no_inicio(No* newNo){
	No* atual = first;
	if (atual != nullptr){
		newNo->proximo = first;
	}
	first = newNo;
}
 
void encadear_no(No* newNo, int anterior){
	No* atual = first;
	while (atual->valor != anterior){
		atual = atual->proximo;
	}
	newNo->proximo = atual->proximo;
	atual->proximo = newNo;
}
 
int main(){
	SetConsoleOutputCP(CP_UTF8);
	int opt, valor, anterior;
	do{
		exibir_header("Lista Encadeada");
		exibir_menu();
		cout << "O que deseja fazer?" << endl;
		cin >> opt;
		if (opt == 6){
			break;
		}
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			exibir_header("Entrada Inválida");
			system("pause");
			continue;
		}
		switch(opt){
			case 1:
				exibir_header("Cadastrar Valor no Final!");
				valor = pegar_valor("Informe o Valor: ");
				if(verificar_existencia(valor)){
					encadear_no_final(criar_no(valor));
					exibir_header("Nó criado com sucesso!");
				}else{
					exibir_header("Valor já Cadastrado!");
				}
				system("pause");
				break;
			case 2:
				exibir_header("Cadastrar Valor no Início!");
				valor = pegar_valor("Informe o Valor: ");
				if(verificar_existencia(valor)){
					encadear_no_inicio(criar_no(valor));
					exibir_header("Nó criado com sucesso!");
				}else{
					exibir_header("Valor já Cadastrado!");
				}
				system("pause");
				break;
			case 3:
				if (first != nullptr){
					exibir_header("Cadastrar Valor após Outro Valor!");
					valor = pegar_valor("Informe o Valor a ser inserido: ");
					anterior = pegar_valor("Informe o Valor Anterior ao Nó Cadastrado: ");
					if(!verificar_existencia(anterior)){
						if(verificar_existencia(valor)){
							encadear_no(criar_no(valor),anterior);
							exibir_header("Nó criado com sucesso!");
						}else{
							exibir_header("Valor já Cadastrado!");
						}
					}else{
						exibir_header("Valor Anterior não Encontrado!");
					}
				}else{
					exibir_header("Nenhum nó Cadastrado!");
				}
				system("pause");
				break;
			case 4:
				if (first != nullptr){
					exibir_header("Excluir Valor!");
					valor = pegar_valor("Informe o Valor: ");
					if(!verificar_existencia(valor)){
						excluir_no(valor);
					}else{
						exibir_header("Valor não Encontrado!");
					}
				}else{
					exibir_header("Nenhum nó Cadastrado!");
				}
				system("pause");
				break;
			case 5:
				if (first != nullptr){
					exibir_nos();
				}else{
					exibir_header("Nenhum nó Cadastrado!");
				}
				system("pause");
				break;
			default: 
				exibir_header("Opção Inválida!");
				system("pause");
		}
	}while (true);
 
	exibir_header("Adeus, volte logo!");
	system("pause");
	return 0;
}