#include <iomanip>
#include <iostream>
#include <Windows.h>

using namespace std;

// STRUCT
struct ContaBancaria{
	int nro_conta;
	string nome_cliente;
	double saldo;
	
};

// DECLARAÇÃO DE VARIÁVEIS GLOBAIS
const int totalContas = 3;
ContaBancaria contas[totalContas];
int nroAtual = 0, codigo=0;


// FUNÇÕES

void menu(){
	cout << "===========================" << endl;
	cout << setw(20) << right << "MENU PRINCIPAL" << endl;
	cout << "===========================" << endl << endl;
	cout << "1. Cadastrar Conta\n2. Excluir Conta\n3. Consultar Conta\n4. Visualizar todas as Contas\n5. Realizar Saque\n6. Realizar Depósito\n7. Sair\n" << endl;
}


float pega_valor(string mensagem){
	float valor;
	
	while (true){
		cout << mensagem;
		cin >> valor;
		
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			system("cls");
			cout << "\n❌ ERRO -- > Digite apenas números" << endl;
			cout << "-------------------------------------" << "\n\n\n\n\n";
			system("pause");
			continue;
		}
		
		if (valor < 0){
			system("cls");
			cout << "❌ ERRO -- > Valor não pode ser negativo" << endl;
			cout << "-------------------------------------" << "\n\n\n\n\n";
			system("pause");
			continue;
		}
		break;
	}
	return valor;
}

string pega_string(string mensagem){
	string nome;

	cin.ignore();
		
	while (true){
	
	cout << mensagem;
	getline(cin,nome);
	
	if (cin.fail()){
		cin.clear();
		cin.ignore(100,'\n');
		cout << "Entrada Inválida!" << endl;
		system("pause");
		continue;
	}
	if (nome.empty()){
		system("cls");
		cout << "\n❌ ERRO -- > Nome não pode ser vazio!" << endl; 
		cout << "-------------------------------------" << "\n\n\n\n\n";
		system("pause");
		continue;
	}
		break;
	
	}
	return nome;
}

void cadastrar_conta(){
	system("cls");
	cout << "===========================" << endl;
	cout << setw(20) << right << "Criar Conta"<< endl;
	cout << "===========================" << endl;
	
	cout << endl << "Digite as informações da conta número [" << nroAtual+1 << "]" << endl << endl;
	contas[nroAtual].nome_cliente = pega_string("Nome --> ");
	contas[nroAtual].saldo = pega_valor("Saldo inicial da conta --> ");
	
	codigo++;
	contas[nroAtual].nro_conta = codigo;
	
	system("cls");
	cout << "✅ Conta cadastrada com sucesso!" << endl;
	cout << "-------------------------------------" << "\n\n\n\n\n";
	system("pause");
	
	nroAtual++;
}

void consultar_conta(){
	int codigoConta;
	bool achou = false;
	
	system("cls");
	cout << "===========================" << endl;
	cout << setw(20) << right << "Consultar Conta"<< endl;
	cout << "===========================" << endl;
	cout << "\n";
	
	codigoConta = pega_valor("Qual o código da conta? --> ");
	
	for (int i=0;i<nroAtual;i++){
		if (codigoConta == contas[i].nro_conta){
			cout << setw(10) << left << "Código" << 
			setw(20) << left << "Nome" << setw(10) << left << "Saldo" << endl;
			cout << "-------------------------------------" << endl;
			
			cout << setw(9) << left << contas[i].nro_conta <<
			setw(20) << left << contas[i].nome_cliente.substr(0,18) << setw(10) << left << fixed << setprecision(2)<< contas[i].saldo << endl;
			cout << "-------------------------------------" << endl << endl;
			
			system("pause");			
			achou = true;
			break;
		}
	}
	if (!achou){
		system("cls");
			cout << "❌ Nenhuma conta foi encontrada com esse código" << endl;
			system("pause");
		}
}

void consultar_todas_contas(){
	system("cls");
	cout << "===========================" << endl;
	cout << setw(20) << right << "Consultar todas as Contas"<< endl;
	cout << "===========================" << endl;
	cout << "\n";
	
	cout << setw(10) << left << "Código" << 
	setw(20) << left << "Nome" << setw(10) << left << "Saldo" << endl;
	cout << "-------------------------------------" << endl;
	
			
	for (int i=0;i<nroAtual;i++){
			
			cout << setw(9) << left << contas[i].nro_conta <<
			setw(20) << left << contas[i].nome_cliente.substr(0,18) << setw(10) << left << fixed << setprecision(2)<< contas[i].saldo << endl;
			cout << "-------------------------------------" << endl;
			
	}
	system("pause");
}

void realizar_saque(){
	int codigoConta;
	double saque;
	bool achou = false;
	
	system("cls");
	cout << "===========================" << endl;
	cout << setw(20) << right << "Realizar Saque"<< endl;
	cout << "===========================" << endl;
	cout << "\n";
	
	codigoConta = pega_valor("Qual o código da conta? --> ");
	
	for (int i=0;i<nroAtual;i++){
		if (codigoConta == contas[i].nro_conta){
			achou = true;
			cout << setw(10) << left << "Código" << setw(10) << left << "Saldo" << endl;
			
			cout << setw(9) << left << contas[i].nro_conta << setw(10) << left << fixed << setprecision(2)<< contas[i].saldo << endl;
			cout << "-------------------------------------" << endl << endl;
			saque = pega_valor("Saldo para ser sacado --> ");
			
			if (saque > contas[i].saldo){
				system("cls");
				cout << "❌ ERRO -- > Tentativa de saque maior do que o saldo disponpivel!" << endl << endl;
				system("pause");
				break;
			}else{
				system("cls");
				contas[i].saldo -= saque;
				cout << "✅ Valor sacado com sucesso! O saldo atual da conta é " << contas[i].saldo << endl << endl;
				system("pause");
			}
		}
	}
	if (!achou){
		system("cls");
			cout << "❌ Nenhuma conta foi encontrada com esse código" << endl;
			system("pause");
		}
}

