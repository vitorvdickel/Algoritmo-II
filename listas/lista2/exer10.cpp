/*10 - Um pangrama é uma frase que contém todas as letras de um determinado
alfabeto.
Em português, um pangrama pode incluir também letras acentuadas, mas neste
problema vamos desconsiderar os acentos (mesmo que isso torne a frase mal escrita!),
também vamos considerar o seguinte alfabeto:
a b c d e f g h i j l m n o p q r s t u v x z
Não consideramos as letras k, w ou y. Note ainda que as frases não contêm letras
acentuadas mas podem conter símbolos gráficos como espaço em branco, vírgula, ponto
e dois pontos.
Entrada
Uma única linha da entrada contendo uma cadeia de caracteres C.
Saída
Seu programa deve produzir uma única linha, contendo um único caractere, que deve
ser S se a frase for um pangrama ou N caso contrário.
Restrições
A cadeia de caracteres C tem no mínimo um e no máximo 200 caracteres. Os únicos
caracteres em C são as letras minúsculas do alfabeto mostrado acima, podem existir
caracteres repetidos, espaços em branco, vírgulas, ponto e o caractere dois pontos.*/

#include <iostream>
#include <cstring> // Necessária para o strlen()

using namespace std;

int main() {
    // A restrição diz que a frase tem no máximo 200 caracteres, 
    // então um vetor de 205 é uma margem de segurança excelente.
    char frase[205]; 

    // Lê a linha inteira, inclusive os espaços
    cin.getline(frase, 205);

    int tamanho = strlen(frase);
    
    // Vetor para marcar quais letras já apareceram
    bool letras_vistas[26];
    
    // Inicializa tudo com falso
    for (int i = 0; i < 26; i++) {
        letras_vistas[i] = false;
    }

    // Varre a frase letra por letra
    for (int i = 0; i < tamanho; i++) {
        char c = frase[i];
        
        // Verifica se é uma letra minúscula
        if (c >= 'a' && c <= 'z') {
            // O pulo do gato: 'a'-'a' = 0, 'b'-'a' = 1, 'c'-'a' = 2...
            int posicao = c - 'a'; 
            letras_vistas[posicao] = true;
        }
    }

    bool eh_pangrama = true;

    // Verificando se as 23 letras exigidas apareceram
    for (int i = 0; i < 26; i++) {
        // Ignorando o k (índice 10), w (índice 22) e y (índice 24)
        if (i == 10 || i == 22 || i == 24) {
            continue; // Pula para a próxima repetição do laço
        }
        
        // Se batermos em alguma letra (fora as 3 acima) que não foi vista...
        if (letras_vistas[i] == false) {
            eh_pangrama = false;
            break; // Já sabemos que não é pangrama, não precisa olhar o resto
        }
    }

    // Saída exigida (apenas S ou N)
    if (eh_pangrama) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}