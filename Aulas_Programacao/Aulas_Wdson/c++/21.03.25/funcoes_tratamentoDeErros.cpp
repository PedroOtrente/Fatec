/*Exercicio5-Programa para  calcular a área de figuras 
geométricas : quadrado, círculo, triângulo ou 
trapézio.
As funções receberão os parâmetros enviados
pelo programa principal e retornarão o resultado
para serem apresentados ao usuário.

Menu de opções:

1.Área do quadrado  -> lado * lado
2.Área do círculo   -> M_PI * (raio**2)
3.Área do triângulo -> (base * altura) / 2
4.Área do trapézio  -> ((base_maior + base_menor)*altura)/2
5.Sair
*/


#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>

using namespace std;

int menu(){
	int opc;
	cout << "MEU DE OPÇÕES" << endl;
	cout << "1. Área do quadrado\n2. Área do cículo\n3. Área do triângulo\n4. Área do trapézio\n5. Sair" << endl;
	cout << "Digite a opção desejada!\n";
	cin >> opc;
	
	return opc;
}

float tratarDados(float num){
	int momentaneo = 0;
	do{
	momentaneo = 0;
	if (num <= 0){
		cout << "Não há lugares para números negativos ou nulos aqui." << endl;
		cout << "Digite novamente o número" << endl;
		cin >> num;
		momentaneo = 1;
	}
		
	if (cin.fail()){
		cout << "Entrada de dados inválida!" << endl;
		cin.clear();
		cin.ignore(100,'\n');
		cout << "Digite novamente o número" << endl;
		cin >> num;
		momentaneo = 1;
	}
	
	}while (momentaneo>0);
	
	return num;

}

void areaDoQuadrado(){
	float num1,num2;
	system("cls");
	
	cout << "Área do quadrado!\nDigite o primeiro valor!\n";
	cin >> num1;
	num1 = tratarDados(num1);
	cout << "Digite o segundo valor!\n";
	cin >> num2;
	num2 = tratarDados(num2);
	
	cout << "A área do quadrado é " << num1*num2 << endl;
	system("pause");
	cout << endl;
	}
	
	


void areaDoCirculo(){
	float num1;
	system("cls");
	
	cout << "Área do círculo!\nDigite o raio!\n";
	cin >> num1;
	num1 = tratarDados(num1);
	
	cout << "A área do cirulo é " << (M_PI*(pow(num1,2))) << endl;
	system("pause");
	cout << endl;
}
	
	
void areaDoTriangulo(){
	float num1,num2;
	system("cls");
	
	cout << "Área do triângulo!\nDigite a base!\n";
	cin >> num1;
	num1 = tratarDados(num1);
	cout << "Digite a altura!" << endl;
	cin >> num2;
	num2 = tratarDados(num2);
	
	cout << "A área do triângulo é  " << ((num1*num2)/2) << endl;
	system("pause");
	cout << endl;
	}
	

	

void areaDoTrapezio(){
	float num1,num2,num3;
	system("cls");
	
	cout << "Área do trapézio!\nDigite a base maior!\n";
	cin >> num1;
	num1 = tratarDados(num1);
	cout << "Digite a base menor!" << endl;
	cin >> num2;
	num2 = tratarDados(num2);
	cout << "Digite a altura!" << endl;
	cin >> num3;
	num3 = tratarDados(num3);
	
	cout << "A área do trapézio é " << (((num1+num2)*num3)/2) << endl;
	system("pause");
	cout << endl;
	}


void sair(){
	system("cls");
	cout << "Até a próxima, parceiro!\n\n";
	system("pause");
}
	


int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	bool loop = true;
	
	cout << fixed << setprecision(2);
	
	while(loop == true){
	
	int opc = menu();
	if (opc < 1 || opc > 5){
		cout << "Digite um número dentro do escopo!" << endl;
		continue;
	}
	if (cin.fail()){
		cout << "Entrada inválida!";
		cin.clear();
		cin.ignore(100,'\n');
	}
	
	

	
	switch (opc){
		case 1:
			areaDoQuadrado();
			break;
		case 2:
			areaDoCirculo();
			break;
		case 3:
			areaDoTriangulo();
			break;
		case 4:
			areaDoTrapezio();
			break;
		case 5:
			sair();
			loop = false;
			break;
		default:
			cout << "Essa opção não está lá muito válida..." << endl;
			break;
	
	}
	
}
	
	
}