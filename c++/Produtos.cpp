#include <iomanip>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
	SetConsoleOutputCP(CP_UTF8);
	float p[7];
	int i;
	float total, media, maisVendido, menosVendido, produtosAbaixo;
	maisVendido = 0;
	menosVendido=0;
	
	
	for (i=0;i<7;i++){
		cout<<"Digite a venda do "<< i+1 <<"° produto" << endl;
		cin>>p[i];
		total = total+p[i];
		
		if (p[i] > maisVendido){
			maisVendido=p[i];
		}
		
		if(menosVendido==0){
			menosVendido = p[i];
		}
		if(p[i]<menosVendido){
			menosVendido=p[i];
		}
	}
	media = total/7;
	
	for(i=0; i<7; i++){
		cout << i+1 << "° produto: " << p[i] << endl;
	}
	

	
	cout << "================" << endl;
	cout << "O total é de: " << total << endl;
	cout << "A média é de: " << media << endl;
	cout << "O mais vendido foi o: " << maisVendido << endl;
	cout << "O menos vendido foi o: " << menosVendido << endl;
	
	for(i=0;i<7;i++){
	if (p[i]<media){
			cout << "O produto "<< i+1 << "° está abaixo!" << endl;
		}
	}
	
	
	

}