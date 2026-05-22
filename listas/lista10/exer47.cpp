#include <iostream>
#include <cstring>

using namespace std;

void maiusculo (char *texto){
    while (*texto != '\0'){
        if (*texto >= 'a' && *texto <= 'z'){
            *texto = *texto - 32;
        }
        texto++;
    }
}

int main(){
    char *texto = new char [200];

    cout << "Digite um texto: " << endl;
    cin.getline(texto, 200);

    cout << "Texto original: " << endl;

    for (char *p = texto; *p != '\0'; p++){
        cout << *p;
    }

    cout << "Texto de trás para frente:" << endl;

    for (char *p = texto + strlen(texto) - 1; p >= texto; p--){
        cout << *p;
    }

    maiusculo(texto);

    cout << "Texto em maisculo" << endl;

    for (char *p = texto; *p != '\0'; p++){
        cout << *p;
    }

    delete [] texto;

    return 0;
}