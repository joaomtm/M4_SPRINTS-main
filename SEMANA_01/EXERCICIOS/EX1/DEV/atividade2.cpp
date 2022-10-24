#include <iostream>
#include <string>

using namespace std;

int leComando(){
    int digito;
    cin >> digito;
    return digito;

}

int main(){
  cout << "Digite o Comando (0 ou 1):";
	int cmd = leComando();
	cout << "Comando Recebido: " << cmd << endl;
}
