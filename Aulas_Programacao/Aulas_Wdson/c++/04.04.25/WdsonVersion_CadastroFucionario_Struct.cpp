#include <iostream>
#include <iomanip>
#include <Windows.h>


using namespace std;

struct registro{
	string nome;
	int codigo;
	int idade;
	float salario;
};


// Declarar variáveis globais
const int maxfunc=3;
registro func[maxfunc];
int nrofunc = 0, codigo_automatico=0;


// Funções
void menu(){
	cout << "\n === Menu de Opções ===\n\n";
	cout << "1. Cadastrar Funcionário\n2. Consultar Funcionário\n3. Remover Funcionário\n4. Listar todos os Funcionários\n5. Sair\n";
}

float pega_valor(string mensagem){
	float valor;
	while(true){
		cout << mensagem;
		cin >> valor;
		if(cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "Valor Inválido";
			continue;
		}
		if (valor > 0){
			return valor;
		}else{
			cout << "Valor não pode ser negativo";
		}
	}
}

void consultar_func(int codigof){
	bool achou = false;
	
	for (int i=0;i<nrofunc;i++){
		if (func[i].codigo == codigof){
			cout << "\nInformações do funionário\n";
			cout << setw(10) << left << "Código" << setw(20) << left << "Nome" << setw(10) << left << "Idade"
			<< setw(15) << left << "Salário (R$)\n";
			
			cout << setw(10) << left << func[i].codigo << setw(20) << left << func[i].nome << setw(10) << left << func[i].idade
			<< setw(15) << left << fixed << setprecision(2) << func[i].salario << endl;
			achou = true;	
			break;
		}	
	}
	if (!achou){
		cout << "\nFuncionário não encontrado\n";
	}
}

void remover_func(int codigof){
	bool achou = false;
	for (int i=0;i<nrofunc;i++){
			if (func[i].codigo == codigof){
				for (int j=i; j < nrofunc-1;j++){
					func[j] = func[j+1];
				}
				nrofunc--;
				achou = true;
				cout << "\nFuncionário removido com sucesso\n";
				break;
			}
	}
	if (!achou){
		cout << "\nFuncionário não encontrado!" << endl;
	}
	
}

void listar_func(){
	
	cout << "\nListagem de todos os funcionários\n";
			cout << setw(10) << left << "Código" << setw(20) << left << "Nome" << setw(10) << left << "Idade"
			<< setw(15) << left << "Salário (R$)\n";
	
		for (int i=0;i<nrofunc;i++){
		cout << setw(10) << left << func[i].codigo << setw(20) << left << func[i].nome << setw(10) << left << func[i].idade
		<< setw(15) << left << fixed << setprecision(2) << func[i].salario << endl;
	}
}

void adicionar_func(){
	cout << "Inserir informações do funcionário --> (" << nrofunc+1 << ")" << endl;
	while(true){
		cout << "Nome: ";
		cin.ignore();
		getline(cin,func[nrofunc].nome);
		if (!func[nrofunc].nome.empty()){
			break;
		}else{
			cout << "\nNome não pode ser vazio\n";
		}
	}
	codigo_automatico += 1;
	func[nrofunc].idade = pega_valor("Digite a idade: ");
	func[nrofunc].codigo = codigo_automatico;
	func[nrofunc].salario = pega_valor("Digite o salario: ");
	nrofunc++;
	cout << "\nFuncionário foi cadastrado com sucesso\n";
}


int main(){
	SetConsoleOutputCP(CP_UTF8);
	int op, codigof;
	while(true){
		system("cls");
		menu();
		cout << "\nDigite a opção desejada: \n";
		cin >> op;
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\nOperação Inválida\n";
			system("pause");
			continue;
		}
		
		if (op==5){
			system("cls");
			break;
		}
		switch (op){
			case 1:
				if (nrofunc < maxfunc){
					adicionar_func();
				}else{
					cout << "\nLimite máximo de funcionários foi atingido!\n";
				}
				break;
			case 2:
				if (nrofunc > 0){
					codigof = pega_valor("Digite o código para consulta --> ");
					consultar_func(codigof);
				}else{
					cout << "\nNão existe funcionários cadastrados\n";
				}
				break;
			case 3:
				if (nrofunc > 0){
				codigof = pega_valor("Digite o código do funcionário para a remoção --> ");
				remover_func(codigof);
				}else{
					cout << "\nNão existe funcionários cadastrados\n";
				}
				break;
			case 4:
				if (nrofunc > 0){
					listar_func();
				}
				else{
					cout << "Não existem funcinários cadastrado.";
				}
				break;
			default:
				cout << "Opção inválida!";
				continue;
		}
		system("pause");
	}
	
	
	return 0;
}