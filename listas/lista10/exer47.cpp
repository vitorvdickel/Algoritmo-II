#include <iostream>
#include <cstring>

using namespace std;

void maiusculo(char *texto)
{
    while (*texto != '\0')
    {
        if (*texto >= 'a' && *texto <= 'z')
        {
            *texto = *texto - 32;
        }
        texto++;
    }
}

int main()
{
    char *texto;
    int tamanho;

    cout << "Digite o tamanho do texto: ";
    cin >> tamanho;
    cin.ignore();

    texto = new char[tamanho + 1];

    cout << "Digite um texto: ";
    cin.getline(texto, tamanho + 1);

    cout << "\nTexto digitado: ";
    
    char *p = texto;
    while (*p != '\0')
    {
        cout << *p;
        p++;
    }

    cout << "\nTexto invertido: ";

    p = texto + strlen(texto) - 1;

    while (p >= texto)
    {
        cout << *p;
        p--;
    }

    maiusculo(texto);

    cout << "\nTexto em maiusculo: ";

    p = texto;
    while (*p != '\0')
    {
        cout << *p;
        p++;
    }

    delete[] texto;

    return 0;
}