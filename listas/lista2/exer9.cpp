/*9 - Escreva um programa que recebe uma string do usuário e verifica se ela é um
endereço de e-mail do google válido, sabendo que os endereços de e-mail do google
seguem o seguinte formato:
textoqualquer@gmail.com
Algumas restrições importantes:
- endereços de e-mail não podem conter espaço em branco
- obrigatoriamente deve aparecer somente uma vez o caracter @
- considere que neste caso o endereço de e-mail não pode iniciar por um número
- endereço de e-mail só pode conter caracteres minúsculos
- o “_” underline e o “.” ponto podem aparecer entre duas palavras
Apresente como saída a mensagem “VÁLIDO” se o endereço for correto ou “INVÁLIDO”
se o endereço não estiver correto*/

#include <iostream>
#include <cstring> // Necessária para strlen() e strcmp()

using namespace std;

int main() {
    // Vetor de char para armazenar a entrada (tamanho 256 é seguro para e-mails)
    char email[256];

    // Lendo a entrada. Usamos cin.getline() ao invés de só cin >> email
    // porque o cin normal para de ler no primeiro espaço em branco, 
    // e nós precisamos ler o espaço para poder invalidá-lo depois.
    cout << "Digite o e-mail: ";
    cin.getline(email, 256);

    int tamanho = strlen(email);
    bool valido = true;
    int qtd_arroba = 0;
    int pos_arroba = -1;

    // Regra: Não pode iniciar com número
    if (email[0] >= '0' && email[0] <= '9') {
        valido = false;
    }

    // Regra: Não pode ter prefixo vazio (ex: só "@gmail.com")
    if (email[0] == '@') {
        valido = false;
    }

    // Varrer o e-mail caractere por caractere
    for (int i = 0; i < tamanho; i++) {
        // Regra: Não pode conter espaço em branco
        if (email[i] == ' ') {
            valido = false;
        }

        // Regra: Só pode conter caracteres minúsculos (se for letra)
        if (email[i] >= 'A' && email[i] <= 'Z') {
            valido = false;
        }

        // Conta quantos '@' existem e salva a posição
        if (email[i] == '@') {
            qtd_arroba++;
            pos_arroba = i;
        }

        // Verificando se o caractere é permitido (letras minúsculas, números, _, . e @)
        if (!(email[i] >= 'a' && email[i] <= 'z') &&
            !(email[i] >= '0' && email[i] <= '9') &&
            email[i] != '_' && email[i] != '.' && email[i] != '@') {
            valido = false;
        }
    }

    // Regra: Obrigatoriamente deve aparecer SOMENTE UMA vez o caracter @
    if (qtd_arroba != 1) {
        valido = false;
    }

    // Regra do formato final do Google
    // Se ainda for válido até aqui e tivermos encontrado o '@'
    if (valido && pos_arroba != -1) {
        // O pulo do gato: &email[pos_arroba] pega o pedaço da string a partir do '@' até o fim.
        // A função strcmp() compara duas strings e retorna 0 se elas forem exatamente iguais.
        if (strcmp(&email[pos_arroba], "@gmail.com") != 0) {
            valido = false;
        }
    }

    // Saída final conforme exigido pelo exemplo
    if (valido) {
        cout << "VÁLIDO" << endl;
    } else {
        cout << "INVÁLIDO" << endl;
    }

    return 0;
}