void realizar_deposito(){
	int codigoConta;
	double deposito;
	bool achou = false;
	
	system("cls");
	cout << "===========================" << endl;
	cout << setw(20) << right << "Realizar Deposito"<< endl;
	cout << "===========================" << endl;
	cout << "\n";
	
	codigoConta = pega_valor("Qual o código da conta? --> ");
	
	for (int i=0;i<nroAtual;i++){
		if (codigoConta == contas[i].nro_conta){
			achou = true;
			cout << setw(10) << left << "Código" << setw(10) << left << "Saldo" << endl;
			
			cout << setw(9) << left << contas[i].nro_conta << setw(10) << left << fixed << setprecision(2)<< contas[i].saldo << endl;
			cout << "-------------------------------------" << endl << endl;
			deposito = pega_valor("Saldo para ser depositado --> ");
			
				system("cls");
				contas[i].saldo += deposito;
				cout << "✅ Valor depositado com sucesso! O saldo atual da conta é " << contas[i].saldo << endl << endl;
				system("pause");
			
		}
	}
	if (!achou){
		system("cls");
			cout << "❌ Nenhuma conta foi encontrada com esse código" << endl;
			system("pause");
		}
}

void remover_conta(){
	int codigoConta;
	bool achou = false;
	
	system("cls");
	cout << "===========================" << endl;
	cout << setw(20) << right << "Remover Conta ☠️"<< endl;
	cout << "===========================" << endl;
	cout << "\n";
	
	codigoConta = pega_valor("Qual o código da conta? --> ");
	
	for (int i=0;i<nroAtual;i++){
			for (int j=i;j<nroAtual-1; j++){
				contas[j] = contas[j+1];
			}
			
			system("cls");
			cout << "✅ Conta no nome de [" << contas[i].nome_cliente << "] removida com sucesso!" << endl;
			cout << "-------------------------------------" << "\n\n\n\n\n";
			
			system("pause");			
			achou = true;
			nroAtual --;
			break;
			
		}       
			if (!achou){           
			system("cls");
				cout << "❌ Nenhuma conta foi encontrada com esse código" << endl;
				system("pause");
			}	
			
		         
	}
	

// PROGRAMA PRINCIPAL


int main(){
	SetConsoleOutputCP(CP_UTF8);
	
	// Funções do escopo MAIN
	int opc;
	
	
	while (true){
		system("cls");
		
		
		// Tratamento de dados no MENU
		menu();
		cout << "Digite a opção desejada" << "\n";
		cout << "-------------------------------------" << endl;
		cin >> opc;
		
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			system("cls");
			cout << "\n❌ ERRO -- > Digite apenas números" << endl;
			cout << "-------------------------------------" << "\n\n\n\n\n";
			system("pause");
			continue;
		}
		
		if (opc == 7){
			system("cls");
			cout << "Encerrando o programa..." << endl;
			break;
		}
		
		if (opc < 1 || opc > 7){
			system("cls");
			cout << "❌ ERRO -- > Número fora do escopo!" << endl;
			cout << "-------------------------------------" << "\n\n\n\n\n";
			system("pause");
			continue;
		}
		
		// Demais Opções
		
		switch (opc){
			case 1:
				if (nroAtual >= 3){
					system("cls");
					cout << "\n❌ Número máximo de contas atingido!\n\n\n";
					system("pause");
					break;
				}
				cadastrar_conta();
				break;
			case 2:
				if (nroAtual == 0){
					system("cls");
					cout << "❌ Não há contas cadastradas no momento!" << endl;
					system("pause");
					break;
				}
				remover_conta();
				break;
			case 3:
				if (nroAtual == 0){
					system("cls");
					cout << "❌ Não há contas cadastradas no momento!" << endl;
					system("pause");
					break;
				}
				consultar_conta();
				break;
			case 4:
				if (nroAtual == 0){
					system("cls");
					cout << "❌ Não há contas cadastradas no momento!" << endl;
					system("pause");
					break;
				}
				consultar_todas_contas();
				break;
			case 5:
				if (nroAtual == 0){
					system("cls");
					cout << "❌ Não há contas cadastradas no momento!" << endl;
					system("pause");
					break;
				}
				realizar_saque();
				break;
			case 6:
				if (nroAtual == 0){
					system("cls");
					cout << "❌ Não há contas cadastradas no momento!" << endl;
					system("pause");
					break;
				}
				realizar_deposito();
				break;
			default:
				system("cls");
				cout << "❌ Opção inválida! Tente novamente." << endl;
				cout << "-------------------------------------" << "\n\n\n\n\n";
				system("pause");
				break;
		}
		
	}
	
	
	
	return 0;
}