#include <iostream>
#include <string>

using namespace std;

int continuar(){
  int num;
  cout << "Digite 1 para parar o mapeamento! ";
  cin >> num;
  if (num != 18){
    return 0;
  } else {
    return num;
  }
}

int main(){
  int suspender = 0;
  while (suspender == 0){
    suspender = continuar();
  }
 
  return 1;
}


