#include <iomanip>
#include <Windows.h>
#include <iostream>

using namespace std;
char confirma;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	
	while(true){
		int nro_clientes;
		cout << "\n=== Pesquisa de satisfação ===";
		while(true){
			cout << "Digite o número de clientes (1 a 10) ou (-1 para sair): ";
			cin >> nro_clientes;
			
			if (nro_clientes == -1){
				break;
			}
			if (cin.fail()){
				cout << "Entrada inválida. Nã aceita carcater\n";
				cin.clear();
				cin.ignore(100,'\n');
				continue;
			}
			if (nro_clientes<1 or nro_clientes>10){
				cout << "\nEntrada inválida. Digite um nro entre 1 a 10\n";
			}else{
				break;
			}
			
			
		}
		if (nro_clientes != -1){
			int comida[nro_clientes],atendimento[nro_clientes],ambiente[nro_clientes];
			double somacomida=0, somaatendimento=0,somaambiente=0;
			double mediacomida=0, mediaatendimento=0,mediaambiente=0;
			for (int i=0; i<nro_clientes;i++){
				cout << "	Cliente (" << i+1 << ")\n";
				while(true){
					cout << "	Comida (1 a 5): ";
					cin >> comida[i];
					if (cin.fail()){
						cout << "Nota inválida! (Não aceitamos carater aqui.)\n";
						cin.clear();
						cin.ignore(100,'\n');
					}
					else{
						if (comida[i] < 1 or comida[i] > 5){
							cout << "\nNota inválida. (Digite uma nota de 1 a 5)\n";
						}else{
							somacomida += comida[i];
							break;
						}
					}
				}
				while(true){
					cout << "	Atendimento (1 a 5): ";
					cin >> atendimento[i];
					if (cin.fail()){
						cout << "Nota inválida! (Não aceitamos carater aqui.)\n";
						cin.clear();
						cin.ignore(100,'\n');
					}
					else{
						if (atendimento[i] < 1 or atendimento[i] > 5){
							cout << "\nNota inválida. (Digite uma nota de 1 a 5)\n";
						}else{
							somaatendimento += atendimento[i];
							break;
						}
					}
				}
				while(true){
					cout << "	Ambiente (1 a 5): ";
					cin >> ambiente[i];
					if (cin.fail()){
						cout << "Nota inválida! (Não aceitamos carater aqui.)\n";
						cin.clear();
						cin.ignore(100,'\n');
					}
					else{
						if (ambiente[i] < 1 or ambiente[i] > 5){
							cout << "\nNota inválida. (Digite uma nota de 1 a 5)\n";
						}else{
							somaambiente += ambiente[i];
							break;
						}
					}
				}
		}
		
		mediacomida = somacomida/nro_clientes;
		mediaatendimento = somaatendimento/nro_clientes;
		mediaambiente = somaambiente/nro_clientes;
		
		cout << fixed << setprecision(2);
		cout << "\n=== Resultados ===\n";
		cout << "\nMédia do item <comida>   	:" << mediacomida << endl;
		cout << "\nMédia do item <atendimento> 	:" << mediaatendimento << endl;
		cout << "\nMédia do item <ambiente>		:" << mediaambiente << endl;
		
		cout << "\nMédia Geral					:" << (mediacomida+mediaatendimento+mediaambiente)/3 << endl;
		
		while (true){
			cout << "\nDeseja coletar uma nova pesquisa? (s/n) : " << endl;
			cin >> confirma;
			if (tolower(confirma)=='s' or tolower(confirma=='n')){
				break;
			}else{
				cout << "\nEntrada inválida\n";
			}
		}
		if (tolower(confirma) == 'n'){
			break;
		}
		
		}else{
		break;
		}
		
	}
	system("cls");
	
	return 0;
}