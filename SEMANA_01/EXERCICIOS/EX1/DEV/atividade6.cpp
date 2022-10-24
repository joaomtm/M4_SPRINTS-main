#include <iostream>
#include <string>

using namespace std;

int dirigir_robo(int vetor[]) {
  
  int vetorDist[4] = {};
  string comandos[4] = {"Direita", "Esquerda", "Frente", "Trás"};
  string ordemDir[4] = {};

  for (int i = 0; i <= 3; i++) {
    vetorDist[i] = vetor[i];
  }

  for (int i = 0; i < 4; i++) {

    for (int j = i + 1; j < 4; j++) {

      if (vetorDist[i] < vetorDist[j]) {
        int temp = vetorDist[i];
        vetorDist[i] = vetorDist[j];
        vetorDist[j] = temp;
        
      }
    }
  }

  for (int i = 0; i <= 3; i++){
    for (int j = 0; j <= 3; j++){
      if(vetorDist[j] == vetor[i]){
        ordemDir[j] = comandos[i];
      }
    }
  }

  cout << vetorDist[0] << endl;
  cout << vetorDist[1] << endl;
  cout << vetorDist[2] << endl;
  cout << vetorDist[3] << endl;
  cout << ordemDir[0] << endl;
  cout << ordemDir[1] << endl;
  cout << ordemDir[2] << endl;
  cout << ordemDir[3] << endl;
  
  return 0;
}

int main() {

  int posicoes[4] = {0, 10, 30, 20};

  cout << dirigir_robo(posicoes);
}