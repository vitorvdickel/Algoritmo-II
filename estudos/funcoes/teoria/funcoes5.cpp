// Funções - Parte 5 Omissão de argumentos e argumentos padrão
// Argumentos padrão: quando um argumento é omitido, o valor padrão é usado
#include <iostream>

using namespace std;

void imprimir(string texto = "Nenhum texto informado"); // argumento padrão

int main(){

    imprimir("Vitor");

    return 0;
}

void imprimir(string texto){
    cout << texto << endl;
}