#include <iomanip>
#include <iostream>
#include <Windows.h>

using namespace std;

void menu(){
	cout << "1. Cadastrar conta\n2. Depositar\n3. Sacar\n4. Consultar saldo\n5. Sair" << endl;
}
void cadastrar(nomeConta[],totalContas[], indice){
	cout << "Digite o nome do titular da conta: " << endl;
	while true{
		cin >> nomeConta[indice];
		if (cin.fail()){
			cout << "É necessário ser uma string." << endl;
			cin.clear();
			cin.ignore(100,'\n');
		}else{
			break;
		}
	}
	totalContas[indice] = 0;
	cout << fixed << setprecisio(2);
	cout << "A conta número " << (indice)+1 << " está cadastrada no nome de " << nomeConta[indice] << " com um saldo de " << totalContas[indice];
}

int main{
SetConsoleOutputCP(CP_UTF8)

bool principal=true;
int totalContas[9], indice=0;
string nomeConta[9];

while (true){
	int opcao;
	cout << "=== Sistema Bancário! ===" << endl;
	cout << "Digite uma opção!" << endl;
	menu();
	while true{
		cin >> opcao;
		if (cin.fail()){
			cout << "Entrada inválida! Não aceitamos caracteres!" << endl;
			cin.clear();
			cin.ignore(100,'\n');
			continue
		}
		if (opcao < 1 or opcao > 5){
			cout << "Entrada inválida! Digite um número entre 1 e 5!" << endl;
			continue;
		}
		break;
	}
	switch opcao{
	case 1{
		if (indice == 10){
			cout << "Número total de contas já foi atingido!" << endl;
			break;
		}else{
		cadastrar(nomeConta[],totalContas[], indice);
		indice +=1;
		break;
	}
	}
	case 2{
		depositar(totalContas[]);  // PAREI AQUI!!!!!!!!!!!!!!!!!!!!!!!
		break;
	}
	case 3{
		sacar();
		break;
	}
	case 4{
		consultar();
		break;
	}
	case 5{
		principal = false;
		cout << "Até a próxima!!" << endl;
		break;
	}
	default{
		cout << "Opção inválida!" << endl;
		break;
	}
	}
	
	
}


return 0;
}